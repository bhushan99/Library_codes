#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++) 
#define present(c,val) ((c).find(val) != (c).end()) 
#define cpresent(c,val) (find(all(c),val) != (c).end()) 
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, x, y) for(int i= (x); i<= (y); ++i)
#define FORR(i, x, y) for(int i= (y); i>= (x); --i)

#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
#define debug(var) cerr<<#var<<" = "<<(var)<<endl;
#define debugarr(var,n) cerr<<#var<<" = { ";rep(i,n) cerr<<var[i]<<" ";cerr<<"}"<<endl; 
#define debugmat(var,m,n) cerr<<#var<<" = \n";rep(i,m) {rep(j,n) cerr<<var[i][j]<<" ";cerr<<endl;}

ll a[100005];
ll sg[270000];

inline void readint(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    }
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    if(neg)
        x = -x;
}

void build(int index,int start,int end) {
	if(start==end) sg[index]=a[start];
	else {
		int mid=(start+end)/2;
		build(2*index,start,mid);
		build(2*index+1,mid+1,end);
		sg[index]=sg[2*index]+sg[2*index+1];
	}
}

void update(int index,int start,int end,int q1,int q2) {
	if(start==end) {sg[index]=sqrt(sg[index]);return;}
	if(start==q1 && end==q2) {
 		if(sg[index]>end-start+1) {
			int mid=(start+end)/2;
			update(2*index,start,mid,start,mid);
			update(2*index+1,mid+1,end,mid+1,end);
			sg[index]=sg[2*index]+sg[2*index+1];
		}
	} else {
		if(sg[index]>end-start+1) {
			int mid=(start+end)/2;
			if(q1>mid) update(2*index+1,mid+1,end,q1,q2);
			else if (q2<mid+1) update(2*index,start,mid,q1,q2);
			else {
				update(2*index,start,mid,q1,mid);
				update(2*index+1,mid+1,end,mid+1,q2);
			}
			sg[index]=sg[2*index]+sg[2*index+1];
		}
	}
}

ll query(int index,int start,int end,int q1,int q2) {
	if(start==end) {return sg[index];}
	if(start==q1 && end==q2) {
 		return sg[index];
	} else {
		int mid=(start+end)/2;
		if(q1>mid) return query(2*index+1,mid+1,end,q1,q2);
		else if (q2<mid+1) return query(2*index,start,mid,q1,q2);
		else return query(2*index,start,mid,q1,mid)+query(2*index+1,mid+1,end,mid+1,q2);
	}
}

int main() {
	int n;cin>>n;int ct=1;
	while(!feof(stdin)) {
		cout<<"Case #"<<ct<<":\n";ct++;
		rep(i,n) cin>>a[i];
		build(1,0,n-1);
		int q;readint(q);
		while(q--) {
			int x,y,z;readint(x);readint(y);readint(z);
			if(!x) update(1,0,n-1,y-1,z-1);
			else cout<<query(1,0,n-1,y-1,z-1)<<endl;
		}
		cout<<endl;
		cin>>n;
	}
	return 0;
}

struct SegmentTreeNode {
	int start, end;
	ll total, pendingUpdate;
	
	SegmentTreeNode() : total(0), pendingUpdate(0) {}
	
	void assignLeaf(ll value) {
		total = value;
	}
	
	void merge(SegmentTreeNode& left, SegmentTreeNode& right) {
		total = left.total + right.total;
		if (left.pendingUpdate > 0)
			total += left.pendingUpdate * (left.end - left.start + 1);
		if (right.pendingUpdate > 0)
			total += right.pendingUpdate * (right.end - right.start + 1);
	}
	
	ll query() {
		return total;
	}
	
	bool hasPendingUpdate() {
		return pendingUpdate != 0;
	}
	
	void applyPendingUpdate() {
		total += (end - start + 1) * pendingUpdate;
		pendingUpdate = 0;
	}
	
	void addUpdate(ll value) {
		pendingUpdate += value;
	}
	
