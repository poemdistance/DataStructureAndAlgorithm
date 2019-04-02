#include <stdio.h>

int BinarySearch(const int a[], int low, int high, int num)
{
    int center = 0;

    while(low <= high)
    {
        center = ( low + high ) / 2;

        if( num > a[center] )
            low = center + 1;
        else if(num < a[center])
            high = center - 1;
        else
            return center;
    }
    return -1;
}
