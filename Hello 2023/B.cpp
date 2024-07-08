# include <bits/stdc++.h>

void _() {
	int n,i;
	scanf("%d",&n);
	if(n==3) return puts("NO"), void();
	puts("YES");
	if(n&1) {
		for(i=1;i<=n;i++) printf("%d ",(i&1)?n-3:1-n);
	} else {
		for(i=1;i<=n;i++) printf("%d ",1-(i&1)*2);	
	}
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

