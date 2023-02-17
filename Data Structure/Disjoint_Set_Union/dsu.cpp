#define MAXN 100005

typedef struct DisjoinSetUnion {
    int dsu[MAXN], dsusz[MAXN];
    // set<int> elements[MAXN];
    DisjoinSetUnion(int n) {
        for (int i = 1; i <= n; i++) {
            dsu[i] = i;
            dsusz[i] = 1;
            // elements[i].insert(i);
        }
    }
    int fa(int x) {
        if (dsu[x] == x) return x;
        return dsu[x] = fa(dsu[x]);
    }
    int sz(int x) {
        return dsusz[fa(x)];
    }
    bool same(int a, int b) {
        return fa(a) == fa(b);
    }
    bool isRoot(int x) {
        return dsu[x] == x;
    }
    void uni(int a, int b) {
        a = fa(a), b = fa(b);
        dsu[b] = a;
        dsusz[a] += dsusz[b];
        dsusz[b] = 0;
        // if (sz(a) < sz(b)) swap(a, b);
        // for (auto i : elements[b]) {
        //     elements[a].insert(i);
        //     dsu[i] = a;
        // }
        // elements[b].clear();
    }
} DSU;

/*
Usage:
    DSU dsu(n);
    dsu.uni(a, b);
    dsu.same(a, b);
    dsu.sz(x);
    dsu.isRoot(x);

Notice:
    a[]: 1-base
    if occur segmentation fault, please put dsu and dsusz array in Global.
    if you need record elements, please undefine the code.

Things Need To Do:
    define MAXN
*/