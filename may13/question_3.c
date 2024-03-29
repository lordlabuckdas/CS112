//implement stack using array

#include<stdio.h>

int stack[50], top=-1; //declaring stack and reqd variables

int isempty() //to check if stack is empty
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push() //to add elements to stack 
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

void pop() //to delete elements from stack
{
    if(isempty())
    {
        printf("\nCannot pop, stack is empty!\n");
        return;
    }
    printf("\nPop: %d\n",stack[top--]);
}

void peek() //to print the top element
{
    if(isempty())
    {
        printf("\nCircular queue is empty!");
        return;
    }
    printf("\nTop element is: %d\n",stack[top]);
}

void display() //to display stack
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
    int ch; //choice variable
    printf("\n\t**Menu**\n1. Push\n2. Pop\n3. Isempty\n4. Peek\n5. Display\n6. Quit\n\nEnter choice: "); //menu
    scanf("%d",&ch);
    while(1) //inf loop till user exit
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
