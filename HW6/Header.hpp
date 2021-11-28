#pragma once
#include <iostream>
#include <string>
#include <numeric>

class Fractions
{
private:
	int m_numerator;
	std::size_t m_denominator;
public:
	Fractions() : m_numerator(0), m_denominator(1) {}

	Fractions(int num, unsigned den = 1) : m_numerator(num), m_denominator(den) 
	{
		if (den == 0)
		{
			std::cerr << "Zero denominator";
		}
	}
	~Fractions();

	int get_numerator() { return m_numerator; }
	unsigned get_dedominator() { return m_denominator; }

	void reduction();

	double converting();

	friend std::ostream& operator<< (std::ostream& stream, const Fractions& fraction); /* перегрузку ввода и вывода реализуем через дружественные функции, т.к. левый операнд не является эземпляром класса Fractions*/
	friend std::istream& operator>> (std::istream& stream, Fractions& fraction);

	Fractions& operator+= (const Fractions& other); /*левый операнд изменяется, используем перегрузку через методы класса*/
	Fractions& operator-= (const Fractions& other);
	Fractions& operator*= (const Fractions& other);
	Fractions& operator/= (const Fractions& other);

	friend Fractions operator+(const Fractions& lhs, const Fractions& rhs); /*левый операнд не изменяется, используем перегрузку через дружественные функции*/
	friend Fractions operator-(const Fractions& lhs, const Fractions& rhs);
	friend Fractions operator*(const Fractions& lhs, const Fractions& rhs);
	friend Fractions operator/(const Fractions& lhs, const Fractions& rhs);

	Fractions& operator++(); /*версии префикс*/
	Fractions& operator--();
	Fractions operator++(int); /*фиктивная переменная, версии постфикс*/
	Fractions operator--(int);

	friend bool operator==(const Fractions& lhs, const Fractions& rhs); /*левый операнд не изменяется, используем перегрузку дружественной функцией*/
	friend bool operator!=(const Fractions& lhs, const Fractions& rhs);
	friend bool operator>(const Fractions& lhs, const Fractions& rhs);
	friend bool operator>=(const Fractions& lhs, const Fractions& rhs);
	friend bool operator<(const Fractions& lhs, const Fractions& rhs);
	friend bool operator<=(const Fractions& lhs, const Fractions& rhs);
};

