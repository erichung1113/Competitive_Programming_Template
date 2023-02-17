typedef struct DisjoinSetUnion {
    // vector<set<int>> elements;
    vector<int> dsu, dsusz;
    int group;

    DisjoinSetUnion(int n) {
        // elements.resize(n+1);
        dsu.resize(n + 1);
        dsusz.resize(n + 1);
        group = n;
        for (int i = 1; i <= n; i++) {
            dsu[i] = i;
            dsusz[i] = 1;
            // elements[i].insert(i);
        }
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
    int fa(int x) {
        if (isRoot(x)) return x;
        return dsu[x] = fa(dsu[x]);
    }
    bool uni(int a, int b) {
        a = fa(a), b = fa(b);
        if (a == b) return false;
        dsu[b] = a;
        dsusz[a] += dsusz[b];
        dsusz[b] = 0;
        group--;
        // if (sz(a) < sz(b)) swap(a, b);
        // for (auto i : elements[b]) {
        //     elements[a].insert(i);
        //     dsu[i] = a;
        // }
        // elements[b].clear();
        return true;
    }
} DSU;

/*
Usage:
    DSU dsu(n);
    dsu.uni(a, b);
    dsu.same(a, b);
    dsu.sz(x);
    dsu.isRoot(x);
    dsu.group

Notice:
    a[]: 1-base
    if occur segmentation fault, please put dsu and dsusz in Global.
    if you need record elements, please undefine the code.
*/