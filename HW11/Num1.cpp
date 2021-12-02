#include <iostream>
#include <type_traits>


template < typename RT, typename ... A >
struct is_function_v  : std::false_type {};

template < typename RT, typename ... A >
struct is_function_v < RT(A...) > : std::true_type {};

template < typename RT, typename ... A >
struct is_function_v < const RT(A...) > : std::true_type {};

template < typename RT, typename ... A >
struct is_function_v < RT(A...) & > : std::true_type {};

template < typename RT, typename ... A >
struct is_function_v < RT(A...) && > : std::true_type {};



int main()
{
	std::cout << is_function_v < int(bool) > ::value << std::endl;
	std::cout << is_function_v < double(int) > ::value << std::endl;
	return 0;
}
