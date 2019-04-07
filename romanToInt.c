#include <stdio.h>
#include <string.h>

/*建立从数字到字符的映射关系CharTable & NumTable*/

/*1,4, 5,,9, 10, 40, 50, 90, 100, 400, 500, 900, 1000*/
char CharTable[][3] = { "I", "IV", "V", "IX", "X", "XL" ,"L", 
    "XC", "C", "CD", "D", "CM", "M" };

int NumTable[13]= {1,4 ,5,9, 10, 
    40, 50, 90, 100, 400, 500, 900, 1000};

int Map(char *s)
{
    for(int i = 0; i < 13; i++)
        if(strcmp(CharTable[i], s) == 0)
            return NumTable[i];

        return 0;
}

int romanToInt(char *s)
{
    char *p = s;
    char str[3];
    int num  = 0;
    int i = 0, j = 0;
    while(*p) {
        if(*p == 'I' && (*(p+1) == 'V' || *(p+1) == 'X'))
            i = 2;
        else if(*p == 'X' && (*(p+1) == 'C' || *(p+1) == 'L')) 
            i = 2;
        else if(*p == 'C' && (*(p+1) == 'D' || *(p+1) == 'M')) 
            i = 2;
        else 
            i = 1;
        
        for(j = 0; j < i; j++)
            str[j] = *p++;
        str[j] = '\0';

        num += Map(str);
    }
    return num;
}

int main()
{
    char str[] = "IVIIXCMI";
    int res = romanToInt(str);
    printf("%d\n", res);
    return 0;
}

/* 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:

输入: "III"
输出: 3
示例 2:

输入: "IV"
输出: 4
示例 3:

输入: "IX"
输出: 9
示例 4:

输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:

输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * */
