#ifndef COMPLEXNUMBERS_EXPONENTIAL_H
#define COMPLEXNUMBERS_EXPONENTIAL_H

#include "complex_numbers/complex.h"

namespace ComplexNumbers
{
    /**
     * @brief Экспоненциальная форма комплексного числа.
     *
     * Комплексное число вида |z| * e^(i*theta), где |z| - модуль, а theta - аргумент.
     * |z| иногда обозначается как r, а theta - как phi.
     */
    class Exponential : public Complex
    {
        /**
         * @brief Конструктор.
         * @param modulus Модуль комплексного числа.
         * @param argument Аргумент комплексного числа.
         */
        Exponential(double modulus = 0.0, double argument = 0.0);

        /** @brief Присваивание другого комплексного числа. */
        Exponential &operator=(const Exponential &other) = default;

        /** @brief Присваивание действительного числа.(Здесь то же самое что и присвоить модуль)
         *  @param value Задает только модуль, аргумент при этом будет 0, то есть число будет на действительной оси.
         */
        Exponential &operator=(double value);

        /**
         * @brief Сложение двух комплексных чисел.
         */
        Exponential operator+(const Exponential &other) const;
        /**
         * @brief Вычитание двух комплексных чисел.
         */
        Exponential operator-(const Exponential &other) const;
        /**
         * @brief Умножение двух комплексных чисел.
         * При умножении в экспоненциальной форме, модули перемножаются, а аргументы складываются.
         */
        Exponential operator*(const Exponential &other) const;
        /**
         * @brief Деление двух комплексных чисел.
         * При делении в экспоненциальной форме, модули делятся,
         * а аргументы вычитаются.
         */
        Exponential operator/(const Exponential &other) const;

        /** @brief Сложение с присваиванием. */
        Exponential &operator+=(const Exponential &other);
        /** @brief Вычитание с присваиванием. */
        Exponential &operator-=(const Exponential &other);
        /** @brief Умножение с присваиванием. */
        Exponential &operator*=(const Exponential &other);
        /** @brief Деление с присваиванием. */
        Exponential &operator/=(const Exponential &other);

        /** @brief Сложение с действительным числом. */
        Exponential operator+(double value) const;
        /** @brief Вычитание действительного числа. */
        Exponential operator-(double value) const;
        /** @brief Умножение на действительное число. */
        Exponential operator*(double value) const;
        /** @brief Деление на действительное число. */
        Exponential operator/(double value) const;

        /** @brief Сложение действительного числа с присваиванием. */
        Exponential &operator+=(double value);
        /** @brief Вычитание действительного числа с присваиванием. */
        Exponential &operator-=(double value);
        /** @brief Умножение на действительное число с присваиванием. */
        Exponential &operator*=(double value);
        /** @brief Деление на действительное число с присваиванием. */
        Exponential &operator/=(double value);

        /** @brief Получение сопряженного комплексного числа. */
        Exponential conjugate() const;

        /** @brief Получение нормы комплексного числа. */
        double norm() const;

        /** @brief Представление числа в виде строки. */
        std::string show() const override;

        /** @brief Получить модуль комплексного числа. */
        double modulus() const;

        /** @brief Получить аргумент комплексного числа. */
        double argument() const;

        /** @brief получить действительную часть комплексного числа. */
        double real() const override;

        /** @brief получить мнимую часть комплексного числа. */
        double imaginary() const override;
    };
} // ComplexNumbers

#endif // COMPLEXNUMBERS_EXPONENTIAL_H