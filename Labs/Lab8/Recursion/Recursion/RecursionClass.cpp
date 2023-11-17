
//Calculate a factorial iteratively and recursevely
#include<iostream>
using namespace std;
long fact(long n);
long fact2(long n);
int fib(int n);

int main() {
	int input;
    cout << "Enter a number: ";
    cin >> input;
    cout << "The fibonacci sequence of " << input << " is " << fib(input);

}

int fib(int n) {
	if (n <= 1)return n;
	//if (n == 0)return 0;
	return fib(n - 1) + fib(n - 2);
}

long fact2(long n) {
	if (n == 1)return 1;//termination
	return n * fact2(n - 1);//recursion
}

long fact(long n) {
	long product = 1;
	for (long i = n; i > 0; i--) {
		product *= i;
	}
	return product;
}
