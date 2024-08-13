// Copyright 2023 Jessica Vu

#include <iostream>
#include <string>

#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"
using PhotoMagic::FibLFSR;

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

// Instructor's Tests

BOOST_AUTO_TEST_CASE(testStepInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testGenerateInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.generate(9), 51);
}

// My 4 Tests for FibLFSR

BOOST_AUTO_TEST_CASE(testStep) {
  FibLFSR str("0000000010110110");
  BOOST_REQUIRE_EQUAL(str.step(), 0);
  BOOST_REQUIRE_EQUAL(str.step(), 0);
  BOOST_REQUIRE_EQUAL(str.step(), 0);
  BOOST_REQUIRE_EQUAL(str.step(), 1);
}

BOOST_AUTO_TEST_CASE(testGenerate1) {
  FibLFSR str("0000000000000001");
  BOOST_REQUIRE_EQUAL(str.generate(16), 45);
}

BOOST_AUTO_TEST_CASE(testGenerate2) {
  FibLFSR str("1111111111111111");
  BOOST_REQUIRE_EQUAL(str.generate(15), 13);
}

BOOST_AUTO_TEST_CASE(testOstream) {
  FibLFSR str("0000000010110110");
  std::string expected = "0000000010110110";
  std::stringstream ostream;
  ostream << str;
  BOOST_REQUIRE_EQUAL(ostream.str(), expected);
}

// My other test for PhotoMagic
BOOST_AUTO_TEST_CASE(testEncrypt) {
  FibLFSR str("1011011000110110");
  FibLFSR* seed = &str;
  sf::Image image;
  image.loadFromFile("input-file.png");
  transform(image, seed);

  sf::Image expected_img;
  expected_img.loadFromFile("output-file.png");
  sf::Color p1;
  sf::Color p2;

  sf::Vector2u img_size = image.getSize();

  for (unsigned int x = 0; x < img_size.x; x++) {
    for (unsigned int y = 0; y < img_size.y; y++) {
      p1 = image.getPixel(x, y);
      p2 = expected_img.getPixel(x, y);
      BOOST_CHECK_EQUAL(p1.r, p2.r);
      BOOST_CHECK_EQUAL(p1.g, p2.g);
      BOOST_CHECK_EQUAL(p1.b, p2.b);
    }
  }
}
