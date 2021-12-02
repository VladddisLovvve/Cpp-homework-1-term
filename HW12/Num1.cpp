#include <iostream>


template < int n, int k > // C из n по k
struct binomial_coeficcient
{
	static const int ans = binomial_coeficcient < n - 1, k > ::ans +
		binomial_coeficcient < n - 1, k - 1 > ::ans; // правило сложения биномиальных коэффициентов из теорвера
};

template < int n >
struct binomial_coeficcient  < n, 0 > // C из n по 0 = 1
{
	static const int ans = 1;
};


template < int n >
struct binomial_coeficcient < n, n > // C из n по n = 1
{
	static const int ans = 1;
};

template < int n, int k >
using C = int binomial_coeficcient < n, k > ::ans;

int main()
{
	std::cout << C < 5, 5 > << '\n' << C < 3, 0 >  << '\n' << C < 7, 3 >   // 35
		<< '\n' << C < 12, 7 >  ; // 792

	return 0;
}
