//wap to accept 10nos and display both unsorted and sorted list
//with sorting based on 1. name, 2. age

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee //structure body
{
    char *name;
    int *age;
    float salary;
};

void swapp(struct employee *a, struct employee *b) //to swap by reference
{
    int tage;
    char tname[100];
    float tsal;
    tage=*a->age;
    *a->age=*b->age;
    *b->age=tage;
    strcpy(tname,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,tname);
    tsal=a->salary;
    a->salary=b->salary;
    b->salary=tsal;
}

void sortt(struct employee a[]) //to sort based on keys 1 and 2
{
    int i,j;
    for(i=0;i<10;i++) //bubble sort algo
    {
        for(j=0;j<9-i;j++)
        {
            if((strcmp(a[j].name,a[j+1].name)>0)||(strcmp(a[j].name,a[j+1].name)==0&&(*a[j].age>*a[j+1].age)))
            {
                swapp(&a[j],&a[j+1]);
            }
        }
    }
}

void printt(struct employee a[]) //display function
{
    int i;
    printf("\nName:\t\tAge:\tSalary:\t\n");
    for(i=0;i<10;i++)
    {
        printf("%s\t\t%d\t%f\n",a[i].name,*a[i].age,a[i].salary);
    }
}

int main()
{
    int i,age;
    char name[100];
    struct employee a[10];
    printf("\nEnter name in a line and age and salary space separated in another line\n");
    for(i=0;i<10;i++) //input loop
    {
        scanf("%s",name);
        a[i].name=(char*)malloc(strlen(name)*sizeof(char));
        strcpy(a[i].name,name);
        scanf("%d",&age);
        scanf("%f",&a[i].salary);
        a[i].age=(int*)malloc(sizeof(int));
        *a[i].age=age;
    }
    printt(a); //display unsorted records
    sortt(a); //sort
    printt(a); //display sorted records
    printf("\n");
}