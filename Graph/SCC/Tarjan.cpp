const int MAXN = 100005;
vector<int> Graph[MAXN];
stack<int> stk;
bool instk[MAXN];
int dfn[MAXN], up[MAXN], sccId[MAXN], sccRoot[MAXN], id, sccCnt;

void tarjan(int now) {
    dfn[now] = up[now] = ++id;

    stk.push(now);
    instk[now] = true;

    for (auto i : Graph[now]) {
        if (!instk[i] && dfn[i]) continue;

        if (!dfn[i]) tarjan(i);
        up[now] = min(up[now], up[i]);
    }

    if (dfn[now] == up[now]) {
        sccRoot[++sccCnt] = now;
        while (true) {
            int x = stk.top();
            stk.pop();
            instk[x] = false;
            sccId[x] = sccCnt;
            if (x == now) break;
        }
    }
}

//----------main----------
for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
}