#include<stdio.h>

int stack[50], top=-1;

int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push()
{
    if(top==49)
    {
        printf("\nCannot push, stack is full!\n");
        return;
    }
    int data;
    printf("\nPush: ");
    scanf("%d",&data);
    stack[++top]=data;
}

void pop()
{
    if(isempty())
    {
        printf("\nCannot pop, stack is empty!\n");
        return;
    }
    printf("\nPop: %d\n",stack[top--]);
}

void peek()
{
    if(isempty())
    {
        printf("\nCircular queue is empty!");
        return;
    }
    printf("\nTop element is: %d\n",stack[top]);
}

void display()
{
    printf("\n");
    if(isempty())
    {
        printf("Stack is empty!\n");
        return;
    }
    int temp=top;
    while(temp!=-1)
    {
        printf("%d ",stack[temp]);
        temp--;
    }
    printf("\n");
}

int main()
{
    int ch;
    printf("\n\t**Menu**\n1. Push\n2. Pop\n3. Isempty\n4. Peek\n5. Display\n6. Quit\n\nEnter choice: ");
    scanf("%d",&ch);
    while(1)
    {
        switch(ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: if(isempty()) printf("\nStack is empty!\n"); else printf("\nStack is not empty!\n"); break;
            case 4: peek(); break;
            case 5: display(); break;
            case 6: printf("\n"); return 0;
            default: printf("\nEnter proper choice!");
        }
        printf("\nEnter choice: ");
        scanf("%d",&ch);
    }
}
