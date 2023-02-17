#define MAXN 100005
vector<int> Graph[MAXN], Rev_Graph[MAXN];
int sccId[MAXN], sccCnt;
bitset<MAXN> vis;
stack<int> stk;

void dfs1(int now) {
    vis[now] = true;
    for (auto i : Graph[now]) {
        if (!vis[i]) dfs1(i);
    }
    stk.push(now);
}

void dfs2(int now) {
    vis[now] = true;
    sccId[now] = sccCnt;
    for (auto i : Rev_Graph[now]) {
        if (!vis[i]) dfs2(i);
    }
}

//----------------main-----------------

for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs1(i);
}
vis.reset();
while (!stk.empty()) {
    int x = stk.top(); stk.pop();
    if (vis[x]) continue;
    sccCnt++;
    dfs2(x);
}