#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>

unsigned int countWords(char words[50][101], unsigned int numWords, char grid[100][100], unsigned int gridRows, unsigned int gridColumns);

TEST_CASE("Finds multiple words") {
    char grid[100][100] = {
        { 'x', 'h', 'e', 'l', 'l', 'o', 'y', 'z' },
        { 'z', 't', 'o', 'w', 'o', 'r', 'l', 'd' },
        { 'c', 'a', 't', 'r', 'd', 'o', 'g', 's' },
        { 't', 'e', 'h', 'e', 'l', 'l', 'o', 'n' }
    };
    char words[50][101] = { "hello", "world", "fmi" };
    CHECK(countWords(words, 3, grid, 4, 8) == 2);
}

TEST_CASE("Finds one-letter words") {
    char words[50][101] = {"a", "h", "r", "d"};
    char grid[100][100] = {
        {'a', 'h', 'h', 'r', 'l', 'd'},
        {'a', 'h', 'e', 'r', 'l', 'd'},
        {'a', 'e', 'h', 'r', 'l', 'd'},
        {'a', 'l', 'e', 'r', 'l', 'd'},
        {'a', 'l', 'l', 'r', 'l', 'd'},
        {'a', 'o', 'l', 'r', 'l', 'd'},
        {'a', 'w', 'o', 'r', 'l', 'd'},
    };
    CHECK(countWords(words, 4, grid, 7, 6) == 4);
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
