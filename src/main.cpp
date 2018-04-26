#include "SFML/Graphics.hpp"

#include "math/Bezier.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "hello world");

    std::vector<sf::Vector2f> vectors = {
        sf::Vector2f{100.f, 100.f},
        sf::Vector2f{600.f, 300.f},
        sf::Vector2f{550.f, 500.f},
        sf::Vector2f{200.f, 550.f}
    };

    size_t numVertices = 50;
    sf::VertexArray lines;
    sf::VertexArray bezierCurve;

    lines.setPrimitiveType(sf::PrimitiveType::LinesStrip);
    bezierCurve.setPrimitiveType(sf::PrimitiveType::LinesStrip);

    for (size_t i = 0; i < numVertices; i++) {
        const float t = static_cast<float>(i) / static_cast<float>(numVertices);
        sf::Vector2f v = math::deCasteljau<sf::Vector2f>(vectors, t);
        bezierCurve.append(sf::Vertex{v});
    }

    for (auto& v : vectors) {
        lines.append(sf::Vertex{v});
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(lines);
        window.draw(bezierCurve);
        window.display();
    }

    return 0;
}