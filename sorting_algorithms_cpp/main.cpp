#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <string>
using namespace std;

const int max = 1000;
int comparison = 0;
int swapping = 0;


void swap(int A[], int first, int last)
{
	int temp = A[first];
	A[first] = A[last];
	A[last] = temp;
}

void insertion(int array[], int num)
{
	int i, j;
	bool inorder;

	for (i = 1; i < num; i++)
	{
		inorder = false;
		j = i;

		while (j != 0 && !inorder)
		{
			comparison++;
			if (array[j] < array[j - 1])
			{
				swapping++;
				swap(array, j, j - 1);
				j--;
			}
			else
				inorder = true;
		}
	}
}

void selection(int array[], int n)
{
	int temp, i, min, j;

	for (i = 0; i < n - 1; i++)
	{
		min = i;

		for (j = i + 1; j < n; j++)
		{
			comparison++;
			if (array[j] < array[min])
				min = j;
		}

		swapping++;
		swap(array, min, i);
	}
}

void merge(int A[], int lf, int ll, int rf, int rl)
{
	int temp[max];
	int j = lf;
	int saveIndex = lf;

	while (lf <= lf && rf <= rl)
	{
		comparison++;
		if (A[lf] < A[rf])
			temp[j++] = A[rf++];
		else
			temp[j++] = A[rf++];
	}

	while (rf <= rl)
	{
		comparison++;
		temp[j++] = A[rf++];
	}


	while (lf <= ll)
	{
		comparison++;
		temp[j++] = A[lf++];
	}

	for (int i = saveIndex; i <= rl; i++)
		A[i] = temp[i];

}

void mergeSort(int A[], int first, int last)
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		mergeSort(A, first, middle);
		mergeSort(A, middle + 1, last);
		merge(A, first, middle, middle + 1, last);
	}
}

int split(int A[], int first, int last)
{
	int pivot = A[first];
	int small = first;
	int i;

	for (i = first + 1; i <= last; i++)
	{
		comparison++;
		if (A[i] < pivot)
		{
			small++;
			swapping++;
			swap(A, small, i);
		}
	}

	swapping++;
	swap(A, first, small);
	return small;
}

void quickSort(int A[], int first, int last)
{
	if (first < last)
	{
		int pivotPosition = split(A, first, last);
		quickSort(A, first, pivotPosition - 1);
		quickSort(A, pivotPosition + 1, last);
	}
}

void heapDown(int A[], int top, int bottom)
{
	int max = 2 * top + 1;
	int temp = A[top];

	while (max <= bottom)
	{
		comparison++;
		if (max < bottom)
			if (A[max] < A[max + 1])
				max = max + 1;

		comparison++;
		if (temp > A[max])
			break;
		else
		{
			swapping++;
			A[top] = A[max];
			top = max;
			max = 2 * top + 1;
		}

		A[top] = temp;
	}
}
void heapSort(int A[], int length)
{
	int i;

	for (int i = (length - 2) / 2; i >= 0; i--)
		heapDown(A, i, length - 1);

	for (i = length - 1; i > 0; i--)
	{
		swapping++;
		swap(A[0], A[i]);
		heapDown(A, 0, i);
	}
}

void bubbleSort(int A[], int length)
{
	int i = 1; int j;
	bool swapped = false;

	do
	{
		j = length - 1;

		while (j > i)
		{
			comparison++;
			if (A[j] < A[j - 1])
			{
				swapping++;
				swap(A, j, j - 1);
				swapped = true;
			}
			j--;
		}
		i++;
	} while (i < length-1 && swapped);
}

int main()
{
	int a[max];
	int i = 0;
	string line;
	char delim = ',';
	int dataChoice;
	int sortingChoice;
	string dataset;

	
	cout << "\n1: Inverse100.txt" << "\n";
	cout << "2: Random100.txt" << "\n";
	cout << "3: Almost100.txt" << "\n";
	cout << "4: Inverse1000.txt" << "\n";
	cout << "5: Random1000.txt" << "\n";
	cout << "6: Almost1000.txt" << "\n";
	cout << "Enter the number of your choice of datasets: ";
	cin >> dataChoice;

	switch (dataChoice)
	{
	case 1:
		dataset = "Inverse100.txt";
		break;
	case 2:
		dataset = "Random100.txt";
		break;
	case 3:
		dataset = "Almost100.txt";
		break;
	case 4:
		dataset = "Inverse1000.txt";
		break;
	case 5:
		dataset = "Random1000.txt";
		break;
	case 6:
		dataset = "Almost1000.txt";
		break;
	default:
		cout << "\nYour input is invalid." << "\n";
	}

	cout << "\nYour choice of dataset: " << dataset << "\n";

	ifstream myfile(dataset);

	if (myfile.is_open())
	{
		while (getline(myfile, line, delim))
		{
			a[i] = atoi(line.c_str());
			i++;
		}

		myfile.close();
	}

	cout << "\nDataset contains: ";

	for (int j = 0; j < i; j++)
		cout << a[j] << ", ";
	cout << endl;

	cout << "\n1: Insertion Sort" << "\n";
	cout << "2: Selection Sort" << "\n";
	cout << "3: Merge Sort" << "\n";
	cout << "4: Quick Sort" << "\n";
	cout << "5: Heap Sort" << "\n";
	cout << "6: Bubble Sort" << "\n";
	cout << "Enter the number of your choice of sorting algorithm: ";
	cin >> sortingChoice;

	switch (sortingChoice)
	{
	case 1:
		cout << "\nYour choice of sorting algorithm: Insetion Sort" << endl;
		insertion(a, i);
		cout << "The number of comparison made in insertionSort: " << comparison << "\n";
		cout << "The number of swap made in insertionSort: " << swapping << "\n";
		break;
	case 2:
		cout << "\nYour choice of sorting algorithm: Selection Sort" << endl;
		selection(a, i);
		cout << "The number of comparison made in selectionSort: " << comparison << "\n";
		cout << "The number of swap made in selectionSort: " << swapping << "\n";
		break;
	case 3:
		cout << "\nYour choice of sorting algorithm: Merge Sort" << endl;
		mergeSort(a, 0, i - 1);
		cout << "The number of comparison made in mergeSort: " << comparison << "\n";
		cout << "The number of swap made in mergeSort: " << swapping << "\n";
		break;
	case 4:
		cout << "\nYour choice of sorting algorithm: Quick Sort" << endl;
		quickSort(a, 0, i - 1);
		cout << "The number of comparison made in quickSort: " << comparison << "\n";
		cout << "The number of swap made in quickSort: " << swapping << "\n";
		break;
	case 5:
		cout << "\nYour choice of sorting algorithm: Heap Sort" << endl;
		heapSort(a, i);
		cout << "The number of comparison made in heapSort: " << comparison << "\n";
		cout << "The number of swap made in heapSort: " << swapping << "\n";
		break;
	case 6:
		cout << "\nYour choice of sorting algorithm: Bubble Sort" << endl;
		bubbleSort(a, i);
		cout << "The number of comparison made in bubbleSort: " << comparison << "\n";
		cout << "The number of swap made in bubbleSort: " << swapping << "\n";
		break;
	default:
		cout << "Your input is invalid." << "\n";
	}

	return 0;
}