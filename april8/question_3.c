//linked list
//function to print the kth element from the tail

#include<stdio.h>
#include<stdlib.h>

struct node //declaration of self referential structure
{
    int data; //data value
    struct node* nxt; //pointer to next node
};

struct node *p,*prev,*head=NULL; //global declaration of reqd nodes
int n=0; //variable to count the number of nodes

void inpt_list() //function to read nodes from user
{
    int c=1;
    while(c) //choice loop
    {
        p=(struct node*)malloc(sizeof(struct node)); //dynamic allocation
        p->nxt=NULL;
        printf("Enter data: "); //read data
        scanf("%d",&p->data);
        if(head==NULL)
            head=p;
        else
            prev->nxt=p;
        prev=p;
        printf("Would you like to add another node? Print 0 for no ");
        scanf("%d",&c);
        n++;
    }
}

void prnt_list() //function to display nodes
{
    p=head;
    printf("\n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->nxt;
    }
    printf("\n");
}

void prnt_kth(int k) //function to print the kth element from tail
{
    int cnt=1;
    k=n-k+1;
    p=head;
    while(cnt++<k)
        p=p->nxt;
    printf("\nValue of kth element from tail is: %d\n",p->data);
}

int main()
{
    printf("\n");
    inpt_list(); //read nodes
    prnt_list(); //display linklist
    printf("\nEnter k: ");
    int k;
    scanf("%d",&k); //read k
    if(k>n) //if k>n, then kth element from tail is out of bounds
    {
        printf("\nk is greater than n\n");
        return 0;
    }
    prnt_kth(k); //function call
    return 0;
}