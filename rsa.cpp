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

void encryptMessage(string orign, int encry[], int &size)
{
    // copyOrign copy of orign;
    string copyOrign = orign;
    int len = copyOrign.size();
    int ekey = e[0];

    int i;
    long int k;
    for (i=0; i<len; i++) {
        int pcnum = copyOrign[i];
        k = 1;
        for (int j=0; j<ekey; j++) {
            k *= pcnum;
            k %= n;
        }
        if (size > i)
            encry[i] = k;
        else {
            cout << "\nSpace of arrary is not enough\n";
            exit(1);
        }
    }
    encry[i] = -1;
    size = i;
    cout << "\nThe encrypted message:\n";
    for (int j=0; j<size; j++) {
        printf("%c", encry[j]);
    }
}

void decryptMessage(int encry[])
{
    int keyd = d[0];
    string result;
    int i = 0;
    long int k;
    while (encry[i] != -1) {
        int rdnum = encry[i];
        k = 1;
        for (int j=0; j<keyd; j++) {
            k *= rdnum;
            k %= n;
        }
        result += char(k);
        i++;
    }
    cout << "\nThe deencry message:\n";
    cout << result << endl;
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
    string msg;
	cin >> msg;

	n = p*q;
	t = (p-1) * (q-1);

    calced();
    cout << "\n Possible values of e and d\n";
    for (int i=0; i<count; i++) {
        cout << e[i] << "\t" << d[i] << endl;
    }
    int size = 200;
    int *encry = new int[size];
    encryptMessage(msg, encry, size);
    decryptMessage(encry);
	return 0;
}
