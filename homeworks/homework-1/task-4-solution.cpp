#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a < 0) {
       a = 0;
    }

    for (int i = a; i <= b; i++) {
        int temp = i;
        int numDigits = 1;

        while (temp >= 10) {
            temp /= 10;
            numDigits++;
        }

        int summedDigits = 0;
        temp = i;

        while (temp != 0) {
            int digit = temp % 10;
            temp = temp / 10;
            int powered = 1;

            for (int j = 1; j <= numDigits; j++) {
                powered *= digit;
            }

            summedDigits += powered;
        }

        if (i == summedDigits) {
            cout << i << endl;
        }
    }

    return 0;
}
