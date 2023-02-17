#define MAXN 100005

typedef struct BIT {
    int bit[MAXN];
    void update(int x, int val) {
        while (x < MAXN) {
            bit[x] += val;
            x += x & (-x);
        }
    }
    int query(int x) {
        int ans = 0;
        while (x) {
            ans += bit[x];
            x -= x & (-x);
        }
        return ans;
    }
} BIT;
