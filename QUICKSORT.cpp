#include <iostream>
using namespace std;

//array of integers to hold values
int arr[20];
int cmp_count = 0; // number of comparasion
int mov_count = 0; // number of data movements
int n;

void input() {
	while (true)
	{
		cout << "Masukkan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}

	cout << "\n----------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n----------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
//swaps the element at index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)									// Langkah 1
		return;

	//partition the list into two parts;
	//one containing elements less that or equal to pivot
	//outher containing elements greather than pivot

	pivot = arr[low];								// Langkah 2

	i = low + 1;									// Langkah 3
	j = high;										// Langkah 4


	while (i <= j)									// Langkah 10
	{
		//search for an element greater than pivot
		while ((arr[i] <= pivot) && (i <= high))	// Langkah 5
		{
			i++;									// Langkah 6
			cmp_count++;
		}
		cmp_count++;
		//search for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low))		// Langkah 7
		{
			j--;									// Langkah 8
			cmp_count++;
		}
		cmp_count++;

		// Langkah 9
		if (i < j) // if the greater element is on the left of the element
		{
			//swap the element at index i whit the element at index j
			swap(i, j);
			mov_count++;
		}
	}
	//j now containt the index of the last element in the sorted list
	if (low < j)									// Langkah 11
	{
		// move the pivot to its correct position in the list
		swap(low, j);
		mov_count++;
	}
	//sort the list on the left of pivot using quick sort
	q_short(low, j - 1);							// Langkah 12

	//sort the list on the right of pivot using quick sort 
	q_short(j + 1, high);							// Langkah 13


}


void display() {
	cout << "\n-----------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "\n-----------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "";
	}

	cout << "\n\nNumber of comparasions : " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}


int main()
{

	input();
	//sort the array using quick sort
	q_short(0, n - 1);
	display();
	system("pause");

	return 0;
}