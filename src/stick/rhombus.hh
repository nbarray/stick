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

      Rhombus(Rhombus const&) = delete;
      Rhombus(Rhombus&&) = delete;
      Rhombus operator=(Rhombus const&) = delete;

      bool contains(sf::Vector2f point);
    private:
      float width_;
  };
}
