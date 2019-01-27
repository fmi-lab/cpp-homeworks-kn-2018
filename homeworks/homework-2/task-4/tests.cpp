#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include "doctest.h"

unsigned int countWords(char words[50][101], unsigned int numWords, char grid[100][100], unsigned int gridRows, unsigned int gridColumns);

TEST_CASE("Sample 1") {
    char grid[100][100] = {
        { 'x', 'h', 'e', 'l', 'l', 'o', 'y', 'z' },
        { 'z', 't', 'o', 'w', 'o', 'r', 'l', 'd' },
        { 'c', 'a', 't', 'r', 'd', 'o', 'g', 's' },
        { 't', 'e', 'h', 'e', 'l', 'l', 'o', 'n' }
    };
    char words[50][101] = { "hello", "world", "fmi" };
    CHECK(countWords(words, 3, grid, 4, 8) == 2);
}

TEST_CASE("Finds a single word in a row") {
    char words[50][101] = {"hello"};
    char grid[100][100] = {
        {'a', 'h', 'e', 'h', 'e', 'a', 't' },
        {'a', 'h', 'e', 'l', 'l', 'o', 't' },
        {'a', 'h', 'e', 'h', 'e', 'a', 't' },
    };
    CHECK(countWords(words, 1, grid, 3, 7) == 1);
}

TEST_CASE("Finds a single word in a column") {
    char words[50][101] = {"hello"};
    char grid[100][100] = {
        {'a', 'h', 'h'},
        {'a', 'h', 'e'},
        {'a', 'h', 'h'},
        {'a', 'h', 'e'},
        {'a', 'h', 'l'},
        {'a', 'h', 'l'},
        {'a', 'h', 'o'},
    };
    CHECK(countWords(words, 1, grid, 7, 3) == 1);
}

TEST_CASE("Counts every word once") {
    char words[50][101] = {"hello"};
    char grid[100][100] = {
        {'a', 'h', 'h'},
        {'a', 'h', 'e'},
        {'a', 'e', 'h'},
        {'a', 'l', 'e'},
        {'a', 'l', 'l'},
        {'a', 'o', 'l'},
        {'a', 'h', 'o'},
    };
    CHECK(countWords(words, 1, grid, 7, 3) == 1);
}

TEST_CASE("Finds multiple words") {
    char words[50][101] = {"hello", "world"};
    char grid[100][100] = {
        {'a', 'h', 'h', 'r', 'l', 'd'},
        {'a', 'h', 'e', 'r', 'l', 'd'},
        {'a', 'e', 'h', 'r', 'l', 'd'},
        {'a', 'l', 'e', 'r', 'l', 'd'},
        {'a', 'l', 'l', 'r', 'l', 'd'},
        {'a', 'o', 'l', 'r', 'l', 'd'},
        {'a', 'w', 'o', 'r', 'l', 'd'},
    };
    CHECK(countWords(words, 2, grid, 7, 6) == 2);
}

TEST_CASE("Works when no words are specified") {
    char words[50][101] = {};
    char grid[100][100] = {
        {'a', 'h', 'h', 'r', 'l', 'd'},
        {'a', 'h', 'e', 'r', 'l', 'd'},
        {'a', 'e', 'h', 'r', 'l', 'd'},
        {'a', 'l', 'e', 'r', 'l', 'd'},
        {'a', 'l', 'l', 'r', 'l', 'd'},
        {'a', 'o', 'l', 'r', 'l', 'd'},
        {'a', 'w', 'o', 'r', 'l', 'd'},
    };
    CHECK(countWords(words, 0, grid, 7, 6) == 0);
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

TEST_CASE("Doesn't count missing words") {
    char words[50][101] = {"hello", "world", "law", "order"};
    char grid[100][100] = {
        {'a', 'h', 'h', 'r', 'l', 'd'},
        {'a', 'h', 'e', 'r', 'l', 'd'},
        {'a', 'e', 'h', 'r', 'l', 'd'},
        {'a', 'w', 'o', 'r', 'l', 'd'},
        {'a', 'l', 'l', 'r', 'l', 'd'},
        {'a', 'a', 'l', 'r', 'l', 'd'},
        {'a', 'w', 'i', 'r', 'l', 'd'},
    };
    CHECK(countWords(words, 4, grid, 7, 6) == 2);
}

TEST_CASE("Respects number of grid rows and columns") {
    char words[50][101] = { "hrld", "hello" };
    char grid[100][100] = {
        {'a', 'h', 'h', 'r', 'l', 'd'},
        {'a', 'h', 'e', 'r', 'l', 'd'},
        {'a', 'e', 'h', 'r', 'l', 'd'},
        {'a', 'l', 'e', 'r', 'l', 'd'},
        {'a', 'l', 'l', 'r', 'l', 'd'},
        {'a', 'a', 'l', 'r', 'l', 'd'},
        {'a', 'w', 'o', 'r', 'l', 'd'},
    };
    CHECK(countWords(words, 2, grid, 6, 5) == 0);
}

TEST_CASE("Finds words that span full row") {
    char words[50][101] = { "athens" };
    char grid[100][100] = {
        {'a', 't', 'h', 'e', 'n', 's'}
    };
    CHECK(countWords(words, 1, grid, 1, 6) == 1);
}

TEST_CASE("Finds words that span full column") {
    char words[50][101] = { "athens" };
    char grid[100][100] = {
        {'a'},
        {'t'},
        {'h'},
        {'e'},
        {'n'},
        {'s'}
    };
    CHECK(countWords(words, 1, grid, 6, 1) == 1);
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
