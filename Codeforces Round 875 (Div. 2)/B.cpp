# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int f[N<<1],g[N<<1],a[N],b[N];
int max(int x,int y) {return x>y?x:y;}
void _() {
	int n,i,j,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	memset(f,0,(n*2+5)<<2);
	memset(g,0,(n*2+5)<<2);
	for(i=1;i<=n;i=j) {
		for(j=i;j<=n && a[i]==a[j];j++);
		f[a[i]]=max(f[a[i]],j-i);
	}
	for(i=1;i<=n;i=j) {
		for(j=i;j<=n && b[i]==b[j];j++);
		g[b[i]]=max(g[b[i]],j-i);
	}
	for(i=1;i<=n*2;i++) ans=max(ans,f[i]+g[i]);
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

