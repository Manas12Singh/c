#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

char *longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0) return "";
    for (int i = 0; i < strsSize - 1; i++) {
        for (int j = 0; j < strsSize - i - 1; j++) {
            if (strcmp(strs[j], strs[j + 1]) > 0)
                swap(&strs[j], &strs[j + 1]);
        }
    }
    int l1 = strlen(strs[0]);
    int c, i;
    char *s = (char *)malloc(l1 + 1);
    for (i = 0; i < l1; i++) {
        c = 0;
        for (int j = 0; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i])
                break;
            c++;
        }
        if (c != strsSize)
            break;
        else
            s[i] = strs[0][i];
    }
    s[i] = '\0';
    return s;
}

int main() {
    char *strs[] = {"dog", "racecar", "cars"};
    int strsSize = sizeof(strs) / sizeof(char *);
    char *res = longestCommonPrefix(strs, strsSize);
    printf("%s\n", res);
    free(res);
    return 0;
}