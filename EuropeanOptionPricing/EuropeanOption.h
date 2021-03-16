// EuropeanOption.h
//
// Exact solutions of one-factor plain options
// The program shows the exact formulae for plain (European) equity options.
// with zero dividends and their sensitivities
// These options can be exercised at the expiry time T only

#ifndef EuropeanOption_H
#define EuropeanOption_H

#include <iostream>

class EuropeanOption
{
private:
	double b;					// cost of carry, b = r is the Black-Scholes stock option model
	char type;					// C = Call Price, P = Put Price

public:
	double K;					// Strike price
	double T;					// Time to maturity
	double r;					// Risk-free interest rate
	double sig;					// Stock price volatility

	EuropeanOption();			// Default constructor
	EuropeanOption(double newK, double newT, double newr, double newsig, char newType);		// Constructor with parameters
	EuropeanOption(const EuropeanOption& source);		// Copy constructor
	~EuropeanOption();									// Destructor

	// Getters
	double ModelParameter();
	char Type();

	// Setters
	void ModelParameter(const double& param);
	void Type(const char& Type);

	// Calculate option price
	double Price(const double& S);

	// Assignment operator
	EuropeanOption& operator = (const EuropeanOption& source);

};

#endif // !EuropeanOption_H

