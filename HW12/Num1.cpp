#include <iostream>


template < int n, int k > // C из n по k
struct binomial_coeficcient
{
	static int ans = binomial_coeficcient < n - 1, k > ::ans +
		binomial_coeficcient < n - 1, k - 1 > ::ans; // правило сложения биномиальных коэффициентов из теорвера
};

template < int n >
struct binomial_coeficcient  < n, 0 > // C из n по 0 = 1
{
	static int ans = 1;
};


template < int n >
struct binomial_coeficcient < n, n > // C из n по n = 1
{
	static int ans = 1;
};
