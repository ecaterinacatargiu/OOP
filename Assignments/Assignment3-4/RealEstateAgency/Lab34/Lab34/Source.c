#include <stdio.h>

int fun(int i)
{
	if (i % 2)
		return i++;
	else
		return fun(fun(i - 1));
}
int main()
{
	printf("%d", fun(200));
	return 0;
}