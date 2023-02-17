#define MAXN 100005

int n;
typedef struct SparseTable {
    int st[MAXN][20];
    SparseTable(vector<int> &a) {
        for (int j = 0; j <= log2(n); j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                if (j == 0)
                    st[i][j] = a[i];
                else
                    st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r) {
        int k = log2(r - l + 1);
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    }
} ST;

/*
Usage:
    ST st(array);
    st.query(l, r)

Decleared Variables:
    n

Notice:
    a[]: 0-base
    if occur segmentation fault, please put st array in Global.
    don't declear n in main

Needs To Do:
    define MAXN
*/