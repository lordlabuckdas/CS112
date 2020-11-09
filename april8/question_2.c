//linked list
//function to delete the next 2 elements after the (first) middle element

#include<stdio.h>
#include<stdlib.h>

struct node //declaration of the self referential structure
{
    int data; //data value
    struct node* nxt; //pointer to next node
};

struct node *p,*prev,*head=NULL; //global declaration of reqd nodes
int n=0; //variable to find the number of nodes

void inpt_list() //function to read nodes from user
{
    int c=1;
    while(c) //choice loop
    {
        p=(struct node*)malloc(sizeof(struct node)); //dynamic allocation
        p->nxt=NULL; //last node points to NULL
        printf("Enter data: ");
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

void prnt_list() //function to display the linked list
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

void list_2deln(int pos) //function to delete the next 2 elements from given 'pos'
{
    p=head;
    int cnt=1;
    while(cnt<pos-1)
    {
        p=p->nxt;
        cnt++;
    }
    struct node* temp=p->nxt;
    if(temp->nxt!=NULL)
        p->nxt=temp->nxt->nxt;
    else
        p->nxt=NULL;
    free(temp->nxt); //deallocation of memory
    free(temp);
}

int main()
{
    printf("\n");
    inpt_list(); //read nodes
    prnt_list(); //display linklist
    if(n<4) //if there are less than 4 elements, can't delete
    {
        printf("\nNot enough elements to delete\n");
        return 0;
    }
    if(n%2==0) //function call respectively for odd and even n
    {
        list_2deln(n/2+1);
    }
    else
    {
        list_2deln((n+1)/2+1);
    }
    prnt_list(); //display linklist
    return 0;
}