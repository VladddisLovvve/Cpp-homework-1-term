#include <iostream>
#include <type_traits>

template < bool c, typename T >
struct enable_if {};

template < typename T >
struct enable_if < true, typename T > 
{ using type = T; };

template < bool c, typename T >
using enable_if_t = typename enable_if < c, T >;
