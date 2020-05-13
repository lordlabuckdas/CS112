#include<stdio.h>

int main(int argc, char *argv[])
{
    printf("\n");
    if(argc==1)
        printf("One argument expected");
    else if(argc>2)
        printf("Too many arguments are supplied");
    else
        printf("The argument supplied is %s",argv[1]);
    printf("\n\n");
    return 0;
}