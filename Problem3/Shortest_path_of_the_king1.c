#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    char start[2], end[2];
    char path[8][3];
    size_t cnt = 0;
    scanf("%s%s", start, end);
    while (true)
    {
        if (start[0] < end[0] && start[1] < end[1])
        {
            strcpy(path[cnt], "RU");
            ++start[0];
            ++start[1]; 
        }
        else if (start[0] < end[0] && start[1] == end[1])
        {
            strcpy(path[cnt], "R");
            ++start[0];
        }
        else if (start[0] < end[0] && start[1] > end[1])
        {
            strcpy(path[cnt], "RD");
            ++start[0];
            --start[1];
        }
        else if (start[0] == end[0] && start[1] < end[1])
        {
            strcpy(path[cnt], "U");
            ++start[1]; 
        }
        else if (start[0] == end[0] && start[1] == end[1])
        {
            break;
        }
        else if (start[0] == end[0] && start[1] > end[1])
        {
            strcpy(path[cnt], "D");
            --start[1];
        }
        else if (start[0] > end[0] && start[1] < end[1])
        {
            strcpy(path[cnt], "LU");
            --start[0];
            ++start[1]; 
        }
        else if (start[0] > end[0] && start[1] == end[1])
        {
            strcpy(path[cnt], "L");
            --start[0];
        }
        else if (start[0] > end[0] && start[1] > end[1])
        {
            strcpy(path[cnt], "LD");
            --start[0];
            --start[1];
        }
        ++cnt;
    }
    printf("%d\n", cnt);
    for (size_t index = 0; index < cnt; ++index)
        printf("%s\n", path[index]);
    return 0;
}