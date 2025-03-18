#pragma once
#include <SFML/Graphics.hpp>
#include "EnumWrapper.h"

class UIManager {
public:

    void WaitForContinue();
    template<typename enumType>
    EnumWrapper<enumType> ChooseOptions(const std::vector<EnumWrapper<enumType>>& options) {
        sf::RenderWindow window(sf::VideoMode({ 400, 300 }), "SFML Buttons");



        std::vector<sf::RectangleShape> buttons;
        std::vector<sf::Text> texts;

        int buttonWidth = 400;
        int buttonHeight = 300 / options.size(); // Dynamically size buttons
        float yPos = 0;

        for (size_t i = 0; i < options.size(); i++) {
            // Create button
            sf::RectangleShape button(sf::Vector2f(buttonWidth, buttonHeight));
            button.setPosition({ 0, yPos });
            button.setFillColor(sf::Color(100, 100, 255)); // Blue color
            button.setOutlineThickness(5);
            button.setOutlineColor(sf::Color::White);
            buttons.push_back(button);

            // Create text
            sf::Text text(font, (std::string)options[i], 20);
            text.setFillColor(sf::Color::White);
            centerText(text, button);
            texts.push_back(text);

            yPos += buttonHeight; // Move to next row
        }

        while (window.isOpen()) {
            while (const std::optional<sf::Event> event = window.pollEvent()) {
                if (event->getIf<sf::Event::Closed>())
                    window.close();

                else if (event->getIf<sf::Event::MouseButtonPressed>() )  {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

                    for (size_t i = 0; i < buttons.size(); i++) {
                        if (buttons[i].getGlobalBounds().contains(mousePosF)) {
                            //std::cout << "Button " << i + 1 << " pressed: " << (std::string)options[i] << std::endl;
                            return options[i]; // Return selected object
                        }
                    }
                }
            }

            window.clear(sf::Color::Black);
            for (size_t i = 0; i < buttons.size(); i++) {
                window.draw(buttons[i]);
                window.draw(texts[i]);
            }
            window.display();
        }

        return options[0]; // Default return value in case of error
    }

    template<typename enumType>
    EnumWrapper<enumType> Choose4Options(const EnumWrapper<enumType>& arg1, const EnumWrapper<enumType>& arg2,
        const EnumWrapper<enumType>& arg3, const EnumWrapper<enumType>& arg4) {
        sf::RenderWindow window(sf::VideoMode({ 400, 300 }), "SFML Buttons");

        sf::RectangleShape button1(sf::Vector2f(200, 150));
        button1.setPosition({ 0, 0 });
        button1.setFillColor(sf::Color::Red);
        button1.setOutlineThickness(5);
        button1.setOutlineColor(sf::Color::White);

        sf::RectangleShape button2(sf::Vector2f({ 200, 150 }));
        button2.setPosition({ 200, 0 });
        button2.setFillColor(sf::Color::Green);
        button2.setOutlineThickness(5);
        button2.setOutlineColor(sf::Color::White);

        sf::RectangleShape button3(sf::Vector2f(200, 150));
        button3.setPosition({ 0, 150 });
        button3.setFillColor(sf::Color::Blue);
        button3.setOutlineThickness(5);
        button3.setOutlineColor(sf::Color::White);

        sf::RectangleShape button4(sf::Vector2f(200, 150));
        button4.setPosition({ 200, 150 });
        button4.setFillColor(sf::Color::Cyan);
        button4.setOutlineThickness(5);
        button4.setOutlineColor(sf::Color::White);

        sf::Text text1(font, (std::string)arg1, 20);
        sf::Text text2(font, (std::string)arg2, 20);
        sf::Text text3(font, (std::string)arg3, 20);
        sf::Text text4(font, (std::string)arg4, 20);

        centerText(text1, button1);
        centerText(text2, button2);
        centerText(text3, button3);
        centerText(text4, button4);

        while (window.isOpen()) {
            while (const std::optional<sf::Event> event = window.pollEvent()) {
                if (event->getIf<sf::Event::Closed>())
                    window.close();

                else if (event->getIf<sf::Event::MouseButtonPressed>()) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

                    if (button1.getGlobalBounds().contains(mousePosF)) {
                        //std::cout << "Button 1 pressed: " << (std::string)arg1 << std::endl;
                        return arg1;
                    }
                    else if (button2.getGlobalBounds().contains(mousePosF)) {
                        //std::cout << "Button 2 pressed: " << (std::string)arg2 << std::endl;
                        return arg2;
                    }
                    else if (button3.getGlobalBounds().contains(mousePosF)) {
                        //std::cout << "Button 3 pressed: " << (std::string)arg3 << std::endl;
                        return arg3;
                    }
                    else if (button4.getGlobalBounds().contains(mousePosF)) {
                        //std::cout << "Button 4 pressed: " << (std::string)arg4 << std::endl;
                        return arg4;
                    }
                }
            }

            window.clear(sf::Color::Black);

            window.draw(button1);
            window.draw(button2);
            window.draw(button3);
            window.draw(button4);
            window.draw(text1);
            window.draw(text2);
            window.draw(text3);
            window.draw(text4);

            window.display();
        }

