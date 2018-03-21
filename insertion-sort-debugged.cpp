//insertion sort can be from O.n-1 to O.n^2 (max) number of comparisons, depending on the disorder of the list
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

template <typename eType>
void print(eType[], int);

template <typename eType>
void insertionSort(eType[], int);

int main() {
	int intList[100];
	int num;
	for (int i = 0; i < 100; i++) {
		num = (rand() + time(0)) % 10000;
		intList[i] = num;
	}
	cout << "intList before sorting:\n";
	print(intList, 100);
	cout << "\n\n";
	insertionSort(intList, 100);
	cout << "intList after selection sort:\n";
	print(intList, 100);
	cout << endl;
	system("PAUSE");
	return 0;
}

template <typename eType>
void print(eType list[], int length) {
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
void insertionSort(eType list[], int length) {
	for (int firstOrder = 1; firstOrder < length; firstOrder++) {
		if (list[firstOrder] < list[firstOrder - 1]) {
			eType temp = list[firstOrder]; //copies first out of order into temp
			int location = firstOrder; //initializes location to first out of order
			do {
				list[location] = list[location - 1]; //shifts all places down to accomodate value.
				location--; 
			} while ((location > 0) && (list[location - 1] > temp));
			list[location] = temp; //copy temp into list location
		}
	}
}