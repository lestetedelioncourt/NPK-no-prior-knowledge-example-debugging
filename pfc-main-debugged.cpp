#include <iostream>
#include <iomanip>
#include <fstream>
#include "LinkedStackType.h"

using namespace std;

void test(linkedStackType<int>);
void evalExpression(ifstream&, ofstream&, linkedStackType<double>&, char&, bool&);
void evalOperator(ofstream&, linkedStackType<double>&, char&, bool&);
void discard(ifstream&, ofstream&, char&);
void print(ofstream&, linkedStackType<double>&, bool);

int main() {
	bool expressionOk;
	char ch;
	linkedStackType<double> stack;
	ifstream infile;
	ofstream outfile;
	infile.open("data.txt");
	outfile.open("results.txt");
	outfile << fixed << showpoint << setprecision(2);
	infile >> ch;
	while (infile) {
		stack.initialiseStack();
		expressionOk = true;
		outfile << ch;
		evalExpression(infile, outfile, stack, ch, expressionOk);
		print(outfile, stack, expressionOk);
		infile >> ch;
	}
	infile.close();
	outfile.close();

	system("PAUSE");
	return 0;
}

void evalExpression(ifstream& in, ofstream& out, linkedStackType<double>& stack, char& ch, bool& isOk) {
	double num;
	while (ch != '=') {
		switch (ch) {
		case '#': 
			in >> num;
			out << num << " ";
			stack.push(num);
			break;
		default:
			evalOperator(out, stack, ch, isOk);
		}
		if (isOk) {
			in >> ch;
			out << ch;
			if (ch != '#') {
				out << " ";
			}

		}
		else {
			discard(in, out, ch);
		}
	}
}

void evalOperator(ofstream& out, linkedStackType<double>& stack, char& ch, bool& isOk) {
	double op1, op2;
	if (stack.isEmptyStack()) {
		out << " (Not enough operands)";
		isOk = false;
	}
	else {
		op2 = stack.top();
		stack.pop();
		if (stack.isEmptyStack()) {
			out << " (Not enough operands)";
			isOk = false;
		}
		else {
			op1 = stack.top();
			stack.pop();
			switch (ch) {
			case '+': stack.push(op1 + op2); break;
			case '-': stack.push(op1 - op2); break;
			case '*': stack.push(op1 * op2); break;
			case '/': if (op2 != 0) stack.push(op1 / op2); else { out << " (Division by zero)"; isOk = false;} break;
			default: out << " (Illegal operator)"; isOk = false;
			}
		}
	}
}

void discard(ifstream& in, ofstream& out, char& ch) {
	while (ch != '=') {
		in.get(ch);
		out << ch;
	}
}

void print(ofstream& out, linkedStackType<double>& stack, bool isOk) {
	double result;
	if (isOk) {
		if (!stack.isEmptyStack()) {
			result = stack.top();
			stack.pop();
			if (stack.isEmptyStack()) {
				out << result << endl;
			}
			else {
				out << " (Too many operands)" << endl;
			}
		}
		else {
			out << " (Error in expression)" << endl;
		}
	}
	else {
		out << " (Error in expression)" << endl;
	}
	out << "____________________________________\n\n";
}

void test(linkedStackType<int> copystack) {
	cout << "Testing copy constructor... ";
	while (!copystack.isEmptyStack()) {
		cout << copystack.top() << " ";
		copystack.pop();
	}
}