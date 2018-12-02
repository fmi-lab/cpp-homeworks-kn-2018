#include <iostream>

using namespace std;

int main()
{
    double x, result;
    cin >> x;

    double denominator = x*x*x - 25;

    if (denominator == 0) {
        result = 0;
    } else {
        double enumerator = 11*x*x + 3*x + 15;

        result = enumerator / denominator;
    }

    cout << result;

    return 0;
}
