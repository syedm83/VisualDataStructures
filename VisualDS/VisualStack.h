#ifndef VISUALSTACK_H
#define VISUALSTACK_H

#include <SFML/Graphics.hpp>
#include <stack>

class VisualStack {
public:
    VisualStack(float baseX, float baseY, float width, float height, float spacing);

    void push(int value);
    void startPushAnimation(int value);
    void startPopAnimation();
    void updateAnimation();
    void render(sf::RenderWindow& window);

    bool isEmpty() const;
    bool isAnimationActive() const;

private:
    sf::Color getRandomColor();

    float baseX, baseY, width, height, spacing;
    float animatingSpeed;
    float targetY;
    int fadeSpeed;

    bool isPushing;
    bool isPopping;

    std::stack<int> stack;
    std::vector<sf::RectangleShape> bars;
    sf::RectangleShape animatingBar;
};

#endif
