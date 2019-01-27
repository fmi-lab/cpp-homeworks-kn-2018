#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>

int countReads(char grid[30][30][101], int gridRows, int gridColumns, char sentence[90901]);

TEST_CASE("works for a single word") {
	char grid[30][30][101] = {
		{"cat"}
	};
	char sentence[101] = "cat";

	CHECK(countReads(grid, 1, 1, sentence) == 1);
}

TEST_CASE("starts from any point of the grid") {
	char grid[30][30][101] = {
		{"cat", "dog"},
		{"tiger", "cat"}
	};
	char sentence[101] = "cat";

	CHECK(countReads(grid, 2, 2, sentence) == 2);
}

TEST_CASE("repeats squares") {
	char grid[30][30][101] = {
		{"one", "two", "three"},
		{"four", "five", "six"}
	};
	char sentence[101] = "one two three two five";

	CHECK(countReads(grid, 2, 3, sentence) == 1);
}

TEST_CASE("counts multiple occurences") {
	char grid[30][30][101] = {
		{"one",  "two",  "three"},
		{"two",  "five", "six"  },
		{"five", "six",  "eight"}
	};
	char sentence[101] = "one two five six eight";

	CHECK(countReads(grid, 3, 3, sentence) == 5);
}

TEST_CASE("works for non-square grids") {
	char grid[30][30][101] = {
		{"one", "six"},
		{"two", "five"},
		{"three", "four"},
		{"four", "five"}
	};
	char sentence[101] = "one two three four five";

	CHECK(countReads(grid, 4, 2, sentence) == 3);
}

TEST_CASE("ignores cells outside of the grid dimensions") {
	char grid[30][30][101] = {
		{"one", "six"},
		{"two", "five"},
		{"three", "four"},
		{"four", "five"}
	};
	char sentence[101] = "one two three four five";

	CHECK(countReads(grid, 2, 2, sentence) == 0);
}

TEST_CASE("works for cyclic grids") {
	char grid[30][30][101] = {
		{"one", "two"},
		{"two", "five"},
		{"three", "four"},
		{"four", "five"}
	};
	char sentence[101] = "one two one two one two";

	CHECK(countReads(grid, 2, 2, sentence) == 8);
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
