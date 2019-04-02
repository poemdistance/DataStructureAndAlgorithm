#include <stdio.h>

/*欧几里德算法求两数最公大因数*/
int Gcd( int M, int N )
{
    int remain;
    int tmp;

    if( M > N ) {
        tmp = N;
        N = M;
        M = tmp;
    }

    while ( N > 0 ) {
        remain = M % N;
        M = N;
        N = remain;
    }

    return M;
}
