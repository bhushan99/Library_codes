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
set<int> hs[600001];
int main() {
	int n,m;cin>>n>>m;
	string x,y,z;
	hash<string> hx;
	while(n--) {
		cin>>x;
		hs[x.length()].insert(hx(x));
	}
	while(m--) {
		cin>>x;
		bool ans=false;
		y=z=x;
		rep(i,x.length()) {
			if(x[i]=='a') y[i]='b',z[i]='c';
			else if(x[i]=='b') y[i]='a',z[i]='c';
			else y[i]='a',z[i]='b';
			if(present(hs[x.length()],hx(y))) {cout<<"YES\n";ans=true;break;}
			else if(present(hs[x.length()],hx(z))) {cout<<"YES\n";ans=true;break;}
			y[i]=z[i]=x[i];
		}
		if(!ans) cout<<"NO\n";
	}
	return 0;
}