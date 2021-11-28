#include "Header.hpp"


void Fractions::reduction()
{
	int temp = std::gcd(m_numerator, m_denominator);
	m_numerator /= temp;
	m_denominator /= temp;
}

double Fractions::converting()
{
	return(m_numerator / m_denominator);
}

std::ostream& operator<< (std::ostream& out, const Fractions& fraction)
{
	out << fraction.m_numerator << "/" << fraction.m_denominator;
	return out;
}

std::istream& operator>> (std::istream& in, Fractions& fraction)
{
	in >> fraction.m_numerator;
	in >> fraction.m_denominator;

	if (fraction.m_denominator == 0)
	{
		fraction.m_denominator = 1;
		std::cerr << "Division by zero is unacceptable. Your denominator was transformed into 1.";
	}

	fraction.reduction();
	return in;
}

Fractions& Fractions::operator+= (const Fractions& other)
{
	unsigned temp = m_denominator;
	m_numerator = m_numerator * other.m_denominator + other.m_numerator * m_denominator;
	m_denominator *= other.m_denominator;
	
	(*this).reduction();
	return (*this);
}
Fractions& Fractions::operator-= (const Fractions& other)
{
	m_numerator = m_numerator * other.m_denominator - other.m_numerator * m_denominator;
	m_denominator *= other.m_denominator;	

	(*this).reduction();
	return *this;
}
Fractions& Fractions::operator*= (const Fractions& other)
{
	m_numerator *= other.m_numerator;
	m_denominator *= other.m_denominator;

	(*this).reduction();
	return *this;
}
Fractions& Fractions::operator/= (const Fractions& other)
{
	if (other.m_numerator == 0)
	{
		std::cerr << "Division by zero is unacceptable.";
		return *this;
	}

	m_numerator *= other.m_denominator;
	m_denominator *= other.m_numerator;

	(*this).reduction();
	return *this;
}

Fractions operator+ (const Fractions& lhs, const Fractions& rhs)
{
	Fractions summ;
	summ.m_numerator = lhs.m_numerator * rhs.m_denominator + rhs.m_numerator * lhs.m_denominator;
	summ.m_denominator = lhs.m_denominator * rhs.m_denominator;

	summ.reduction();
	return summ;
}
Fractions operator- (const Fractions& lhs, const Fractions& rhs)
{
	Fractions diff;
	diff.m_numerator = lhs.m_numerator * rhs.m_denominator - rhs.m_numerator * lhs.m_denominator;
	diff.m_denominator = lhs.m_denominator * rhs.m_denominator;
	
	diff.reduction();
	return diff;
}
Fractions operator* (const Fractions& lhs, const Fractions& rhs)
{
	Fractions mult;
	mult.m_numerator = lhs.m_numerator * rhs.m_numerator;
	mult.m_denominator = lhs.m_denominator * rhs.m_denominator;

	mult.reduction();
	return mult;
}
Fractions operator/ (const Fractions& lhs, const Fractions& rhs)
{
	if (rhs.m_denominator == 0)
	{
		std::cerr << "Division by zero is unacceptable.";
		return lhs;
	}

	Fractions div;
	div.m_numerator = lhs.m_numerator * rhs.m_denominator;
	div.m_denominator = lhs.m_denominator * rhs.m_numerator;

	div.reduction();
	return div;
}

Fractions& Fractions::operator++ () /*префикс*/
{
	(*this).m_numerator += m_denominator;

	(*this).reduction();
	return *this;
}

Fractions& Fractions::operator-- ()
{
	(*this).m_numerator -= m_denominator;

	(*this).reduction();
	return *this;
}

Fractions Fractions::operator++ (int) /*постфикс*/
{
	Fractions tmp = *this;
	(*this).m_numerator += m_denominator;

	(*this).reduction();
	return tmp;
}

Fractions Fractions::operator-- (int)
{
	Fractions tmp = *this;
	(*this).m_numerator -= m_denominator;

	(*this).reduction();
	return tmp;
}

bool operator== (const Fractions& lhs, const Fractions& rhs)
{
	if ((lhs - rhs).m_numerator != 0)
		return false;
	else
		return true;
}

bool operator!= (const Fractions& lhs, const Fractions& rhs)
{
	if ((lhs - rhs).m_numerator == 0)
		return false;
	else
		return true;
}

bool operator> (const Fractions& lhs, const Fractions& rhs)
{
	if ((lhs - rhs).m_numerator > 0)
		return true;
	else
		return false;
}

bool operator>= (const Fractions& lhs, const Fractions& rhs)
{
	if ((lhs - rhs).m_numerator >= 0)
		return true;
	else
		return false;
}

bool operator< (const Fractions& lhs, const Fractions& rhs)
{
	if ((lhs - rhs).m_numerator < 0)
		return true;
	else
		return false;
}

bool operator<= (const Fractions& lhs, const Fractions& rhs)
{
	if ((lhs - rhs).m_numerator <= 0)
		return true;
	else
		return false;
}
