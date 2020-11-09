//program to implement queue using array

#include<stdio.h>

int queue[50],rear=-1,front=-1; //declaring queue and reqd variables

int isempty() //to check if queue is empty
{
    if(front==rear&&front==-1)
    {
        return 1;
    }
    else
        return 0;
}

int isfull() //to check if queue is full
{
    if(rear==49)
        return 1;
    else
        return 0;
}

void display() //to display queue
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

void enqueue() //to add elements to queue
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

void dequeue() //to delete elements from queue
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
    int ch; //choice variable
    printf("\n\t**Menu**\n1. Enqueue\n2. Dequeue\n3. Isempty\n4. Isfull\n5. Display\n6. Quit\n\nEnter choice: "); //menu display
    scanf("%d",&ch);
    while(1) //inf loop till user wants to exit
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
