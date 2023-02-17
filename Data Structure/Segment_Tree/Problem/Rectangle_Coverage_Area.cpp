//https://tioj.ck.tp.edu.tw/problems/1224

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define F first
#define S second
#define MAXN 200005

int sum[MAXN * 4], lazy[MAXN * 4], N;
vector<int> Real;

void update(int now, int l, int r) {
    if (l == r) {
        sum[now] = (lazy[now] > 0);
        return;
    }
    int mid = (l + r) / 2;
    if (lazy[now] > 0)
        sum[now] = Real[r] - Real[l];
    else
        sum[now] =
            (lazy[now * 2] > 0 ? Real[mid] - Real[l] : sum[now * 2]) +
            (lazy[now * 2 + 1] > 0 ? Real[r] - Real[mid] : sum[now * 2 + 1]);
}

void update_range(int lb, int rb, int val, int now = 1, int l = 0, int r = N) {
    if (lb <= l && r <= rb) {
        lazy[now] += val;
        update(now, l, r);
        return;
    }

    int mid = (l + r) / 2;
    if (lb < mid) update_range(lb, rb, val, now * 2, l, mid);
    if (mid < rb) update_range(lb, rb, val, now * 2 + 1, mid, r);

    update(now, l, r);
}

int ID(int x) {
    return lower_bound(all(Real), x) - Real.begin();
}

signed main() {
    int n;
    cin >> n;
    vector<pair<int, tuple<int, int, int>>> b;
    for (int i = 1; i <= n; i++) {
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        b.push_back({d, {l, r, 1}});
        b.push_back({u, {l, r, -1}});
        Real.push_back(l);
        Real.push_back(r);
    }
    sort(all(Real));
    Real.resize(unique(all(Real)) - Real.begin());
    N = Real.size() - 1;

    sort(all(b));
    int ans = 0, pre = -1, i = 0;
    while (i < n * 2) {
        if (pre != -1) ans += sum[1] * (b[i].F - pre);
        pre = b[i].F;

        do {
            int L = ID(get<0>(b[i].S)), R = ID(get<1>(b[i].S)),
                val = get<2>(b[i].S);
            //cout << b[i].F << ' ' << L << ' ' << R << ' ' << val << '\n';
            update_range(L, R, val);
            i++;
        } while (i < n * 2 && b[i - 1].F == b[i].F);
    }
    cout << ans << '\n';
}