#include <stick/rhombus.hh>

#include <iostream>

namespace stick
{

  Rhombus::Rhombus(float x, float y, float width)
    : sf::ConvexShape(4)
    , rect_{x, y, width, width / 2}
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
  }

  Rhombus::Rhombus(sf::Vector2f origin, float width)
    : Rhombus(origin.x, origin.y, width)
  {}

  bool
  Rhombus::contains(sf::Vector2f point) const
  {
    /*
     *  1
     *  | #
     *  +----2
     */
    float x = rect_.left;
    float y = rect_.top;
    float dx = std::abs(point.x - x - rect_.width / 2);
    float dy = std::abs(point.y - y - rect_.height / 2);

    auto f = [&] (float x) { return -x / 2 + rect_.height / 2; };
    return (dx < rect_.width / 2) && (dy < f(dx));
  }
}
