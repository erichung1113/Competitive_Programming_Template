// #define double int
#define int long long
#define inf 1e18
#define MAXN 1000005
#define lb -1e6
#define rb 1e6

typedef struct LiChao {
    struct line {
        double m, b = -inf;
        double y(int x) {
            return m * x + b;
        }
    } seg[MAXN * 4];
    int Lson[MAXN], Rson[MAXN], cnt = 1;

    int insert(line ins, int now = 1, int l = lb, int r = rb) {
        if (now == 0) now = ++cnt;

        if (l == r) {
            if (ins.y(l) > seg[now].y(l)) seg[now] = ins;
            return now;
        }
        int mid = l + (r - l) / 2, L = Lson[now], R = Rson[now];
        if (seg[now].m > ins.m) swap(ins, seg[now]);

        if (seg[now].y(mid) > ins.y(mid)) {
            Rson[now] = insert(ins, R, mid + 1, r);
        } else {
            swap(ins, seg[now]);
            Lson[now] = insert(ins, L, l, mid);
        }
        return now;
    }

    double query(int x, int now = 1, int l = lb, int r = rb) {
        if (l == r) return seg[now].y(x);

        int mid = l + (r - l) / 2, L = Lson[now], R = Rson[now];
        if (x <= mid) {
            return max(seg[now].y(x), query(x, L, l, mid));
        } else {
            return max(seg[now].y(x), query(x, R, mid + 1, r));
        }
    }
} Lichao;
LiChao lichao;

/*
Usage:
    lichao.insert(line); //line={(double)m,(double)b}
    lichao.query(x);

Notice:
    Set lb and rb first
    Line's parameter(m and b) is double
    If all operations are in integer, you can define double to int
    x axis : Integer
    y axis : Double
*/