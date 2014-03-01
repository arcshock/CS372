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

std::string intToNumeral(int number);

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

/* == Function intToNumeral ================================
 *
 * Precondition: number >= 0
 *
 * Post Condition: Return a string containing Roman Numerals
 * 	representing the value of number.
 *
 * ======================================================== */
std::string intToNumeral(int number)
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
	REQUIRE( intToNumeral(0) == "" );
	REQUIRE( intToNumeral(1) == "I" );
	REQUIRE( intToNumeral(2) == "II" );
	REQUIRE( intToNumeral(3) == "III" );
	REQUIRE( intToNumeral(4) == "IV" );
	REQUIRE( intToNumeral(5) == "V" );
	REQUIRE( intToNumeral(7) == "VII" );
	REQUIRE( intToNumeral(9) == "IX" );
	REQUIRE( intToNumeral(10) == "X" );
	REQUIRE( intToNumeral(50) == "L" );
	REQUIRE( intToNumeral(99) == "XCIX" );
	REQUIRE( intToNumeral(100) == "C" );
}
