#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>

bool allConcatenatedNumbers(int numbers[], int length);

TEST_CASE("Recognizes concatenated numbers for single-digit numbers 0 - 11") {
    int numbers[] = { 0, 11, 22, 3, 444, 55, 6666, 7, 8, 99, 101010, 1111 };
    int length = sizeof(numbers)/sizeof(int);

    CHECK(allConcatenatedNumbers(numbers, length));
}

TEST_CASE("Multiples are not concatenated numbers") {
    int numbers[] = { 0, 2 };
    int length = sizeof(numbers)/sizeof(int);

    CHECK_FALSE(allConcatenatedNumbers(numbers, length));
}

TEST_CASE("Concatenated number must be fully repeated") {
    int numbers[11] = { 0, 11, 22, 3, 444, 55, 6666, 7, 8, 99, 10101 };
    int length = sizeof(numbers)/sizeof(int);

    CHECK_FALSE(allConcatenatedNumbers(numbers, length));
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
