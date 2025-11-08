#pragma once
#include <string>

double parse(const std::string& s);
double add(const std::string& a, const std::string& b);
double subtract(const std::string& a, const std::string& b);
double multiply(const std::string& a, const std::string& b);
double divide(const std::string& a, const std::string& b);
double square(const std::string& a);
double squareRoot(const std::string& a);
double power(const std::string& a, const std::string& b);
double modulus(const std::string& a, const std::string& b);
bool isPositive(const std::string& a);
bool isInteger(const std::string& a);