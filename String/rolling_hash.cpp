typedef struct RollingHash {
    const int MAXN = 1000005;
    const int mul = 127;
    using ll = long long;

    vector<int> powf, hash_array;
    string str;
    int n;

    RollingHash(string s) {
        str = s;
        n = str.size();

        hash_array.resize(n + 1);
        powf.resize(n + 1);
        powf[0] = 1;

        for (int i = 1; i <= n; i++) {
            hash_array[i] = ((ll)hash_array[i - 1] * mul + str[i - 1]) % mod;
            powf[i] = (ll)powf[i - 1] * mul % mod;
        }
    }

    int hash(int l, int r) {
        if (l > r) return 0;
        int Hash = hash_array[r] - (ll)hash_array[l - 1] * powf[r - l + 1] % mod;
        while (Hash < 0)
            Hash += mod;
        return Hash;
    }
} rh;

/*
Usage:
    rh S(str)
    S.hash(1,n)

Notice:
    a[]: 1-base
    if WA, try #define int long long
*/