#include <iostream>
#include <type_traits>


template < typename RT, typename ... A >
struct is_function  : std::false_type {};

template < typename RT, typename ... A >
struct is_function < RT(A...) > : std::true_type {};

template < typename RT, typename ... A >
struct is_function < const RT(A...) > : std::true_type {};

template < typename RT, typename ... A >
struct is_function < RT(A...) & > : std::true_type {};

template < typename RT, typename ... A >
struct is_function < RT(A...) && > : std::true_type {};


template < typename RT, typename ... A >
using is_function_v = typename is_function < RT(A...) > ::value



int main()
{
	std::cout << is_function_v < int(bool) > << std::endl;
	std::cout << is_function_v < double(int) > << std::endl;
	return 0;
}
