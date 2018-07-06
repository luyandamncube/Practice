int     ft_ws(int c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

int     ft_toup(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int		ft_base(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((ft_toup(c) >= 'A' && ft_toup(c) <= ('A' + base - 10)));
}

int    atoi_base(const *str, int str_base)
{
    int n = 0;
    //int b = strbase;
    int s = 0;

    int sign = 1;
    //Skip past whitespace characters
    while (ft_ws(*str))
        str++;
    //Skip past -/+ characters and assign sign variable
    if (*str++ == '-')
		sign *= -1;

    //n = strlen(str)
    while (*str && ft_base(*str, str_base))
	{
        //char to int conversion for A-F
		if (ft_toup(*str) >= 'A' && 'F' >= ft_toup(*str))
			s = (s * base) + (*str - 'A' + 10);
		else
        //char to int conversion for 0-9
			s = (s * base) + (*str - '0');
		str++;
	}
    return (s * sign);
}