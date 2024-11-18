#include "VisualStack.h"
#include <cstdlib>  
#include <ctime>    

VisualStack::VisualStack(float baseX, float baseY, float width, float height, float spacing)
    : baseX(baseX), baseY(baseY), width(width), height(height), spacing(spacing),
    isPushing(false), isPopping(false), animatingSpeed(5.f), targetY(0.f), fadeSpeed(5) {

    srand(static_cast<unsigned int>(time(0)));
}

sf::Color VisualStack::getRandomColor() {
    int r = rand() % 256;  
    int g = rand() % 256;
    int b = rand() % 256;

    return sf::Color(r, g, b);
}

void VisualStack::push(int value) {
    stack.push(value);

    sf::RectangleShape bar(sf::Vector2f(width, height));

    bar.setFillColor(getRandomColor());  
    bar.setOutlineThickness(1.f);
    bar.setOutlineColor(sf::Color(100, 149, 237));

    float posY = baseY - (bars.size() * (height + spacing));
    bar.setPosition(baseX, posY);

    bars.push_back(bar);
}

void VisualStack::startPushAnimation(int value) {
    if (!isPushing && !isPopping) {
        stack.push(value);

        animatingBar = sf::RectangleShape(sf::Vector2f(width, height));
        animatingBar.setFillColor(getRandomColor());  
        animatingBar.setOutlineThickness(1.f);
        animatingBar.setOutlineColor(sf::Color(100, 149, 237));

        animatingBar.setPosition(baseX, baseY + 50.f); 
        targetY = baseY - (bars.size() * (height + spacing)); 
        isPushing = true;
    }
}

void VisualStack::startPopAnimation() {
    if (!stack.empty() && !isPopping && !isPushing) {
        stack.pop();
        isPopping = true;

        animatingBar = bars.back(); 
        bars.pop_back();
        animatingBar.setFillColor(sf::Color(animatingBar.getFillColor().r, animatingBar.getFillColor().g, animatingBar.getFillColor().b, 255)); 
}

void VisualStack::updateAnimation() {
    if (isPushing) {
        animatingBar.move(0.f, -animatingSpeed);

        sf::Color color = animatingBar.getFillColor();
        if (color.a < 255) { 
            animatingBar.setFillColor(sf::Color(color.r, color.g, color.b, std::min(color.a + fadeSpeed, 255)));
        }

        if (animatingBar.getPosition().y <= targetY) {
            isPushing = false;
            bars.push_back(animatingBar); 
        }
    }
    else if (isPopping) {
        animatingBar.move(0.f, animatingSpeed);

        sf::Color color = animatingBar.getFillColor();
        if (color.a > 0) { 
            animatingBar.setFillColor(sf::Color(color.r, color.g, color.b, std::max(color.a - fadeSpeed, 0)));
        }

        if (animatingBar.getPosition().y > baseY + 50.f || color.a == 0) {
            isPopping = false;
        }
    }
}

void VisualStack::render(sf::RenderWindow& window) {
    for (auto& bar : bars) {
        window.draw(bar);
    }

    if (isPushing || isPopping) {
        window.draw(animatingBar);
    }
}

bool VisualStack::isEmpty() const {
    return stack.empty();
}

bool VisualStack::isAnimationActive() const {
    return isPushing || isPopping;
}
