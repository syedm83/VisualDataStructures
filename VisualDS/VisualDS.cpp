#include <SFML/Graphics.hpp>
#include "VisualStack.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Modern Stack Visualizer", sf::Style::Titlebar | sf::Style::Close);
    sf::Event ev;

    VisualStack visualStack(300.f, 400.f, 80.f, 15.f, 5.f); 

    for (int i = 1; i <= 6; ++i) {
        visualStack.push(i * 10);
    }

    while (window.isOpen()) {
        while (window.pollEvent(ev)) {
            switch (ev.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::P) {
                    static int nextValue = 70;
                    if (!visualStack.isAnimationActive()) {
                        visualStack.startPushAnimation(nextValue);
                        nextValue += 10;
                    }
                }
                else if (ev.key.code == sf::Keyboard::O) {
                    if (!visualStack.isAnimationActive() && !visualStack.isEmpty()) {
                        visualStack.startPopAnimation();
                    }
                }
                break;
            }
        }

        visualStack.updateAnimation();

        window.clear(sf::Color(245, 245, 245)); 
        visualStack.render(window);
        window.display();
    }

    return 0;
}
