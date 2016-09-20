// Segment Tree with lazy propagation
// Edit the functions as required


#define N 30300
#define l(x) (x << 1) + 1
#define r(x) (x << 1) + 2
#define mid(l, r) ((l + r) >> 1)

int a[N];
struct node {
    ll sum;
    ll val;
    bool push;

    inline void combine(const node & left, const node & right) {
        sum = left.sum + right.sum;     // For max() change here
    }

} T[N << 2];

struct segmentTree {
    int n;
    
    segmentTree(int m) : n(m) {
        build(0, 0, n - 1);
    }

    void build(int x, int l, int r) {
        T[x].val = 0; T[x].push = false;
        if(l == r) {
            T[x].sum = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(l(x), l, m);
        build(r(x), m + 1, r);
        T[x].combine(T[l(x)], T[r(x)]);
    }

    inline void resolve(int x, int l, int r) {  // For max() change lines of this function
        if(T[x].push) {
            T[x].sum = T[x].val * (r - l + 1);  // To add the new value to the elements of the range
                                                // instead of replacing the current value and putting the new value, change = to +=
            if(l != r) {
                T[l(x)].val = T[x].val;         // Change to += to 'add' to the range and not 'replace'
                T[r(x)].val = T[x].val;         //  -do-
                T[l(x)].push = T[r(x)].push = true;
            }
            T[x].push = false;
            T[x].val = 0;
        }
    }

    void updateRange(int x, int l, int r, int ql, int qr, ll v) {
        resolve(x, l, r);
        if(l > qr || r < ql) return;
        if(l >= ql && r <= qr) {
            T[x].val = v;
            T[x].push = true;
            resolve(x, l, r);
            return;
        }
        int m = (l + r) >> 1;
        updateRange(l(x), l, m, ql, qr, v);
        updateRange(r(x), m + 1, r, ql, qr, v);
        T[x].combine(T[l(x)], T[r(x)]);
    }

    ll queryRange(int x, int l, int r, int ql, int qr) {
        resolve(x, l, r);
        if(l >= ql && r <= qr) return T[x].sum;
        ll ret = 0;
        int m = (l + r) >> 1;
        if(ql <= m) ret += queryRange(l(x), l, m, ql, qr);      // For max() change these two lines
        if(qr > m) ret += queryRange(r(x), m + 1, r, ql, qr);
        return ret;
    }

    void update(int ql, int qr, ll v) {
        updateRange(0, 0, n - 1, ql, qr, v);
    }

    ll query(int ql, int qr) {
        return queryRange(0, 0, n - 1, ql, qr);
    }
};

struct segmentTree {
    vi seg;
    int n;
    int type;
    int segN;
 
    segmentTree() {}
 
    segmentTree(int m, int type) : n(m), type(type) {
        int sz = n;
        int segN;
        for (segN = 2; segN < sz; segN <<= 1);
        seg.assign(segN * 2, -1);
        for (int i = 0; i < sz; ++i) {
            seg[segN + i] = nxt[i][type];
        }
        for (int i = segN; --i; ) {
            seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
        }
    }

    inline int query(int a, int b) {
        int segN = seg.size() >> 1;
        int ret = -1;
        for (a += segN, b += segN; a <= b; a >>= 1, b >>= 1) {
            if ( a & 1) ret = max(ret, seg[a++]);
            if (~b & 1) ret = max(ret, seg[b--]);
        }
        return ret;
    }

    
};

node seg[2 * N]; // N is some power of two

void add(int i, node x)
{
    seg[i += N] = x;
    for(i /= 2; i; i /= 2)
        seg[i] = merge(seg[i * 2], seg[i * 2 + 1]);
}

node get(int l, int r)
{
    node resL, resR;
    for(l += N, r += N; l < r; l /= 2, r /= 2)
    {
        if(l % 2)
            resL = merge(resL, seg[l++]);
        if(r % 2)
            resR = merge(seg[--r], resR);
    }
    return merge(resL, resR);
}







typedef long long LL;

LL min(LL a, LL b) {
    if (a < b) {
        return a;
    }
    
    return b;
}

#define offset (1 << 18)

LL delta[offset + offset], mini[offset + offset];

inline void updateVal(int x) {
    while (true) {
        x >>= 1;
        if (x == 0) {
            break;
        }
        mini[x] = min(mini[2 * x] + delta[2 * x], mini[2 * x + 1] + delta[2 * x + 1]);
    }
}

void inc(int a, int b, LL d) {
    for (a += offset, b += offset; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
        if (a & 1) {
            delta[a] += d;
            updateVal(a);
        }
        if ((b & 1) == 0) {
            delta[b] += d;
            updateVal(b);
        }
    }
}

inline LL realVal(int x) {
    LL r = mini[x];
    for (; x > 0; x >>= 1) {
        r += delta[x];
    }
    return r;
}

LL RMQ(int a, int b) {
    LL r = 1LL << 62;
    
    for (a += offset, b += offset; a <= b; a = (a + 1) >> 1, b = (b - 1) >> 1) {
        r = min(r, min(realVal(a), realVal(b)));
    }
    
    return r;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        LL t;
        scanf("%I64d", &t);
        inc(i, i, t);
    }
    
    
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b, d;
        char c;
        scanf("%d%d%c", &a, &b, &c);
        if (a <= b) {
            if (c == ' ') {
                scanf("%d", &d);
                inc(a, b, d);
            } else {
                printf("%I64d\n", RMQ(a, b));
            }
        } else {
            if (c == ' ') {
                scanf("%d", &d);
                inc(0, b, d);
                inc(a, n - 1, d);
            } else {
                printf("%I64d\n", min(RMQ(0, b), RMQ(a, n - 1)));
            }
        }
        
    }
    return 0;
}