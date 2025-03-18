#pragma once
#include <iostream>
#include <string>
#include <type_traits>


class Utility {
public:
    static void ClearConsole();
    static void WaitForEnter();
    static void ClearInputBuffer();
    static bool TestAgainstProb(float probability);
    static int ChooseInRange(int start, int end);
    static void Wait(float seconds);
   
    
   /* template<typename T>
    static auto PrintToConsole(bool endLine)
    {
        if (endLine)
        {
            std::cout << std::endl;
        }
        else
        {
            return;
        }
    }*/

    template<typename T, typename... Args>
    static auto PrintToConsole(bool endLine, T t, Args... args)
        -> decltype(std::cout << t, void()) // Ensures `first` is printable
    {
        if constexpr (std::is_same_v<T, float>) {
            std::cout << static_cast<int>(t); 
        }
        else {
            std::cout << t;
        }

        if constexpr (sizeof...(args) > 0)
        {
            PrintToConsole(endLine, args...);
        }
        else if (endLine)
        {
            std::cout << std::endl;
        }

    }
    
    static std::string RecieveInput();
};







