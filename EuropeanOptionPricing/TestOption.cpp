// Test.cpp
//
// This is a source file for Testing BS option pricing models

#include <iostream>
#include "EuropeanOption.h"
#include "OptionElements.h"

int main()
{
	// Commented out for Testing different Batches
	// using namespace Batch1;		// C = 2.13337, P = 5.84628
	// using namespace Batch2;		// C = 7.96557, P = 7.96557
	// using namespace Batch3;		// C = 0.204058, P = 4.07326
	using namespace Batch4;			// C = 92.17570, P = 1.24750

	// Set type parameters
	char type1 = 'C';			// Call option
	char type2 = 'P';			// Put option

	EuropeanOption EuropeanCall(K, T, r, sig, type1);
	EuropeanOption EuropeanPut(K, T, r, sig, type2);

	// Print the result
	std::cout << "Call option price: " << EuropeanCall.Price(S)
		<< " Put option price: " << EuropeanPut.Price(S) << '\n' << '\n';

	// Put-Call Parity Testing
	std::cout << "Call-Parity(Put): " << ParityPrice(S, EuropeanCall)
		<< ", Put-Parity(Call): " << ParityPrice(S, EuropeanPut) << '\n';

	return 0;
}