//indent poorly indented c code

#include<stdio.h>

int main()
{
    FILE *fp1,*fp2;
    int count=1,ind_lvl=0,i,for_brack=0; //ind_level for indentation, for_brack for statements inside for initialiser
    char ch,prev_ch;
    fp1=fopen("Input/Q2_input2.c","r"); //opening input file in read mode
    fp2=fopen("Q2_Output/Q2_output2.c","w"); //opening output file in write mode
    if(fp1==NULL||fp2==NULL) //null check if file not opened
    {
        printf("Error opening file!");
        return 1;
    }
    fprintf(fp2,"1.");
    count++;
    while(1)
    {
        ch=fgetc(fp1);
        if(ch==EOF)
            break;
        else 
        {
            if(ch=='\n'||ch=='\t') //ignore the poorly indented code
                continue;
            if(ch==' '&&(prev_ch==';'||prev_ch=='{'||prev_ch==' ')) //for unnecessary spaces
                continue;
            if(ch=='{')
            {
                fprintf(fp2,"\n%d.",count); //move to next line
                for(i=1;i<=ind_lvl;i++)
                    fprintf(fp2,"\t"); //indent accordingly
                count++; //increase line numbering
                ind_lvl++; //increase indent level
            }
            else if(ch=='}')
            {
                fprintf(fp2,"\n%d.",count);
                count++;
                ind_lvl--; //lower indent level
                for(i=1;i<=ind_lvl;i++)
                    fprintf(fp2,"\t");
            }
            fprintf(fp2,"%c",ch); //print character
            if(ch=='{'||ch=='>'||(ch==';'&&for_brack!=1))
            {
                fprintf(fp2,"\n%d.",count);
                count++;
                for(i=1;i<=ind_lvl;i++)
                    fprintf(fp2,"\t");
            }
            else if(ch=='(')
                for_brack++; //entering for initialiser
            else if(ch==')')
                for_brack--; //exiting for initialiser
            prev_ch=ch; //to check for unnecessary spaces
        }
    }
    fclose(fp1);
    fclose(fp2);
}
