#pragma once
#include <iostream>
#include <string>
#include <numeric>

class Fractions
{
private:
	int m_numerator;
	int m_denominator;
public:
	//Fractions() : m_numerator(0), m_denominator(1) {}

	//Fractions(int num, int den = 1) : m_numerator(num), m_denominator(den) 
	//{
	//	if (den == 0)
	//	{
	//		std::cerr << "Zero denominator";
	//	}
	//}

	Fractions(const Fractions &) = default;

	~Fractions();

	int get_numerator() { return m_numerator; }
	int get_denominator() { return m_denominator; }

	void reduction();

	operator double();

	friend std::ostream& operator<< (std::ostream& out, const Fractions& fraction); /* перегрузку ввода и вывода реализуем через дружественные функции, т.к. левый операнд не является эземпляром класса Fractions*/
	friend std::istream& operator>> (std::istream& in, Fractions& fraction);

	Fractions& operator+= (const Fractions& other); /*левый операнд изменяется, используем перегрузку через методы класса*/
	Fractions& operator-= (const Fractions& other);
	Fractions& operator*= (const Fractions& other);
	Fractions& operator/= (const Fractions& other);

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

Fractions operator+ (const Fractions& lhs, const Fractions& rhs); /*левый операнд не изменяется, используем перегрузку через (не)дружественные функции*/
Fractions operator- (const Fractions& lhs, const Fractions& rhs);
Fractions operator* (const Fractions& lhs, const Fractions& rhs);
Fractions operator/(const Fractions& lhs, const Fractions& rhs);
