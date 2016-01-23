#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000

char * multiply(char [],char[]);
int main(){
    char a[MAX];
    char b[MAX];
    char *c;
    int la,lb;
    int i;
    printf("Enter the first number : ");
    scanf("%s",a);
    printf("Enter the second number : ");
    scanf("%s",b);
    printf("Multiplication of two numbers : ");
    c = multiply(a,b);
    printf("%s",c);
    return 0;
}

char * multiply(char a[],char b[]){
    static char mul[MAX];
    char c[MAX];
    char temp[MAX];
    int la,lb;
    int i,j,k=0,x=0,y;
    long int r=0;
    long sum = 0;
    la=strlen(a)-1;
        lb=strlen(b)-1;
   
        for(i=0;i<=la;i++){
                a[i] = a[i] - 48;
        }

        for(i=0;i<=lb;i++){
                b[i] = b[i] - 48;
        }

    for(i=lb;i>=0;i--){
         r=0;
         for(j=la;j>=0;j--){
             temp[k++] = (b[i]*a[j] + r)%10;
             r = (b[i]*a[j]+r)/10;
         }
         temp[k++] = r;
         x++;
         for(y = 0;y<x;y++){
             temp[k++] = 0;
         }
    }
   
    k=0;
    r=0;
    for(i=0;i<la+lb+2;i++){
         sum =0;
         y=0;
         for(j=1;j<=lb+1;j++){
             if(i <= la+j){
                 sum = sum + temp[y+i];
             }
             y += j + la + 1;
         }
         c[k++] = (sum+r) %10;
         r = (sum+r)/10;
    }
    c[k] = r;
    j=0;
    for(i=k-1;i>=0;i--){
         mul[j++]=c[i] + 48;
    }
    mul[j]='\0';
    return mul;
}

/**
  A function that multiplies two positive integer numbers stored as strings.

  @Assumptions:
    1) This program does not handle negative numbers. Not even +/- signs.
    2) It will not prune down leading 0's.
    3) The two input strings consist of valid digits only.

  @Algorithm:
    0) Create a result string of size (a.length + b.length).
    1) Take the last untouched digit (least-significant to start with) of one of
       the given numbers (in this case I picked 'b').
    2) Multiply it with all the digits of the other number ('a').
    3) Accumulate the outcome in the result string.
    4) Goto step 1.

*/

#include <iostream>

#define INT(c)  ((int)((c) - '0'))
#define CHAR(i) ((char)(i + int('0')))

using namespace std;

string multiply(const string &a, const string &b)
{
  /* initially fill the result string with 0's */
  size_t total_len= a.length() + b.length();
  string result(total_len, '0');

  int num;                                      /* intermediate store */
  int i, j;
  int last_pos_i, last_pos_j, last_pos_k;

  last_pos_i= total_len - 1;

  /* i-loop */
  for (i= b.length() - 1; i >= 0; i --)
  {
    last_pos_j= last_pos_i;

    /* j-loop */
    for (j= a.length() - 1; j >=0; j --)
    {
      last_pos_k= last_pos_j;
      num= INT(a.at(j)) * INT(b.at(i));

      /* k-loop : the actual updation of result string takes place here. */
      while (num)
      {
        num += INT(result.at(last_pos_k));
        result.at(last_pos_k)= CHAR(num % 10);
        /* 'carry' it forward.. ;)  */
        num= num / 10;
        last_pos_k --;
      }

      last_pos_j --;
    }

    last_pos_i --;
  }
  return result;
}

int main()
{
  string n1("99");
  string n2("9");
  cout << n1 << " * " << n2 << " = "  << multiply(n1, n2) << endl;
  return 0;
}

string add(string s,string t){
	int i,j,l1=s.length(),l2=t.length();
	int l3=max(l1,l2)+1;
	string ans(l3,'0');
	int pos=l3-1,carry=0;
	for(i=l1-1,j=l2-1;i>=0&&j>=0;i--,j--){
		ans[pos]=(s[i]-'0'+t[j]-'0'+carry)%10+'0';
		carry=(s[i]-'0'+t[j]-'0'+carry)/10;
		pos--;
	}
	while(i>=0) {ans[pos]=(s[i]-'0'+carry)%10+'0';carry=(s[i]-'0'+carry)/10;i--;pos--;}
	while(j>=0) {ans[pos]=(t[j]-'0'+carry)%10+'0';carry=(t[j]-'0'+carry)/10;j--;pos--;}
	if(carry) ans[pos]+=carry;
	i=0;
	while(ans[i]=='0') i++;
	return ans.substr(i,l3-i);
}
