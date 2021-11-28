#include <iostream>
#include <vector>

class Example
{
private:

	int* m_data; 
	std::size_t  m_length;
	std::vector <int> m_vector;

public:

	Example(); /*к-р по умолчанию*/
	
	Example(int x); /*Пользовательские к-ры*/

	Example(const int* data);

	Example(const int* data, unsigned length);

	Example(const std::vector <int>& vector);

	Example(const int* data, unsigned length, const std::vector <int>& vector);

	~Example(); /*Деструктор*/

	unsigned size_of_vector() { return m_vector.size(); }; /*функции-члены (getter-ы)*/

	unsigned size_of_data() { return m_length; };

	const int* get_m_data() { return m_data; };

	std::vector <int> get_m_vector() { return m_vector; };

	Example& operator= (const Example& other); /*операторы =*/

	Example& operator= (Example&& other);

	Example(const Example& other); /*конструктор копирования(copy) экземпляра класса*/

	Example(Example&& other); /*конструктор перемещения(move) экземпляра класса*/

	
};

Example::Example() : m_length(0), m_data(nullptr), m_vector({}) {}

Example::Example(int x) : m_length(1), m_vector({})
{
	m_data = new int[1];
	m_data[0] = x;
}

Example::Example(const int* data) : m_length(1), m_vector({})
{
	m_data = new int[1];
	m_data[0] = data[0];
}

Example::Example(const int* data, unsigned length) : 
	m_length(length), m_vector({})
{
	m_data = new int[length];
	for (auto i = 0U; i <= length; i++)
	{
		m_data[i] = data[i];
	}
}

Example::Example(const std::vector <int>& vector) : 
	m_length(0), m_data(nullptr), m_vector(vector) {}

Example::Example(const int* data, unsigned length, const std::vector <int>& vector) :
	m_length(length), m_vector(vector)
{
	m_data = new int[length];
	for (auto i = 0U; i <= length; i++)
	{
		m_data[i] = data[i];
	}
}

Example:: ~Example()
{
	delete[] m_data;
}

Example& Example::operator=(const Example& other)
{
	if (&other == this)
		return *this;
	m_vector = other.m_vector;
	m_length = other.m_length;
	delete[] m_data;
	m_data = new int[m_length];
	for (auto i = 0U; i <= m_length; ++i)
	{
		m_data[i] = other.m_data[i];
	}
	return *this;
}

Example& Example::operator=(Example&& other)
{
	m_vector = std::move(other.m_vector);
	m_length = other.m_length;
	m_data = other.m_data;
	other.m_data = nullptr;
	other.m_length = 0;
	return *this;
}

Example::Example(const Example& other) : m_length(other.m_length), m_vector(other.m_vector)
{
	m_data = new int[m_length];
	for (auto i = 0U; i <= m_length; ++i)
	{
		m_data[i] = other.m_data[i];
	}
}


Example::Example(Example&& other) : m_length(other.m_length), m_data(other.m_data)
{
	m_vector = std::move(other.m_vector);

	other.m_data = nullptr;
	other.m_length = 0U;
}



int main()
{
	int x = 5;
	Example ex1(x);
	std::cout << "ex1 m_data first element is: " << ex1.get_m_data()[0];

	int* data = new int[4];
	for (auto i = 0U; i <= 3; i++)
	{
		data[i] = i;
	}
	Example ex2(data, 4);
	std::cout << "\nex2 m_data first element is: " << ex2.get_m_data()[0];
	std::cout << "\nex2 m_data length is: " << ex2.size_of_data();

	std::vector <int> vector = {1, 2, 3, 4};
	Example ex3(vector);
	std::cout << "\nex3 m_vector first element is: " << ex3.get_m_vector()[0];

	Example ex4(data, 4, vector);
	std::cout << "\nex4 m_data first element is: " << ex4.get_m_data()[0] <<
		"\nex4 m_vector first element is: " << ex4.get_m_vector()[0];
	
	//int* data2 = new int[4];
	//for (auto i = 0U; i <= 3, i++)
	//{
	//	data[i] = i + 3;
	//}
	//std::vector <int> vector2 = { 3, 2, 1, 0 };
	//Example ex5(data2, 4, vector2);
	Example ex5(ex4);
	std::cout << "\nex4 m_data first element after copy is: " << ex4.get_m_data()[0];
	std::cout << "\nex5 m_data first element after copy is: " << ex5.get_m_data()[0];
	Example ex6(std::move(ex3));
	std::cout << "\nex3 m_vector length after copy is: " << ex3.size_of_vector();
	std::cout << "\nex6 m_vector length after copy is: " << ex6.size_of_vector() << '\n';

	return 0;
}
