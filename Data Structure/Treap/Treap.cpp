const int inf = 1e9;

typedef struct Node {
    int val, size, cnt, w;
    struct Node *l, *r;
    Node(int x) {
        val = x, size = cnt = 1, w = rand();
        l = r = NULL;
    }
    void update_son() {
        size = cnt;
        if (l != NULL) size += l->size;
        if (r != NULL) size += r->size;
    }
} Node;
Node* Root;
typedef struct Treap {
    Treap() {
        Root = new Node(inf);
        Root->l = new Node(-inf);
        Root->w = -inf, Root->l->w = -inf;
        Root->update_son();
    }

    int size(Node* node) {
        return node ? node->size : 0;
    }

    void left_rotate(Node*& a) {
        Node* b = a->r;
        a->r = b->l, b->l = a, a = b;
        a->update_son(), a->l->update_son();
    }

    void right_rotate(Node*& a) {
        Node* b = a->l;
        a->l = b->r, b->r = a, a = b;
        a->update_son(), a->r->update_son();
    }

    void insert(int val, Node*& node = Root) {
        if (!node) {
            node = new Node(val);
            return;
        }
        if (val == node->val) {
            node->cnt++;
        } else if (val < node->val) {
            insert(val, node->l);
            if (node->l->w < node->w) right_rotate(node);
        } else {
            insert(val, node->r);
            if (node->r->w < node->w) left_rotate(node);
        }
        node->update_son();
    }

    void del(int val, Node*& node = Root) {
        if (val < node->val)
            del(val, node->l);
        else if (node->val < val)
            del(val, node->r);
        else {
            if (node->cnt > 1) {
                node->cnt--;
                node->update_son();
                return;
            }

            if (node->l == NULL && node->r == NULL) {
                delete node;
                node = NULL;
                return;
            }

            if (node->l == NULL) {
                left_rotate(node);
                del(val, node->l);
            } else if (node->r == NULL) {
                right_rotate(node);
                del(val, node->r);
            } else {
                if (node->l->w < node->r->w) {
                    right_rotate(node);
                    del(val, node->r);
                } else {
                    left_rotate(node);
                    del(val, node->l);
                }
            }
        }
        node->update_son();
    }

    int val_to_rank_(int val, Node* node = Root) {
        if (val == node->val)
            return size(node->l) + 1;
        else if (val < node->val)
            return val_to_rank_(val, node->l);
        else
            return size(node->l) + node->cnt + val_to_rank_(val, node->r);
    }

    int val_to_rank(int val) {
        return val_to_rank_(val) - 1;
    }

    int rank_to_val_(int rank, Node* node = Root) {
        if (rank <= size(node->l))
            return rank_to_val_(rank, node->l);
        else if (rank <= size(node->l) + node->cnt)
            return node->val;
        else
            return rank_to_val_(rank - size(node->l) - node->cnt, node->r);
    }

    int rank_to_val(int val) {
        return rank_to_val_(val + 1);
    }

    int smallerBiggest(int val) {
        Node* p = Root;
        int pre = 0;
        while (p) {
            if (val <= p->val)
                p = p->l;
            else
                pre = p->val, p = p->r;
        }
        return pre;
    }
    
    int biggerSmallest(int val) {
        Node* p = Root;
        int suf = 0;
        while (p) {
            if (val >= p->val)
                p = p->r;
            else
                suf = p->val, p = p->l;
        }
        return suf;
    }
} Treap;

/*
Usage:
    Treap treap;
    treap.insert(val);
    treap.del(val);
    treap.val_to_rank(val);
    treap.rank_to_val(val);
    treap.smallerBiggest(val);
    treap.biggerSmallest(val);
*/