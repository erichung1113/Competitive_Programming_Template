#define pii pair<int,int>
#define int long long
const int MAXN = 105;
vector<pii> graph[MAXN];





int start = 1;

vector<int> dis(n + 1, LLONG_MAX);
dis[start] = 0;

priority_queue<pii, vector<pii>, greater<pii>> pq;
pq.push({dis[start], start});

while (!pq.empty()) {
    pii cur = pq.top(); pq.pop();
    int d = cur.first, u = cur.second;
    if (dis[u] < d) continue;

    for (pii nxt : graph[u]) {
        int v = nxt.first, w = nxt.second;
        if (dis[u] + w < dis[v]) {
            dis[v] = dis[u] + w;
            pq.push({dis[v], v});
        }
    }
}