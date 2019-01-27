int ladderSum(
    int matrix[100][100],
    unsigned int rows,
    unsigned int columns,
    unsigned int startRow,
    unsigned int startColumn
) {
    if (startRow >= rows || startColumn >= columns) {
        return 0;
    }

    int sum = matrix[startRow][startColumn];

    sum += startColumn + 1 < columns ? matrix[startRow][startColumn + 1] : 0;

    return ladderSum(matrix, rows, columns, startRow + 1, startColumn + 1) + sum;
}
