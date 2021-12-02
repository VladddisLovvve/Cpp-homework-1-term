#include <iostream>
#include <type_traits>


template < typename RT, typename ... A >
struct is_function : std::false_type {};

template < typename RT, typename ... A >
struct is_function < RT(A...) > : std::true_type {};

template < typename RT, typename ... A >
struct is_function < const RT(A...) > : std::true_type {};

template < typename RT, typename ... A >
struct is_function < RT(A...)& > : std::true_type {};

template < typename RT, typename ... A >
struct is_function < RT(A...)&& > : std::true_type {};


template < typename RT, typename ... A >
inline constexpr bool is_function_v = is_function < RT, typename ... A > ::value; // почему это не работает с typename ... A???? Без него код компилируется



int main()
{
	std::cout << is_function_v < int(bool) > << std::endl;
	std::cout << is_function_v < double(int) > << std::endl;
	return 0;
}
