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
	{50, "L"},	
	{10, "X"},	
	{5, "V"},	
	{1, "I"}
};

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
	REQUIRE( printNumeral(10) == "X" );
	REQUIRE( printNumeral(50) == "L" );
	REQUIRE( printNumeral(100) == "C" );
}
