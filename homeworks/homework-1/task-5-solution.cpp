#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int sum;
    int result = 2018;

    do {
        result++;
        sum = 0;

        int temp = result;

        while (temp != 0) {
            sum += temp % 10;
            temp = temp / 10;
        }
    } while (n % sum != 0);

    cout << result;

    return 0;
}
