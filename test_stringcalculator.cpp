#include "stringcalculator.h"
#include "catch_amalgamated.hpp"

TEST_CASE("Integer checker works", "[isInteger]") {
    REQUIRE(isInteger("3.14159") == false); //base
    REQUIRE(isInteger("0") == true); //edge
    REQUIRE_THROWS_AS(isInteger("three.five"), std::invalid_argument); //error case
}

TEST_CASE("Sign checker works", "[isPositive]") {
    REQUIRE(isPositive("-5") == false); //base
    REQUIRE(isPositive("0") == false); //edge (0 is first non positive value, in descending order)
    REQUIRE_THROWS_AS(isPositive("zero"), std::invalid_argument); //error case
}

TEST_CASE("Modulus works", "[modulus]") {
    REQUIRE(modulus("10", "3") == 1); //base
    REQUIRE(modulus("10", "2") == 0); //edge
    REQUIRE_THROWS_AS(modulus("3", "0"), std::invalid_argument); //error case (cannot divide(or mod) by 0)
}

TEST_CASE("Exponent function works", "[power]") {
    REQUIRE(power("2", "2") == 4); //base
    REQUIRE(power("10", "-2") == 0.1); //edge (negative exponent)
    REQUIRE_THROWS_AS(power("ten", "one"), std::invalid_argument); //error case
}

TEST_CASE("SquareRoot works", "[squareRoot]") {
    REQUIRE(squareRoot("100") == 10); //base
    REQUIRE(squareRoot("0") == 0); //edge (cannot take sqrt of less than 0)
    REQUIRE_THROWS_AS(squareRoot("-100"), std::invalid_argument); //error (sqrt of negative)
}

TEST_CASE("Squaring works", "[square]") {
    REQUIRE(square("2") == 4); //base
    REQUIRE(square("-10") == 100); //edge
    REQUIRE_THROWS_AS(square("abcd"), std::invalid_argument); //error case
}

TEST_CASE("Division works", "[divide]") {
    REQUIRE(divide("200", "20") == 10); //base
    REQUIRE(divide("1000", "-100") == -10); //edge
    REQUIRE_THROWS_AS(divide("999", "0"), std::invalid_argument); //error case (divide by 0)
}

TEST_CASE("Multiplication works", "[multiply]") {
    REQUIRE(multiply("10", "9") == 90); //base
    REQUIRE(multiply("-20", "222") == -4440); //edge (multiplying by a negative)
    REQUIRE_THROWS_AS(multiply("one", "one"), std::invalid_argument); //error case
}

TEST_CASE("Subtraction works", "[subtract]") {
    REQUIRE(subtract("100", "40") == 60); //base
    REQUIRE(subtract("100", "-20") == 120); //edge (subtracting a negative)
    REQUIRE_THROWS_AS(subtract("ten", "two"), std::invalid_argument); //error case
}

TEST_CASE("Addition works", "[add]") {
    REQUIRE(add("6", "7") == 13); //base
    REQUIRE(add("-6", "7") == 1); //edge (negative)
    REQUIRE_THROWS_AS(add("abc", "def"), std::invalid_argument); //error case (non numerical)
}
