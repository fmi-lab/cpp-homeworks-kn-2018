#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>

int countReads(char grid[30][30][101], int gridRows, int gridColumns, char sentence[90001]);

TEST_CASE("works for a single word") {
	char grid[30][30][101] = {
		{"cat"}
	};

	CHECK(countReads(grid, 1, 1, "cat") == 1);
}

TEST_CASE("starts from any point of the grid") {
	char grid[30][30][101] = {
		{"cat", "dog"},
		{"tiger", "cat"}
	};

	CHECK(countReads(grid, 2, 2, "cat") == 2);
}

TEST_CASE("repeats squares") {
	char grid[30][30][101] = {
		{"one", "two", "three"},
		{"four", "five", "six"}
	};

	CHECK(countReads(grid, 2, 3, "one two three two five") == 1);
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
