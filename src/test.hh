#pragma once

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#define STICK_TEST_SUITE                                                      \
\
static std::string test_binary;\
static void _test_suite();\
bool init_unit_test_suite()\
{\
  try\
  {\
    _test_suite();\
  }\
  catch (...)\
  {\
    throw boost::unit_test::framework::setup_error("Stick error");\
  }\
  return true;\
}\
int main(int ac, char** av)\
{\
  test_binary = av[0];\
  return ::boost::unit_test::unit_test_main(\
    &init_unit_test_suite, ac, av);\
}\
static void _test_suite\

