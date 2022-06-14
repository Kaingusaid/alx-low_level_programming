#include "main.h"


/**
 *_isalpha - display 1 to lower/upper case, 0 otherwise
 *@c: parameter character or ascii code
 *Return: 0 or 1
 */
int _isalpha(int c)
{
	int result;

	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		result = 1;
	}
	else
	{
		result = 0;
	}

	return (result);
}
