// OptionElements.h
//
//

#ifndef OptionElements_H
#define OptionElements_H

#include <iostream>
#include <vector>

// The set of test values for option pricing
namespace Batch1
{
	double T = 0.25;
	double K = 65;
	double sig = 0.30;
	double r = 0.08;
	double S = 60;				// current stock price where to price the option
}

namespace Batch2
{
	double T = 1.0;
	double K = 100;
	double sig = 0.2;
	double r = 0.0;
	double S = 100;
}

namespace Batch3
{
	double T = 1.0;
	double K = 10;
	double sig = 0.50;
	double r = 0.12;
	double S = 5;
}

namespace Batch4
{
	double T = 30.0;
	double K = 100.0;
	double sig = 0.30;
	double r = 0.08;
	double S = 100.0;
}

// Struct
struct OptionData
{
	double K;				// strike price
	double T;				// time to maturity
	double r;				// risk-free interest rate
	double sig;				// stock price volatility
};

// Global Functions Declarations
// double BSCallPrice(const double& S, const double& K, const double& T, const double& r, const double& sig);
// double BSPutPrice(const double& S, const double& K, const double& T, const double& r, const double& sig);
// double PCParity(const double& S, const double& K, const double& T, const double& r, const double& sig);

// Global Function Using Struct
double BSCallPrice(const OptionData& optD, const double& S);
double BSPutPrice(const OptionData& optD, const double& S);
double PCParity(const OptionData& optD, const double& S, const double& price, const char& type);

// Global function that produces a mesh array of doubles seperated by mesh size h
std::vector<double> Vec(const double& start, const double& h, const int& size);

#endif // !OptionElements_H


