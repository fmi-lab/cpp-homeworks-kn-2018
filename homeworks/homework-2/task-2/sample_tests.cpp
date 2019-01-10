#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>

int ladderSum(
    int matrix[100][100],
    unsigned int rows,
    unsigned int columns,
    unsigned int startRow,
    unsigned int startColumn
);

TEST_CASE("works for a single value") {
	int matrix[100][100] = {
		{1}
	};

	CHECK(ladderSum(matrix, 1, 1, 0, 0) == 1);
}

TEST_CASE("3x3") {
	int matrix[100][100] = {
		{1,2,3},
		{4,5,6}
	};

	CHECK(ladderSum(matrix, 2, 3, 0, 1) == 11);
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
