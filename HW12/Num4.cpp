template < int num, int k >
constexpr bool is_prime_loop() 
{
    return (k * k > num) ? true : (num % k == 0) ? false : is_prime_loop(num, k + 1);
}

template < int num >
constexpr bool is_prime()
{
	return is_prime_loop(num, 2);
}

template < int num >
constexpr int get_prime()
{ return get_prime_loop(num, 2); }


template < int num, int k >
constexpr int get_prime_loop()
{ return (num == 0) ? k : getPrimeLoop(num - 1, next_prime(k + 1)); }


template < int k >
constexpr int next_prime()
{
	return is_prime(k) ? k : next_prime(k + 1);
}



int main()
{
	std::cout << get_prime < 54 > << '\n' << get_prime < 38 > << '\n' << get_prime < 72 >; 
}
