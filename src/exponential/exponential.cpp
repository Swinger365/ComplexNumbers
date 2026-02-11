#include "complex_numbers/exponential.h"
#include <cmath>
#include <sstream>
namespace ComplexNumbers
{
    // ============ Конструктор ============

    Exponential::Exponential(double modulus, double argument)
        : Complex(modulus, argument)
    {
    }

    // ============ Присваивание ============

    Exponential &Exponential::operator=(double value)
    {
        first = value; // Модуль
        second = 0.0;  // Аргумент
        return *this;
    }

    // ============ Операции с комплексными ============

    Exponential Exponential::operator+(const Exponential &other) const
    {
        double real = this->first * cos(this->second);
        double imag = this->first * sin(this->second);

        double other_real = other.first * cos(other.second);
        double other_imag = other.first * sin(other.second);

        double sum_real = real + other_real;
        double sum_imag = imag + other_imag;

        double modulus = sqrt(sum_real * sum_real + sum_imag * sum_imag);
        double argument = atan2(sum_imag, sum_real);
        return Exponential(modulus, argument);
    }

    Exponential Exponential::operator-(const Exponential &other) const
    {
        double real = this->first * cos(this->second);
        double imag = this->first * sin(this->second);

        double other_real = other.first * cos(other.second);
        double other_imag = other.first * sin(other.second);

        double diff_real = real - other_real;
        double diff_imag = imag - other_imag;

        double modulus = sqrt(diff_real * diff_real + diff_imag * diff_imag);
        double argument = atan2(diff_imag, diff_real);
        return Exponential(modulus, argument);
    }

    Exponential Exponential::operator*(const Exponential &other) const
    {
        double modulus = this->first * other.first;
        double argument = this->second + other.second;
        return Exponential(modulus, argument);
    }

    Exponential Exponential::operator/(const Exponential &other) const
    {
        if (other.first == 0.0)
            throw std::runtime_error("Division by zero complex number");

        double modulus = this->first / other.first;
        double argument = this->second - other.second;
        return Exponential(modulus, argument);
    }

    Exponential &Exponential::operator+=(const Exponential &other)
    {
        *this = *this + other;
        return *this;
    }

    Exponential &Exponential::operator-=(const Exponential &other)
    {
        *this = *this - other;
        return *this;
    }

    Exponential &Exponential::operator*=(const Exponential &other)
    {
        *this = *this * other;
        return *this;
    }

    Exponential &Exponential::operator/=(const Exponential &other)
    {
        *this = *this / other;
        return *this;
    }

    // ===== Операции с действительными числами =====

    Exponential Exponential::operator+(double value) const
    {
        return *this + Exponential(value, 0.0);
    }

    Exponential Exponential::operator-(double value) const
    {
        return *this - Exponential(value, 0.0);
    }

    Exponential Exponential::operator*(double value) const
    {
        return Exponential(first * value, second);
    }

    Exponential Exponential::operator/(double value) const
    {
        if (value == 0.0)
            throw std::runtime_error("Division by zero scalar");

        return Exponential(first / value, second);
    }

    Exponential &Exponential::operator+=(double value)
    {
        *this = *this + value;
        return *this;
    }

    Exponential &Exponential::operator-=(double value)
    {
        *this = *this - value;
        return *this;
    }

    Exponential &Exponential::operator*=(double value)
    {
        *this = *this * value;
        return *this;
    }

    Exponential &Exponential::operator/=(double value)
    {
        *this = *this / value;
        return *this;
    }

    // ============ Функции ============

    Exponential Exponential::conjugate() const
    {
        return Exponential(first, -second);
    }

    double Exponential::norm() const
    {
        return first * first;
    }

    std::string Exponential::show() const
    {
        std::stringstream ss;

        if (first == 0.0)
            return "0";

        ss << first << " * e^(i * " << second << ")";

        return ss.str();
    }

    double Exponential::real() const
    {
        return first * cos(second);
    }

    double Exponential::imaginary() const
    {
        return first * sin(second);
    }

    double Exponential::modulus() const
    {
        return first;
    }

    double Exponential::argument() const
    {
        return second;
    }
} // namespace ComplexNumbers