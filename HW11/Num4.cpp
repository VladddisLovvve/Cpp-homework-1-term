#include <iostream>
#include <type_traits>


template < bool Condition, typename T = void >
struct enable_if {};

template < typename T >
struct enable_if < true, typename T > 
{ using type = T; };

template < bool Condition, typename T >
using enable_if_t = typename enable_if < Condition, T >;

