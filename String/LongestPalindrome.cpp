string LongestPalindrome(string s) {
    string str = "#";
    for (char i : s) str = str + i + '#';

    int R = 0, C = 0, n = str.size();
    int len = 0, center = 0;
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        if (i < R) {
            int mirror = C - (i - C);
            p[i] = min(R - i, p[mirror]);
        } else {
            p[0] = 0;
        }

        while (i - 1 - p[i] >= 0 && i + 1 + p[i] < n && str[i - 1 - p[i]] == str[i + 1 + p[i]]) {
            p[i]++;
        }

        if (p[i] > len) {
            len = p[i];
            center = i;
        }

        if (i + p[i] > R) {
            R = i + p[i];
            C = i;
        }
    }
    return s.substr((center - len) / 2, len);
}