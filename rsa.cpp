#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    long nbits = 63;
    int number;
    cin >> number;

    // int count = 0;
    for (int j=nbits; j>=0; j--) {
        if (number & (1 << j)) {
            cout << "1";
        } else {
            cout << "0";
        }
        // count++;
        // if (count % 4 == 0) {
        //     cout << " ";
        // }
    }
    cout << endl;

    return 0;
}
