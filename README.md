# Black-Scholes option pricing model

The program illustrates the exact formula for plain (European) equity options  with zero dividends and their sensitivities. These options can be exercised at the expiry time only.

### Mathematical and financial background

The formula apply to option pricing on a range of underlying securities, but this program focuses on stocks.

The generalized Black-Scholes formula to calculate the price of a call option on some underlying asset, the call price is a function:

![Capture1](https://user-images.githubusercontent.com/24828971/114290555-594e7880-9a78-11eb-8175-c78ff34c2e66.JPG)

The exeact formula for call option C is given by:

![Capture2](https://user-images.githubusercontent.com/24828971/114290563-69665800-9a78-11eb-91c6-5d3381237ecc.JPG)

The exact formula for put option P is also  given by:

![Capture5](https://user-images.githubusercontent.com/24828971/114290569-784d0a80-9a78-11eb-9f5c-45fa66ef79a6.JPG)

where N(x) is the standard cumulative normal distribution function defined by:

![Capture3](https://user-images.githubusercontent.com/24828971/114290574-7daa5500-9a78-11eb-9f62-7750eaeb5206.JPG)

and

![Capture4](https://user-images.githubusercontent.com/24828971/114290579-83a03600-9a78-11eb-8c2f-f9bca6b3e2c0.JPG)

The cost-of-carry parameter has specific values depending on the kind of security: 

b = r is the Black-Scholes stock option model, use this for the case of stock options.

The differentiate of C and P with respect of the parameters produce a formula for the option sensitivities. 

There is a relationship between the price of a European call option and European put option when they have the same strike price K and maturity T. This is called Put-Call parity and is given by the formula:

![Capture6](https://user-images.githubusercontent.com/24828971/114290584-8bf87100-9a78-11eb-8b6f-64dec5dc4b46.JPG)

* **Option Sensitivities, aka the Greeks**

 Option sensitivities are the partial derivatives of the Black-Scholes option pricing formula with respect of its parameters. Being a partial derivative, a given greek quantity is a measure of the sensitivity of the option price to a small change in the formula's parameter. 
 
 There are exact formula for the greeks:
 
![Capture7](https://user-images.githubusercontent.com/24828971/114290586-931f7f00-9a78-11eb-8b14-0d1ce62c7317.JPG)
 
 * **Divided differences to approximate option sensitivities**
 
 In some cases, an exact formula may not exist (or is difficult to find), which applies to numerical methods. In which case, it can approximate first and second-order derivatives in S by 3-point second order approximations:
 
![Capture8](https://user-images.githubusercontent.com/24828971/114290591-9a468d00-9a78-11eb-92d3-51d7b50bc06a.JPG)
 
 where  h is small (various values of h produce better approximations)

### Requirements

* **Environment:** Visual Studio 2019 

* **Configuration:** x64-Debug

* **C++ library:** STL and Boost 17.5.0

