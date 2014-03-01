/*
 * Author: Bucky Frost
 * File: numerals.cpp
 * Purpose: Implementation file for numbers to roman numerals kata.
 * 	    For CS 372 Homework 3.
 */
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <string>
#include <map>
#include <functional>

std::string printNumeral(int number);

std::map<int, std::string, std::greater<int> > intToNumeralsMapping {
	{100, "C"},	
	{99, "XCIX"},
	{50, "L"},	
	{10, "X"},	
	{9, "IX"},
	{7, "VII"},	
	{5, "V"},	
	{4, "IV"},
	{1, "I"}
};

/* == Function printNumeral ================================
 *
 * Precondition: number >= 0
 *
 * Post Condition: Return a string containing Roman Numerals
 * 	representing the value of number.
 *
 * ======================================================== */
std::string printNumeral(int number)
{
	std::string numeralString = "";

	for (auto kv : intToNumeralsMapping) {
		while (number >= kv.first) {
			number -= kv.first;
			numeralString += kv.second;
		}
	}

	return numeralString;
}

TEST_CASE("Numeral Test") {
	REQUIRE( printNumeral(0) == "" );
	REQUIRE( printNumeral(1) == "I" );
	REQUIRE( printNumeral(2) == "II" );
	REQUIRE( printNumeral(3) == "III" );
	REQUIRE( printNumeral(4) == "IV" );
	REQUIRE( printNumeral(5) == "V" );
	REQUIRE( printNumeral(7) == "VII" );
	REQUIRE( printNumeral(9) == "IX" );
	REQUIRE( printNumeral(10) == "X" );
	REQUIRE( printNumeral(50) == "L" );
	REQUIRE( printNumeral(99) == "XCIX" );
	REQUIRE( printNumeral(100) == "C" );
}
