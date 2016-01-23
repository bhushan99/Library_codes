#include <bits/stdc++.h>
#define fi(n) scanf("%d",&n)
#define rep(i,a,b) for(__typeof(a) i = (a); i < (b) ; i++)
#define MAXN 5005
using namespace std;


struct entry { 
	int nr[2], p;
} L[MAXN];

int cmp(struct entry a, struct entry b){
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

int main(){
	string str;
	int t,n,q,k,rows,type,stp,cnt,i,ans,r,X,Y;
	fi(t);
	while(t--){
		fi(n);fi(q);
		cin>>str;
		//////////////////////
		rows = ceil(log2(n));
		rows++;
		int P[rows][n]; type = 0;
		for(i=0;i<n;i++) P[0][i] = str[i]-'a';
		//////////////////////
		for (stp = 1, cnt = 1; cnt < n; stp ++, cnt <<= 1) {
			for (i = 0; i < n; i ++){ 
				L[i].nr[0] = P[stp - 1][i];
				L[i].nr[1] = i + cnt < n ? P[stp - 1][i + cnt] : -1;
				L[i].p = i; 
			}
			sort(L, L + n, cmp);
			type = 0;
			for (i = 0; i < n; i ++) 
				P[stp][L[i].p] = (i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1]) ? P[stp][L[i - 1].p] : i;
		}
		//////////////////////
		stp--;
		
		int suffix_array[n]; // i'th element of this array will tell you the i'th suffix's (after sorting) original start point in the given array 

		for (i = 0; i < n; i ++){ 
			L[i].nr[0] = P[stp][i]; L[i].nr[1] = i;
		}
		sort(L,L+n,cmp);
		for (i = 0; i < n; i ++){ 
			 suffix_array[i] = L[i].nr[1];
		}
		while(q--){
			fi(k);
			ans = 0;
			for(i=0;i<=n-k;i++){
				X = suffix_array[i]; Y = suffix_array[i+k-1];
				if(X==Y)
					ans += n-X;
				else{
					for(r=stp-1;r>=0 && X<n && Y< n;r--){
						if(P[r][X]==P[r][Y]){
							ans += 1<<r;
							X += 1<<r;
							Y += 1<<r;
						}
					}
				}
			}
			//////////////////////
			cout<<ans<<endl;
		}
		return 0;
	}
} 