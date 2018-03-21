//binary search can only be used on a sorted list, uses middle of array + greater/less than to determine the position of an array element. For a 1000 item array reduces average amount of search processing to find data from 500 items down to 11 items. 
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename eType>
int binarySearch(const eType list[], int loc, eType & item);

int main() {
	cin.exceptions(ios_base::failbit);
	const int len = 100;
	int list[len];

	for (int i = 0; i < len; i++) {
		list[i] = (rand() * time(0)) % 10000;
	}

	int temp;

	for (int i = 0; i < 100; i++) {
		cout << setw(5) << list[i];
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

	cout << "\n\n";

	
	//sort algorithm
	for (int i = 1; i < 100; i++) {
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
	}

	for (int i = 0; i < 100; i++) {
		cout << setw(5) << list[i];
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

	temp = 10000;

	do {
		try {
			cout << "Please enter the integer you wish to search for (0-9999): ";
			cin >> temp;
		}
		catch (exception e) {
			cout << "A valid integer was not entered\n";
			cin.clear();
			cin.ignore(100, '\n');
			temp = 10000;
		}
	} while ((temp < 0) || (temp > 9999));

	temp = binarySearch(list, len, temp);
	
	if (temp == -1) {
		cout << "Search item not found\n";
	}
	else {
		cout << "Item found at index position [" << temp << "]\n";
	}

	system("PAUSE");
	return 0;
}

 template <typename eType>
 int binarySearch(const eType list[], int length, eType &item) {
	 int mid, beg = 0, end = length -1;
	 bool found = false;
	 while ((beg <= end) &&(!found)) {
		 mid = (beg + end) / 2;
		 if (list[mid] == item) {
			 found = true;
		 }
		 else {
			 if (item < list[mid]) {
				 end = mid - 1;
			 }
			 else if (item > list[mid]) {
				 beg = mid + 1;
			 }
		 }
	 }

	 if (found) {
		 return mid;
	 }
	 else {
		 return -1;
	 }
 }