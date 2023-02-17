#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define MAXN 200005
int Root[MAXN], L_child[MAXN << 4], R_child[MAXN << 4], sum[MAXN << 4], node;

int built(int l, int r) {
    int curNode = node++;
    if (l == r) return curNode;
    int mid = (l + r) / 2;
    L_child[curNode] = built(l, mid);
    R_child[curNode] = built(mid + 1, r);
    return curNode;
}

int insert(int root, int l, int r, int Kth) {
    int curNode = node++;
    L_child[curNode] = L_child[root];
    R_child[curNode] = R_child[root];
    sum[curNode] = sum[root] + 1;
    if (l == r) return curNode;
    int mid = (l + r) / 2;
    if (Kth <= mid)
        L_child[curNode] = insert(L_child[root], l, mid, Kth);
    else
        R_child[curNode] = insert(R_child[root], mid + 1, r, Kth);
    return curNode;
}

int query(int QlbRoot, int QrbRoot, int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    int L_num = sum[L_child[QrbRoot]] - sum[L_child[QlbRoot]];
    if (k <= L_num)
        return query(L_child[QlbRoot], L_child[QrbRoot], l, mid, k);
    else
        return query(R_child[QlbRoot], R_child[QrbRoot], mid + 1, r, k - L_num);
}

int main() {
    cin.sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1), Hash(1,INT_MIN);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Hash.pb(a[i]);
    }

    sort(all(Hash));
    Hash.resize(unique(all(Hash)) - Hash.begin());
    int m = Hash.size() - 1;

    Root[0] = built(1, m);

    for (int i = 1; i <= n; i++) {
        int Kth = lower_bound(all(Hash), a[i]) - Hash.begin();
        Root[i] = insert(Root[i - 1], 1, m, Kth);
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        int Kth = query(Root[l - 1], Root[r], 1, m, k);
        cout << Hash[Kth] << '\n';
    }
}
