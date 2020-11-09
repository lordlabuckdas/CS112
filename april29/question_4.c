//to generate spiral matrix

#include<stdio.h>
#include<stdlib.h>

void spir_mat_gen(int **a) //spiral matrix generator
{
    int i=0,j=0,k=1,t=0;
    while(t<4) //loop circles around 3 times
    {
        i=t; //setting appropriate beginning positions and checks
        for(j=t;j<7-t;j++)
            *(*(a+i)+j)=k++;
        j=6-t;
        for(i=t+1;i<7-t;i++)
            *(*(a+i)+j)=k++;
        i=6-t;
        for(j=5-t;j>=t;j--)
            *(*(a+i)+j)=k++;
        j=t;
        for(i=5-t;i>=t+1;i--)
            *(*(a+i)+j)=k++;
        t++; //incrementing t
    }
}

void printt(int **a) //display function
{
    printf("\n");
    int i,j;
    for(i=0;i<7;i++)
    {
        for(j=0;j<7;j++)
            printf("%3d ",*(*(a+i)+j));
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int i,*a[7];
    for(i=0;i<7;i++)
        a[i]=(int *)malloc(7*sizeof(int));
    spir_mat_gen(a);
    printt(a);
}