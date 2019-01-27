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

TEST_CASE("4x5") {
	int matrix[100][100] = {
		{1,2,3,4,0},
		{5,6,7,8,0},
		{9,10,11,12,0},
		{0,0,0,0,0}
	};

	CHECK(ladderSum(matrix, 4, 5, 0, 1) == 32);
}


TEST_CASE("3x4 at the end") {
	int matrix[100][100] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};

	CHECK(ladderSum(matrix, 3, 4, 2, 3) == 12);
}

TEST_CASE("biggest matrix") {
	int matrix[100][100];
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            matrix[i][j] = i * 100 + j;
        }
    }

	CHECK(ladderSum(matrix, 100, 100, 5,5) == 987975);
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
