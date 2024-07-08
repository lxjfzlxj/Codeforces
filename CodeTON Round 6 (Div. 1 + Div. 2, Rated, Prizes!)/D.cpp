# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N],t[N],t_n,ans[N];
void _() {
	int n,k,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	scanf("%d",&k);
	t_n=0;
	for(i=1;i<=n;i++) {
		while(t_n && a[t[t_n]]>=a[i]) t_n--;
		t[++t_n]=i;
	}
	memset(ans,0,n+5<<2);
	for(i=1;i<t_n;i++) {
		ans[t[i]]=std::max((1ll*a[t[i+1]]*(k/a[t[i]])-k+a[t[i+1]]-a[t[i]]-1)/(a[t[i+1]]-a[t[i]]),0ll);
		k-=ans[t[i]]*a[t[i]];
	}
	ans[t[t_n]]=k/a[t[t_n]];
	for(i=n;i>=1;i--) ans[i]+=ans[i+1];
	for(i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}
