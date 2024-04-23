// Copyright 2015 fredm@cs.uml.edu for 91.204 Computing IV
// Wed Mar 25 06:32:17 2015

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "RingBuffer.hpp"

BOOST_AUTO_TEST_CASE(CustomForPointsPleaseDontTakeOffThanks) {
    // normal constructor, no exception
    BOOST_REQUIRE_NO_THROW(RingBuffer(20));

    // invalid arguement on bad constructor
    BOOST_REQUIRE_THROW(RingBuffer(0), std::invalid_argument);

    // no exceptions on normal RB
    RingBuffer rb(5);
    rb.enqueue(5);
    rb.enqueue(4);
    rb.enqueue(3);
    rb.enqueue(2);
    rb.enqueue(1);
    rb.dequeue();
    rb.enqueue(5);
    // should throw exception for tring to fill greater than capacity
    BOOST_REQUIRE_THROW(rb.enqueue(0), std::runtime_error);
    rb.dequeue();
    rb.dequeue();
    rb.dequeue();
    rb.dequeue();
    rb.dequeue();
    // should throw for trying to dequeue or peek on empty RB
    BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);
    BOOST_REQUIRE_THROW(rb.peek(), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(RBcontructor) {
    // normal constructor
    BOOST_REQUIRE_NO_THROW(RingBuffer(100));

    // this should fail
    BOOST_REQUIRE_THROW(RingBuffer(0), std::exception);
    BOOST_REQUIRE_THROW(RingBuffer(0), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(RBenque_dequeue) {
    RingBuffer rb(100);

    rb.enqueue(2);
    rb.enqueue(1);
    rb.enqueue(0);

    BOOST_REQUIRE(rb.dequeue() == 2);
    BOOST_REQUIRE(rb.dequeue() == 1);
    BOOST_REQUIRE(rb.dequeue() == 0);

    BOOST_REQUIRE_THROW(rb.dequeue(), std::runtime_error);
}