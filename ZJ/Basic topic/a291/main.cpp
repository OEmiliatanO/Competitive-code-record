#include <cstdio>
using namespace std;
int main()
{
    for(int a,b,c,d,t,in1,in2,in3,in4,A=0,B=0;scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF;)
    {
        scanf("%d",&t);
        int _a=a,_b=b,_c=c,_d=d;
        for(A=0,B=0;t--&&scanf("%d %d %d %d",&in1,&in2,&in3,&in4)!=EOF;A=0,B=0,_a=a,_b=b,_c=c,_d=d)
        {
            if(in1==_a) {A++; _a=-2; in1=-2;}
            if(in2==_b) {A++; _b=-3; in2=-3;}
            if(in3==_c) {A++; _c=-4; in3=-4;}
            if(in4==_d) {A++; _d=-5; in4=-5;}
            if(in1>=0)
            {
                if(in1==_b&&_b>=0) {in1=-1; _b=-3; B++;}
                else if(in1==_c&&_c>=0) {in1=-1; _c=-4; B++;}
                else if(in1==_d&&_d>=0) {in1=-1; _d=-5; B++;}
            }
            if(in2>=0)
            {
                if(in2==_a&&_a>=0) {in2=-1; _a=-2; B++;}
                else if(in2==_c&&_c>=0) {in2=-1; _c=-4; B++;}
                else if(in2==_d&&_d>=0) {in2=-1; _d=-5; B++;}
            }
            if(in3>=0)
            {
                if(in3==_a&&_a>=0) {in3=-1; _a=-2; B++;}
                else if(in3==_b&&_b>=0) {in3=-1; _b=-3; B++;}
                else if(in3==_d&&_d>=0) {in3=-1; _d=-5; B++;}
            }
            if(in4>=0)
            {
                if(in4==_a&&_a>=0) {in4=-1; _a=-2; B++;}
                else if(in4==_b&&_b>=0) {in4=-1; _b=-3; B++;}
                else if(in4==_c&&_c>=0) {in4=-1; _c=-4; B++;}
            }
            printf("%dA%dB\n",A,B);
        }
    }
    return 0;
}
