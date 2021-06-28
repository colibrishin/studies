#include <stdio.h>

int main(void) {
	int i, cnt = 0;
	char str[1000001] = { 0, };

	gets(str);

	if (str[0] == ' ') cnt--;
	
	for (i = 0; i < 1000001; i++){
		if (str[i] == 0) {
			if (str[i - 1] == ' ') cnt--; 
			break;
		}
		if (str[i] == ' ') cnt++;
	}
	printf("%d", cnt + 1);
}
