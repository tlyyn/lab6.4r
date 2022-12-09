#define NOMINMAX
#include <iostream>
#include <Windows.h>
using namespace std;

void InitArray(int arr[], const int size, int i)
{
	if (i < size)
	{
		arr[i] = -10 + rand() % 21;
		InitArray(arr, size, i + 1);
		return;
	}
}

void PrintArray(const int* const arr, const int size, int i)
{
	if (i < size)
	{
		if (i == 0)
			cout << "{";
		cout << arr[i];
		if (i != size - 1)
			cout << ", ";
		else cout << "}" << endl;
		PrintArray(arr, size, i + 1);
		return;
	}
}

int CountElementArray(const int const arr[], const int size, const int A, const int B, int i)
{
	if (i < size)
	{
		if (arr[i] >= A && arr[i] <= B)
			return 1 + CountElementArray(arr, size, A, B, i + 1);
		else
			return CountElementArray(arr, size, A, B, i + 1);
	}
	else return 0;
}

void IndexMax(const int* arr, int size, int& max, int& index, int i)
{
	if (i < size)
	{
		if (arr[i] > max) {
			index = i;
			max = arr[i];
		}
		IndexMax(arr, size, max, index, i + 1);
		return;
	}
}

int SumElementArray(const int const arr[], const int size, int index)
{
	if (index < size)
	{
		return arr[index] + SumElementArray(arr, size, index + 1);
	}
	else return 0;
}

void FindIndexMin(int arr[], int size, int& min, int& index, int i)
{
	if (i < size)
	{
		if (abs(arr[i]) < abs(min)) {
			index = i;
			min = arr[i];
			FindIndexMin(arr, size, min, index, i + 1);
		}
		else
			return FindIndexMin(arr, size, min, index, i + 1);
	}
}

void SortArray(int arr[], const int size, int i)
{
	if (i < size)
	{
		int index = i, min = arr[i];
		FindIndexMin(arr, size, min, index, i);
		arr[index] = arr[i];
		arr[i] = min;
		SortArray(arr, size, i + 1);
		return;
	}

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));
	int n, A, B;
	cout << "n = "; cin >> n;
	cout << "A = "; cin >> A;
	cout << "B = "; cin >> B;
	int* arr = new int[n];
	InitArray(arr, n, 0);

	PrintArray(arr, n, 0);
	cout << "Кількість елементів масиву, що лежать в діапазоні від [" << A << " до " << B << "] = "
		<< CountElementArray(arr, n, A, B, 0) << endl;
	int index, max;
	IndexMax(arr, n, max, index, 0);
	if (index != -1)
		cout << "Суму елементів масиву, розташованих після максимального елементу [" << index << "] = "
		<< SumElementArray(arr, n, index + 1) << endl;
	SortArray(arr, n, 0);
	PrintArray(arr, n, 0);

	delete[] arr;
	arr = nullptr;
	return 0;
}
