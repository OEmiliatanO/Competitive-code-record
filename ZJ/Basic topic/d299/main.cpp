#include <cstdio>
#include <string.h>
using namespace std;
bool Numberlock[10];
int main()
{
    /*memset(Numberlock,false,sizeof(Numberlock));
    for(int F=0;F<10;F++)
    {
        Numberlock[F]=true;
        for(int O=0;O<10;O++)
        {
            if(Numberlock[O]) continue;
            Numberlock[O]=true;
            for(int R=0;R<10;R++)
            {
                if(Numberlock[R]) continue;
                Numberlock[R]=true;
                for(int T=0;T<10;T++)
                {
                    if(Numberlock[T]) continue;
                    Numberlock[T]=true;
                    for(int Y=0;Y<10;Y++)
                    {
                        if(Numberlock[Y]) continue;
                        Numberlock[Y]=true;
                        for(int E=0;E<10;E++)
                        {
                            if(Numberlock[E]) continue;
                            Numberlock[E]=true;
                            for(int N=0;N<10;N++)
                            {
                                if(Numberlock[N]) continue;
                                Numberlock[N]=true;
                                for(int S=0;S<10;S++)
                                {
                                    if(Numberlock[S]) continue;
                                    Numberlock[S]=true;
                                    for(int I=0;I<10;I++)
                                    {
                                        if(Numberlock[I]) continue;
                                        Numberlock[I]=true;
                                        for(int X=0;X<10;X++)
                                        {
                                            if(Numberlock[X]) continue;
                                            Numberlock[X]=true;
                                            if((Y+N+N)%10==Y)
                                            {
                                                int offset2=(Y+N+N)/10;
                                                if((offset2+T+E+E)%10==T)
                                                {
                                                    int offset3=(offset2+T+E+E)/10;
                                                    if((offset3+R+T+T)%10==X)
                                                    {
                                                        int offset4=(offset3+R+T+T)/10;
                                                        if((offset4+O)%10==I)
                                                        {
                                                            int offset5=(offset4+O)/10;
                                                            if(offset5+F==S)
                                                                printf("%d%d%d%d%d + %d%d%d + %d%d%d = %d%d%d%d%d",F,O,R,T,Y,T,E,N,T,E,N,S,I,X,T,Y);
                                                        }
                                                    }
                                                }
                                            }
                                            Numberlock[X]=false;
                                        }
                                        Numberlock[I]=false;
                                    }
                                    Numberlock[S]=false;
                                }
                                Numberlock[N]=false;
                            }
                            Numberlock[E]=false;
                        }
                        Numberlock[Y]=false;
                    }
                    Numberlock[T]=false;
                }
                Numberlock[R]=false;
            }
            Numberlock[O]=false;
        }
        Numberlock[F]=false;
    }*/
    printf("29786 + 850 + 850 = 31486\n");
    return 0;
}
