
#include <stdio.h>

#include<stdlib.h>

struct node{
int info ;
struct node *link;
};
struct node *createlist(struct node *start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start,int data);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
struct node *addafter(struct node *start,int data,int item);
struct node *addbefore(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *del(struct node *start,int data);
struct node *reverse(struct node *start);

void display(struct node *start){struct node *p;
if(start==NULL)
{
    printf("list is empty");
    return ;
}
p=start;
printf("list is ");
while(p!=NULL){
        printf("%d",p->info);
p=p->link;
}
printf("\n");
}



void count(struct node *start){
struct node *p;
int cnt=0;
p=start;
while(p!=NULL){
   p=p->link;
    cnt++;
}
printf("%d",cnt);
}




void search(struct node *start,int data){
struct node *p=start;
int pos=1;
while(p!=NULL){
    if(p->info==data){
        printf("the data item is %d at posuitoin",data,pos);
        return;
    }
    p=p->link;
    pos++;

}
printf("item is not found");

}


struct node *addatbeg(struct node *start,int data ){
struct node *tmp;
tmp=(struct node *)malloc(sizeof(struct node));
tmp->info=data;
tmp->link=start;
start=tmp;
return start;
}


struct node *addatend(struct node *start,int data)
{struct node *tmp;
tmp=(struct node *)malloc(sizeof(struct node));
struct node *p;
    p=start;
while(p->link!=NULL){
      p=p->link;

      }
tmp->info=data;
p->link=tmp;
tmp->link=NULL;
return start;
}
struct node *addafter(struct node *start,int data,int item)
{struct node *tmp,*p;
tmp=(struct node *)malloc(sizeof(struct node *));
p=start;
while(p!=NULL){
    if(p->info==item)
    {tmp->link=p->link;
    tmp->info=data;
    p->link=tmp;
    return start;

    }
    p=p->link;

}

   printf("item not present");
   return start;



}
struct node *addbefore(struct node *start,int data ,int item){

struct node *tmp,*p;
tmp=(struct node *)malloc(sizeof(struct node));
p=start;
while(p!=NULL){
    if(p->link->info==item){
      tmp->info=data;
      tmp->link=p->link;
      p->link=tmp;
      return start;

    }
   p=p->link;

}
return start;

}

struct node *addatpos(struct node *start,int data,int pos ){
struct node *p,*tmp;
tmp=(struct node *)malloc(sizeof(struct node));
p=start;
int i;
for(i=1;i<pos-1&&p!=NULL;i++)
   {

   p=p->link;}
   tmp->info=data;
tmp->link=p->link;
p->link=tmp;


return start;
}
struct node *createlist(struct node *start){
int i,n,data;
printf("enter the number of nodes to be inserted");
scanf("%d",&n);
start=NULL;
if(n==0)
return start;
printf("enter the data to be inserted ");
scanf( "%d",&data);
start=addatbeg(start,data);
for(i=2;i<=n;i++){
    printf("enter the data to be inserted ");
    scanf("%d",&data);
    start=addatend(start,data);

}
return start;


}
struct node *del(struct node *start,int data){
struct node *tmp,*p;
if(start=NULL){
    printf("it is empty ");


}
if(start->info==data){
    tmp=start;
    start=start->link;
    free(tmp);
    return start;
}
p=start;
while(p!=NULL){
    if(p->link->info==data){
        tmp=p->link;
        p->link=tmp->link;
        free(tmp);

        return start;}
    p=p->link;


}
return start;
}
struct node *reverse(struct node *start)
{struct node *prev,*ptr,*next;
prev=NULL;
ptr=start;
while(ptr!=NULL){
    next=ptr->link;
    ptr->link=NULL;
    prev=ptr;
    ptr=next;
}
start=prev;
return start;
}


