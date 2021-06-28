int main(void) {
	int i, length, best_w, best_n = 0, words[129] = { 0, }, conflict;
	char str[1000001] = { 0, };

	scanf("%s", str);

	for (length = 0;; length++){
		if (str[length] == 0) break;
		if (str[length] > 96) str[length] -= 32;
	}

	for (i = 0; i < length; i++)
		words[(int)str[i]]++;

	for (i = 0; i < 129; i++){

		if (words[i] > best_n) {
			best_n = words[i];
			best_w = i;
			conflict = 0;
		}

		else if (words[i] == best_n)
			conflict = 1;
	}
	if (conflict == 1) printf("?");
	else printf("%c", best_w);
}