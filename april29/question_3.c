//to generate magic sqaure of 5x5

#include<stdio.h>
#include<stdlib.h>

void gen_mgic_sqr(int **a) //generating fucntion
{
    int p,q,k;
    for(p=0;p<5;p++)
        for(q=0;q<5;q++)
            *(*(a+p)+q)=0; //initialise elements to 0
    p=2,q=4; // algo starts with n/2 and n-1 as coordinates
    for(k=1;k<=25;) //goes till 25 as n^2 is 25
    {
        if(p==-1&&q==5) //if out of the last square
        {
            q=3;
            p=0;
        }
        else
        {
            if(q==5) //if exceeded in columns
                q=0;
            if(p<0) //if exceeded in rows
                p=4;
        }
        if(*(*(a+p)+q)) //if value hasn't been assigned
        {
            q-=2;
            p++;
            continue; //ignore the following statements
        }
        else
            *(*(a+p)+q)=k++; //assign value of square
        q++; //moving onto next element
        p--;
    }

}

void prntt(int **a) //display function
{
    printf("\n");
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            printf("%d\t",*(*(a+i)+j));
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int i,*a[5];
    for(i=0;i<5;i++)
        a[i]=(int *)malloc(5*sizeof(int));
    gen_mgic_sqr(a);
    prntt(a);
    return 0;
}