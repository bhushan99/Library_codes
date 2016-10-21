#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end() 
#define tr(c,inst) for(auto &inst : c) 
#define present(c,val) ((c).find(val) != (c).end()) 
#define cpresent(c,val) (find(all(c),val) != (c).end()) 
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, x, y) for(int i= (x); i<= (y); ++i)
#define mset(a, v) memset(a, v, sizeof(a))
#define sz(x) (int)(x).size()

#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()

#define sci(var) scanf("%d",&(var))
#define scl(var) scanf("%lld",&(var)) 
#define scf(var) scanf("%lf",&(var))

#define BLOCK {bool first = true;os << "[";for(auto i : v){if(!first)os << ", ";os << i;first = false;}return os << "]";}
template <typename T1, typename T2> 
inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> inline std::ostream &operator << (std::ostream & os,const vector<T>& v) BLOCK
template<typename T1, typename T2> inline std::ostream &operator << (std::ostream & os,const map<T1,T2>& v) BLOCK
template<typename T> inline std::ostream &operator << (std::ostream & os,const set<T>& v) BLOCK
struct debugger {template<typename T> debugger& operator , (const T& v) {cerr<<v<<endl;return *this;} }dbg;
#define debug(args...) {dbg,args;}
#define dbvar(var) cerr<<#var<<" = "<<var<<endl;
#define dbarr(var,n) cerr<<#var<<" = { ";rep(i,n) cerr<<var[i]<<" ";cerr<<"}"<<endl; 
#define dbmat(var,m,n) cerr<<#var<<" = \n";rep(i,m) {rep(j,n) cerr<<var[i][j]<<" ";cerr<<endl;}

#define MOD ((int)1e9+7)
#define N 100005

int main() {
	
	return 0;
}