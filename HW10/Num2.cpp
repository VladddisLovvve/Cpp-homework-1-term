#include <iostream>
#include <vector>


template <typename Type, typename ... Types>
Type* ptr(Types ... args) { return new Type(args...); }

int main()
{
	auto* point = ptr < std::vector < double > > (3.141592, 2.721828);
	std::cout << typeid(point).name() << "\n\n";
	std::cout << typeid(*point).name() << "\n\n";
	delete point;

	return 0;
}
