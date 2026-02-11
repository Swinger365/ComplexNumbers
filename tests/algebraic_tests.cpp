#include <gtest/gtest.h>
#include <complex_numbers/algebraic.h>

#include <cmath>

using namespace ComplexNumbers;

// ============ Конструктор ============

TEST(AlgebraicComplex, ConstructorWorks)
{
    Algebraic z(3, -2);

    EXPECT_DOUBLE_EQ(z.real(), 3);
    EXPECT_DOUBLE_EQ(z.imaginary(), -2);
}

TEST(AlgebraicComplex, DefaultConstructorWorks)
{
    Algebraic z;

    EXPECT_DOUBLE_EQ(z.real(), 0);
    EXPECT_DOUBLE_EQ(z.imaginary(), 0);
}

// ============ Присваивание ============

TEST(AlgebraicComplex, AssignFromDouble)
{
    Algebraic z(1, 5);

    z = 7;

    EXPECT_DOUBLE_EQ(z.real(), 7);
    EXPECT_DOUBLE_EQ(z.imaginary(), 0);
}

TEST(AlgebraicComplex, AssignFromComplex)
{
    Algebraic a(1, 2);
    Algebraic b(5, -3);

    a = b;

    EXPECT_DOUBLE_EQ(a.real(), 5);
    EXPECT_DOUBLE_EQ(a.imaginary(), -3);
}

// ============ Операции с комплексными ============

TEST(AlgebraicComplex, PlusOperatorComplex)
{
    Algebraic a(1, 2);
    Algebraic b(3, 4);

    Algebraic res = a + b;

    EXPECT_DOUBLE_EQ(res.real(), 4);
    EXPECT_DOUBLE_EQ(res.imaginary(), 6);
}

TEST(AlgebraicComplex, MinusOperatorComplex)
{
    Algebraic a(5, 2);
    Algebraic b(3, 1);

    Algebraic res = a - b;

    EXPECT_DOUBLE_EQ(res.real(), 2);
    EXPECT_DOUBLE_EQ(res.imaginary(), 1);
}

TEST(AlgebraicComplex, MultiplyOperatorComplex)
{
    Algebraic a(1, 2);
    Algebraic b(3, 4);

    Algebraic res = a * b;

    EXPECT_DOUBLE_EQ(res.real(), -5);
    EXPECT_DOUBLE_EQ(res.imaginary(), 10);
}

TEST(AlgebraicComplex, DivideOperatorComplex)
{
    Algebraic a(1, 2);
    Algebraic b(3, 4);

    Algebraic res = a / b;

    EXPECT_NEAR(res.real(), 0.44, 1e-2);
    EXPECT_NEAR(res.imaginary(), 0.08, 1e-2);
}

// ============ Составные операторы ============

TEST(AlgebraicComplex, PlusEqualOperator)
{
    Algebraic a(1, 2);
    Algebraic b(3, 4);

    a += b;

    EXPECT_DOUBLE_EQ(a.real(), 4);
    EXPECT_DOUBLE_EQ(a.imaginary(), 6);
}

TEST(AlgebraicComplex, MinusEqualOperator)
{
    Algebraic a(5, 2);
    Algebraic b(3, 1);

    a -= b;

    EXPECT_DOUBLE_EQ(a.real(), 2);
    EXPECT_DOUBLE_EQ(a.imaginary(), 1);
}

TEST(AlgebraicComplex, MultiplyEqualOperator)
{
    Algebraic a(1, 2);
    Algebraic b(3, 4);

    a *= b;

    EXPECT_DOUBLE_EQ(a.real(), -5);
    EXPECT_DOUBLE_EQ(a.imaginary(), 10);
}

TEST(AlgebraicComplex, DivideEqualOperator)
{
    Algebraic a(1, 2);
    Algebraic b(3, 4);

    a /= b;

    EXPECT_NEAR(a.real(), 0.44, 1e-2);
    EXPECT_NEAR(a.imaginary(), 0.08, 1e-2);
}

// ============ Операции с double ============

