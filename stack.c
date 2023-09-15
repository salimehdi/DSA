#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX],top=-1;
void push();
void pop();
void display();
int main()
{
    int ch;
    while(1)
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            default:printf("invalid choice\n");
        }
    }
}
void push()
{
    int item;
    if(top==MAX-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        printf("enter the element to be pushed\n");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;
    }
}
void pop()
{
    int item;
    if(top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        item=stack[top];
        top=top-1;
        printf("popped item is %d\n",item);
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("stack elements are\n");
        for(i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

