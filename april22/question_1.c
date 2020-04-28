//given 2 sets of strings, count the number of pairs which when concatenated have all characters

#include<stdio.h>
#include<string.h>

int main()
{
    int m,n,mp[26];
    printf("Enter the number of strings in set A and B respectively: ");
    scanf("%d %d",&m,&n); //reading the size of sets from user
    char a[m][52],b[n][52];
    int i,j,k,count=0,flag;
    printf("Enter the strings of set A:\n");
    for(i=0;i<m;i++)
        scanf("%s",a[i]); //reading strings of A
    printf("Enter the strings of set B:\n");
    for(i=0;i<n;i++)
        scanf("%s",b[i]); //reading strings of B
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            flag=0;
            memset(mp,0,sizeof(mp)); //setting the elements of mp to 0
            for(k=0;k<strlen(a[i]);k++)
                mp[a[i][k]-97]++; //adding 1 correspondingly to character
            for(k=0;k<strlen(b[j]);k++)
                mp[b[j][k]-97]++;
            for(k=0;k<26;k++)
            {
                if(mp[k]<1) //if even one character is not there, break
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                count++; //add to the count of perfect pairs
        }
    }
    printf("%d pair(s) has/have all the characters\n",count);
}