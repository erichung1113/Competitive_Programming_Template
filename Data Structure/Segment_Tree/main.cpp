#define SegMode_Sum
int a[MAXN], n, seg[MAXN * 4], lazy[MAXN * 4];

typedef struct Seg {
    void push_down(int now, int l, int r) {
        int L = now * 2, R = now * 2 + 1, val = lazy[now], mid = (l + r) / 2;
        seg[L] += val;
        seg[R] += val;
        lazy[L] += val;
        lazy[R] += val;
        lazy[now] = 0;
    }
    int calculate(int a, int b) {
        #ifdef SegMode_Sum
                return a + b;
        #endif
        #ifdef SegMode_Max
                return max(a, b);
        #endif
        #ifdef SegMode_Min
                return min(a, b);
        #endif
        #ifdef SegMode_Gcd
                return gcd(a, b);
        #endif
        return -1;
    }

    void built(int now = 1, int l = 1, int r = n) {
        if (l == r) {
            seg[now] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        built(now * 2, l, mid);
        built(now * 2 + 1, mid + 1, r);

        seg[now] = calculate(seg[now * 2], seg[now * 2 + 1]);
    }

    void update(int lb, int rb, int val, int now = 1, int l = 1, int r = n) {
        if (lb <= l && r <= rb) {
            seg[now] += val;
            lazy[now] += val;
            return;
        }

        push_down(now, l, r);

        int mid = (l + r) / 2;
        if (lb <= mid) update(lb, rb, val, now * 2, l, mid);
        if (mid + 1 <= rb) update(lb, rb, val, now * 2 + 1, mid + 1, r);

        seg[now] = calculate(seg[now * 2], seg[now * 2 + 1]);
    }

    int query(int lb, int rb, int now = 1, int l = 1, int r = n) {
        if (lb <= l && r <= rb) return seg[now];

        push_down(now, l, r);

        int mid = (l + r) / 2;
        if (rb <= mid) {
            return query(lb, rb, now * 2, l, mid);
        } else if (mid + 1 <= lb) {
            return query(lb, rb, now * 2 + 1, mid + 1, r);
        } else {
            return calculate(query(lb, rb, now * 2, l, mid),
                             query(lb, rb, now * 2 + 1, mid + 1, r));
        }
    }
} Seg;

/*
Usage:
    Seg seg;
    seg.built();
    seg.update(L, R, val);
    seg.query(L, R)

Decleared Variables:
    a[]
    n

Notice:
    a[]: 1-base
    if occur segmentation fault, please put seg array and lazy array in Global.
    don't declear n in main

Needs To Do:
    set SegMode by define [SegMode_Sum or SegMode_Max or SegMode_Min or SegMode_Gcd]
    define MAXN
*/