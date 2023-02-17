#define matrix vector<vector<int>>
#define MatrixSize 10


matrix matrix_multiply(matrix &a, matrix &b) { 
    matrix ans(MatrixSize, vector<int>(MatrixSize));
    for (int i = 0; i < MatrixSize; i++) {
        for (int j = 0; j < MatrixSize; j++) {
            for (int k = 0; k < MatrixSize; k++) {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

matrix matrix_powf(matrix a, int b) {
    matrix ans(MatrixSize, vector<int>(MatrixSize));
    for (int i = 0; i < MatrixSize; i++) {
        ans[i][i] = 1;
    }

    while (b) {
        if (b & 1) ans = matrix_multiply(ans, a);
        a = matrix_multiply(a, a);
        b >>= 1;
    }
    return ans;
}