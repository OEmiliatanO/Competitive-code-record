#include <cstdio>
using namespace std;

typedef struct _matrix
{
    long long m_00,m_01,m_02,m_03;
}Matrix;
inline Matrix multiply(Matrix A,Matrix B)
{
    Matrix C;
    C.m_00=(A.m_00*B.m_00+A.m_01*B.m_02);
    C.m_01=(A.m_00*B.m_01+A.m_01*B.m_03);
    C.m_02=(A.m_02*B.m_00+A.m_03*B.m_02);
    C.m_03=(A.m_02*B.m_01+A.m_03*B.m_03);
    return C;
}
Matrix Matrix_pow(Matrix O,int n)
{
    if(n==1) return O;
    else if(n%2)
    {
        Matrix R=Matrix_pow(O,(n-1)/2);
        return multiply(multiply(R,R),O);
    }
    else
    {
        Matrix R=Matrix_pow(O,n/2);
        return multiply(R,R);
    }
}
long long F(int n)
{
    Matrix O;
    O.m_00=1;
    O.m_01=1;
    O.m_02=1;
    O.m_03=0;
    Matrix f=Matrix_pow(O,n);
    return f.m_00;
}
int main()
{
    for(int n;scanf("%d",&n)!=EOF;)
        if(n==0||n==1) printf("1\n");
        else
            printf("%lld\n",F(n));
    return 0;
}
