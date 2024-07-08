# include <bits/stdc++.h>
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
void _() {
	int n,i,x,g=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		if(!g) g=x;
		else g=gcd(g,x);
	}
	if(g==1) return puts("0"), void();
	for(i=n;i>=1 && i>=n-2;i--) {
		if(gcd(g,i)==1) return printf("%d\n",n-i+1), void();
	}
	puts("3");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

