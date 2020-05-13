#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    printf("\nEnter the path of the directory: ");
    char b[100]="ls ";
    scanf("%s",b+3);
    printf("\n");
    char a[]="date '+%d %B %Y'";
    system(a);
    printf("\n");
    system(b);
    printf("\n");
    return 0;
}