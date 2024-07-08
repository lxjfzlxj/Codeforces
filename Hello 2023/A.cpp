# include <bits/stdc++.h>
# define N 100010
char s[N];
void _() {
	int n,i,rmn=2e9,lmx=0;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++) {
		if(s[i]=='L') lmx=i;
		else if(rmn>n) rmn=i;
	}
	if(lmx>rmn) return puts("0"), void();
	for(i=1;i<n;i++) {
		if(s[i]=='L' && s[i+1]=='R') return printf("%d\n",i), void();
	}
	puts("-1");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

