//linked list porgram
//porgram to
//1.Delete node given name and roll number
//2.Insert node
//3.Count the numbe of nodes/students
//4.Reverse the linked list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node //struct body declaration
{
    char *name, *rollno, *grade;
    float cpi;
    struct node* nxt;
};

struct node *p,*head=NULL;

void inpt_list(int f) //input function
{
    struct node *prev;
    int c=1; //choice variable
    char namee[100]; //variable for name
    while(c)
    {
        p=(struct node*)malloc(sizeof(struct node)); //dynamic allocation
        printf("\nEnter name: ");
        fgets(namee,sizeof(namee),stdin); //takes in name with spaces
        p->name=(char*)malloc(sizeof(char)*(strlen(namee)+1)); //dynamic allocation
        strcpy(p->name,namee); //copies to node
        printf("Enter roll num: ");
        scanf ("%s",namee);
        p->rollno=(char*)malloc(sizeof(char)*(strlen(namee)+1));
        strcpy(p->rollno,namee);
        printf("Enter grade: ");
        scanf ("%s",namee);
        p->grade=(char*)malloc(sizeof(char)*(strlen(namee)+1));
        strcpy(p->grade,namee);
        printf("Enter CPI: ");
        scanf ("%f",&p->cpi);
        struct node *tmp;
        tmp=head;
        if (tmp == NULL)  //initial insertion
        {  
            p->nxt = p;  
            head = p;  
        }  
        else if (strcmp(tmp->name,p->name)>=0) //appropriate insertion
        {  
            while(tmp->nxt != head)  
                tmp = tmp->nxt;  
            tmp->nxt = p;  
            p->nxt = head;  
            head = p; //change of head
        }  
        else
        {  
            while (tmp->nxt!= head && strcmp(tmp->nxt->name,p->name)<0)  
                tmp = tmp->nxt;
            p->nxt = tmp->nxt;  
            tmp->nxt = p;  
        }  
        if(f==1) //for initial insertion of nodes
        {
            printf("Would you like to add another node? (0 to stop) ");
            scanf("%d",&c);
            char b; //buffer variable to read '\n' from input stream
            scanf("%c",&b);
        }
        else
            c=0; //for menu based call of insertion
    }
}

void prnt_list() //display function
{
    p=head;
    printf("\n");
    do
    {
        printf("Name: %sRoll num: %s\nGrade: %s\nCPI: %f\n\n",p->name,p->rollno,p->grade,p->cpi);
        p=p->nxt;
    }while(p!=head);
}

void count() //count function
{
    p=head;
    int cnt=0;
    do
    {
       cnt++;
        p=p->nxt;
    }while(p!=head);
    printf("\nThere are %d students\n",cnt);
}

void rev() //reversing function
{
    p=head;
    struct node *forw,*back=NULL;
    do
    {
        forw=p->nxt;
        p->nxt=back;
        back=p;
        p=forw;
    } while(p!=head);
    head->nxt=back;
    head=back;
}

void deln() //deletion function
{
    char b; //buffer variable :(
    scanf("%c",&b);    
    printf("\nEnter the name of the student to be deleted: "); //user input of name and roll number
    char word[100],roll[20];
    fgets(word,sizeof(word),stdin);
    printf("Enter roll number of the student to be deleted: ");
    scanf("%s",roll);
    p=head;
    struct node *tmp;
    do
    {
        if(strcmp(p->nxt->name,word)==0&&strcmp(p->nxt->rollno,roll)==0) //checking for match
        {
            if(p->nxt==head)
                head=p->nxt->nxt;
            tmp=p->nxt;
            p->nxt=p->nxt->nxt;
            free(tmp); //delete node
            return;
        }
        p=p->nxt;
    }while(p->nxt!=head->nxt);
    printf("\nGiven student data doesn't exist\n"); //if data doesn't match
}
int main() //main function
{
    inpt_list(1);
    prnt_list();
    int ch=1; //choice variable
    char b; //nuffer variable
    while(ch!=5)
    {
        printf("MENU\n1.Deletion\n2.Insertion\n3.Number of students\n4.Reverse order\n5.Exit\nEnter choice: ");
        scanf("%d",&ch); //menu display and choice
        switch(ch)
        {
            case 1: deln(); prnt_list(); break; //deletes
            case 2: scanf("%c",&b); inpt_list(0); prnt_list(); break; //inserts node
            case 3: count(); break; //counts
            case 4: rev(); prnt_list(); break; //reverses
            default: printf("Exiting..\n"); break; //exits loop
        }
    }
    return 0;
}