# include <bits/stdc++.h>

void _() {
	int n,i,x,_or=0,_and=1023;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		_or|=x; _and&=x;
	}
	printf("%d\n",_or-_and);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

