#include<stdio.h>
#include<string.h>
int main()
{
char a[1001];
int n;
scanf("%d",&n);
getchar();
for(int i=0;i<n;i++)
{gets(a);puts(a);printf("\n");}
while(scanf("%s",a)!=EOF)
{
  printf("%s\n",a);
  printf("\n");
}
return 0;
}
