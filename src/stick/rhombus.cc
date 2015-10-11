#include <stick/rhombus.hh>

#include <iostream>

namespace stick
{

  Rhombus::Rhombus(float x, float y, float width)
    : sf::ConvexShape(4)
    , width_(width)
  {
    /*         1
     *       # | #
     *    0----+----2
     *       # | #
     *         3
     */  
    setPoint(0, sf::Vector2f(x, y + width / 4));
    setPoint(1, sf::Vector2f(x + width / 2, y));
    setPoint(2, sf::Vector2f(x + width, y + width / 4));
    setPoint(3, sf::Vector2f(x + width / 2, y + width / 2));

    setPosition(x, y);
  }

  Rhombus::Rhombus(sf::Vector2f origin, float width)
    : Rhombus(origin.x, origin.y, width)
  {}

  bool
  Rhombus::contains(sf::Vector2f point)
  {
    /*
     *  1
     *  | #
     *  +----2
     */
    float x = getPosition().x;
    float y = getPosition().y;
    float dx = std::abs(point.x - x - width_ / 2);
    float dy = std::abs(point.y - y - width_ / 4);

    std::cerr << "x: " << x << ", y: " << y << std::endl;
    auto f = [&] (float x) { return -x / 2 + width_ / 4; };
    return (dx < width_ / 2) && (dy < f(dx));
  }
}
