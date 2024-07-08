# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
int t[111],t_n=0;
void _() {
	long long n;
	int i;
	scanf("%lld",&n);
	t_n=0;
	while(n>0) t[++t_n] = n%10, n/=10;
//	puts(t[t_n]!=1 || t[1]==9?"NO":"YES");
	if(t[t_n]!=1) report("NO\n");
	for(i=1;i<=t_n;i++) {
		if(t[i]==9 || t[i]==-1) report("NO\n");
		t[i+1]--;
	}
	puts("YES");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

