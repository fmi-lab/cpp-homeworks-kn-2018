#include <cstring>

char mapPair(char dna) {
    switch (dna) {
        case 'A':
            return 'T';
        case 'T':
            return 'A';
        case 'C':
            return 'G';
        case 'G':
            return 'C';
        default:
            return dna;
    }
}

bool isReverseDNAPalindrome(char dna[1000]) {
    char reverseDna[1000] = "";
    int dna_length = strlen(dna);

    for (int i = 0; i < dna_length; ++i) {
        reverseDna[i] = mapPair(dna[dna_length - i - 1]);
    }

    return strncmp(dna, reverseDna, dna_length) == 0;
}
