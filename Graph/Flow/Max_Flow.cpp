const int MAXN = 105;

int rest[MAXN][MAXN], from[MAXN], mi[MAXN], n, m;

bool bfs(int s, int e) {
    queue<int> q;
    memset(from, 0, sizeof(from));

    q.push(s);
    from[s] = s;
    mi[s] = INT_MAX;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {
            if (!from[i] && rest[now][i]) {
                from[i] = now;
                mi[i] = min(mi[now], rest[now][i]);

                if (i == e) return true;
                q.push(i);
            }
        }
    }
    return false;
}

int max_flow(int s, int e) {
    int sum_flow = 0;
    while (bfs(s, e)) {
        int increase_flow = mi[e];
        sum_flow += increase_flow;

        int now = e;
        while (now != 1) {
            rest[from[now]][now] -= increase_flow;
            rest[now][from[now]] += increase_flow;
            now = from[now];
        }
    }
    return sum_flow;
}

//--------main---------

cin >> m >> n;
for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    rest[u][v] += w;
}
int ans = max_flow(1, n);
