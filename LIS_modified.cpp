#include <iostream>

#include <limits.h>

#include <algorithm>

#include <vector>
 
using namespace std;

int main(){

    int n,*a,j,i,INF=INT_MAX,max;

    vector<int> d;

    cin>>n;
    a=new int[n];

    for(i=0;i<n;i++)

        cin>>a[i];

    d.push_back(-INF);

    for (i=1; i<n; ++i)

        d.push_back(INF);

    for (i=0; i<n; i++) {

        j = int(upper_bound(d.begin(), d.end(), a[i]) - d.begin());

        if (d[j-1] <=a[i] && a[i] <=d[j])

            d[j] = a[i];

    }

    for(i=n-1;i>0;i--)

        if(d[i]!=INF)

            break;

    cout<<i-1+1<<endl;

    return 0;

} 
