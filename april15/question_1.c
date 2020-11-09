//linked list porgram
//delete duplicate nodes

#include<stdio.h> //reqd header files
#include<stdlib.h>

struct node //struct body declaration
{
    int data;
    struct node* nxt;
};

struct node *p,*head=NULL; //assigning head and moving pointer

void inpt_list() //input function
{
    struct node *prev;
    int c=1; //choice variable
    while(c) //choice loop
    {
        p=(struct node*)malloc(sizeof(struct node)); //dynamic allocation
        p->nxt=NULL;
        printf("Enter data: "); //user input of data
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

void prnt_list() //display function
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

void del_dupl() //duplicate deletion function
{
    p=head;
    struct node *cur,*temp;
    while(p!=NULL&&p->nxt!=NULL)
    {
        cur=p;
        while(cur->nxt!=NULL)
        {
            if(p->data==cur->nxt->data) //compares current element with pivot element
            {
                temp=cur->nxt;
                cur->nxt=cur->nxt->nxt;
                free(temp); //deletes if same
            }
            else
                cur=cur->nxt; //else moves on
        }
        p=p->nxt;
    }
}

int main() //main function
{
    printf("\n");
    inpt_list();
    prnt_list();
    del_dupl();
    prnt_list();
    return 0;
}