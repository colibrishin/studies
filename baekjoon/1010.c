int combi(int n, int k);
int combi(int n, int k){
	int i;
	unsigned long long r = 1;
	for (i = 1; i<=k; i++) 
		r = r*(n - i+1) / i;

	return r;
}

int main(void) {
	int tc, n, m, i;
	scanf("%d", &tc);

	for (i = 0; i < tc; i++){
		scanf("%d %d", &n, &m);
		if (m == n) printf("1\n");
		else printf("%d\n", combi(m,n));
	}
	return 0;
}