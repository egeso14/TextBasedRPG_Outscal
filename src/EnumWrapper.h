#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <type_traits>

template <typename EnumType>
class EnumWrapper {
private:
    EnumType value;
    static const std::unordered_map<EnumType, std::string> enumToStringMap;
    
public:
    // Constructor
    explicit EnumWrapper(EnumType v) : value(v), uninitialized(false) {}
    EnumWrapper() : value(static_cast<EnumType>(0)), uninitialized(true) {};
        

    // Implicit conversion to std::string
    operator std::string() const {
        auto it = enumToStringMap.find(value);
        return (it != enumToStringMap.end()) ? it->second : "Unknown";
    }

    friend std::ostream& operator<<(std::ostream& os, EnumWrapper<EnumType> t) {
        
        if (t.uninitialized)
        {
            os << "Uninitialized";
            return os;
        }
        os << (std::string)t;
        return os;
    }

    bool operator==(const EnumWrapper<EnumType>& other) const {
        return value == other.get();
    }
    bool operator!=(const EnumWrapper<EnumType>& other) const {
        return value != other.get();
    }

    // Getter for the original enum value
    EnumType get() const { return value; }
    static std::vector<EnumWrapper<EnumType>> getAllValues() 
    {
        std::vector<EnumWrapper<EnumType>> values;
        for (auto itr = enumToStringMap.begin(); itr != enumToStringMap.end(); ++itr)
        {
            values.push_back(EnumWrapper<EnumType>(itr->first));
        }
        return values;
    }
    bool uninitialized;
};


#define DEFINE_ENUM_MAPPING(EnumType, ...) \
    template<> \
    const std::unordered_map<EnumType, std::string> EnumWrapper<EnumType>::enumToStringMap = __VA_ARGS__