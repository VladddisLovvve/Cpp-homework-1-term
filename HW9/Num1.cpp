#include <iostream>

template < typename T >
void quick_sort(T* arr, int left, int right)
{
	if (right - left < 1) { return };

	int k = left;

	for (auto i = left; i < right; i++)
	{
		if arr[i] < arr[right]
		{
			std::swap(arr[i], arr[k]);
			k++;
		}
	}
	std::swap(arr[k], arr[right]);
	quick_sort(arr, left, k - 1);
	quick_sort(arr, k + 1, right);
}
