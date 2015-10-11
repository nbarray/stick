#pragma once

#include <ostream>

namespace stick
{
  struct Printable
  {
    virtual std::string print() const = 0;
  };

  std::ostream& operator<<(std::ostream& out, Printable const& object);
}
