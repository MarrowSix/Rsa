#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// prime number p, q;
int p, q;
// t save (p-1) * (q-1)
int t;
// n save p*q
int n;
// possible variable of e and d
int e[100], d[100];

// message
string msg, m;

// calculator x and y of "ax + by = 1"
int gcd(int a, int b, int *x, int *y)
{
	if (b==0) {
		*x = 1;
		*y = 0;
		return a;
	} else {
		int r = gcd(b, a%b, x, y);
		int t = *x;
		*x = *y;
		*y = t - (a/b) * (*y);
		return r;
	}
}

bool isprime(int num)
{
	bool flag = true;
	for (int i=2; i<sqrt(double(num)); i++) {
		if (num % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

void calce()
{
	int k = 0;

	for (int j=2; j<t; j++) {
		if (t % j == 0) {
			continue;
		}
		bool flag = prime(j);
	}

}

int main(int argc, char *argv[])
{
	cout << "Input the prime number p: ";
	cin >> p;
	if (!isprime(p)) {
		cout << p << " isn't a prime number" << endl;
		exit(1);
	}

	cout << "Input the prime number q: ";
	cin >> q;
	if (!isprime(q)) {
		cout << q <<" isn't a prime number" << endl;
		exit(1);
	}

	cout << "Input the message: " << endl;
	cin >> msg;
	m = msg;

	n = p*q;
	t = (p-1) * (q-1);

	return 0;
}
