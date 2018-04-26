#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

namespace primitives {
    class LineStrip 
    : public sf::Drawable,
      public sf::Transformable {
    public:
        LineStrip();
        LineStrip(const std::vector<sf::Vector2f>& points);

        void setLineColor(const sf::Color& color);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::VertexArray vertices;
    }; // class LineStrip
} // namespace primitives