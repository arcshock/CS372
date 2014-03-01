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
	return "";
}

TEST_CASE("Numeral Test") {
	REQUIRE( printNumeral(0) == "" );
}
