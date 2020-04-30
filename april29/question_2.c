//generate random matrix of 5x5
//and check if it's a magic square

#include<stdio.h>
#include<time.h> //for srand() argument
#include<stdlib.h> 

void mat_gen(int **a) //to generate the random matrix
{
    int i,j;
    srand(time(0)); //srand with seed value
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            *(*(a+i)+j)=rand()%100 + 1; //random value assignment
}

void prnt(int **a) //display function
{
    int i,j;
    printf("\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            printf("%d\t",*(*(a+i)+j));
        printf("\n");
    }
    printf("\n");
}

void magic_chk(int **a) //check if it's a magic square
{
    int i,j,sum=0;
    for(i=0;i<5;i++)
    {
        sum=0;
        for(j=0;j<5;j++)
        {
            sum+=*(*(a+i)+j); //row sum
        }
        if(sum!=65) //for 5x5 magic square, the sum of each row/col/diag is 65
        {
            printf("Not a magic square\n\n");
            return; //return from function if it's not
        }
    }
    for(i=0;i<5;i++)
    {
        sum=0;
        for(j=0;j<5;j++)
        {
            sum+=*(*(a+j)+i); //column sum
        }
        if(sum!=65)
        {
            printf("Not a magic square\n\n");
            return;
        }
    }
    sum=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(i==j)
                sum+=*(*(a+i)+j); //major diag sum
        }
    }
    if(sum!=65)
    {
        printf("Not a magic square\n\n");
        return;
    }
    sum=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(i+j==4)
                sum+=*(*(a+i)+j); //minor diag sum
        }
    }
    if(sum!=65)
    {
        printf("Not a magic square\n\n");
        return;
    }
    printf("Magic Square!\n\n");
}

int main()
{
    int *a[5],i;
    for(i=0;i<5;i++)
        a[i]=(int *)malloc(5*sizeof(int));
    mat_gen(a);
    prnt(a);
    magic_chk(a);
}