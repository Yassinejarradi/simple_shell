#include "shell.h"

/**
 * interactive - outputs true if shell is interactive mode
 * @info: address of the struct
 *
 * Output: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
        return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - verifies if char(i.e Character) is a delimeter
 * @c: the character to verify
 * @delim: the delimeter string
 * Output: 1 if true and 0 if false
 */
int is_delim(char c, char *delim)
{
        while (*delim)
                if (*delim++ == c)
                        return (1);
        return (0);
}

/**
 *_isalpha - verifies for alphabetic character
 *@c: The character to input
 *Output: 1 if the value of c is alphabetic, 0 if the value of c is not alphabetic
 */

int _isalpha(int c)
{
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                return (1);
        else
                return (0);
}

/**
 *_atoi - Changes a string to an integer
 *@s: the string to be changed
 *output: 0 if no numbers in string, otherwaise, output changed number
 */

int _atoi(char *s)
{
        int i,  flag = 0, sign = 1, output;
        unsigned int result = 0;

        for (i = 0;  s[i] != '\0' && flag != 2; i++)
        {
                if (s[i] == '-')
                        sign *= -1;

                if (s[i] >= '0' && s[i] <= '9')
                {
                        flag = 1;
                        result *= 10;
                        result += (s[i] - '0');
                }
                else if (flag == 1)
                        flag = 2;
        }

        if (sign == -1)
                output = -result;
        else
                output = result;

        return (output);
}

