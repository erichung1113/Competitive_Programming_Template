const int mod = 1e9 + 7;

int fpow(long long a, int b) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}