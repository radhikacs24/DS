#include<stdio.h>
#include<stdlib.h>
int n; //n==max size
int top=-1;
int item;
void push(int *s,int n){
    printf("enter the item");
    scanf("%d",&item);
if(top==n-1){
    printf("stack is overflow");
}
else{
    top=top+1;
    s[top]=item;
    printf("pushed item is %d\n",s[top]);
}
}
void pop(int *s){
if(top==-1){
    printf("stack is underflow\n");
}else{
 item==s[top];
 top=top-1;
 printf("poped item is %d\n",item);
}
}
void display(int *s){
if(top==-1){
    printf("stack is underflow\n");
}else{
    for(int i=top;i>=0;i--)
    {
        printf("item is %d\n",s[i]);
}
}}
int main(){
printf("enter the maximum size:");
scanf("%d",&n);
int s[n];
int choice=0;
while(choice!=4){
printf("enter choice\n");
printf("1,push\n");
printf("2,pop\n");
printf("3,display\n");
printf("4,exit\n");
printf("enter the choice between 1 to 4=");
scanf("%d",&choice);
if(choice==1){
    push(s,n);
}else if(choice==2){
pop(s);
}else if(choice==3){
display(s);
}else if(choice==4){
exit(0);
}else{
printf("not valid!!");
}
}
}




