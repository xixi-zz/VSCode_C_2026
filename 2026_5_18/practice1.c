#include<stdio.h>
int main()
{
    FILE*file=fopen("word.txt","r");
    if(file==NULL)
    {
        return 1;
    }
    char word[10];
    while((fscanf(file,"%s",word))!=EOF)
    {
        printf("%s\n",word);
    }
    fclose(file);
    return 0;
}