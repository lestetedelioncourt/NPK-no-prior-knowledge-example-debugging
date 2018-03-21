#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

template <typename eType>
void bubbleSort(eType[], int);

template <typename eType>
void print(eType[], int);

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
	bubbleSort(intList, 100);
	cout << "intList after bubble sort:" << endl;
	print(intList, 100);
	cout << endl;
	system("PAUSE");
	return 0;
}

template <typename eType>
void bubbleSort(eType list[], int length) {
	for (int i = 1; i < length; i++) {
		for (int index = 0; index < length - i; index++) {
			if (list[index] > list[index + 1]){
				eType temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
		}
	}
}

//my earlier version of sorting algorithm
/*for (int i = 1; i < 100; i++) {
	for (int a = 0; a < i; a++) {
		if (list[i] < list[a]) {
			temp = list[i];
			for (int b = i; b > a; b--) {
				list[b] = list[b - 1];
			}
			list[a] = temp;
			break;
		}
	}
}*/

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