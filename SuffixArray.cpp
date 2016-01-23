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

#define MAXN 5005

struct entry { 
	int nr[2], p;
} L[MAXN];

int cmp(struct entry a, struct entry b){
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

void getSuffixArray(int* suffix_array,string str) {
		int type,stp,cnt,i;
		int n=str.length(); 
		int rows = ceil(log2(n));
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

		for (i = 0; i < n; i ++){ 
			L[i].nr[0] = P[stp][i]; L[i].nr[1] = i;
		}
		sort(L,L+n,cmp);
		for (i = 0; i < n; i ++){ 
			 suffix_array[i] = L[i].nr[1];
		}
}

namespace SuffixArray
{
    const int MXN = 1 << 21;
    string S;
    int N, gap;
    int sa[MXN], pos[MXN], tmp[MXN], lcp[MXN];

    bool sufCmp(int i, int j)
    {
        if (pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i < N && j < N) ? pos[i] < pos[j] : i > j;
    }

    void buildSA()
    {
        N = sz(S);
        rep(i, N) sa[i] = i, pos[i] = S[i];
        for (gap = 1;; gap *= 2)
        {
            sort(sa, sa + N, sufCmp);
            rep(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
            rep(i, N) pos[sa[i]] = tmp[i];
            if (tmp[N - 1] == N - 1) break;
        }
    }

    void buildLCP()
    {
        for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
        {
            for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
            ++k;
            lcp[pos[i]] = k;
            if (k)--k;
        }
    }
} // end namespace SuffixArray

int main(){

	// HASHING CODE:
	hash<string> hx; cout<<hx(string("hello"))<<endl;

	string str;
	int t,n,q,k,rows,type,stp,cnt,i,ans,r,X,Y;

	cin>>str;
	n=str.length();
	int suffix_array[n];
	getSuffixArray(suffix_array,str);
	SuffixArray::S=str;
	SuffixArray::buildSA();
	SuffixArray::buildLCP();
	rep(i,n) cout<<SuffixArray::lcp[i]<<endl;
	return 0;

} 




// CODEFORCES code

template <typename T> vector<T> readVector(int n) { vector<T> res(n); for (int i = 0 ; i < n ; i++) cin >> res[i]; return res; }

// z-function implementation taken from e-maxx.ru
vector<int> zFunction(vector<int> &s) {
    int n = (int) s.size();
    vector<int> z (n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]])
            ++z[i];
        if (i+z[i]-1 > r)
            l = i,  r = i+z[i]-1;
    }
    return z;
}

int findNumberOfOccurences(vector<int> &v, vector<int> &pattern) {
    if (pattern.size() == 0) return v.size() + 1;

    vector<int> str = pattern;
    str.insert(str.end(), v.begin(), v.end());
    vector<int> z = zFunction(str);

    int result = 0;

    for (int i = pattern.size() ; i < z.size() ; i++) {
        if (z[i] >= pattern.size()) result++;
    }
        
    return result;
}

vector<int> toDiffArray(vector<int> &v) {
    vector<int> result;
    for (int i = 1 ; i < v.size() ; i++)
        result.push_back(v[i] - v[i - 1]);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    int m; cin >> m;
	
    vector<int> a = readVector<int>(n);
    vector<int> b = readVector<int>(m);

    vector<int> aDiff = toDiffArray(a);
    vector<int> bDiff = toDiffArray(b);

    int result = findNumberOfOccurences(aDiff, bDiff);

    cout << result;
}
