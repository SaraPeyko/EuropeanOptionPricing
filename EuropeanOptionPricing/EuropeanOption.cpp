// EuropeanOption.cpp
//
//

#include "EuropeanOption.h"
#include <boost/math/distributions/normal.hpp>

// Default constructor
EuropeanOption::EuropeanOption()
	:K(0), T(0), r(0), sig(0), type('C'), b(0) {}

// Constructor with parameters
EuropeanOption::EuropeanOption(double newK, double newT, double newr, double newsig, char newtype)
	: K(newK), T(newT), r(newr), sig(newsig), type(newtype), b(newr) {}

// Copy constructor
EuropeanOption::EuropeanOption(const EuropeanOption& source)
	: K(source.K), T(source.T), r(source.r), sig(source.sig), type(source.type), b(source.b) {}

// Destructor
EuropeanOption::~EuropeanOption() {}

// Setters
void EuropeanOption::ModelParameter(const double& param) { b = param; }
void EuropeanOption::Type(const char& Type) { type = Type; }

// Getters
double EuropeanOption::ModelParameter() { return b; }
char EuropeanOption::Type() { return type; }

// Calculate Option Price
double EuropeanOption::Price(const double& S)
{
	double price, d1, d2;							// Parameters
	boost::math::normal_distribution<> N(0, 1);		// Standard Normal Distribution

	// Calculate using parameters
	d1 = (log(S / K) + (b + (sig * sig / 2)) * T) / (sig * (sqrt(T)));
	d2 = d1 - sig * sqrt(T);

	// calculate pric with different type
	if (type == 'C')		// Call Price
	{
		price = S * exp((b - r) * T) * boost::math::cdf(N, d1) - K * exp(-r * T) * boost::math::cdf(N, d2);
		// N(x) is the cumulative normal distribution function (cdf)
	}
	else
	{
		price = K * exp(-r * T) * boost::math::cdf(N, -d2) - S * exp((b - r) * T) * boost::math::cdf(N, -d1);
	}

	return price;
}

// Assignment Operator
EuropeanOption& EuropeanOption::operator = (const EuropeanOption& source)
{
	if (&source != this)
	{
		// Assignment parameters
		b = source.b;
		type = source.type;
		K = source.K;
		T = source.T;
		r = source.r;
		sig = source.sig;
	}

	return *this;
}

double ParityPrice(const double& S, EuropeanOption& source)
{
	if (source.type == 'C')	
	{
		// Parity put price
		return (source.Price(S) + source.K * exp(-source.r * source.T) - S);
	}
	else
	{
		// Parity call price
		return (source.Price(S) + S - source.K * exp(-source.r * source.T));
	}

}

// Sensitivities
double EuropeanOption::Delta(const double& S)
{
	double delPrice;
	boost::math::normal_distribution<> N(0, 1);		// Standard normal distribution

	// Calculate using parameters
	double d1 = (log(S / K) + (b + (sig * sig / 2)) * T) / (sig * sqrt(T));

	// Calculate price with different type
	if (type == 'C')
	{
		// Call delta
		delPrice = exp((b - r) * T) * boost::math::cdf(N, d1);
	}
	else
	{
		delPrice = -exp((b - r) * T) * boost::math::cdf(N, -d1);
	}

	return delPrice;
}

double EuropeanOption::Gamma(const double& S)
{
	double gammaPrice;
	boost::math::normal_distribution<> N(0, 1);

	// Calculate using parametera
	double d1 = (log(S / K) + (b + (sig * sig / 2)) * T) / (sig * sqrt(T));
	gammaPrice = (boost::math::pdf(N, d1) * exp((b - r) * T)) / (S * sig * sqrt(T));

	return gammaPrice;
}