vector<array<int, 3>> edge;



int start = 1;

vector<int> dis(n + 1, INT_MAX);
dis[start] = 0;

for (int t = 1; t <= n - 1; t++) {
    for (auto i : edge) {
        int u = i[0], v = i[1], w = i[2];
        if (dis[u] + w < dis[v]) {
            dis[v] = dis[u] + w;
        }
    }
}

bool HasNegativeCircle=false;
for(auto i:edge){
    int u = i[0], v = i[1], w = i[2];
    if (dis[u] + w < dis[v]) {
        HasNegativeCircle=true;
        break;
    }
}