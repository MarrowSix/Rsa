#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int nbits = 31;
    int number;
    cin >> number;

    string result;
    for (int j=nbits; j>=0; j--) {
        if (number & (1 << j)) {
            result += "1";
            cout << "1";
        } else {
            result += "0";
            cout << "0";
        }
    }
    cout << endl;
    cout << result << endl;

    return 0;
}
