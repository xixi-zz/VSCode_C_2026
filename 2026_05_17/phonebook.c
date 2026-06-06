#include<stdio.h>
#include<stdlib.h>
char* get_string(char* s);
int main(void)
{
    FILE * file=fopen("phonebook.csv","a");
    if(file==NULL)
    {
        return 1;
    }
    char* name=get_string("Name:");//需要手动销毁malloc分配的内存
    char* number=get_string("Number:");
    fprintf(file,"%s,%s\n",name,number);
    fclose(file);
    free(name);
    name=NULL;
    free(number);
    number=NULL;
    return 0;
}
char* get_string(char* input)
{
    char* output;
    output=malloc(1000*sizeof(char));
    if(output==NULL)
    {
        return NULL;
    }
    printf("%s",input);
    scanf("%s",output);
    return output;
}