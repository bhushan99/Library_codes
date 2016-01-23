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

int z[3000005];

void computeZ(string s,int *z,int n) {
	int l=0,r=0;
	for(int i=1;i<n;i++) {
		if(i>r) {
			l=r=i;
			while(r<n && s[r]==s[r-l]) r++;
			z[i]=r-l;
			r--;
		}
		else {
			if(z[i-l]<r-i+1) z[i]=z[i-l];
			else {
				l=i;
				while(r<n && s[r]==s[r-l]) r++;
				z[i]=r-l;
				r--;
			}
		}
	}
	return;
}

int main() {
	int n;string s,t;cin>>n>>s>>t;
	s=s+'#'+t+t;
	computeZ(s,z,3*n+1);
	int mx=0,mxi=0;
	for(int i=n+1;i<2*n+1;i++) {if(z[i]>mx) mx=z[i],mxi=i-n-1;}
	cout<<mxi<<endl;
	return 0;
}