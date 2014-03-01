/*
 * Author: Bucky Frost
 * File: numerals.cpp
 * Purpose: Implementation file for numbers to roman numerals kata.
 * 	    For CS 372 Homework 3.
 */
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <string>

std::string printNumeral(int number);

std::string printNumeral(int number)
{
	std::string numeralString = "";

	for (auto ii = 0; ii < number; ++ii) {
		numeralString += "I";
	}
	
	return numeralString;
}

TEST_CASE("Numeral Test") {
	REQUIRE( printNumeral(0) == "" );
	REQUIRE( printNumeral(1) == "I" );
	REQUIRE( printNumeral(2) == "II" );
	REQUIRE( printNumeral(3) == "III" );
	REQUIRE( printNumeral(5) == "V" );
}
