#define MAXN 200005
int Root[MAXN], L_child[MAXN << 4], R_child[MAXN << 4], sum[MAXN << 4], node;

int built(int l, int r) {
    int curNode = node++;
    if (l == r) return curNode;
    int mid = (l + r) / 2;
    L_child[curNode] = built(l, mid);
    R_child[curNode] = built(mid + 1, r);
    return curNode;
}

int insert(int root, int l, int r, int target, int val) {
    int curNode = node++;
    L_child[curNode] = L_child[root];
    R_child[curNode] = R_child[root];
    sum[curNode] = sum[root] + val;
    if (l == r) return curNode;
    int mid = (l + r) / 2;
    if (target <= mid)
        L_child[curNode] = insert(L_child[root], l, mid, target, val);
    else
        R_child[curNode] = insert(R_child[root], mid + 1, r, target, val);
    return curNode;
}

int query(int curNode, int l, int r, int lb, int rb) {
    if (lb <= l && r <= rb) return sum[curNode];
    int mid = (l + r) / 2;
    int ans = 0;
    if (lb <= mid)
        ans += query(L_child[curNode], l, mid, lb, rb);
    if (mid + 1 <= rb)
        ans += query(R_child[curNode], mid + 1, r, lb, rb);

    return ans;
}

/*
Usage:
    Root[0]=built(l, r);     //empty tree
    Root[index]=insert(root_of_based_on_which_tree, l, r, target, value);    //insert value at target
    query(root_of_tree, l, r, queryL, queryR);     //query sum of range [queryL, queryR]
    
Things need to do:
    define MAXN
*/