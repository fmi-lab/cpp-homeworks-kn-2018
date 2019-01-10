#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include "doctest.h"

bool isReverseDNAPalindrome(char dna[1000]);

TEST_CASE("works for a single 'A'") {
    char dna[1000] = "A";

    CHECK(!isReverseDNAPalindrome(dna));
}

TEST_CASE("more complex: 'GCATGC' ") {
    char dna[1000] = "GCATGC";

    CHECK(isReverseDNAPalindrome(dna));
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
