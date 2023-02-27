int n, m;


void bfs(int sx, int sy) {
    queue<pii> q;
    q.push({sx, sy});
    while (!q.empty()) {
        pii now = q.front(); q.pop();
        int x = now.F, y = now.S;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 1 || nx > n || ny < 1 || ny > m || used[nx][ny]) continue;

            used[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}