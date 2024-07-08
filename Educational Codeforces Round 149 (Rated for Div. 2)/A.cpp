# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int x,k;
	scanf("%d%d",&x,&k);
	if(x%k) printf("1\n%d\n",x);
	else printf("2\n%d %d\n",x-1,1);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

