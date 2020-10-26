#include <stdio.h>
#include <stdlib.h>
int main()
{
    char start[2], end[2];
    scanf("%s%s", start, end);
    int dx = end[0] - start[0];
    int dy = end[1] - start[1];
    char cx, cy;
    cx = dx > 0 ? 'R' : 'L';
    cy = dy > 0 ? 'U' : 'D';
    dx = abs(dx);
    dy = abs(dy);
    int result = dx > dy ? dx : dy;
    printf("%d\n", result);
    for (; dx || dy; putchar('\n'))
    {
        if (dx > 0)
        {
            putchar(cx);
            --dx;
        }
        if (dy)
        {
            putchar(cy);
            --dy;
        }
    }
    return 0;
}