# include <bits/stdc++.h>

int main() {
	int T,a,b;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&a,&b);
		puts((a+b)%2?"Alice":"Bob");
	}
	return 0;
} 
