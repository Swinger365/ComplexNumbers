#ifndef COMPLEXNUMBERS_COMPLEX_H
#define COMPLEXNUMBERS_COMPLEX_H

#include <string>

namespace ComplexNumbers {

    /**
     * @brief Абстрактная базовая форма комплексного числа.
     *
     * Хранит действительную и мнимую части и задает интерфейс вывода.
     */
    class Complex {
    protected:
        /** @brief Действительная часть. */
        double first;
        /** @brief Мнимая часть. */
        double second;

    public:
        /**
         * @brief Конструктор базового класса.
         * @param first Действительная часть.
         * @param second Мнимая часть.
         */
        Complex(double first = 0.0, double second = 0.0)
            : first(first), second(second)
        {}

        /** @brief Виртуальный деструктор. */
        virtual ~Complex() = default;

        /**
         * @brief Представление числа в виде строки.
         * @return Строка в выбранном формате.
         */
        virtual std::string show() const = 0;

        /** @brief Действительная часть. */
        double real() const {
            return first;
        }

        /** @brief Мнимая часть. */
        double imaginary() const {
            return second;
        }
    };

} // namespace ComplexNumbers

#endif // COMPLEXNUMBERS_COMPLEX_H
