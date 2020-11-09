//implement circular queue using array

#include<stdio.h>

int cqueue[50], front=-1, rear=-1; //declaring circular queue and reqd variables

int isfull() //to check if cqueue is full
{
    if((front==rear+1)||(front==0&&rear==49))
        return 1;
    else
        return 0;
}

int isempty() //to check if cqueue is empty
{
    if(front==-1)
        return 1;
    else
        return 0;
}

void enqueue() //to add elements to cqueue
{
    if(isfull())
    {
        printf("\nCannot enqueue elements, circular queue is full!\n");
        return;
    }
    if(isempty())
    {
        rear++;
        front++;
    }
    else if(rear==49&&front>0)
    {
        rear=0;
    }
    else
        rear++;
    int data;
    printf("\nEnqueue: ");
    scanf("%d",&data);
    cqueue[rear]=data;
}

void dequeue() //to delete elements from cqueue
{
    if(isempty())
    {
        printf("\nCannot dequeue elements, circular queue is empty!\n");
        return;
    }
    printf("\nDequeued: %d\n",cqueue[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front++;
}

void display() //to display cqueue
{
    int i;
    if(isempty())
    {
        printf("\nCircular Queue is empty\n");
        return;
    }
    printf("\nCircular Queue elements are: ");
    if(front>=rear)
    {
        for(i=front;i<=49;i++) //print till end, then from start to rear
            printf("%d ",cqueue[i]);
        for(i=0;i<=rear;i++)
            printf("%d ",cqueue[i]);
    }
    else
    {
        for(i=front;i<=rear;i++)
            printf("%d ",cqueue[i]);
    }
    printf("\n");
}

int main()
{
    int ch; //choice variable
    printf("\n\t**Menu**\n1. Enqueue\n2. Dequeue\n3. Isempty\n4. Isfull\n5. Display\n6. Quit\n\nEnter choice: "); //menu
    scanf("%d",&ch);
    while(1) //inf loop till user exit
    {
        switch(ch)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: if(isempty()) printf("\nQueue is empty!\n"); else printf("\nQueue is not empty!\n"); break;
            case 4: if(isfull()) printf("\nQueue is full!\n"); else printf("\nQueue is not full!\n"); break;
            case 5: display(); break;
            case 6: printf("\n"); return 0;
            default: printf("\nEnter proper choice!");
        }
        printf("\nEnter choice: ");
        scanf("%d",&ch);
    }
}
