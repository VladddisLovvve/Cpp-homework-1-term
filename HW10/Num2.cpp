#include <iostream>
#include <vector>


template <typename Type, typename ... Types>
Type* ptr(Types ... args) { return new Type(args...); }

int main()
{
	auto* pointer = ptr < std::vector < double > > (3.141592, 2.721828);
	std::cout << typeid(pointer).name() << "\n\n";
	std::cout << typeid(*pointer).name() << "\n\n";
	delete pointer;

	return 0;
}