        return arg1; // Default return value
    }

    template<typename enumType>
    std::vector<EnumWrapper<enumType>> ChooseMultipleOptions(std::vector<EnumWrapper<enumType>>& options, size_t numChoices) {
        sf::RenderWindow window(sf::VideoMode({ 400, 350 }), "Select Options");

        

        std::vector<sf::RectangleShape> buttons;
        std::vector<sf::Text> texts;
        std::vector<bool> selected(options.size(), false); // Track selected options

        int buttonWidth = 400;
        int buttonHeight = 300 / options.size();
        int yPos = 0;

        for (size_t i = 0; i < options.size(); i++) {
            // Create button
            sf::RectangleShape button(sf::Vector2f(buttonWidth, buttonHeight));
            button.setPosition(0, yPos);
            button.setFillColor(sf::Color(100, 100, 255)); // Default blue
            button.setOutlineThickness(5);
            button.setOutlineColor(sf::Color::White);
            buttons.push_back(button);

            // Create text
            sf::Text text((std::string)options[i], font, 20);
            text.setFillColor(sf::Color::White);
            centerText(text, button);
            texts.push_back(text);

            yPos += buttonHeight; // Move to next row
        }

        // "Confirm" button
        sf::RectangleShape confirmButton(sf::Vector2f(400, 50));
        confirmButton.setPosition(0, 300);
        confirmButton.setFillColor(sf::Color(0, 200, 0)); // Green
        confirmButton.setOutlineThickness(5);
        confirmButton.setOutlineColor(sf::Color::White);

        sf::Text confirmText("Confirm", font, 24);
        confirmText.setFillColor(sf::Color::White);
        centerText(confirmText, confirmButton);

        while (window.isOpen()) {
            while (const std::optional<sf::Event> event = window.pollEvent()) {
                if (event->getIf<sf::Event::Closed>())
                    window.close();

                else if (event->getIf<sf::Event::MouseButtonPressed>()) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

                    for (size_t i = 0; i < buttons.size(); i++) {
                        if (buttons[i].getGlobalBounds().contains(mousePosF)) {
                            // Toggle selection
                            selected[i] = !selected[i];
                            buttons[i].setFillColor(selected[i] ? sf::Color(255, 100, 100) : sf::Color(100, 100, 255));
                        }
                    }

                    // Confirm button logic
                    if (confirmButton.getGlobalBounds().contains(mousePosF)) {
                        std::vector<EnumWrapper<enumType>> chosenOptions;
                        for (size_t i = 0; i < options.size(); i++) {
                            if (selected[i])
                                chosenOptions.push_back(options[i]);
                        }
                        if (chosenOptions.size() == numChoices) {
                            window.close();
                            return chosenOptions;
                        }
                        else {
                            std::cout << "Please select exactly " << numChoices << " options." << std::endl;
                        }
                    }
                }
            }

            // Render UI
            window.clear(sf::Color::Black);
            for (size_t i = 0; i < buttons.size(); i++) {
                window.draw(buttons[i]);
                window.draw(texts[i]);
            }
            window.draw(confirmButton);
            window.draw(confirmText);
            window.display();
        }

        return {}; // Default return if window closes unexpectedly
    }

    // allows you to choose between multiple options and returns a list of pointers to the chosen enums
    template<typename enumType>
    std::vector<EnumWrapper<enumType>*> ChooseMultipleOptionsRef(std::vector<EnumWrapper<enumType>>& options, size_t numChoices) {
        sf::RenderWindow window(sf::VideoMode({ 400, 350 }), "Select Options");

       

        std::vector<sf::RectangleShape> buttons;
        std::vector<sf::Text> texts;
        std::vector<bool> selected(options.size(), false); // Track selected options

        int buttonWidth = 400;
        int buttonHeight = 300 / options.size();
        float yPos = 0;

        for (size_t i = 0; i < options.size(); i++) {
            // Create button
            sf::RectangleShape button(sf::Vector2f(buttonWidth, buttonHeight));
            button.setPosition({ 0, yPos });
            button.setFillColor(sf::Color(100, 100, 255)); // Default blue
            button.setOutlineThickness(5);
            button.setOutlineColor(sf::Color::White);
            buttons.push_back(button);

            // Create text
            sf::Text text(font, (std::string)options[i], 20);
            text.setFillColor(sf::Color::White);
            centerText(text, button);
            texts.push_back(text);

            yPos += buttonHeight; // Move to next row
        }

        // "Confirm" button
        sf::RectangleShape confirmButton(sf::Vector2f(400, 50));
        confirmButton.setPosition({ 0, 300 });
        confirmButton.setFillColor(sf::Color(0, 200, 0)); // Green
        confirmButton.setOutlineThickness(5);
        confirmButton.setOutlineColor(sf::Color::White);

        sf::Text confirmText(font, "Confirm", 24);
        confirmText.setFillColor(sf::Color::White);
        centerText(confirmText, confirmButton);

        while (window.isOpen()) {
            while (const std::optional<sf::Event> event = window.pollEvent()) {
                if (event->getIf<sf::Event::Closed>())
                    window.close();

                else if (event->getIf<sf::Event::MouseButtonPressed>()) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

                    for (size_t i = 0; i < buttons.size(); i++) {
                        if (buttons[i].getGlobalBounds().contains(mousePosF)) {
                            // Toggle selection
                            selected[i] = !selected[i];
                            buttons[i].setFillColor(selected[i] ? sf::Color(255, 100, 100) : sf::Color(100, 100, 255));
                        }
                    }

                    // Confirm button logic
                    if (confirmButton.getGlobalBounds().contains(mousePosF)) {
                        std::vector<EnumWrapper<enumType>*> chosenOptions;
                        for (size_t i = 0; i < options.size(); i++) {
                            if (selected[i])
                                chosenOptions.push_back(&(options[i]));
                        }
                        if (chosenOptions.size() == numChoices) {
                            window.close();
                            return chosenOptions;
                        }
                        else {
                            std::cout << "Please select exactly " << numChoices << " options." << std::endl;
                        }
                    }
                }
            }

            // Render UI
            window.clear(sf::Color::Black);
            for (size_t i = 0; i < buttons.size(); i++) {
                window.draw(buttons[i]);
                window.draw(texts[i]);
            }
            window.draw(confirmButton);
            window.draw(confirmText);
            window.display();
        }

        return {}; // Default return if window closes unexpectedly
    }


    
    static UIManager* GetInstance()
    {
        if (instance == nullptr)
        {
            instance = new UIManager();
        }
        return instance;
    }

private:

    UIManager();
    void centerText(sf::Text& text, const sf::RectangleShape& button);

    // font variables
    inline static const std::string fontFileLocation = "SourGummy-VariableFont_wdth,wght.ttf";
    sf::Font font;

    static UIManager* instance;
};
