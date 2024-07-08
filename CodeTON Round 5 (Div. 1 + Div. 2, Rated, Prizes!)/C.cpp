# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N],f[N],mx[N];
void _() {
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	memset(mx,128,n+5<<2);
	f[0]=0;
	for(i=1;i<=n;i++) {
		f[i]=std::max(f[i-1],mx[a[i]]+i);
		mx[a[i]]=std::max(mx[a[i]],f[i-1]-(i-1));
	}
	printf("%d\n",f[n]);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}