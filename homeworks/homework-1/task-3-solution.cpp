#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int result = 0;
    int tens = 1;

    while (n != 0) {
        int digit = n % 10;
        int newDigit;

        if (digit % 3 == 0) {
            newDigit = digit / 3;
        } else if (digit % 2 == 0) {
            newDigit = digit + 1;
        } else {
            newDigit = digit + 2;
        }

        result = result + newDigit * tens;
        tens *= 10;
        n = n / 10;
    }

    cout << result * 2;

    return 0;
}
