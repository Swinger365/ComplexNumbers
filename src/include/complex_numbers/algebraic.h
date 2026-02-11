#ifndef COMPLEXNUMBERS_ALGEBRAIC_H
#define COMPLEXNUMBERS_ALGEBRAIC_H

#include "complex.h"

#include <string>
#include <stdexcept>

namespace ComplexNumbers
{

    /**
     * @brief Алгебраическая форма комплексного числа: a + bi.
     */
    class Algebraic final : public Complex
    {
    public:
        /**
         * @brief Конструктор.
         * @param first Действительная часть.
         * @param second Мнимая часть.
         */
        Algebraic(double first = 0.0, double second = 0.0);

        /** @brief Присваивание другого комплексного числа. */
        Algebraic &operator=(const Algebraic &other) = default;
        /**
         * @brief Присваивание действительного числа.
         * @param value Новое значение действительной части.
         */
        Algebraic &operator=(double value);

        /** @brief Сложение двух комплексных чисел. */
        Algebraic operator+(const Algebraic &other) const;
        /** @brief Вычитание двух комплексных чисел. */
        Algebraic operator-(const Algebraic &other) const;
        /** @brief Умножение двух комплексных чисел. */
        Algebraic operator*(const Algebraic &other) const;
        /** @brief Деление двух комплексных чисел. */
        Algebraic operator/(const Algebraic &other) const;

        /** @brief Сложение с присваиванием. */
        Algebraic &operator+=(const Algebraic &other);
        /** @brief Вычитание с присваиванием. */
        Algebraic &operator-=(const Algebraic &other);
        /** @brief Умножение с присваиванием. */
        Algebraic &operator*=(const Algebraic &other);
        /** @brief Деление с присваиванием. */
        Algebraic &operator/=(const Algebraic &other);

        /** @brief Сложение с действительным числом. */
        Algebraic operator+(double value) const;
        /** @brief Вычитание действительного числа. */
        Algebraic operator-(double value) const;
        /** @brief Умножение на действительное число. */
        Algebraic operator*(double value) const;
        /** @brief Деление на действительное число. */
        Algebraic operator/(double value) const;

        /** @brief Сложение действительного числа с присваиванием. */
        Algebraic &operator+=(double value);
        /** @brief Вычитание действительного числа с присваиванием. */
        Algebraic &operator-=(double value);
        /** @brief Умножение на действительное число с присваиванием. */
        Algebraic &operator*=(double value);
        /** @brief Деление на действительное число с присваиванием. */
        Algebraic &operator/=(double value);

        /** @brief Модуль комплексного числа |z|. */
        double abs() const;
        /** @brief Норма |z|^2. */
        double norm() const;
        /** @brief Аргумент числа (угол). */
        double arg() const;

        /** @brief Комплексно-сопряженное число. */
        Algebraic conjugate() const;

        /** @brief Представление числа в виде строки. */
        std::string show() const override;
    };

} // namespace ComplexNumbers

#endif // COMPLEXNUMBERS_ALGEBRAIC_H
