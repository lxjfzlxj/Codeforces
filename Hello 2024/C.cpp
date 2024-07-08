# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N];
void _() {
	int n,i,s=2e9,t=2e9,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) {
		if(s>t) std::swap(s,t);
		if(a[i]<=s) s=a[i];
		else if(a[i]<=t) t=a[i];
		else ans++, s=a[i];
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

