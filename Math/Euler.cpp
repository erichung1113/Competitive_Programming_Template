int phi(int n) {
    if (n == 1) return 1;
    int ans = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ans = ans * (i - 1) / i;
        }
    }
    if (n != 1) ans = ans * (n - 1) / n;
    return ans;
}