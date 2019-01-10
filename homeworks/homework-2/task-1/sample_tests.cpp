#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>

bool allRepeatedNumbers(unsigned int numbers[], unsigned int length);

TEST_CASE("Recognizes repeated numbers for single-digit numbers 0 - 11") {
    unsigned int numbers[] = { 0, 11, 22, 3, 444, 55, 6666, 7, 8, 99, 101010, 1111 };
    unsigned int length = sizeof(numbers)/sizeof(unsigned int);

    CHECK(allRepeatedNumbers(numbers, length));
}
TEST_CASE("Multiples are not repeated numbers") {
    unsigned int numbers[] = { 0, 2 };
    unsigned int length = sizeof(numbers)/sizeof(unsigned int);

    CHECK_FALSE(allRepeatedNumbers(numbers, length));
}
TEST_CASE("Numbers must be fully repeated") {
    unsigned int numbers[11] = { 0, 11, 22, 3, 444, 55, 6666, 7, 8, 99, 10101 };
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
