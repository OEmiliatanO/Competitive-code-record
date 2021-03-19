#include <cstdio>
using namespace std;
int main()
{
    int N,i,j;
    char ch;
    scanf("%d",&N);
    getchar();
    for(i=0;i<N;i++)
        for(j=0;j<N&&(ch=getchar());j++)
            if(i==j) putchar(ch);
    return 0;
}
