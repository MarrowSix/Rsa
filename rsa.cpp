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
// count size of e and d
int count;
// msg message; m copy of msg; en msg with encry
string msg, m, en;

// calculator x of "ax + by = 1"
int cald(long int x)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}

bool isprime(int num)
{
	bool flag = true;
	for (int i=2; i<=sqrt(num); i++) {
		if (num % i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

void calced()
{
	int k = 0;

	for (int j=2; j<t; j++) {
		if (t % j == 0) {
			continue;
		}
		bool flag = isprime(j);
        if (flag && j != p && j != q) {
            e[k] = j;
            int x;
            x = cald(e[k]);
            if (x > 0) {
                d[k] = x;
                k++;
            }
            if (k == 99) {
                break;
            }
        }
	}
    count = k;
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

    calced();
    cout << "\n Possible values of e and d\n";
    for (int i=0; i<count; i++) {
        cout << e[i] << "\t" << d[i] << endl;
    }
	return 0;
}
