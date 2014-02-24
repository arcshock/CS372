/*
 * Author: Bucky Frost
 * File: main.cpp
 * Purpose: Main function for managing the neural network.
 * CS 405 Intro to A.I.
 */
#include "neuralnet.h"
#include <iostream>
#include <array>
#include <chrono>
#include <string>


std::string timingManager(NeuralNet<4> & neuralNet, int iterations);
double timingFunc(int iterations, NeuralNet<4> & neuralNet); // used for timing board evals
double timeavg(std::vector<double>::iterator begin, std::vector<double>::iterator end, int samples);
void messaging(std::string message);

int main()
{
	std::array<int, 4> hidden_layers = {{ 32, 40, 10, 1 }};

	NeuralNet < hidden_layers.size() > test1 (hidden_layers);
	test1.loadInput();
	test1.setWeights();
	test1.forwardFeed();

	messaging("Timing");
	std::cout << timingManager(test1, 50) << "\n" << std::endl; 

	messaging("Printing Network Weights");
	test1.printNetworkWeights();

	messaging("Mutating Network Weights");
	test1.mutateNetwork();
	test1.printNetworkWeights();

	return 0;
}

// Precondition:
// Message is a string value to inform the user.
// 
// Post Condition:
// Prints the messege between stings of '#' characters.
void messaging(std::string message)
{
	for (int i = 0; i < 120; ++i) {
		std::cout << "#";
		if ( i == 60 )
			std::cout << std::endl << message << std::endl;
	}
	std::cout << std::endl;
}

// Precondition:
// iterations are the number of times to call the feedforward function from class NeuralNet
//
// Post Conditions:
// Returns a string with relevent timing of the feedForward function.
std::string timingManager(NeuralNet<4> & neuralNet, int iterations)
{
	std::vector<double> times;

	for (int i = 0; i < iterations; ++i) {
		times.push_back(timingFunc(iterations, neuralNet));
	}

	// Report string construction.
	auto timeMessage = "Completed " + std::to_string(iterations) + " iterations of feed forward function in " + 
	std::to_string(timeavg(times.begin(), times.end(), times.size())) + " ms.";
	return timeMessage;
}

// Precondition:
// iterations are the number of times to call the feedforward function from class NeuralNet
// 
// Post Condition:
// Returns the total time to execute the number of iterations of the feedforward function in ms.
double timingFunc(int iterations, NeuralNet<4> & neuralNet)
{
	auto startTime = std::chrono::system_clock::now();

	for (auto i = 0; i < iterations; ++i)
		neuralNet.forwardFeed();

	auto endTime = std::chrono::system_clock::now();
	auto elapsedTime = endTime - startTime;

	return std::chrono::duration <double, std::milli> (elapsedTime).count();
}

// Precondition: 
// The begin and end iterators are for a vector that contain times for a feedforward call.
// Samples are the number of iterations for that time. <- Need to rething this.
//
// Post Condition:
// Return the average to the times.
double timeavg(std::vector<double>::iterator begin, std::vector<double>::iterator end, int samples)
{
	auto runningTotal = 0.0;

	for (auto iter = begin; begin != end; ++begin) {
		runningTotal += *iter;
	}

	auto average = runningTotal/samples;
	
	return average;
}
