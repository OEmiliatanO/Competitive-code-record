#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    cin.ignore();
    while(n--)
    {
        stack<char> sex;
        int Count=0;
        while(1){
            char ch=getchar();
            if(ch=='.')
                continue;
            else if(ch=='p')
                sex.push('p');
            else if(ch=='q')
            {
                if(!sex.empty()&&sex.top()=='p')
                {
                    sex.pop();
                    Count++;
                }
            }
            else
                break;
        }
        printf("%d\n",Count);
    }
    return 0;
}
