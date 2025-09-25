#include<stdlib.h>
#include <stdio.h>

int count_len(long nb)
{       
    int i = 0;
    if(nb <= 0)
        i++;
    while(nb != 0)
    {
        nb /= 10;
        i++;
    }
    return(i);
}
char *itoa(int nb)
{
    int i;
    int len;
    long n;
    char *str;

    n = nb;
    len = count_len(n);
    str = malloc(sizeof(char) * (len+ 1));
    str[len] = '\0';
    i = len - 1;
    if(n < 0)
    {
        str[0] = '-';
        n *= -1;
    }
    while(n > 9)
    {
        str[i] = n % 10 + '0';
        n /= 10;
        i--;
    }
        str[i] = n + '0';
    	return (str);
}

int main()
{
    char *numero = itoa(45);
    printf("%s \n",numero);
}