#include <iostream>


template < int n >
struct Fib
{ static const int Fib < n - 1 > + Fib < n - 2 >; };


template < >
struct Fib < 1 >
{ static const int value = 1; };


template < >
struct Fib < 2 >
{ static const int value = 1; };

template < int n > 
int Fib_v = Fib < n > ::value;
