#include<stdio.h>
int main()
{
    char a[100];
    int b[7]={0};
    gets(a);
    for(int i=0;a[i];i++)
    {
        if(a[i]>=97&&a[i]<=103)
        b[a[i]-'a']++;
    }
    for(int i=0;i<7;i++)
    {
        printf("%c:%d\n",i+'a',b[i]);
    }
    return 0;
}
