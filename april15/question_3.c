//linked list program
//program to accept strings and sort them using pointers

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() //main function
{ 
    int i,n;
    printf("\nEnter the number of names: ");  //user input of number of names
    scanf("%d",&n);
    char b;
    scanf("%c",&b);
    char word[100]; //variable to accept names
    char *name[n]; //array of character pointers
    for(i=0;i<n;i++)
    {
        printf("Enter name: ");
        fgets(word,sizeof(word),stdin); //input of name with spaces
        name[i]=(char*)malloc(sizeof(char)*(strlen(word)+1)); //dynamic allocation
        strcpy(name[i],word); //copying the name
    }
    int j;
    for(i=0;i<n-1;i++) //sort
    {
        for(j=0;j<n-1;j++)
        {
            if(strcmp(name[j],name[j+1])>0) //compare with adjacent if greater
            {
                strcpy(word,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],word);
            }
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
        printf("%s",name[i]); //printing the names
    
    return 0;
}