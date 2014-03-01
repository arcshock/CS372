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

	while (number > 0) {
		if (number == 10) {
			numeralString += "X";
			number -= 10;
		} else if (number == 5) {
			numeralString += "V";
			number -= 5;
		} else {
			numeralString += "I";
			--number;
		}
	}
	
	return numeralString;
}

TEST_CASE("Numeral Test") {
	REQUIRE( printNumeral(0) == "" );
	REQUIRE( printNumeral(1) == "I" );
	REQUIRE( printNumeral(2) == "II" );
	REQUIRE( printNumeral(3) == "III" );
	REQUIRE( printNumeral(5) == "V" );
	REQUIRE( printNumeral(10) == "X" );
}
