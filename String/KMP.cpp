void KMP(string A, string B) {
    int n = A.size(), m = B.size();

    vector<int> lps(m);
    int j = 0, i = 1;
    while (i < m) {
        if (B[j] == B[i]) {
            lps[i++] = ++j;
        } else {
            if (j == 0)
                lps[i++] = 0;
            else
                j = lps[j - 1];
        }
    }
    for (int i = 0, j = 0; i < n; i++) {
        while (j && A[i] != B[j]) j = lps[j - 1];
        if (A[i] == B[j]) j++;
        if (j == m) {
            cout << i - j + 1 << ' ';
            j = lps[j - 1];
        }
    }
    cout << '\n';
}