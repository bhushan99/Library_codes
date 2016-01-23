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

#define MAXN 100005
#define MOD 5000000

int n,k,BIT[51][MAXN+5],arr[10005],dp[51],val[51][MAXN+5];
bool vis[MAXN];

int read(int ind,int sel) {
	int sum=0;
	while(ind>0) {
		sum=(sum+BIT[sel][ind])%MOD;
		ind-=ind&-ind;
	}
	return sum;
}

void update(int ind,int sel,int freq) {
	while(ind<MAXN) {
		BIT[sel][ind]=(BIT[sel][ind]+freq)%MOD;
		ind+=ind&-ind;
	}
}

int main() {
	cin>>n>>k;
	rep(i,n) cin>>arr[i];
	rep(i,n) {
		for(int j=0;j<k-1;j++) {
			dp[j]=read(arr[i],j);
			dp[j]=(dp[j]-val[j][arr[i]]+MOD)%MOD;
			val[j][arr[i]]=dp[j];	
		}
		if(!vis[arr[i]]) vis[arr[i]]=true,update(arr[i]+1,0,1);
		for(int j=1;j<k;j++) update(arr[i]+1,j,dp[j-1]);
	}
	cout<<read(MAXN,k-1)<<endl;
	return 0;
}