#include <iostream>



//true_type и false_type
template < typename T, T v >
struct integral_constant {
    static constexpr T value = v;

    using value_type = T;
    using type = integral_constant;

    constexpr operator value_type() const 
    { return value; }

    constexpr value_type operator()() const 
    { return value; }
};

template <bool v>
using bool_constant = integral_constant < bool, v >;

using true_type = bool_constant < true >;
using false_type = bool_constant < false >;



//st_function
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


template < typename RT >
inline constexpr bool is_function_v = is_function < RT > ::value;



int main()
{
	std::cout << is_function_v < int(bool) > << std::endl;
	std::cout << is_function_v < double(int) > << std::endl;
	return 0;
}
