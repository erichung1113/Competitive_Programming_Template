#define pii pair<int, int>
const int MAXN = 105;
vector<pii> graph[MAXN];






int start = 1;

vector<int> dis(n + 1, INT_MAX), cnt(n + 1, 0);
vector<bool> inq(n + 1, false);
deque<int> q;

q.push_back(start);
inq[start] = true;
dis[start] = 0;

while (!q.empty()) {
    int u = q.front();
    q.pop_front();
    inq[u] = false;

    for (auto cur : graph[u]) {
        int v = cur.first, w = cur.second;
        if (dis[u] + w < dis[v]) {
            dis[v] = dis[u] + w;
            if (!inq[v]) {
                if (++cnt[v] == n) cout << "Has Negative Circle" << '\n';

                if (!q.empty() && dis[v] < dis[q.front()])
                    q.push_front(v);
                else
                    q.push_back(v);
                inq[v] = true;
            }
        }
    }
}