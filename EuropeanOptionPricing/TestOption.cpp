// TestOption.cpp
//
// This is a source file for Testing BS option pricing models

#include <iostream>
#include <iomanip>
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
	// std::cout << "Call option price: " << EuropeanCall.Price(S) << " Put option price: " << EuropeanPut.Price(S) << '\n';

	// Put-Call Parity Testing
	// std::cout << "Call-Parity(Put): " << ParityPrice(S, EuropeanCall) << " Put-Parity(Call): " << ParityPrice(S, EuropeanPut) << '\n' << '\n';

	OptionData OptData;															// Create an object of struct OptionData
	OptData.K = K, OptData.T = T, OptData.r = r, OptData.sig = sig;				// Initialize each member data

	double C1 = BSCallPrice(OptData, S);
	double P1 = BSPutPrice(OptData, S);

	// Using Struct
	// Print result
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(3);		// prevent scientific notation with 3 decimal places
	std::cout << "Call option price: " << C1 << " Put option price: " << P1 << '\n';

	// Put-Call Parity Testing
	std::cout << "Call-Parity(Put): " << PCParity(OptData, S, C1, type1) << " Put-Parity(Call): " << PCParity(OptData, S, P1, type2) << '\n' << '\n';

	// Containers
	std::vector<double> stock = Vec(1, 1, 50);
	std::vector<double> time = Vec(0.25, 0.25, 50);
	std::vector<double> volatility = Vec(0.10, 0.01, 50);

	// Containers of result
	std::vector<double> output1;
	output1.reserve(50);
	std::vector<double> output2;
	output2.reserve(50);

	// Option price for different stock prices
	std::cout << "Option price for different stock price:\n";
	for (int i = 0; i < 50; i++)
	{
		// calculate call price
		output1.push_back(BSCallPrice(OptData, stock[i]));

		// calculate put price
		output2.push_back(BSPutPrice(OptData, stock[i]));

		// print the result
		std::cout << "Stock price: " << stock[i] << " Call price: "
			<< output1[i] << " Put price: " << output2[i] << '\n';
	}
	output1.clear();
	output2.clear();

	// Option price for different time to maturity
	std::cout << "\n\nOption price for different time to maturity:\n";
	for (int i = 0; i < 50; i++)
	{
		OptData.T = time[i];

		// calculate call price
		output1.push_back(BSCallPrice(OptData, S));

		// calculate put price
		output2.push_back(BSPutPrice(OptData, S));

			std::cout << "Time to maturity: " << time[i]
				<< " Call price: " << output1[i] 
				<< " Put price: " << output2[i] << '\n';
	}
	output1.clear();
	output2.clear();

	// Option price for different volatility
	std::cout << "\n\nOption price for different stock price volatility:\n";
	for (int i = 0; i < 50; i++)
	{
		OptData.sig = volatility[i];

		// calculate call price
		output1.push_back(BSCallPrice(OptData, S));

		// calculate put price
		output2.push_back(BSPutPrice(OptData, S));

		// print the result
		std::cout << "Volatility: " << volatility[i] << " Call price "
			<< output1[i] << " Put price: " << output2[i] << '\n';
	}
	output1.clear();
	output2.clear();

	// Testing for Delta and Gamma
	// Given the Data set
	K = 100;
	S = 105;
	T = 0.5;
	r = 0.1;
	sig = 0.36;
	double b = 0.0;		// b = 0 is the Black-Scholes futures option model

	EuropeanOption EuropeanCall1(K, T, r, sig, type1);
	EuropeanOption EuropeanPut1(K, T, r, sig, type2);

	EuropeanCall1.ModelParameter(b);
	EuropeanPut1.ModelParameter(b);

	// Print the result
	std::cout << "\n\nDelta call: " << EuropeanCall1.Delta(S)
		<< " Delta put: " << EuropeanPut1.Delta(S) << '\n';

	std::cout << "Gamma call: " << EuropeanCall1.Gamma(S) << '\n';

	// Delta test with different stocks
	stock = Vec(1, 5, 50);
	std::cout << "\n\nDelta test for different stock price:\n";
	for (int i = 0; i < 50; i++)
	{
		output1.push_back(EuropeanCall1.Delta(stock[i]));
		output2.push_back(EuropeanPut1.Delta(stock[i]));

		// print the result
		std::cout << "Stock price: " << stock[i]
			<< " Delta call: " << output1[i]
			<< " Delta put: " << output2[i] << '\n';
	}
	output1.clear();
	output2.clear();

	// Using divided differences
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(5);
	std::vector<double> H = Vec(0.1, 0.05, 10);		// steplength
	std::cout << "\n\nApproximated Version for Delta:\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Step length: " << H[i] 
			<< " Delta call: " << EuropeanCall1.ApproxDelta(S, H[i])
			<< " Delta put: " << EuropeanPut1.ApproxDelta(S, H[i]) << '\n';
	}

	double h = 0.50;
	std::cout << "\n\nApproximated Version for Delta:\n";
	for (int i = 0; i < 50; i++)
	{
		output1.push_back(EuropeanCall1.ApproxDelta(stock[i], h));
		output2.push_back(EuropeanPut1.ApproxDelta(stock[i], h));

		std::cout << "Stock price: " << stock[i]
			<< " Approx delta call: " << output1[i]
			<< " Approx delta put: " << output2[i] << '\n';
	}
	output1.clear();
	output2.clear();

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
		// the input 'price' is a put option price
		parityP = price + optD.K * exp(-optD.r * optD.T) - S;
	}
	else
	{
		// the input 'price' is a call-option price
		parityP = price + S - optD.K * exp(-optD.r * optD.T);
	}

	//std::cout << "Original option type: " << type << '\n';

	return parityP;
}

// produces an array of doubles seperated by a size h
std::vector<double> Vec(const double& start, const double& h, const int& size)
{
	std::vector<double> v;
	v.reserve(size);
	for (int i = 0; i < size; i++)
	{
		v.push_back(start + h * i);
	}
	return v;
}