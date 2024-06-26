#include <iostream>
#include "SFML/Graphics.hpp"
#include "GameController.h"

int main() {
    sf::Clock deltaClock;
    sf::Time dt = deltaClock.getElapsedTime();

    sf::RenderWindow window(sf::VideoMode(1600, 900), "My window");

    sf::View view(sf::FloatRect(0, 0, 1600.f, 900.f)); // 800*800
    window.setView(view);

    auto gameController = GameController::getInstance();
    gameController->setCamera(view);
    gameController->setWindow(window);
    gameController->start();

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        gameController->runUpdatableSystems(dt);
        gameController->runDrawableSystems(window);

        // end the current frame
        window.display();
        dt = deltaClock.restart();
    }
}
