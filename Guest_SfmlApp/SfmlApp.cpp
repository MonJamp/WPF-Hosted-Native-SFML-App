#include "pch.h"
#include <SFML/Graphics.hpp>
#include <random>

extern "C"
{
    __declspec(dllexport) void RunApp(HWND& handle)
    {
        sf::RenderWindow renderWindow;
        renderWindow.create(handle);

        sf::CircleShape shape(50.f);
        shape.setFillColor(sf::Color::Green);

        while (renderWindow.isOpen())
        {
            sf::Event event;
            // Treat the handle being set to null as an event
            if (renderWindow.pollEvent(event) || handle == NULL)
            {
                // Simulate close event
                if (event.type == sf::Event::Closed || handle == NULL)
                {
                    renderWindow.close();
                    return; // isOpen() still returns true so terminate here
                }
            }

            sf::Vector2f currPosition = shape.getPosition();
            sf::Vector2u winSize = renderWindow.getSize();

            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist10(1, 10);
            std::uniform_int_distribution<std::mt19937::result_type> dist20(1, 20);

            sf::Vector2f newPosition;
            if (dist10(rng) % 2)
            {
                newPosition = sf::Vector2f((int)(currPosition.x + dist20(rng)) % winSize.x, (int)(currPosition.y + dist20(rng)) % winSize.y);
            }
            else
            {
                newPosition = sf::Vector2f((int)(currPosition.x + dist20(rng)) % winSize.x, currPosition.y);
            }

            shape.setPosition(sf::Vector2f(newPosition.x, newPosition.y));

            renderWindow.clear();
            renderWindow.draw(shape);
            renderWindow.display();
        }

        return;
    }
}