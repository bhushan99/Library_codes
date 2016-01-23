string add(string A,string B) {
    string ans="";
    int carry=0;
    int m=A.size(),n=B.size();
    for(int i=1;i<=min(m,n);i++) {
        int ct=A[m-i]-'0'+B[n-i]-'0'+carry;
        if(ct/10==0) carry=0;
        else ct%=10,carry=1;
        ans=(char)(ct+'0')+ans;
    }
    for(int i=min(m,n)+1;i<=n;i++) {
        int ct=B[n-i]-'0'+carry;
        if(ct/10==0) carry=0;
        else ct%=10,carry=1;
        ans=(char)(ct+'0')+ans;
    }
    for(int i=min(m,n)+1;i<=m;i++) {
        int ct=A[m-i]-'0'+carry;
        if(ct/10==0) carry=0;
        else ct%=10,carry=1;
        ans=(char)(ct+'0')+ans;
    }
    if(carry) ans=string("1")+ans;
    return ans;
}

string mult(string A,int x) {
    if(!x) return string("0");
    string ans="";
    int n=A.size();
    int carry=0;
    for(int i=n-1;i>=0;i--) {
        int ct=x*(A[i]-'0')+carry;
        carry=ct/10;
        ct%=10;
        ans=(char)(ct+'0')+ans;
    }
    if(carry) ans=(char)(carry+'0')+ans;
    return ans;
}

string Solution::multiply(string A, string B) {
    int i=0,j=0;
    while(A[i]=='0') i++;
    while(B[j]=='0') j++;
    int m=A.size(),n=B.size();
    if(i==m||j==n) return string("0");
    A=A.substr(i,m-i);B=B.substr(j,n-j);
    m=A.size(),n=B.size();
    string ans="0";
    for(int i=n-1;i>=0;i--) {
        int x=(int)(B[i]-'0');
        string res=mult(A,x);
        res+=string(n-1-i,'0');
        ans=add(ans,res);
    }
    return ans;
}