	ll getPendingUpdate() {
		return pendingUpdate;
	}
};

// TEMPLATE SOURCE: https://github.com/kartikkukreja/blog-codes/blob/master/src/spoj_HORRIBLE.cpp
template<class InputType, class UpdateType, class OutputType>
class SegmentTree {
	SegmentTreeNode* nodes;
	int N;
	
public:
	SegmentTree(InputType arr[], int N) {
		this->N = N;
		nodes = new SegmentTreeNode[getSegmentTreeSize(N)];
		buildTree(arr, 1, 0, N-1);
	}
	
	~SegmentTree() {
		delete[] nodes;
	}
	
	OutputType query(int start, int end) {
		SegmentTreeNode result = query(1, start, end);
		return result.query();
	}
	
	void update(int start, int end, UpdateType value) {
		update(1, start, end, value);
	}
	
private:
	void buildTree(InputType arr[], int stIndex, int start, int end) {
		nodes[stIndex].start = start, nodes[stIndex].end = end;
		
		if (start == end) {
			nodes[stIndex].assignLeaf(arr[start]);
			return;
		}
		
		int mid = (start + end) / 2,
			leftChildIndex = 2 * stIndex,
			rightChildIndex = leftChildIndex + 1;
			
		buildTree(arr, leftChildIndex, start, mid);
		buildTree(arr, rightChildIndex, mid + 1, end);
		nodes[stIndex].merge(nodes[leftChildIndex], nodes[rightChildIndex]);
	}
	
	int getSegmentTreeSize(int N) {
		int size = 1;
		for (; size < N; size <<= 1);
		return size << 1;
	}
	
	SegmentTreeNode query(int stIndex, int start, int end) {
		if (nodes[stIndex].start == start && nodes[stIndex].end == end) {
			SegmentTreeNode result = nodes[stIndex];
			if (result.hasPendingUpdate())
				result.applyPendingUpdate();
			return result;
		}
		
		int mid = (nodes[stIndex].start + nodes[stIndex].end) >> 1,
			leftChildIndex = stIndex << 1,
			rightChildIndex = leftChildIndex + 1;			
		SegmentTreeNode result;
		
		if (start > mid)
			result = query(rightChildIndex, start, end);
		else if (end <= mid)
			result = query(leftChildIndex, start, end);
		else {
			SegmentTreeNode leftResult = query(leftChildIndex, start, mid),
							rightResult = query(rightChildIndex, mid+1, end);
			result.start = leftResult.start;
			result.end = rightResult.end;
			result.merge(leftResult, rightResult);
		}
		
		if (nodes[stIndex].hasPendingUpdate()) {
			result.addUpdate(nodes[stIndex].getPendingUpdate());
			result.applyPendingUpdate();
		}		
		return result;
	}
	
	void update(int stIndex, int start, int end, UpdateType value) {
		if (nodes[stIndex].start == start && nodes[stIndex].end == end) {
			nodes[stIndex].addUpdate(value);
			return;
		}
		
		int mid = (nodes[stIndex].start + nodes[stIndex].end) >> 1,
			leftChildIndex = stIndex << 1,
			rightChildIndex = leftChildIndex + 1;
			
		if (start > mid)
			update(rightChildIndex, start, end, value);
		else if (end <= mid)
			update(leftChildIndex, start, end, value);
		else {
			update(leftChildIndex, start, mid, value);
			update(rightChildIndex, mid+1, end, value);
		}
		nodes[stIndex].merge(nodes[leftChildIndex], nodes[rightChildIndex]);
	}
};

int A[100005];

int main() {
	int T, N, C, i, p, q, v;
	
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &C);
		SegmentTree<int,ll,ll> st(A, N);

		while (C--) {
			scanf("%d", &i);			
			if (i == 0) {
				scanf("%d%d%d", &p, &q, &v);
				st.update(p-1, q-1, v);
			} else {
				scanf("%d%d", &p, &q);
				printf("%lld\n", st.query(p-1, q-1));
			}
		}
	}	
	
	return 0;
}