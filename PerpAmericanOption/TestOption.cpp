// Test.cpp
//
// This program illustrates the Perpetual American Options.
// An American option is a contract that can be execised at any time prior to T.
//

#include "PerpAmericanOption.h"
#include <iostream>
#include <vector>

// Global Function Declaration
std::vector<double> Vec(const double& start, const double& h, const int& size);

int main()
{
	// Data set
	double K = 100;
	double sig = 0.1;
	double r = 0.1;
	double b = 0.02;
	double S = 110;
	char type1 = 'C'; char type2 = 'P';

	// Create objects
	PerpAmericanOption AmericanCall(b, K, r, sig, type1);
	PerpAmericanOption AmericanPut(b, K, r, sig, type2);

	std::cout << "Call Price: " << AmericanCall.Price(S) <<
		" Put Price: " << AmericanPut.Price(S) << '\n' << '\n';

	// Containers
	std::vector<double> stock = Vec(1, 1, 50);

	// Get parameters
	std::cout << "Please Enter the parameters:\n";
	std::cout << "K: "; std::cin >> K;
	std::cout << "sig: "; std::cin >> sig;
	std::cout << "r: "; std::cin >> r;
	std::cout << "b: "; std::cin >> b;

	// Print the results
	std::vector<double> output1;
	output1.reserve(50);
	std::vector<double> output2;
	output2.reserve(50);

	for (int i = 0; i < 50; i++)
	{
		output1.push_back(AmericanCall.Price(stock[i]));
		output2.push_back(AmericanPut.Price(stock[i]));

		std::cout << "Stock price: " << stock[i] << " Call price: "
			<< output1[i] << " Put price: " << output2[i] << '\n';
	}
	std::cout << '\n';

	return 0;
}

// Global Function Definition
std::vector<double> Vec(const double& start, const double& h, const int& size)
{
	std::vector<double> v;
	v.reserve(size);
	for (int i = 0; i < size; ++i)
	{
		v.push_back(start + h * i);
	}

	return v;
}
