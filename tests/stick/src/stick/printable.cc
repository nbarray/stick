#include <test.hh>
#include <stick/printable.hh>

#include <sstream>

namespace stick
{
  namespace test
  {
    namespace printable
    {

      struct A
        : public Printable
      {
        virtual std::string print() const
        {
          return "foo";
        }
      };

      void simple()
      {
        A foo;

        std::ostringstream out;
        out << foo;
        BOOST_CHECK(out.str() == "foo");
      }
    }
  }
}

STICK_TEST_SUITE()
{
  boost::unit_test::test_suite* printable = BOOST_TEST_SUITE("printable");
	boost::unit_test::framework::master_test_suite().add(printable);

	printable->add(BOOST_TEST_CASE(stick::test::printable::simple));
}
