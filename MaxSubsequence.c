/*最大子序列求解*/
#include <stdio.h>


/*O(N^3)*/
int MaxSubsequence(const int a[], int N)
{
    int thisSum, i, j, k;

    int MaxSum = 0;

    /*计算出了每一个子序列的和*/
    for(i=0; i<N; i++)
    {
        for(j=i; j<N; j++)
        {
            thisSum = 0;
            for (k = i; k <= j; k++)
                thisSum += a[k];
            if( thisSum > MaxSum )
                MaxSum = thisSum;
        }
    }
    return MaxSum;
}

/*O(N^2)*/
int MaxSubsequence2(const int a[], int N)
{
    int thisSum = 0;
    int MaxSum, i, j;

    MaxSum = 0;
    /*两个for循环扫描了整个子序列，保留了最大和用于比较*/
    for( i = 0; i < N; i++ )
    {
        thisSum = 0;
        for ( j = i; j < N; j++ )
        {
            thisSum += a[j];
            if( thisSum > MaxSum )
                MaxSum = thisSum;
        }
    }

    return MaxSum;
}

/*O(N), 只读取一遍序列，可用于联机算法,仅需要常量空间和线性时间运行*/
int MaxSubsequence3(const int a[], int N)
{
    int thisSum = 0;
    int MaxSum = 0;
    int i, j;

    for (i = 0; i < N; i++)
    {
        thisSum += a[i];
        if(thisSum > MaxSum)
            MaxSum = thisSum;

        /*只要thisSum没有小于0,就还可以继续加，否则从新的值开始算，也就是清零thisSum*/
        else if(thisSum < 0)
            thisSum = 0;
    }
    return MaxSum;
}

/*分治解法,时间复杂度：当N为偶数：O(Nlog(N))*/
    int
MaxSubsum(const int a[], int left, int right)
{
    int leftBorderSum, rightBorderSum;
    int maxLeftBorderSum, maxRightBorderSum;
    int maxLeftSum, maxRightSum;
    int center, i;

    if( left == right )
        if(a[left] < 0)
            return 0;
        else
            return a[left];

    center = ( left + right ) / 2;
    /*返回的是左序列的最大值*/
    maxLeftSum = MaxSubsum(a, left, center);

    /*返回右序列的最大值*/
    maxRightSum = MaxSubsum(a, center+1, right);

    /*获取以中间为起点，左右两边序列的最大和*/
    maxLeftBorderSum = 0; leftBorderSum = 0;
    for( i = center; i >= left; i-- )
    {
        leftBorderSum += a[i];
        if( leftBorderSum > maxLeftBorderSum )
            maxLeftBorderSum = leftBorderSum;
    }

    maxRightBorderSum = 0; rightBorderSum = 0;
    for( i = center+1; i <= right; i++ )
    {
        rightBorderSum += a[i];
        if( rightBorderSum > maxRightBorderSum )
            maxRightBorderSum = rightBorderSum;
    }

    int val;
    int middle = maxLeftBorderSum + maxRightBorderSum;

    val = maxLeftSum > maxRightSum ? maxLeftSum : maxRightSum;

    return  val > middle ? val : middle;
}

/*分治求解驱动函数*/
int getMaxSubSum(const int a[], int N)
{
    MaxSubsum(a, 0, N-1);
}
