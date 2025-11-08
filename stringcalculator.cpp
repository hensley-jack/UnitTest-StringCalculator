#include "stringcalculator.h"
#include <stdexcept>
#include <sstream>
#include <cmath>
#include <limits>

// Helper to convert string to double, throws if invalid
double parse(const std::string& s) {
    if (s.empty()) {
        throw std::invalid_argument("Empty string");
    }
    char* end;

    //string to double. removes any remaining characters on end
    double val = strtod(s.c_str(), &end);
    if (*end != '\0') {
        throw std::invalid_argument("Invalid number string");
    }
    return val;
}


double add(const std::string& a, const std::string& b) {
    return parse(a) + parse(b);
}


double subtract(const std::string& a, const std::string& b) {
    return parse(a) - parse(b);
}


double multiply(const std::string& a, const std::string& b) {
    return parse(a) * parse(b);
}


double divide(const std::string& a, const std::string& b) {
    double divisor = parse(b);
    if (divisor == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return parse(a) / divisor;
}


double square(const std::string& a) {
    double val = parse(a);
    return val * val;
}


double squareRoot(const std::string& a) {
    double val = parse(a);
    if (val < 0) {
        throw std::invalid_argument("Square root of negative");
    }
    return std::sqrt(val);
}


double power(const std::string& a, const std::string& b) {
    return std::pow(parse(a), parse(b));
}


double modulus(const std::string& a, const std::string& b) {
    double divisor = parse(b);
    if (divisor == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return std::fmod(parse(a), divisor);
}


bool isPositive(const std::string& a) {
    return parse(a) > 0;
}


bool isInteger(const std::string& a) {
    double val = parse(a);
    return std::floor(val) == val;
}