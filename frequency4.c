#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void main() {
    char wrd[50];
    int a[26], x;
    memset(a, 0, sizeof(a));
    gets(wrd);
    for (int i=0; i<strlen(wrd); i++) {
        char c=wrd[i];
        for (int j=0; j<strlen(wrd); j++) {
            if (wrd[j]==c && wrd[j]!=' ') {
                x=wrd[i]-'a';
                ++a[x];
            }
        }
    }
    for (int i=0; i<strlen(wrd); i++) {
        int g=wrd[i]-'a';
        double p=sqrt(a[g]);
        int e=(int)p;
        if (wrd[i]!=' ')
        printf("%c: %d\n", wrd[i], e);
    }
}
