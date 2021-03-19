#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    int T, M, N;
    int R[100][100];
    cin >> T;
    for (int i=0; i<T; i++) {
        int n = 1;
        cin >> N >> M;
        for (int j=0; j<(N+1)/2; j++) {
            for (int k=0; k<N-2*j-1; k++)
                R[j][j+k] = n++;
            for (int k=0; k<N-2*j-1; k++)
                R[j+k][N-j-1] = n++;
            for (int k=0; k<N-2*j-1; k++)
                R[N-j-1][N-k-j-1] = n++;
            for (int k=0; k<N-2*j-1; k++)
                R[N-j-k-1][j] = n++;
        }
        if (N%2)
            R[N/2][N/2] = n;

        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++)
                if (M == 1)
                    printf("%5d", R[j][k]);
                else
                    printf("%5d", R[k][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
