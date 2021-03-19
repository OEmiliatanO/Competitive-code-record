#include <iostream>

using namespace std;

int main()
{
    int APPLE[10],High;
    while(cin>>APPLE[0])
    {
        int i=1,Count=0;
        while(i<10)
        {
            cin>>APPLE[i++];
        }
        cin>>High;
        High+=30;
        for(i=0;i<10;i++)
        {
            if(APPLE[i]<=High)
                Count++;
        }
        cout<<Count<<endl;
    }
    return 0;
}
