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

ll countInv(ll n,int a[]) {
	if(n<=1) return 0;
	ll ct1,ct2,ct3;
	ct1=countInv(n/2,a);
	ct2=countInv(n-n/2,a+n/2);
	ct3=0;
	int b[n];
	int i=0,j=n/2,k=0;
	while(i<n/2&&j<n) {
		if(a[i]<=a[j]) {
			b[k]=a[i];
			k++;i++;
		}
		else {
			b[k]=a[j];
			ct3+=n/2-i;
			k++;j++;
		} 
	}
	while(i<n/2) {
		b[k]=a[i];
		k++;i++;
	}
	while(j<n) {
		b[k]=a[j];
		k++;j++;
	}
	rep(i,n) a[i]=b[i];
	return ct1+ct2+ct3;
}

int main(){
	int t,t1;cin>>t;t1=t;
	while(t1--){
		cout<<"Case "<<t-t1<<": ";
		int n,k;cin>>n>>k;
		int a[n];
		rep(i,n) cin>>a[i];
		ll inv = countInv(n,a);
		bool flag=false;
		FOR(i,1,n-1) if(a[i]==a[i-1]) flag=true;
		if(inv>=(ll)k) cout<<inv-(ll)k<<endl;
		else if(!flag) cout<< ((ll)k-inv)%2 <<endl;
		else cout<<0<<endl;
	}
	return 0;
}