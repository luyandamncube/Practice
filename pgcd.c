#include <stdio.h>
#include <stdlib.h>

int     main(int argc, char **argv)
{
    int _first;
    int _second;
    int max = 0;
    int k = 1;
    int result = 0;
    if (argc == 3)
    {
        _first = atoi(argv[1]);
        _second = atoi(argv[2]);
        max = _first > _second ? _first : _second;
        while (k < max)
        {
            if ((_first % k == 0) && (_second % k == 0))
                result = k;
            k++;
        }
        printf("%d", result);
    }
    printf("\n");
    return (0);
}