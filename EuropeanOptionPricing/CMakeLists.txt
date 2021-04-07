add_executable(EuropeanOptionPricing 
TestOption.cpp EuropeanOption.cpp EuropeanOption.h OptionElements.h)

find_package(Boost 1.75.0 REQUIRED)
target_link_libraries(EuropeanOptionPricing Boost::boost)