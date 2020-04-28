//linked list
//to shift the linked list to the right by 2 nodes

#include<stdio.h>
#include<stdlib.h>

struct node //declaration of self referential structure
{
    int data; //data value
    struct node* nxt; //pointer to next node
}; 

struct node *p,*prev,*head=NULL; //global declaration of reqd pointers

void inpt_list()
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
    }
}

void prnt_list() //function to print the linked list
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

void shft2() //function to shift the linked list by 2 nodes
{
    p=head;
    if(p->nxt==NULL||p->nxt->nxt==NULL)
    {
        printf("Less than 3 nodes, cannot rotate");
        return;
    }
    while(p->nxt->nxt->nxt!=NULL)
    {
        p=p->nxt;
    }
    p->nxt->nxt->nxt=head;
    head=p->nxt;
    p->nxt=NULL;
}

int main()
{
    printf("\n");
    inpt_list(); //read nodes
    prnt_list(); //disp linklist
    shft2(); //function call
    prnt_list(); //disp linklist
    return 0;
}