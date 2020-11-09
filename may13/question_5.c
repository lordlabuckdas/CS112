//to print current date and files of directory using system command
//note: couldn't produce exact output due to system commands getting executed before printf

#include<stdio.h>
#include<stdlib.h> //header for system()
#include<string.h> //header for strcat

int main()
{
    printf("\nEnter the path of the directory: "); //user input of path
    char b[100]="ls "; //intialising with ls
    scanf("%s",b+3);
    printf("\n");
    char a[]="date '+%d %B %Y'"; //command for printing date in specified fpmat
    system(a); //invoking of date command
    printf("\n");
    system(b); //invoking of ls <path> command
    printf("\n");
    return 0;
}
