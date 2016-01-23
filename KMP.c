#include <stdio.h>

void find_ff(char *t,int m,int a[])
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

void kmp(int m,int n,char *t,char *s,int *a)
{
  int q=0,i;
  for(i=0;i<n;)
  {
    if(s[i]==t[q]) {q+=1;i++;}
    else if(q) {q=a[q-1];}
    else i++;
    if(q==m) {printf("%d\t",i-m);q=a[q-1];}
  }
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
