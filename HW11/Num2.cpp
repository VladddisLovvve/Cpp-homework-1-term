#include <iostream>
#include <type_traits>

template < typename T >
struct add_const
{
	using type = const T;
};

template < typename T >
struct remove_const 
{
	using type = T;
};

template < typename T >
struct remove_const < const T & >
{
	using type = T;
};

template < typename T >
struct remove_const < const T && >
{
	using type = T;
};
