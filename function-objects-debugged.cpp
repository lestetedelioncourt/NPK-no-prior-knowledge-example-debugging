/*function objects - stored in functional header file, can be used more easily than standard functions - used in some type declarations, e.g.  greater<Type> used in declaring:	 
	set<int, greater<int> >   or	multiset<int, greater<int> >

//plus<Type>//
plus<int> addNUm;
int sum = addNum(12, 35);

//minus<Type>//
minus<int> subtractNum;
int diff = subtractNum(12, 5);

//multiplies<Type>//
multiplies<int> prodNum;
int prod = prodNum(12, 35);

//divides<Type>//
divides<int> quoNum;
int div = quoNum(12, 5);

//modulus<Type>//
modulus<int> modNum;
int mod = modNum(12, 5);

//negate<Type>//
mult<int> prodNum;
int prod = prodNum(12, 35);

//equal_to<Type>//
equal_to<int> compnum;
bool isEqual = compNum(12, 35);

//not_equal_to<Type>//
not_equal_to<int> compNum;
bool notEqual = compNum(12, 35);

//greater<Type>//
greater<int> compNum;
bool isGreater = compNum(12, 35);

//greater_equal<Type>//
greater_equal<int> compNum;
bool isEqualGreater = compNum(12, 35);

//less<Type>//
less<int> compNum;
bool isLess = compNum(12, 35);

//less_equal<Type>//
mult<int> prodNum;
int prod = prodNum(12, 35);


*/

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <functional>

using namespace std;

int function1(plus<int>, int, int);

int main() {
	plus<int> addNum;
	int num = addNum(34, 56);
	cout << "num = " << num << endl;

	plus<string> join;
	string str1 = "Sup ", str2 = "y'all";
	string str = join(str1, str2);
	cout << "str = " << str << endl;
	cout << "sum of 12 and 23 = " << function1(addNum, 12, 23) << endl;

	int list1[8] = { 1,2,3,4,5,6,7,8 };
	vector<int> intList(list1, list1 + 8);
	ostream_iterator<int> print1(cout, " ");
	cout << "intList = ";
	copy(intList.begin(), intList.end(), print1);
	cout << endl;

	int sum = accumulate(intList.begin(), intList.end(), 0);
	cout << "sum of elements of intList = " << sum << endl;

	int product = accumulate(intList.begin(), intList.end(), 0, multiplies<int>());
	cout << "product of elements of intList = " << product << endl;

	equal_to<int> compare;
	bool isEqual = compare(5, 6);
	cout << "isEqual = " << isEqual << endl;
	
	vector<int>::iterator iter1, iter2;
	
	greater<string> larger;
	if (larger(str1, str2)) {
		cout << str1 << " is greater than " << str2 << endl;
	}
	else {
		cout << str1 << " isn't greater than " << str2 << endl;
	}

	int temp[8] = { 2, 3, 4, 5, 1, 7, 8 , 9 };
	vector<int> vecList(temp, temp + 8);
	copy(vecList.begin(), vecList.end(), print1);
	cout << endl;

	iter1 = adjacent_find(vecList.begin(), vecList.end(), greater<int>());
	if (iter1 == vecList.end()) {
		cout << "The entire vector is sorted in ascending order\n";
	}
	else {
		cout << "The last element in the non-decreasing subsequence is at: " << distance(vecList.begin(), iter1) << '\n';
	}

	iter1 = adjacent_find(vecList.begin(), vecList.end(), greater<int>());
	iter2 = iter1 + 1;
	cout << "First set of out of order elements = " << *iter1 << " " << *iter2 << endl;
	cout << "First set of out of order element position = " << vecList.end() - iter2 << endl;

	system("PAUSE");
	return 0;
}

int function1(plus<int> sum, int a, int b) {
	return sum(a, b);
}