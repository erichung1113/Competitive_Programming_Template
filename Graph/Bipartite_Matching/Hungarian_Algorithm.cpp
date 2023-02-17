#define MAXN 100005
vector<int> Match[MAXN];
bitset<MAXN> vis;
int match[MAXN];

bool Try(int now) {
    for (auto i : Match[now]) {
        if (!vis[i]) {
            vis[i] = true;
            if (!match[i] || Try(match[i])) {
                match[i] = now;
                return true;
            }
        }
    }
    return false;
}

//------------main-------------

int matchCnt = 0;
for (int i = 1; i <= n; i++) {
    vis.reset();
    if (Try(i)) matchCnt++;
}