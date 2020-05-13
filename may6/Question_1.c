//count number of uppercases, lowercases, spaces, lines and tabs from file

#include<stdio.h>

int main()
{
    FILE* fp;
    int spaces=0, tabs=0, uppr=0, lowr=0, lines=1; //lines=1 because n(\n)=n(lines)-1
    char ch;
    fp=fopen("Input/Q1_input2.txt","r"); //opening in read mode
    if(fp==NULL) //null check if file not opened
    {
        printf("Error opening file!");
        return 1;
    }
    while(1)
    {
        ch=fgetc(fp); //read character by character from file
        if(ch==EOF) //if eof, break loop
            break;
        else if(ch>='A'&&ch<='Z')
            uppr++;
        else if(ch>='a'&&ch<='z')
            lowr++;
        else if(ch=='\t')
            tabs++;
        else if(ch=='\n')
            lines++;
        else if(ch==' ')
            spaces++;
    }
    printf("\nNo. of upper cases: %d\n",uppr);
    printf("No. of lower cases: %d\n",lowr);
    printf("No. of lines: %d\n",lines);
    printf("No. of spaces: %d\n",spaces);
    printf("No. of tabs: %d\n\n",tabs);
    fclose(fp); //close file
}
