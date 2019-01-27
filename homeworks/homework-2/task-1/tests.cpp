#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>

bool allConcatenatedNumbers(int numbers[], int length);

TEST_CASE("returns true for empty array") {
    unsigned int numbers[1] = {1};
    CHECK(allRepeatedNumbers(numbers, 0));
}

TEST_CASE("Recognizes repeated numbers for single-digit numbers 0 - 11") {
    unsigned int numbers[] = { 0, 11, 22, 3, 444, 55, 6666, 7, 8, 99, 101010, 1111 };
    unsigned int length = sizeof(numbers)/sizeof(unsigned int);

    CHECK(allRepeatedNumbers(numbers, length));
}

TEST_CASE("Numbers must be fully repeated") {
    unsigned int numbers[12] = { 0, 11, 22, 3, 444, 55, 6666, 7, 8, 99, 10110, 1111 };
    unsigned int length = sizeof(numbers)/sizeof(unsigned int);

    CHECK_FALSE(allRepeatedNumbers(numbers, length));
}

TEST_CASE("Works for indexes with multiple digits") {
    unsigned int numbers[1000];
    for (unsigned int i = 0; i < 10; i++) {
        numbers[i] = i * 1111;
    }
    for (unsigned int i = 10; i < 100; i++) {
        numbers[i] = i * 1010101;
    }
    for (unsigned int i = 100; i < 1000; i++) {
        numbers[i] = i * 1001001;
    }
    unsigned int length = sizeof(numbers)/sizeof(unsigned int);

    CHECK(allRepeatedNumbers(numbers, length));
}

TEST_CASE("Checks the 1000th element") {
    unsigned int numbers[1000];
    unsigned int length = sizeof(numbers)/sizeof(unsigned int);

    for (unsigned int i = 0; i < 1000; i++) {
        numbers[i] = i;
    }

    numbers[999] = 1234;

    CHECK_FALSE(allRepeatedNumbers(numbers, length));
}

TEST_CASE("Multiples are not repeated numbers") {
    unsigned int numbers[10] = {0, 1, 2};

    for (unsigned int i = 3; i < 10; i++) {
        numbers[i] = 2 * i;
    }
    unsigned int length = sizeof(numbers)/sizeof(unsigned int);

    CHECK_FALSE(allRepeatedNumbers(numbers, length));
}

int main() {
	// Пускане на тестовете с Doctest
	doctest::Context context;
	context.setOption("no-breaks", true);

	int status = context.run();

	// Магия за Visual Studio :)
	// `_MSC_VER` е дефинирано само ако компилатора е Visual Studio
#ifdef _MSC_VER
	// Ако сме във Visual Studio - задръж ~вратата~ конзолата отворена
	std::cout << "Press enter to close...";
	std::cin.get();
#endif

	return status;
}
