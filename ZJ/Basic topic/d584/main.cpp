#include <cstdio>

using namespace std;

int main()
{
    int career,lv;
    for(int ans=0;scanf("%d %d",&career,&lv)!=EOF;ans=0)
    {
        if(career==0) printf("0\n");
        else
        {
            if(career==2)
            {
                ans+=(lv-8)*3;
                if(lv>=8)
                {
                    ans++;
                    if(lv>=30)
                    {
                        ans++;
                        if(lv>=70)
                        {
                            ans++;
                            if(lv>=120)
                            {
                                ans+=3;
                            }
                        }
                    }
                }
            }
            else
            {
                ans+=(lv-10)*3;
                if(lv>=10)
                {
                    ans++;
                    if(lv>=30)
                    {
                        ans++;
                        if(lv>=70)
                        {
                            ans++;
                            if(lv>=120)
                            {
                                ans+=3;
                            }
                        }
                    }
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
