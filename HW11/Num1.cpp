#include <iostream>
#include <type_traits>


template < typename T, typename ... A >
struct is_function_v  : std::false_type {};

template < typename T, typename ... A >
struct is_function_v < T(A...) > : std::true_type {};

template < typename T, typename ... A >
struct is_function_v < const T(A...) > : std::true_type {};

template < typename T, typename ... A >
struct is_function_v < T(A...) & > : std::true_type {};

template < typename T, typename ... A >
struct is_function_v < T(A...) && > : std::true_type {};



int main()
{
	std::cout << is_function_v < int(bool) > ::value << std::endl;
	std::cout << is_function_v < double(int) > ::value << std::endl;
	return 0;
}
