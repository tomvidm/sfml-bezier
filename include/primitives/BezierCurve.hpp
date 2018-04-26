#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "math/Bezier.hpp"
#include "primitives/LineStrip.hpp"

namespace primitives {
    class BezierCurve 
    : public sf::Drawable,
      public sf::Transformable {
    public:
        BezierCurve();
        BezierCurve(const std::vector<sf::Vector2f>& points, const unsigned resolution);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void update();

        void setControlPoint(const size_t index, const sf::Vector2f point);

        std::vector<sf::Vector2f>& getControlPoints();
    private:
        void constructCurve();
    private:
        bool                        m_needsUpdate;
        unsigned                    m_resolution;
        std::vector<sf::Vector2f>   m_controlPoints;
        sf::VertexArray             m_vertices;
        LineStrip*                  m_controlPointLineStrip;

    }; // class BezierCurve
} // namespace primitives