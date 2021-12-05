#ifndef RADIAL_GRADIENT_CIRCLESHAPE_HPP
#define RADIAL_GRADIENT_CIRCLESHAPE_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

namespace
{
    const float pi = 3.141592653;
}

class RadialGradientCircleShape : public sf::Shape
{
private:
    sf::Color m_gradientColorA;
    sf::Color m_gradientColorB;
    float m_radius;
    std::size_t m_pointCount;
    sf::VertexArray m_vertices;

public:

    explicit RadialGradientCircleShape(float radius, std::size_t pointCount = 30) : 
    m_gradientColorA(0xFF, 0xFF, 0xFF),
    m_gradientColorB(0xFF, 0xFF, 0xFF),
    m_radius(radius),
    m_pointCount(pointCount),
    m_vertices(sf::TriangleFan)
    {
        update();
    }

    void setGradientColorA(const sf::Color& colorA)
    {   
        m_gradientColorA = colorA;
        setFillColor(colorA);
        update();
    }

    void setGradientColorB(const sf::Color& colorB)
    {
        m_gradientColorB = colorB;
        update();
    }

    void setRadius(float radius)
    {
        m_radius = radius;
        update();
    }

    float getRadius(float radius)
    {
        return m_radius;
    }
    
    void setPointCount(std::size_t pointCount)
    {
        m_pointCount = pointCount;
        update();
    }


    const sf::Color& getGradientColorA()
    {
        return m_gradientColorA;
    }

    const sf::Color& getGradientColorB()
    {
        return m_gradientColorB;
    }

    virtual std::size_t getPointCount() const
    {
        return m_pointCount;
    }

    virtual sf::Vector2f getPoint(std::size_t index) const
    {
        static const float pi = std::acos(-1);

        float angle = static_cast<float>(index) * 2.f * pi / static_cast<float>(m_pointCount) - pi / 2.f;
        float x = std::cos(angle) * m_radius;
        float y = std::sin(angle) * m_radius;

        return sf::Vector2f(m_radius + x, m_radius + y);
    }

    virtual void updateFillColors()
    {

        for (std::size_t i = 1; i < m_vertices.getVertexCount(); ++i)
            m_vertices[i].color = m_gradientColorA;
    }
};


#endif // RADIAL_GRADIENT_CIRCLESHAPE_HPP