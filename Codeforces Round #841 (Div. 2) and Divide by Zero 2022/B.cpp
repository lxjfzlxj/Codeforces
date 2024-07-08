# include <bits/stdc++.h>
# define MOD 1000000007
const int i6=(MOD+1)/6;
void _() {
	int n;
	scanf("%d",&n);
	printf("%d\n",(2ll*(n-1)*n%MOD*(2*n-1)%MOD*i6+1ll*n*(n-1)/2+1ll*n*n)%MOD*2022%MOD);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

