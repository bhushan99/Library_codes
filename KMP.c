#include <stdio.h>

void find_ff(string t,int m,int a[])
{
  int i,j;
  a[0]=0;j=0;
  for ( i = 1; i < m; )
  {
    if(t[i]==t[j]) {j++;a[i]=j;i++;}
    else if(j!=0) {j=a[j-1];} 
    else {a[i]=0;i++;}
  }
}

void kmp(int m,int n,string t,string s,int *a)
{
  int q=0,i;
  for(i=0;i<n;)
  {
    if(s[i]==t[q]) {q++;i++;}
    else if(q) {q=a[q-1];}
    else i++;
    if(q==m) {printf("%d\t",i-m);q=a[q-1];}
  }
}

int strStr(const char* s, const char* t) {
    int n=strlen(s),m=strlen(t);
    if(!n || !m) return 0;
    int f[m];
    f[0]=0;
    int i,match=0;
    for(i=1;i<m;) {
        if(t[i]==t[match]) {match++;f[i]=match;i++;}
        else if(match) match=f[match-1];
        else {f[i]=0;i++;}
    }
    match=0;i=0;
    for(;i<n;) {
        if(s[i]==t[match]) {i++;match++;}
        else if(match) match=f[match-1];
        else i++;
        if(match==m) return i-m; // to get all occurances, {ans.pb(i-m);match=f[match-1];}
    }
    return -1;
}

int main()
{
  char *s, *t;
  int m,n,i;
  printf("ENTER M,N\n");
  scanf("%d%d",&m,&n);
  t=(char *)malloc(m*sizeof(char));
  s=(char *)malloc(n*sizeof(char));
  scanf("%s\n%s",s,t);
  m=strlen(t);
  int a[m];
  n=strlen(s);
  find_ff(t,m,a);
  //for(i=0;i<m;i++) {printf("%d\t",a[i] );}
  kmp(m,n,t,s,a);
  //printf("%s\n%s",s,t );

  return 0;

}
