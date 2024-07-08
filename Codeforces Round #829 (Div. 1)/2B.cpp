# include <bits/stdc++.h>

void _() {
	int n,i,d,j;
	scanf("%d",&n);
	for(d=1;n/d*d-1>=d;d++); d--;
	for(i=d-n%d;i>=1;i--) {
		for(j=i;j<=n;j+=d) printf("%d ",j);
	}
	for(i=d-n%d+1;i<=d;i++) {
		for(j=i;j<=n;j+=i) printf("%d ",j);
	}
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

