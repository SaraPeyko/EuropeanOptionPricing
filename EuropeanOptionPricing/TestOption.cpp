// Test.cpp
//
// This is a source file for Testing BS option pricing models

#include <iostream>
#include "EuropeanOption.h"
#include "OptionElements.h"

int main()
{
	// Testing different Batches
	using namespace Batch1;		// C = 2.13337, P = 5.84628

	// Set type parameters
	char type1 = 'C';			// Call option
	char type2 = 'P';			// Put option

	EuropeanOption EuropeanCall(K, T, r, sig, type1);
	EuropeanOption EuropeanPut(K, T, r, sig, type2);

	// Print the result
	std::cout << "Call option price: " << EuropeanCall.Price(S)
		<< " Put option price: " << EuropeanPut.Price(S) << '\n';

	return 0;
}