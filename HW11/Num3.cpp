#include <iostream>



//is_function
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
inline constexpr bool is_function_v = is_function < RT > ::value;



//is_array
template < typename T >
struct is_array : std::false_type {};

template < typename T, std::size_t N >
struct is_array < T[N] > : std::true_type
{
    using type = T;
    static constexpr std::size_t size = N;
};

template < typename T >
struct is_array < T[] > : std::true_type
{
    using type = T;
    static constexpr std::size_t size = 0;
};

template < typename T >
inline constexpr bool is_array_v = is_array < T > ::value;




//if_then_else
template < bool Condition, typename True_Type, typename False_Type >
struct if_then_else
{
    using type = True_Type;
};

template < typename True_Type, typename False_Type >
struct if_then_else < false, True_Type, False_Type >
{
    using type = False_Type;
};

template < bool Condition, typename TT, typename FT >
using if_then_else_t = typename if_then_else < Condition, TT, FT >::type;



//remove_reference
template < typename T >
struct remove_reference
{
    using type = T;
};

template < typename T >
struct remove_reference < T& >
{
    using type = T;
};

template < typename T >
struct remove_reference < T&& >
{
    using type = T;
};
template < typename T >
using remove_reference_t = typename remove_reference < T > ::type;



//add_pointer
template < typename T >
struct add_pointer
{
    using type = T*;
};

template < typename T >
using add_pointer_t = typename add_poiner < T > ::type;



//remove_extent
template < class T >
struct remove_extent
{
    using type = T;
};

template < class T >
struct remove_extent < T[] >
{
    using type = T;
};

template < class T, std::size_t N >
struct remove_extent < T[N] >
{
    using type = T;
};

template< class T >
using remove_extent_t = typename remove_extent < T > ::type;



//наконец, decay
template< typename T1 >
struct decay
{
private:
    using T2 = remove_reference_t < T1 >;
public:
    using type = if_then_else_t < is_array_v < T2 >, remove_extent_t < T2 >, if_then_else_t
        < is_function_v < T2 >, add_pointer < T2 >, remove_extent_t < T2 > > >;
};
using decay_t = typename decay < T > ::type
