int     *ft_range(int start, int end)
{
    int max = start > end ? start : end;
    int min = start < end ? start : end;
    int abs_start = 1;
    int abs_end = 1;
    int range;

    abs_start *= start < 0 ? start : start * -1;
    abs_end *= end < 0 ? end : end * -1;
    range = abs_start + abs_end;

}

int     main()
{
    return (0);
}