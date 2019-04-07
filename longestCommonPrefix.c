/*找出公共最长字符前缀*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {

    int i, j;
    static char com[110] = "";
    char *l, *r;

    /*长度为1,直接返回第一个元素*/
    if(strsSize == 1)
        return strs[0];
    if(strsSize == 0)
        return "";
    else if(strcmp(strs[0], "") == 0)
        return "";

    /*com为起始前缀,与后一个比较然后更新前缀
     *再与后一个比较,以此类推,比较完所有字符串*/
    strcpy(com, strs[0]);
    for( i = 0; i < strsSize - 1; i++ ) {

        l = com;
        r = strs[i+1];
        j = 0;

        while( *l && *r ) {
            if( *l != *r ) {
                break;
            }
            else if( *l == *r ){
                j++;
                l++;
                r++;
            }
        }
        /*更新前缀(截断到对应长度)*/
        com[j] = '\0';
    }
    return com;
}

int main()
{
    char *str[4] = {"baab","bacb","b","bcbc" };
    char *p = longestCommonPrefix(str, 4);
    printf("%s\n", p);
    return 0;
}
