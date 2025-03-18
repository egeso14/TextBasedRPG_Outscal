#include "UIManager.h"


UIManager* UIManager::instance = nullptr;

UIManager::UIManager() {
    // Initialization code here
    if (!font.openFromFile("SourGummy-VariableFont_wdth,wght.ttf")) 
    {
        std::cout << "Error loading font\n";
    }
}

void UIManager::centerText(sf::Text& text, const sf::RectangleShape& button) {
    sf::FloatRect textBounds = text.getLocalBounds();
    
    // Set origin to the center of the text
    text.setOrigin({ textBounds.getCenter() });

    // Get button's position and size
    sf::Vector2f buttonCenter = button.getPosition() + (button.getSize() / 2.0f);

    // Set the text position to the center of the button
    text.setPosition(buttonCenter);
    
}

void UIManager::WaitForContinue()
{
    sf::RenderWindow window(sf::VideoMode({ 400, 350 }), "Continue");

    sf::RectangleShape button1(sf::Vector2f(400, 350));
    button1.setPosition({ 0, 0 });
    button1.setFillColor(sf::Color::Red);
    button1.setOutlineThickness(5);
    button1.setOutlineColor(sf::Color::White);

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            else if (event->is<sf::Event::MouseButtonPressed>()) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

                if (button1.getGlobalBounds().contains(mousePosF)) {
                   
                    return;
                }
            }
        }

        window.clear(sf::Color::Black);

        window.draw(button1);

        window.display();
    }
}
