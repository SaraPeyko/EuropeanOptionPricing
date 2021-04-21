// PerpAmericanOption.h
//
// 

#ifndef PerpAmericanOption_H
#define PerpAmericanOption_H

#include <iostream>

class PerpAmericanOption
{
private:
	char type;						// 'C' for call/ 'P' for put

	double b;						// cost of carry
	double K;						// strike price
	double r;						// risk-free interest rate
	double sig;						// stock price volatility

public:
	PerpAmericanOption();
	PerpAmericanOption(double newb, double newK, double newr, double newsig, char newtype);
	PerpAmericanOption(const PerpAmericanOption& source);
	~PerpAmericanOption();

	void Type(const char& Type);	// Setter
	char Type();					// Setter

	// Seperated function of call price and put price
	double CallPrice(const double& S);
	double PutPrice(const double& S);

	double Price(const double& S);

	// Assignment operator
	PerpAmericanOption& operator = (const PerpAmericanOption& source);


};
#endif // !PerpAmericanOption_H

