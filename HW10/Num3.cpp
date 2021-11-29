#include <iostream>

template <typename F, typename ... A>
 call(F function, A  ... args)
{
	function(args...);
}

void print(int x, double y)
{
	std::cout << "You have called function with x = " << x << " and y = " << y << std::endl;
}


int main()
{
	double x, y;
	std::cin >> x;
	std::cin >> y;

	call(print, x, y);

	return 0;
}