TEST(AlgebraicComplex, PlusOperatorDouble)
{
    Algebraic z(1, 2);

    Algebraic res = z + 3;

    EXPECT_DOUBLE_EQ(res.real(), 4);
    EXPECT_DOUBLE_EQ(res.imaginary(), 2);
}

TEST(AlgebraicComplex, MultiplyOperatorDouble)
{
    Algebraic z(2, -1);

    Algebraic res = z * 3;

    EXPECT_DOUBLE_EQ(res.real(), 6);
    EXPECT_DOUBLE_EQ(res.imaginary(), -3);
}

TEST(AlgebraicComplex, DivideOperatorDouble)
{
    Algebraic z(6, 4);

    Algebraic res = z / 2;

    EXPECT_DOUBLE_EQ(res.real(), 3);
    EXPECT_DOUBLE_EQ(res.imaginary(), 2);
}

TEST(AlgebraicComplex, PlusEqualDouble)
{
    Algebraic z(1, 2);

    z += 5;

    EXPECT_DOUBLE_EQ(z.real(), 6);
    EXPECT_DOUBLE_EQ(z.imaginary(), 2);
}

// ============ Функции ============

TEST(AlgebraicComplex, NormWorks)
{
    Algebraic z(3, 4);

    EXPECT_DOUBLE_EQ(z.norm(), 25);
}

TEST(AlgebraicComplex, AbsWorks)
{
    Algebraic z(3, 4);

    EXPECT_DOUBLE_EQ(z.abs(), 5);
}

TEST(AlgebraicComplex, ArgWorks)
{
    Algebraic z(0, 1);

    EXPECT_NEAR(z.arg(), M_PI / 2, 1e-6);
}

TEST(AlgebraicComplex, ConjugateWorks)
{
    Algebraic z(3, -4);

    Algebraic c = z.conjugate();

    EXPECT_DOUBLE_EQ(c.real(), 3);
    EXPECT_DOUBLE_EQ(c.imaginary(), 4);
}

// ============ Show() ============

TEST(AlgebraicComplex, ShowVariousCases)
{
    Algebraic z1(0, 0);
    EXPECT_EQ(z1.show(), "0");

    Algebraic z2(5, 0);
    EXPECT_EQ(z2.show(), "5");

    Algebraic z2n(-5, 0);
    EXPECT_EQ(z2n.show(), "-5");

    Algebraic z3(0, 2);
    EXPECT_EQ(z3.show(), "2i");

    Algebraic z3n(0, -2);
    EXPECT_EQ(z3n.show(), "-2i");

    Algebraic z3i(0, 1);
    EXPECT_EQ(z3i.show(), "i");

    Algebraic z3in(0, -1);
    EXPECT_EQ(z3in.show(), "-i");

    Algebraic z4(3, 4);
    EXPECT_EQ(z4.show(), "3 + 4i");

    Algebraic z5(3, -4);
    EXPECT_EQ(z5.show(), "3 - 4i");

    Algebraic z6(-3, 4);
    EXPECT_EQ(z6.show(), "-3 + 4i");

    Algebraic z7(-3, -4);
    EXPECT_EQ(z7.show(), "-3 - 4i");

    Algebraic z8(3, 1);
    EXPECT_EQ(z8.show(), "3 + i");

    Algebraic z9(3, -1);
    EXPECT_EQ(z9.show(), "3 - i");
}

TEST(AlgebraicComplex, ShowPureImaginaryUnit)
{
    Algebraic z1(0, 1);
    EXPECT_EQ(z1.show(), "i");

    Algebraic z2(0, -1);
    EXPECT_EQ(z2.show(), "-i");
}

// ============ Исключения ============

TEST(AlgebraicComplex, DivisionByZeroComplexThrows)
{
    Algebraic a(1, 2);
    Algebraic zero(0, 0);

    EXPECT_THROW(a / zero, std::runtime_error);
}

TEST(AlgebraicComplex, DivisionByZeroScalarThrows)
{
    Algebraic a(1, 2);

    EXPECT_THROW(a / 0.0, std::runtime_error);
}
