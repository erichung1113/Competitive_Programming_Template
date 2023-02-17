#define pii pair<int,int>
#define F first 
#define S second

double cross(pii o, pii a, pii b) {
    return (a.F - o.F) * (b.S - o.S) - (a.S - o.S) * (b.F - o.F);
}

vector<pii> Convex_Hull(vector<pii> &a) {
    sort(a.begin(), a.end());
    vector<pii> dot;
    
    for (int i = 0; i < a.size(); i++) {
        while (dot.size() >= 2 && cross(dot[dot.size() - 2], dot.back(), a[i]) <= 0) {
            dot.pop_back();
        }
        dot.push_back(a[i]);
    }
    dot.pop_back();
    for (int i = a.size() - 1, lowest = dot.size(); i >= 0; i--) {
        while (dot.size() >= lowest + 2 && cross(dot[dot.size() - 2], dot.back(), a[i]) <= 0) {
            dot.pop_back();
        }
        dot.push_back(a[i]);
    }
    dot.pop_back();
    return dot;
}