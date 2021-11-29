#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <string>


double square_root(const double& x)
{
	if (x < 0) throw std::domain_error("Value less than zero.");
	return pow(x, 0.5);
}

std::string my_time(int h, int m)
{
	if (h > 24 or h < 0 or m > 60 or m < 0) throw std::invalid_argument("Hours and minutes can't"
		"be less than 0 or more than 24 and 60.");
	return (std::to_string(h) + '.' + std::to_string(m));
}


void print_vector(const std::vector <int> &vector, int length)
{
	if (length != vector.size()) throw std::length_error("Length of vector isn't correct\n");
	for (auto i = 0U; i < length; i++)
	{
		std::cout << "Element number " << i << " is " << vector[i] << std::endl;
	}
}



void time_runns(const double& start_time, const double& end_time)
{
	double time = start_time;
	while (time < end_time)
	{
		time++;
	}
	throw std::runtime_error("Your time is gone...");
}


int main()
{
	try
	{
		double x;
		std::cout << "Enter your value to get square root: " << std::endl;;
		std::cin >> x;
		std::cout << square_root(x) << std::endl;

		int h, m;
		std::cout << "Enter hours and minutes: " << std::endl;;
		std::cin >> h >> m;
		std::cout << my_time(h, m) << std::endl;

		std::vector <int> v = { 1, 0, 2, 1 };
		unsigned l;
		std::cout << "Enter vector { 1, 0, 2, 1 } length" << std::endl;
		std::cin >> l;
		print_vector(v, l);
		std::cout << std::endl;

		time_runns(1, 1e8);
	}

	catch (std::domain_error& e)
	{
		std::cerr << e.what() << std::endl;
		terminate();
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
		terminate();
	}
	catch (std::length_error& e)
	{
		std::cerr << e.what() << std::endl;
		terminate();
	}
	catch (std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		terminate();
	}
	catch (...)
	{
		std::cerr << "Unknown error" << std::endl;
		abort();
	}

	return 0;
}
