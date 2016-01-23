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


class node{
public:
	int ind,wt;
	bool operator<(const node& n1) const{
		return wt>n1.wt;
	}
	node(int x,int y) {ind=x;wt=y;}
	node() {ind=0;wt=0;}
};
	
//typedef std::priority_queue<int,std::vector<int>,std::greater<int>()> mypq_type;

int main() {
	int t;cin>>t;
	while(t--) {
		int n,m,st,dest,x,y,z;cin>>n>>m>>st>>dest;st--;dest--;
		vector<node> adj[n];
		rep(i,m) {
			cin>>x>>y>>z;
			node n1;n1.ind=x-1;n1.wt=z;
			adj[y-1].pb(n1);
			n1.ind=y-1;
			adj[x-1].pb(n1);
		}
		priority_queue<node> pq;
		pq.push(node(st,0));int dist[n];memset(dist,-1,sizeof dist);
		bool vis[n];rep(i,n) vis[i]=false;dist[st]=0;
		while(!pq.empty()) {
			node n1=pq.top();pq.pop();
			if(vis[n1.ind]) continue;
			vis[n1.ind]=true;
			dist[n1.ind]=n1.wt;
			if(n1.ind==dest) {dist[dest]=n1.wt;break;}
			for(std::vector<node>::iterator it=adj[n1.ind].begin();it!=adj[n1.ind].end();it++) {
				if(!vis[(*it).ind]) {
					if(dist[(*it).ind]==-1||dist[(*it).ind]>n1.wt+(*it).wt) pq.push(node((*it).ind,n1.wt+(*it).wt));
				}
			}
		}
		cout<<dist[dest]<<endl;
	}
	return 0;
}

/*
#include<cstdio>
#include<set>
#include<vector>
#define FOR(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define REP(i,n) FOR(i,0,n-1)
#define TR(i,c)\
    for(typeof(c.begin())i=c.begin();i!=c.end();++i)
#define pb push_back
typedef std::pair<int,int> pii;
int p[100010],n,m,x,y,s,f,v,to,z;
long long d[100010];
struct cmp{bool operator() (const int&l,const int&r)const{return d[l]<=d[r];};};
std::set<int,cmp>q;
std::vector< pii >g[100010];
main(){
    scanf("%d%d",&n,&m);s=n-1;
    REP(i,m)
        scanf("%d%d%d",&x,&y,&z),
        --x,--y,g[x].pb(pii(y,z)),g[y].pb(pii(x,z));
    REP(i,n)d[i]=(1ll<<60);
    d[s]=0;p[s]=-1;q.insert(s);
    while(!q.empty()){
        v=*q.begin();q.erase(q.begin());
        TR(it,g[v]){
            to=it->first,z=it->second;
            if (d[v]+z<d[to])
                q.erase(to),
                d[to]=d[v]+z,
                p[to]=v,
                q.insert(to);
        }
    }
    if (d[f]==(1ll<<60)) puts("-1");
    else
        for(x=f;x!=-1;x=p[x])printf("%d ",x+1);
}
*/

