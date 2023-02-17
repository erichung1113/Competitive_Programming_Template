const int mod = 1e9+7;

int fmul(int a, int b) {
    a %= mod;
    b %= mod;
    int ans = 0;
    while (b) {
        if (b & 1)  ans = (ans + a) % mod;
        b >>= 1;
        a = (a << 1) % mod;
    }
    return ans;
}