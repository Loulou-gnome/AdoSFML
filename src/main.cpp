#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    const auto onClose = [&window](const sf::Event::Closed)
        {
            window.close();
        };
    const auto onKeyPressed = [&window](const sf::Event::KeyPressed keyPressed)
        {
            if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
            {
                window.close();
            }
        };

    while (window.isOpen())
    {
        window.handleEvents(onClose, onKeyPressed);
        
        window.clear();
        window.display();
    }
}
