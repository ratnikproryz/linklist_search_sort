#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void reset(int arr[], int root[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = root[i];
	}
	cout << "------------------\n\n";
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

void interchangeSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
		cout << "i= " << i << endl;
		printArray(arr, n);
	}
}

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(&arr[j], &arr[j - 1]);
			}
		}
		cout << "i= " << i << endl;
		printArray(arr, n);
	}
}
void insertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && temp < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
		cout << "i= " << i << endl;
		printArray(arr, n);
	}
}
void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = arr[i];
		int index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < min)
			{
				index = j;
				min = arr[j];
			}
		}
		swap(&arr[i], &arr[index]);
		cout << "i= " << i << endl;
		printArray(arr, n);
	}
}

int main()
{
	int root[] = {4, 9, 3, 6, 11, 2, 32, 6};
	int arr[] = {4, 9, 3, 6, 11, 2, 32, 6};
	int length = sizeof(arr) / sizeof(int);
	printArray(arr, length);

	cout << "Quick Sort\n";
	quickSort(arr, 0, length - 1);
	printArray(arr, length);
	reset(arr, root, length);

	cout<<"Interchange Sort\n";
	interchangeSort(arr,length);
	reset(arr, root, length);

	cout << "Bubble Sort\n";
	bubbleSort(arr, length);
	reset(arr, root, length);

	cout << "Insertion Sort\n";
	insertionSort(arr, length);
	reset(arr, root, length);

	cout << "Selection Sort\n";
	selectionSort(arr, length);
	reset(arr, root, length);

	return 0;
}