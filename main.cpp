// library
#include <SFML/Graphics.hpp>
#include <string>

// main program
int main()
{
    // string
    std::string string = "Align\nMultiple Lines\nText\nIn SFML";

    // load font
    sf::Font font("C:/Windows/Fonts/arial.ttf");

    // create text
    sf::Text text(font);
    text.setCharacterSize(100);
    text.setLetterSpacing(2.f);

    // create window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Title");

    // while window is still open
    while (window.isOpen())
    {
        // handle events
        while (std::optional event = window.pollEvent())
        {
            // when close button is pressed
            if (event->is<sf::Event::Closed>())
            {
                // close window
                window.close();
            }

            // when window is resized
            else if (event->is<sf::Event::Resized>())
            {
                // update view
                window.setView(sf::View(sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize()))));
            }
        }

        // fill window with color
        window.clear(sf::Color(64, 64, 64));

        // draw text
        int n = 0;
        for (int start = 0;; n++)
        {
            start = string.find('\n', start) + 1;
            if (start == 0)
                break;
        }
        for (int start = 0, i = 0;; i++)
        {
            int end = string.find('\n', start);

            text.setString(string.substr(start, end - start));
            sf::FloatRect bounds = text.getLocalBounds();
            text.setOrigin({bounds.position.x + bounds.size.x/2, text.getCharacterSize() * 0.75f});
            text.setPosition({400.f, 300.f + (i-n*0.5f) * 1.5f * text.getCharacterSize()});
            window.draw(text);

            if (end == -1)
                break;

            start = end + 1;
        }

        // display
        window.display();
    }

    // program end successfully
    return 0;
}