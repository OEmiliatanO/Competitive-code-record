#include <cstdio>
using namespace std;
int K,D,A,combo,N;
char s[20];
int main()
{
    scanf("%d",&N);getchar();
    while(N--&&scanf("%[^\n]s",s)&&getchar())
    {
        if(s[0]=='D')
        {
            D++;
            if(combo>=3) puts("SHUTDOWN.");
            else puts("You have been slained.");
            combo=0;
        }
        else if(s[4]=='K')
        {
            combo++;
            K++;
            switch(combo)
            {
                case 3:
                    puts("KILLING SPREE!");
                    break;
                case 4:
                    puts("RAMPAGE~");
                    break;
                case 5:
                    puts("UNSTOPPABLE!");
                    break;
                case 6:
                    puts("DOMINATING!");
                    break;
                case 7:
                    puts("GUALIKE!");
                    break;
                case 8:
                    puts("LEGENDARY!");
                    break;
            }
            if(combo<3) puts("You have slain an enemie.");
            else if(combo>8) puts("LEGENDARY!");
        }
        else if(s[4]=='A')
            A++;
    }
    printf("%d/%d/%d",K,D,A);
    return 0;
}
