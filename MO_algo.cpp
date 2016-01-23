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
#define dmax numeric_limits<double>::max()
#define dmin numeric_limits<double>::min()
#define fmax numeric_limits<float>::max()
#define fmin numeric_limits<float>::min()
#define sqr(x) (x)*(x)

int ct[1000005]={0},anst=1,n,sz;

typedef struct node{
	int i,j,k;
}node;

bool func(node p1,node p2){
	if(p1.i/sz!=p2.i/sz) return p1.i/sz<p2.i/sz;
	return p1.j<p2.j;
}

int main(){
	cin>>n;sz=ceil(sqrt(n));int a[n];for(int i=0;i<n;i++) cin>>a[i];
	int q;cin>>q;
	int ans[q];node arr[q];
	for(int i=0;i<q;i++){
		cin>>arr[i].i>>arr[i].j;arr[i].i--;arr[i].j--;
		arr[i].k=i;
	}
	sort(arr,arr+q,func);
	int currL=0,currR=0;
	ct[a[0]]=1;
	for(int i=0;i<q;i++){
		while(currL<arr[i].i) {ct[a[currL]]--;if(ct[a[currL]]==0) anst--;currL++;}
		while(currL>arr[i].i) {ct[a[currL-1]]++;if(ct[a[currL-1]]==1) anst++;currL--;}
		while(currR<arr[i].j) {ct[a[currR+1]]++;if(ct[a[currR+1]]==1) anst++;currR++;}
		while(currR>arr[i].j) {ct[a[currR]]--;if(ct[a[currR]]==0) anst--;currR--;}
		ans[arr[i].k]=anst;
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}