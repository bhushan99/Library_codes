#include <iostream>
using namespace std;
typedef struct st{
int data;
struct st* next;
}node;
node* newnode(int d){
node * tmp=new node;
tmp->data=d;
tmp->next=NULL;
return tmp;
}
void insert(node ** head,int x){
node* z=newnode(x);
node *y=*head;
*head=z;
z->next=y;
}

void print(node* head){
node* x=head;
while(x!=NULL) {cout<<x->data<<' ';x=x->next;}
cout<<endl;}

void reverse(node** head){
node *prev=NULL, *curr=*head , *next;
while(curr){
next=curr->next;
curr->next=prev;
*head=curr;
prev=curr;
curr=next;
}}

void mergealternate(node* head1,node* head2){
if(!head1||!head2) return ;
node *x=head1->next,*y=head2->next;
head1->next=head2;
head2->next=x;
mergealternate(x,y);
}
void removedup_sorted(node* head){
node *curr=head;
while(curr){
node* next=curr->next;
if(next && curr->data==next->data) {curr->next=next->next;delete next;}
else curr=curr->next;
}}
void remnode(node** head,int d){
if(!*head) return ;
node *h=*head,*pre;
if(d==h->data) {*head=h->next;return ;}
while(h&&h->data!=d) {pre=h;h=h->next;}
if(!h) return ;
pre->next=h->next;
delete(h);
}

void reverse_rec(node** head){
if(!*head) return ;
if((*head)->next==NULL) return ;
node * y=*head;
*head=(*head)->next;
reverse_rec(head);
y->next->next=y;
y->next=NULL;
}

void removedup(node** head)
{
node *curr=*head;
while(curr){
cout<<curr->data<<endl;
node *f=*head,*p;
while(f!=curr && f->data!=curr->data) {p=f;f=f->next;}
if(f==*head) {node *c=*head; *head=(*head)->next;delete(c);curr=curr->next;continue;}
if(f==curr) {curr=curr->next;}
else {p->next=f->next;delete(f);curr=curr->next;}
}
} 

int main(){
node *head1=NULL,*head2=NULL;
insert(&head1,1);
insert(&head1,2);
insert(&head1,3);
insert(&head1,4);
insert(&head1,5);
insert(&head2,1);
insert(&head2,3);
insert(&head2,5);
insert(&head2,7);
insert(&head2,9);
reverse_rec(&head1);
reverse_rec(&head2);
mergealternate(head1,head2);
removedup(&head1);
//remnode(&head1,5);
print(head1);
return 0;}

