//selection sort analysis - generally not good for larger sets of data, does O.n^2 comparisons, O.n data moves but if data movement is expensive and comparison is not may be a better choice than other algorithms
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

template <typename eType>
void print(const eType[], int);

template <typename eType>
int minLocation(eType[], int, int);

template <typename eType>
void swap(eType[], int, int);

template <typename eType>
void selectionSort(eType[], int);

int main() {
	int intList[100];
	int num;
	for (int i = 0; i < 100; i++) {
		num = (rand() + time(0)) % 10000;
		intList[i] = num;
	}
	cout << "intList before sorting:" << endl;
	print(intList, 100);
	cout << "\n\n";
	selectionSort(intList, 100);
	cout << "intList after selection sort:" << endl;
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
int minLocation(eType list[], int first, int last) {
	int loc, minIndex;
	minIndex = first;
	for (loc = first + 1; loc <= last; loc++) {
		if (list[loc] < list[minIndex]) {
			minIndex = loc;
		}
	}
	return minIndex;
}

template <typename eType>
void swap(eType list[], int first, int second) {
	eType temp = list[first];
	list[first] = list[second];
	list[second] = temp;
}

template <typename eType>
void selectionSort(eType list[], int length) {
	int loc, minIndex;
	for (loc = 0; loc < length; loc++) {
		minIndex = minLocation(list, loc, length - 1);
		swap(list, loc, minIndex);
	}
}