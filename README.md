# Black-Scholes option pricing model

The program illustrates the exact formula for plain (European) equity options  with zero dividends and their sensitivities.

These options can be exercised at the expiry time only.

### Mathematical and financial background

The formula apply to option pricing on a range of underlying securities, but this program focuses on stocks.

The generalized Black-Scholes formula to calculate the price of a call option on some underlying asset, the call price is a function:

<p align="center"><img src="https://github.com/SaraPeyko/EuropeanOptionPricing/blob/master/Captures/Capture1.JPG" width="200" height="150" alt="Capture1"></p>

The exeact formula for call option C is given by:

<p align="center"><img src="https://github.com/SaraPeyko/EuropeanOptionPricing/blob/master/Captures/Capture2.JPG" width="180" height="40" alt="Capture2"></p>


The exact formula for put option P is also  given by:

<p align="center"><img src="https://github.com/SaraPeyko/EuropeanOptionPricing/blob/master/Captures/Capture5.JPG" width="180" height="40" alt="Capture5"></p>

where N(x) is the standard cumulative normal distribution function defined by:

<p align="center"><img src="https://github.com/SaraPeyko/EuropeanOptionPricing/blob/master/Captures/Capture3.JPG" width="180" height="40" alt="Capture3"></p>

and

<p align="center"><img src="https://github.com/SaraPeyko/EuropeanOptionPricing/blob/master/Captures/Capture4.JPG" width="250" height="100" alt="Capture4"></p>

The cost-of-carry parameter has specific values depending on the kind of security: 

b = r is the Black-Scholes stock option model, use this for the case of stock options.

The differentiate of C and P with respect of the parameters produce a formula for the option sensitivities. 

There is a relationship between the price of a European call option and European put option when they have the same Strike price K and maturity T. This is called Put-Call parity and is given by the formula:

<p align="center"><img src="https://github.com/SaraPeyko/EuropeanOptionPricing/blob/master/Captures/Capture6.JPG" width="180" height="40" alt="Capture6"></p>

* **Option Sensitivities, aka the Greeks**

 Option sensitivities are the partial derivatives of the Black-Scholes option pricing formula with respect of its parameters. Being a partial derivative, a given greek quantity is a measure of the sensitivity of the option price to a small change in the formula's parameter. 
 
 There are exact formula for the greeks:
 
<p align="center"><img src="https://github.com/SaraPeyko/EuropeanOptionPricing/blob/master/Captures/Capture7.JPG" width="400" height="200" alt="Capture7"></p>
 
 * **Divided differences to approximate option sensitivities**
 
 In some cases, an exact formula may not exist (or is difficlt to find), which applies to numerical methods. In which case, it can approximate first and second-order derivatives in S by 3-point second order approximations:
 
<p align="center"><img src="https://github.com/SaraPeyko/EuropeanOptionPricing/blob/master/Captures/Capture8.JPG" width="180" height="80" alt="Capture8"></p>
 
 where  h is small (various values of h produce better approximations)

### Usage

* **Environment:** Visual Studio 2019 

* **Configuration:** Debug-Windowsx64

* **C++ library:** Vcpkg and boost 17.5.0

