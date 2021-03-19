#include <stack>
#include <cstdio>
using namespace std;
int main()
{
    for(int n,co;scanf("%d",&n)!=EOF;)
    {
        stack<int> st;
        for(int i=0;i<n&&scanf("%d",&co);i++)
            switch(co)
            {
                case 1: st.pop(); break;
                case 2: printf("%d\n",st.top()); break;
                case 3: scanf("%d",&co); st.push(co); break;
            }
    }
    return 0;
}
