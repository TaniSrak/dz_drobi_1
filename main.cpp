#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

class Fraction
{
public:

	// Конструктор по умолчанию, создающий дробь 0/1
	Fraction() : numerator(0), denominator(1) {}

	// Конструктор с параметрами
	Fraction(long num, long den) : numerator(num), denominator(den)
	{
		if (denominator == 0)
		{
			throw std::invalid_argument("Знаменатель не может быть равен нулю!");
		}
	}

	//дроби
	int GetNumerator() const
	{
		return numerator;
	}
	int GetDenominator() const
	{
		return denominator;
	}
	bool isValid() const {//правильноть дроби
		return denominator != 0;
	}

		// Операторы математики для дробей
	Fraction operator+(const Fraction& other) const 
	{
		return Fraction(numerator * other.denominator + other.numerator * denominator,
			denominator * other.denominator);
	}

	Fraction operator-(const Fraction& other) const 
	{
		return Fraction(numerator * other.denominator - other.numerator * denominator,
			denominator * other.denominator);
	}

	Fraction operator*(const Fraction& other) const 
	{
		return Fraction(numerator * other.numerator, denominator * other.denominator);
	}

	Fraction operator/(const Fraction& other) const 
	{
		if (other.numerator == 0) 
		{
			throw std::runtime_error("Деление на ноль!");
		}
		return Fraction(numerator * other.denominator, denominator * other.numerator);
	}

	//операторы математики для целых чисел
	Fraction operator+(long value) const 
	{
		return Fraction(numerator + value * denominator, denominator);
	}

	Fraction operator-(long value) const 
	{
		return Fraction(numerator - value * denominator, denominator);
	}

	Fraction operator*(long value) const 
	{
		return Fraction(numerator * value, denominator);
	}

	Fraction operator/(long value) const 
	{
		if (value == 0) 
		{
			throw std::runtime_error("Деление на ноль!");
		}
		return Fraction(numerator, denominator * value);
	}

	 // Функция для представления дроби в виде действительного числа
	double toDouble() const {
		return static_cast<double>(numerator) / denominator;
	}

private:
	long numerator;
	long denominator;

	//делитель
	int gcd(int a, int b) const
	{
		if (a % b == 0) return b;
		if (b % a == 0) return a;
		if (a > b) return gcd(a % b, b);
		return gcd(a, b % a);
	}

	//для операторов математики приведение дроби
	int BringFraction(Fraction x)
	{
		int xNum = x.numerator;
		if (denominator != x.denominator)
		{
			int cd = denominator * x.denominator;
			xNum *= cd / x.denominator;
			numerator *= cd / denominator;

			denominator = cd;
		}
		return xNum;
	}


};

int main() {
	setlocale(LC_ALL, "Russian");
	int n;


	int a, b, c, d;
	std::cout << "Введите числитель и знаменатель первой дроби:\n";
	std::cin >> a >> b;
	std::cout << "Введите числитель и знаменатель второй дроби:\n";
	std::cin >> c >> d;
	Fraction f1(a, b);
	Fraction f2(c, d);

	std::cout << "f1 + f2 = " << (f1 + f2).GetNumerator() << "/" << (f1 + f2).GetDenominator() << std::endl;
	std::cout << "f1 - f2 = " << (f1 - f2).GetNumerator() << "/" << (f1 - f2).GetDenominator() << std::endl;
	std::cout << "f1 * f2 = " << (f1 * f2).GetNumerator() << "/" << (f1 * f2).GetDenominator() << std::endl;
	std::cout << "f1 / f2 = " << (f1 / f2).GetNumerator() << "/" << (f1 / f2).GetDenominator() << std::endl;

	std::cout << "f1 + 2 = " << (f1 + 2).GetNumerator() << "/" << (f1 + 2).GetDenominator() << std::endl;
	std::cout << "f1 - 2 = " << (f1 - 2).GetNumerator() << "/" << (f1 - 2).GetDenominator() << std::endl;
	std::cout << "f1 * 2 = " << (f1 * 2).GetNumerator() << "/" << (f1 * 2).GetDenominator() << std::endl;
	std::cout << "f1 / 2 = " << (f1 / 2).GetNumerator() << "/" << (f1 / 2).GetDenominator() << std::endl;

	std::cout << "f1 as double: " << f1.toDouble() << std::endl;


	return 0;
}