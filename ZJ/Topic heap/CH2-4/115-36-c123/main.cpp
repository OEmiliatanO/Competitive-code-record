#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while(scanf("%d",&N)==1&&N)
    {
        int arr[1010];
        while(scanf("%d",&arr[1])==1&&arr[1])
        {
            stack<int> st;
            int A=1,B=1;
            for(int i=2;i<=N;i++)
                scanf("%d",&arr[i]);
            bool ok=true;
            while(B<=N)
                if(A==arr[B]) {A++; B++;}
                else if(!st.empty()&&st.top()==arr[B]) {st.pop(); B++;}
                else if(A<=N) st.push(A++);
                else {ok=false; break;}
            printf((ok?"Yes\n":"No\n"));
        }
    }
    return 0;
}
