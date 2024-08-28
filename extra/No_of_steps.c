#include <stdio.h>

void main(){
	int n, min;
	long t = 0;
    scanf("%d", & n);
	int a[n], b[n];
    for (int i = 0; i < n; i++)
    scanf("%d",& a[i]);
    for (int i = 0; i < n; i++)
    scanf("%d",& b[i]);
    min = a[0];
    for (int i = 1; i < n; i++)
    	if (a[i] < min)
        	min = a[i];
    for (int i = 0; i < n; i++)
		if (a[i] > min) {
			if ((((a[i] - min) % b[i]) == 0))
				t += (a[i] - min) / b[i];
			else {
				t = -1;
				break;
			}
    	}
    printf("%ld", t);
}
