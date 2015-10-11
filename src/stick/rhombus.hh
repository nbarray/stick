#pragma once

#include <SFML/Graphics.hpp>

namespace stick
{
  /*
   *  FIXME: Do an AbstractRhombus class, not dependent from sfml yet usable.
   */
  class Rhombus
    : public sf::ConvexShape
  {
    public:
      Rhombus(float x, float y, float width = 128);
      Rhombus(sf::Vector2f origin, float width = 128);

      bool contains(sf::Vector2f point) const;
      sf::FloatRect const& get_rect() const { return rect_; }
    private:

      sf::FloatRect rect_;
  };
}
