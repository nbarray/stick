#include <test.hh>
#include <stick/rhombus.hh>

namespace stick
{
  namespace test
  {
    namespace rhombus
    {
      void contains()
      {
        stick::Rhombus r{0, 0};
        BOOST_CHECK(r.contains(sf::Vector2f(0, 0)) == false);
        BOOST_CHECK(r.contains(sf::Vector2f(128, 0)) == false);
        BOOST_CHECK(r.contains(sf::Vector2f(0, 64)) == false);
        BOOST_CHECK(r.contains(sf::Vector2f(128, 64)) == false);

        BOOST_CHECK(r.contains(sf::Vector2f(64, 32)) == true);
      }
    }
  }
}

STICK_TEST_SUITE()
{
	boost::unit_test::test_suite* rhombus = BOOST_TEST_SUITE("rhombus");
	boost::unit_test::framework::master_test_suite().add(rhombus);
	rhombus->add(BOOST_TEST_CASE(stick::test::rhombus::contains));
}
