#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
#include <string>


double square_root(double x)
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


void print_vector_element(const std::vector <int> &vector, unsigned pos)
{
	if (pos != vector.size()) throw std::length_error("Length of vector isn't correct\n");
	std::cout << vector[pos] << std::endl;
}

void are_you_a_human(bool flag)
{
	if (flag != true) throw std::logic_error("WTF, who are you?!");
}

void change_char_in_string(std::string &str, char c, unsigned pos)
{
	if (pos > str.length()) throw std::out_of_range("Position isn't within the string");
	str.at(pos) = c;
}


void time_runs(const double& start_time, const double& end_time)
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
		unsigned pos;
		std::cout << "Enter the position" << std::endl;
		std::cin >> pos;
		print_vector_element(v, pos);
		
		bool flag;
		std::cout << "Are you a human? Print true or false";
		std::cin >> flag;
		are_you_a_human(flag);

		std::string str = "abcdefg";
		unsigned pos2;
		std::cout << "Enter the position";
		std::cin >> pos2;
		change_char_in_string(str, pos2);

		time_runs(1, 1e8);
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
	catch (std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
		terminate();
	}
	catch (std::logic_error& e)
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
