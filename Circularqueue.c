#include<stdio.h>
#include<conio.h>
#define max 10
int q[max];
int rear;
int front;
int item;
void enqueue(){
printf("Enter the number to be inserted\n");
scanf("%d",&item);
if(front==(rear=1)%max)
    {
    printf("queue i full\n");
}
else if(front==-1){
front=0;
rear=0;
q[rear]=item;
printf("%d i inserted\n",item);
}
else{
rear=((rear+1)%max);
q[rear]=item;
printf("%d is inserted\n",item);
}
}
void dequeue(){
if(front==-1){
    printf("queue is full\n");
}
else if(front==rear){
    front=-1;
    rear=-1;
}else{
front=(front+1)%max;
}
printf("%d is deleted\n",item);

void display(){
if(front==-1){
    printf("queue s full\n");
}
else{
    int i;
    for(i=front;i<=rear;i=(i+1)%max){
            if (i == rear) break;
            i =(i + 1) % max;
        }
        printf("\n");
        printf("%d",q[i]);
    }
}
int main(){
int choice;
while(choice!=4){
    printf("enter your choice: 1.enqueue,2.dequeue,3.display,4.exit\n");
    scanf("%d",&choice);
    if(choice==1){
        enqueue();
    }else if(choice==2){
    dequeue(0);
    }else if(choice==3){
    display();
    }else if(choice==4){
    exit(0);
    }else{
    printf("invalid choice\n");
  }
}}
