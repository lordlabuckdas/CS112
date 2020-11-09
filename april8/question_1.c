//linked list
//insert an element and delete an element
//after given positions 

#include<stdio.h>
#include<stdlib.h>

struct node //declaration of self-referential structure
{
    int data; //data value
    struct node* nxt; //pointer pointing towards next node
};

struct node *p,*prev,*head=NULL; //global declaration of necessary nodes

void inpt_list() //function to read values from user
{
    int c=1; //choice variable
    while(c)
    {
        p=(struct node*)malloc(sizeof(struct node)); //dynamic allocation
        p->nxt=NULL; //last node always points to NULL
        printf("Enter data: "); //reading input data from user
        scanf("%d",&p->data); 
        if(head==NULL) 
            head=p;
        else
            prev->nxt=p;
        prev=p;
        printf("Would you like to add another node? Print 0 for no "); //choice question
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

void insrtion(int pos, int val) //function to insert node after the given positon w/ given value
{
    p=head;
    int cnt=1;
    while(cnt<pos)
    {
        p=p->nxt;
        cnt++;
    }
    struct node* k;
    k=(struct node*)malloc(sizeof(struct node));
    k->data=val;
    k->nxt=p->nxt;
    p->nxt=k;
}

void node_deln(int pos) //function to delete node after the given position
{
    p=head;
    int cnt=1;
    while(cnt<pos)
    {
        p=p->nxt;
        cnt++;
    }
    struct node* tmp=p->nxt;
    if(p->nxt==NULL) //when pos has the last element
        printf("\nLast element, deletion of next element not possible\n");
    else
        p->nxt=tmp->nxt;
    free(tmp); //deallocating the memory
}

int main()
{
    printf("\n");
    inpt_list(); //read values
    prnt_list(); //print them
    int pos,val;
    printf("\nEnter data and the positon after which the data is to be inserted: ");
    scanf("%d %d", &val, &pos); //read the value and position of data to be inserted
    insrtion(pos, val); //function call
    prnt_list(); //print linked list
    printf("\nEnter the position of the node whose succesive node gets deleted: ");
    scanf("%d",&pos); //read the positon for deletion
    node_deln(pos); //function call
    prnt_list();
    return 0;
}