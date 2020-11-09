//doubly linked list
//program to swap kth node from beginning and last
//and rotate the linked list by m clockwise

#include<stdio.h>
#include<stdlib.h>

struct node //defining body of node
{
    int data;
    struct node *next, *prev;
};

struct node *p,*prev_node,*head=NULL; //declaring reqd pointers
int n=0; //variable to count number of nodes

void inpt_list() //input function
{
    int c=1; //choice variable
    while(c)
    {
        p=(struct node*)malloc(sizeof(struct node)); //dynamic allocation
        p->next=NULL;
        printf("Enter data: "); //reading data
        scanf("%d",&p->data);
        if(head==NULL) //entering first element
        {
            head=p;
            p->prev=NULL;
        }
        else
        {
            prev_node->next=p;
            p->prev=prev_node;
        }
        prev_node=p;
        printf("Would you like to add another node? Print 0 for no "); //choice question
        scanf("%d",&c);
        n++; //increment in number of nodes
    }
}

void prnt_list() //display function
{
    p=head;
    printf("\n");
    while(p!=NULL) //traverse till last element
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void swapp(int k) //swap function
{
    if(k>n)
    {
        printf("k is inappropriate");
        return;
    }
    if(2*k-1==n) //because it will be the same linked list
        return;
    int cnt=1;
    struct node *t1=head,*t1_p=NULL,*t1_n=NULL,*t2=head,*t2_p=NULL,*t2_n=NULL; //reqd pointers
    while(cnt!=k) //traverse till kth node from beginning
    {
        t1=t1->next;
        cnt++;
    }

    t1_n=t1->next;
    t1_p=t1->prev;
    
    cnt=1;
    while(cnt!=n-k+1) //traverse till kth node from last
    {
        t2=t2->next;
        cnt++;
    }

    t2_n=t2->next;
    t2_p=t2->prev;

    //swapping starts

    if(t2_p!=NULL)
        t2_p->next=t1;
    if(t2_n!=NULL)
        t2_n->prev=t1;
    t1->prev=t2_p;
    t1->next=t2_n;

    if(t1_p!=NULL)
        t1_p->next=t2;
    if(t1_n!=NULL)
        t1_n->prev=t2;
    t2->prev=t1_p;
    t2->next=t1_n;

    if(k==1||k==n) //change of head in case of first element
        head=t2;
}

void rotatel(int m) //rotate function
{
    m%=n; //in case m>n
    p=head;
    int cnt=1;
    while(cnt!=n) //traverse to the last element
    {
        p=p->next;
        cnt++;
    }
    head->prev=p;
    p->next=head;
    p=head;
    cnt=1;
    while(cnt!=n-m) //till the new head
    {
        p=p->next;
        cnt++;
    }
    head=p->next;
    head->prev=NULL;
    p->next=NULL;
}

int main()
{
    printf("\n");
    inpt_list();
    prnt_list();
    printf("\nEnter k where the kth node from beginning and last will be swapped: ");
    int m;
    scanf("%d",&m);
    swapp(m);
    prnt_list();
    printf("\nEnter m where the linked list will be rotated by m: ");
    scanf("%d",&m);
    rotatel(m);
    prnt_list();
    printf("\n");
    return 0;
}