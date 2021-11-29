// В качестве такой сортировки (сложностью O(nlogn)) подходит быстрая сортировка quick sort

#include <iostream>
#include <vector>

template < typename T, typename F >
void quick_sort(T* arr, int left, int right, F compare)
{
	if (right - left < 1) { return };

	int k = left;

	for (auto i = left; i < right; i++)
	{
		if compare(arr[i], arr[right])
		{
			std::swap(arr[i], arr[k]);
			k++;
		}
	}
	std::swap(arr[k], arr[right]);
	quick_sort(arr, left, k - 1, compare);
	quick_sort(arr, k + 1, right, compare);
}


template< typename T, std::size_t N, typename F > // статический массив
void sort(T (&arr) [N], F compare)
{
	quick_sort(arr, 0, N - 1, F compare);
}

template < typename T, typename F  > // динамический массив
void sort(T* arr, std::size_t size, F compare)
{
	quick_sort(arr, 0, size - 1, F compare);
}
