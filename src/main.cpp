#include "SFML/Graphics.hpp"

#include "primitives/BezierCurve.hpp"
#include "math/Bezier.hpp"
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "hello world");

    std::vector<sf::Vector2f> vectors = {
        sf::Vector2f{-100.f, 100.f},
        sf::Vector2f{200.f, 200.f},
        sf::Vector2f{250.f, -200.f},
        sf::Vector2f{-200.f, -150.f}
    };

    auto w = math::bezier<sf::Vector2f>(vectors, 0.5f);
    primitives::BezierCurve bcurve(vectors, 40);
    bcurve.setPosition(sf::Vector2f(300.f, 300.f));
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(bcurve);
        window.display();
    }

    return 0;
}