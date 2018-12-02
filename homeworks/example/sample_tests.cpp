#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
// #include "../../lib/doctest.h"
#include <iostream>

// ------------------------
// Предварителна декларация на очакваните функции.

int fibonacci(int n);

// ------------------------
// Примерни тестове

TEST_CASE("returns 0 for 0") {
    CHECK(fibonacci(0) == 0);
}

// -------------------------
// `main` функция за изпълнението.

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
