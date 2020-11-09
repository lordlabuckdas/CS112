//to check if single argument is there

#include<stdio.h>

int main(int argc, char *argv[]) //declaring main with arguments
{
    printf("\n");
    if(argc==1) //if no argument is there
        printf("One argument expected");
    else if(argc>2) //if more than one argument is there
        printf("Too many arguments are supplied");
    else
        printf("The argument supplied is %s",argv[1]); //if exactly one
    printf("\n\n");
    return 0;
}
