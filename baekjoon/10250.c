int main(void) {

	int i, j, tc, ppl, width, height;

	scanf("%d", &tc);

	while (tc--){
		scanf("%d %d %d", &height, &width, &ppl);

		for (i = 0; i < width; i++){
			if (ppl == 0) break;
			for (j = 0; j < height; j++){
				if (ppl == 0) break;
				--ppl;
			}
		}
		printf("%d", j);
		if (i < 10) printf("0");
		printf("%d\n", i);
	}
}
