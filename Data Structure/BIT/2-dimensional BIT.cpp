#define MAXN 1005

typedef struct BIT {
    int bit[MAXN][MAXN];
    void update(int x, int y, int val) {
        while (x < MAXN) {
            int ty = y;
            while (ty < MAXN) {
                bit[x][ty] += val;
                ty += ty & (-ty);
            }
            x += x & (-x);
        }
    }
    int query(int x, int y) {
        int ans = 0;
        while (x > 0) {
            int ty = y;
            while (ty > 0) {
                ans += bit[x][ty];
                ty -= ty & (-ty);
            }
            x -= x & (-x);
        }
        return ans;
    }
} BIT;