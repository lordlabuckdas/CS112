//function to take a 2d array as argument and print values and addresses by row major and column major

#include<stdio.h>

int m,n; //declaring globally so that it's not passed as a function

void row_mj(int a[][10]) //function for row major
{
    printf("\nRow Major w/ address:\n");
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            printf("%d %p\n",*(*(a+i)+j),(*(a+i)+j)); //prints value and address by traversing as a double pointer
}

void col_mj(int a[][10]) //function for column major
{
    printf("\nColumn Major w/ address:\n");
    int i,j;
    for(j=0;j<n;j++)
        for(i=0;i<m;i++)
            printf("%d %p\n",*(*(a+i)+j),(*(a+i)+j));
}

int main()
{
    printf("Enter the dimensions of the array: "); //reads dimensions
    scanf("%d %d",&m,&n);
    int i,j,a[10][10];
    printf("Enter the elements: "); //reads elements
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    row_mj(a);
    col_mj(a);
    return 0;
}