# include <bits/stdc++.h>

void _() {
	int n,i;
	scanf("%d",&n);
	printf("%d\n",(n+1)/2);
	for(i=1;i<=(n+1)/2;i++) printf("%d %d\n",i*3-2,3*n-i*3+3);
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

