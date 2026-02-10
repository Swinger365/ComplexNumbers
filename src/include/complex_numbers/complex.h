#ifndef COMPLEXNUMBERS_COMPLEX_H
#define COMPLEXNUMBERS_COMPLEX_H

#include <string>

namespace ComplexNumbers {

    /**
     * @brief Абстрактная базовая форма комплексного числа.
     *
     * Хранит первую и вторую компоненты и задает интерфейс вывода.
     * Первой компонентой может быть действительная часть или модуль, второй - мнимая часть или аргумент, в зависимости от формы представления.
     */
    class Complex {
    protected:
        /** @brief Первая компонента (обычно действительная часть). */
        double first;
        /** @brief Вторая компонента (обычно мнимая часть). */
        double second;

    public:
        /**
         * @brief Конструктор базового класса.
         * @param first Первая компонента (обычно действительная часть).
         * @param second Вторая компонента (обычно мнимая часть).
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
