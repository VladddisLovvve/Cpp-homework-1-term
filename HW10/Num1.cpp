#include <iostream>
#include <vector>
#include <string>
#include <any>

/*Реализация с выражением свёртки*/
template <typename ... Types>
int sizeof_1(Types ... args)
{
	return (sizeof(args) + ...);
}

/*Реализация без выражения свёртки, с рекурсией*/
int sizeof_2()
{
	return 0;
}

template <typename Type, typename ... Types>
int sizeof_2(Type arg1, Types ... args)
{
	return sizeof(arg1) + sizeof_2(args...);
}



int main()
{
	std::cout << sizeof_1(1, 3.141592, "abcdef") << '\n';
	std::cout << sizeof_2(1, 3.141592, "abcdef");

	return 0;
}
