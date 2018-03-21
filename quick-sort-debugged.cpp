//average number of comparisons for quick sort is nlog2n, which makes it a quite efficient sort algorithm
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

template <typename eType>
void print(const eType[], int);

template <typename eType>
int partition(eType[], int, int);

template <typename eType>
void swap(eType[], int, int);

template <typename eType>
void recursiveQuick(eType[], int, int);

template <typename eType>
void quickSort(eType[], int);

int main() {
	int intList[100];
	int num;
	for (int i = 0; i < 100; i++) {
		num = rand() % 10000;
		intList[i] = num;
	}
	cout << "intList before sorting:\n";
	print(intList, 100);
	cout << "\n\n";
	quickSort(intList, 100);
	cout << "intList after quick sort:\n";
	print(intList, 100);
	cout << endl;
	system("PAUSE");
	return 0;
}

template <typename eType>
void print(const eType list[], int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		cout << setw(5) << list[i];
		count++;
		if (count % 10 == 0) {
			cout << endl;
		}
	}
}

template <typename eType>
int partition(eType list[], int first, int last) {
	eType pivot;
	int index, smallIndex;
	swap(list, first, (first + last) / 2);
	pivot = list[first];
	smallIndex = first;
	for (index = first + 1; index <= last; index++) {
		if (list[index] < pivot) {
			smallIndex++;
			swap(list, smallIndex, index);
		}
	}
	swap(list, first, smallIndex);
	return smallIndex;
}

template <typename eType>
void swap(eType list[], int first, int second) {
	eType temp = list[first];
	list[first] = list[second];
	list[second] = temp;
}

template <typename eType>
void recursiveQuick(eType list[], int first, int last) {
	int pivotLocation;
	if (first < last) {
		pivotLocation = partition(list, first, last);
		recursiveQuick(list, first, pivotLocation - 1);
		recursiveQuick(list, pivotLocation + 1, last);
	}
}

template <typename eType>
void quickSort(eType list[], int length) {
	recursiveQuick(list, 0, length - 1);
}