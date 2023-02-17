#define MAXN 100000
const int mod = 1e9 + 7;
int f[MAXN], inv[MAXN];

int powf(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

int C(int n, int k) {
    if (n < k) return 0;
    return f[n] * inv[k] % mod * inv[n - k] % mod;
}

void preprocessing(){
    f[0] = inv[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        f[i] = (f[i - 1] * i) % mod;
        inv[i] = powf(f[i], mod - 2);
    }   
}

//------------main-------------

preprocessing();