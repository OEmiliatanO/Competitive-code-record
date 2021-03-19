#include <cstdio>
#include <vector>
using namespace std;
using uint64=unsigned long long;
using uint=unsigned int;
const int MOD=10007;
typedef vector<int> vec;
typedef vector<vec> mat;
mat mul(const mat &A,const mat &B)
{
    mat C(A.size(),vec(B[0].size()));
    for(int i=0;i<A.size();i++)
        for(int k=0;k<B.size();k++)
            for(int j=0;j<B[0].size();j++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
    return C;
}
mat pow(mat A,int n)
{
    mat B(A.size(),vec(A.size()));
    for(int i=0;i<A.size();i++)
    {
        B[i][i]=1;
    }
    while(n>0)
    {
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
int main()
{
    mat A(3,vec(3));
    A[0][0]=A[0][1]=A[0][2]=1;
    A[1][0]=1,A[1][1]=A[1][2]=0;
    A[2][0]=0,A[2][1]=1,A[2][2]=0;
    mat result;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        result=pow(A,n-1);
        printf("%d\n",(result[2][0]+result[2][1]+result[2][2])%MOD);
    }
    return 0;
}
