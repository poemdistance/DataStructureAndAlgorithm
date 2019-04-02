/*高效率取幂运算:时间复杂度O(logN)*/
int mypow(int num, int N)
{
    if( N == 0 )
        return 1;
    if(num % 2 == 0)
        return mypow( num * num, N / 2 );
    else
        return mypow(num, N-1)*num;
}
