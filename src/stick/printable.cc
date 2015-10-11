#include <stick/printable.hh>

namespace stick
{
  std::ostream& operator<<(std::ostream& out, Printable const& object)
  {
    return out << object.print();
  }
}
