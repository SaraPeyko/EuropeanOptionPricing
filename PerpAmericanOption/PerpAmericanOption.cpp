// PerpAmericanOption.cpp
//
//

#include <iostream>
#include "PerpAmericanOption.h"

// Default constructor
PerpAmericanOption::PerpAmericanOption() : b(0), K(0), r(0), sig(0), type('C') {}

// Constructor with parameters
PerpAmericanOption::PerpAmericanOption(double newb, double newK, double newr, double newsig, char newtype)
	: b(newb), K(newK), r(newr), sig(newsig), type(newtype) {}

// Copy constructor
PerpAmericanOption::PerpAmericanOption(const PerpAmericanOption& source)
	: b(source.b), K(source.K), r(source.r), sig(source.sig), type(source.type) {}

// Destructor 
PerpAmericanOption::~PerpAmericanOption() {}

// Setter
void PerpAmericanOption::Type(const char& Type) { type = Type; }

// Getter
char PerpAmericanOption::Type() { return type; }

// Seperated function of call price and put price
double PerpAmericanOption::CallPrice(const double& S)
{
	double price, param1, param2, fac;

	// Calculate parameters
	param1 = 0.5 - (b / (pow(sig, 2)));
	param2 = sqrt(pow(-param1, 2) + ((2 * r) / pow(sig, 2)));

	double y1 = param1 + param2;
	if (y1 == 1)		// Special case: y1 = 1
	{
		return S;
	}
	else
	{
		fac = ((y1 - 1) / y1) * (S / K);
		price = (K / (y1 - 1)) * pow(fac, y1);
	}

	return price;
}

double PerpAmericanOption::PutPrice(const double& S)
{
	double price, param1, param2, fac;

	// Calculate Parameters
	param1 = 0.5 - (b / pow(sig, 2));
	param2 = sqrt(pow(-param1, 2) + ((2 * r) / pow(sig, 2)));

	double y2 = param1 - param2;
	if (y2 == 1)	// Special case: y2 = 1
	{
		return S;
	}
	else
	{
		fac = ((y2 - 1) / y2) * (S / K);
		price = (K / (1 - y2)) * pow(fac, y2);
	}

	return price;
}


double PerpAmericanOption::Price(const double& S)
{
	if (type == 'C')
	{
		return CallPrice(S);
	}
	else
	{
		return PutPrice(S);
	}
}

// Assignment Operator
PerpAmericanOption& PerpAmericanOption::operator = (const PerpAmericanOption& source)
{
	if (&source == this)
	{
		b = source.b;
		K = source.K;
		r = source.r;
		sig = source.sig;
		type = source.type;
	}

	return *this;
}
