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
	if (number == 1)
		return "I";
	else if (number == 2)
		return "II";

	return "";
}

TEST_CASE("Numeral Test") {
	REQUIRE( printNumeral(0) == "" );
	REQUIRE( printNumeral(1) == "I" );
	REQUIRE( printNumeral(2) == "II" );
}
