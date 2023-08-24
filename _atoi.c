/**
 * _erratoi - custom erratoi function handles invalid input by printing error message and exiting
 * @str - string 
 * return 1 if success
 */
int _erratoi (const char *str)
{
	int value = _atoi(str);

	if (value = 0 && str[0] != '\0')
	{
		_eputs("Error: Invalid integer format\n");
		exit(1);
	}
	return value;
}
/**
 * _atoi - atoi function implementation 
 * @str - string to be converted
 * return 0 if no numbers in string otherwise 1
 */
int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i =0;

	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if(str[i] == '+')
	{
		i++;
	} 
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
	       i++;	
	}
	return result * sign;
}
