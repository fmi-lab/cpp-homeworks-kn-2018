#include <cstring>

char* nextWord(char* sentence, char* word) {
	while (*sentence && *sentence != ' ') {
		*word++ = *sentence++;
	}
	*word = 0;

	if (*sentence == ' ') {
		sentence++;
	}

	if (!*sentence) {
		return nullptr;
	}

	return sentence;
}

int countReadsRecursively(
	char grid[30][30][101],
	int rows,       int cols,
	int row,        int col,
	char* sentence
) {
	char word[90001];
	sentence = nextWord(sentence, word);

	if (row < 0 || row >= rows || col < 0 || col >= cols) {
		return 0;
	}

	if (strcmp(grid[row][col], word) != 0) {
		return 0;
	}

	if (!sentence) {
		return 1;
	}

	int result = 0;

	result += countReadsRecursively(grid, rows, cols, row - 1, col, sentence);
	result += countReadsRecursively(grid, rows, cols, row + 1, col, sentence);
	result += countReadsRecursively(grid, rows, cols, row, col - 1, sentence);
	result += countReadsRecursively(grid, rows, cols, row, col + 1, sentence);

	return result;
}

int countReads(char grid[30][30][101], int gridRows, int gridColumns, char sentence[90001]) {
	int total = 0;

	for (int row = 0; row < gridRows; row++) {
		for (int col = 0; col < gridColumns; col++) {
			total += countReadsRecursively(grid, gridRows, gridColumns, row, col, sentence);
		}
	}

	return total;
}
