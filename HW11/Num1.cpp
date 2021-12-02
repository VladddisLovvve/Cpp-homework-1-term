#include <iostream>
#include <typeinfo>


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

template < typename RT >
struct function_type 
{
	using type = RT;
};

template <typename RT>
using function_t = typename function_type < RT > ::type;

//using function_t = typeid(typename function_type < RT > ::type).name(); - такая реализация почему-то не компилируется

void f() {}
double g() { return 1.0; }




int main()
{
	std::cout << is_function_v < int(bool) > << std::endl;
	std::cout << typeid(function_t < double(int) >).name() << std::endl; //реализовать шаблон с псевдонимом для того, чтобы не писать typeid, по какой-то причине не выходит.
	return 0;
}
