// Test.cpp
//
// This is a source file for Testing BS option pricing models

#include <iostream>
#include <boost/math/distributions.hpp>
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

	// Using Class
	// Print the result
	std::cout << "Call option price: " << EuropeanCall.Price(S)
		<< " Put option price: " << EuropeanPut.Price(S) << '\n';

	// Put-Call Parity Testing
	std::cout << "Call-Parity(Put): " << ParityPrice(S, EuropeanCall)
		<< ", Put-Parity(Call): " << ParityPrice(S, EuropeanPut) << '\n' << '\n';

	OptionData OptData;															// Create an obj of struct OptionData
	OptData.K = K, OptData.T = T, OptData.r = r, OptData.sig = sig;				// Initialise each member data

	double C1 = BSCallPrice(OptData, S);
	double P1 = BSPutPrice(OptData, S);

	// Using Struct
	// Print result
	std::cout << "Call option price: " << C1 << " Put option price: " << P1 << '\n';

	// Put-Call Parity Testing
	std::cout << "Call-Parity(Put): " << PCParity(OptData, S, C1, type1) << '\n';
	std::cout << "Put-Parity(Call): " << PCParity(OptData, S, P1, type2) << '\n' << '\n';


	return 0;
}

// Global Functions Definition
double BSCallPrice(const OptionData& optD, const double& S)
{
	double C, d1, d2, b;							// Declare parameters
	boost::math::normal_distribution<> N(0, 1);		// Standard Normal Distribution

	// Black-Scholes model
	b = optD.r;
	d1 = (log(S / optD.K) + (b + (optD.sig * optD.sig / 2)) * optD.T) / (optD.sig * sqrt(optD.T));
	d2 = d1 - optD.sig * sqrt(optD.T);

	// Calculate Option Price
	C = S * exp((b - optD.r) * optD.T) * cdf(N, d1) - optD.K * exp(-optD.r * optD.T) * boost::math::cdf(N, d2);

	return C;
}

double BSPutPrice(const OptionData& optD, const double& S)
{
	double P, d1, d2, b;							// declare parameters
	boost::math::normal_distribution<> N(0, 1);

	// Black-Scholes model
	b = optD.r;
	d1 = (log(S / optD.K) + (b + (optD.sig * optD.sig / 2)) * optD.T) / (optD.sig * sqrt(optD.T));
	d2 = d1 - optD.sig * sqrt(optD.T);

	// Calculate Option Price
	P = optD.K * exp(-optD.r * optD.T) * boost::math::cdf(N, -d2) - S * exp((b - optD.r) * optD.T) * boost::math::cdf(N, -d1);

	return P;
}

double PCParity(const OptionData& optD, const double& S, const double& price, const char& type)
{
	double parityP;
	if (type == 'C')
	{
		// the input 'price' is a call-option price
		parityP = price + optD.K * exp(-optD.r * optD.T) - S;
	}
	else
	{
		// the input 'price' is a put option price
		parityP = price + S - optD.K * exp(-optD.r * optD.T);
	}

	std::cout << "Original option type: " << type << '\n';

	return parityP;
}