#include <iostream>

constexpr double E(unsigned s) // s - относительная погрешность измерения s в процентах
{
	double ans = 0; 
	int k = 1; int j = 0;
	while (100 / k > s)
	{ ans += 1.0 / k; j++; k *= j; }
	return ans;
}


int main()
{
	std::cout << E(30) << '\n' << E(10) << '\n' << E(1);
}
