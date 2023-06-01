#include <stdio.h>

int main()
{
    char ch[100];
    int n, m;
    gets(ch);
    scanf("%d %d", &n, &m);
    rewind(stdin);
    puts(stdin->_ptr);
    return 0;
}
