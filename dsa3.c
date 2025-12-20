#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max 100
char stack[max];
int top=-1;
void push(char c){
 if(top>=0)
    stack[++top]=c;
  }
char pop(){
if(top>=0)
    return stack[top];
return'\0';
}
char peek(){
if (top>=0)
    return stack[top];
    return '\0';
}
int precedence(char op){
if(op=='+'||op=='-') return 1;
if(op=='*'||op=='/') return 2;
return 0;
}
void infixToPostfix(char infix[]){
char postfix[max];
int i,j=0;
char c,temp;
for(i=0;i<strlen(infix);i++){
c=infix[i];
if(isalnum(c)){
    postfix[j++]=c;
}
else if(c=='('){
            push(c);
        }
else if (c==')'){
    while((temp=pop())!='(')
            postfix[j++]=temp;
}
else if(c=='+'||c=='-'||c=='*'||c=='/'){
            while(precedence(peek())>=precedence(c))
            postfix[j++]=pop();
            push(c);
          }
}
while(top!=-11)
    postfix[j++]=pop();
    postfix[j]='\0';
printf("postfix expression: %s\n",postfix);
}
int main(){
char infix[max];
printf("enter a valid paranthesis infix expression: ");
scanf("%s",infix);
return 0;
}
