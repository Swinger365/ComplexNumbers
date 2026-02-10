#include "complex_numbers/algebraic.h"

#include <cmath>
#include <sstream>

namespace ComplexNumbers {

// ============ Конструктор ============

Algebraic::Algebraic(double first, double second)
    : Complex(first, second)
{}


// ============ Присваивание ============

Algebraic& Algebraic::operator=(double value) {
    first = value;
    second = 0.0;
    return *this;
}


// ============ Операции с комплексными ============

Algebraic Algebraic::operator+(const Algebraic& other) const {
    return Algebraic(first + other.first,
                     second + other.second);
}

Algebraic Algebraic::operator-(const Algebraic& other) const {
    return Algebraic(first - other.first,
                     second - other.second);
}

Algebraic Algebraic::operator*(const Algebraic& other) const {
    return Algebraic(
        first * other.first - second * other.second,
        first * other.second + second * other.first
    );
}

Algebraic Algebraic::operator/(const Algebraic& other) const {
    double denominator = other.norm();

    if (denominator == 0.0)
        throw std::runtime_error("Division by zero complex number");

    return Algebraic(
        (first * other.first + second * other.second) / denominator,
        (second * other.first - first * other.second) / denominator
    );
}


// ============ Составные операторы ============

Algebraic& Algebraic::operator+=(const Algebraic& other) {
    first += other.first;
    second += other.second;
    return *this;
}

Algebraic& Algebraic::operator-=(const Algebraic& other) {
    first -= other.first;
    second -= other.second;
    return *this;
}

Algebraic& Algebraic::operator*=(const Algebraic& other) {
    *this = *this * other;
    return *this;
}

Algebraic& Algebraic::operator/=(const Algebraic& other) {
    *this = *this / other;
    return *this;
}


// ============ Операции с double ============

Algebraic Algebraic::operator+(double value) const {
    return Algebraic(first + value, second);
}

Algebraic Algebraic::operator-(double value) const {
    return Algebraic(first - value, second);
}

Algebraic Algebraic::operator*(double value) const {
    return Algebraic(first * value, second * value);
}

Algebraic Algebraic::operator/(double value) const {
    if (value == 0.0)
        throw std::runtime_error("Division by zero scalar");

    return Algebraic(first / value, second / value);
}

Algebraic& Algebraic::operator+=(double value) {
    first += value;
    return *this;
}

Algebraic& Algebraic::operator-=(double value) {
    first -= value;
    return *this;
}

Algebraic& Algebraic::operator*=(double value) {
    first *= value;
    second *= value;
    return *this;
}

Algebraic& Algebraic::operator/=(double value) {
    if (value == 0.0)
        throw std::runtime_error("Division by zero scalar");

    first /= value;
    second /= value;
    return *this;
}


// ============ Функции ============

double Algebraic::norm() const {
    return first * first + second * second;
}

double Algebraic::abs() const {
    return std::sqrt(norm());
}

double Algebraic::arg() const {
    return std::atan2(second, first);
}

Algebraic Algebraic::conjugate() const {
    return Algebraic(first, -second);
}


// ============ Вывод ============

std::string Algebraic::show() const {
    std::stringstream ss;

    if (first == 0.0 && second == 0.0)
        return "0";

    if (second == 0.0)
        ss << first;

    else if (first == 0.0) {
        double imag = std::abs(second);

        if (imag == 1.0) {
            if (second < 0)
                ss << "-i";
            else
                ss << "i";
        } else {
            ss << second << "i";
        }
    }

    else {
        ss << first;

        if (second > 0)
            ss << " + ";
        else
            ss << " - ";

        double imag = std::abs(second);

        if (imag == 1.0)
            ss << "i";
        else
            ss << imag << "i";
    }

    return ss.str();
}

} // namespace ComplexNumbers
