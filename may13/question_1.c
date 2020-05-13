#include<stdio.h>

int queue[50],rear=-1,front=-1;

int isempty()
{
    if(front==rear&&front==-1)
    {
        return 1;
    }
    else
        return 0;
}

int isfull()
{
    if(rear==49)
        return 1;
    else
        return 0;
}

void display()
{
    printf("\nQueue elements are: ");
    if(isempty())
    {
        printf("Queue is empty!\n");
        return;
    }
    int i;
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("\n");
}

void enqueue()
{
    if(isfull())
    {
        printf("\nCannot enqueue, the queue is already full!\n");
        return;
    }
    if(isempty())
        front++;
    rear++;
    int data;
    printf("\nEnqueue: ");
    scanf("%d",&data);
    queue[rear]=data;
}

void dequeue()
{
    if(isempty())
    {
        printf("\nCannot dequeue, the queue is already empty!\n");
        return;
    }
    printf("\nDequeued: %d\n",queue[front]);
    front++;
    if(front>rear)
    {
        front=-1;
        rear=-1;
    }

}

int main()
{
    int ch;
    printf("\n\t**Menu**\n1. Enqueue\n2. Dequeue\n3. Isempty\n4. Isfull\n5. Display\n6. Quit\n\nEnter choice: ");
    scanf("%d",&ch);
    while(1)
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