#include "primitives/BezierCurve.hpp"

namespace primitives {
    BezierCurve::BezierCurve()
    : m_needsUpdate(false) {
        m_vertices.setPrimitiveType(sf::PrimitiveType::LinesStrip);
    }

    BezierCurve::BezierCurve(const std::vector<sf::Vector2f>& points, const unsigned resolution)
    : m_needsUpdate(true), m_resolution(resolution), m_controlPoints(points) {
        m_vertices.setPrimitiveType(sf::PrimitiveType::LinesStrip);
        m_vertices.resize(m_resolution + 1);
        m_controlPoints = points;
        m_controlPointLineStrip = new LineStrip(points);
        m_controlPointLineStrip->setLineColor(sf::Color(128, 128, 128));
        update();
    }

    void BezierCurve::update() {
        if (m_needsUpdate) {
            constructCurve();
            m_needsUpdate = false;
        }
    }

    void BezierCurve::setControlPoint(const size_t index, const sf::Vector2f point) {
        if (index > m_controlPoints.size()) {
            return;
        } else {
            m_controlPoints[index] = point;
            constructCurve();
        }
    }

    std::vector<sf::Vector2f>& BezierCurve::getControlPoints() {
        return m_controlPoints;
    }

    void BezierCurve::constructCurve() {
        for (size_t i = 0; i <= m_resolution; i++) {
            const float t = static_cast<float>(i) / static_cast<float>(m_resolution);
            m_vertices[i] = sf::Vertex(
                math::bezier<sf::Vector2f>(m_controlPoints, t),
                sf::Color::White
            );
        }
    }

    void BezierCurve::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(*m_controlPointLineStrip, states);
        target.draw(m_vertices, states);
    }
} // namespace primitives