// Copyright [2018] <Scott Gordon>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>
#include "LFSR.h"
BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {
    LFSR l("00111", 2);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);

    LFSR l2("00111", 2);
    BOOST_REQUIRE(l2.generate(8) == 198);

    // test case for a very small string
    LFSR l3("100", 1);
    BOOST_REQUIRE(l3.step() == 1);
    BOOST_REQUIRE(l3.step() == 0);
    BOOST_REQUIRE(l3.step() == 1);
    BOOST_REQUIRE(l3.step() == 1);
    BOOST_REQUIRE(l3.step() == 1);
    BOOST_REQUIRE(l3.step() == 0);

    // test case for a very long string
    LFSR l4("111001010010100101010100110010010", 10);
    BOOST_REQUIRE(l4.step() == 1);
    BOOST_REQUIRE(l4.step() == 1);
}

BOOST_AUTO_TEST_CASE(idkWhatToNameThis) {
    LFSR l("10101011011111111111000001100110101", 3);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 1);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);
    BOOST_REQUIRE(l.step() == 0);

    LFSR l2("101", 1);
    BOOST_REQUIRE(l2.step() == 1);
    BOOST_REQUIRE(l2.step() == 1);
    BOOST_REQUIRE(l2.step() == 0);
    BOOST_REQUIRE(l2.step() == 0);
    BOOST_REQUIRE(l2.step() == 1);
    BOOST_REQUIRE(l2.step() == 0);
}