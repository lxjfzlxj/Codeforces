# include <bits/stdc++.h>
# define N 200010
int a[N];
int max(int x,int y) {return x>y?x:y;}
void _() {
	int n,i,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	for(i=3;i<=n;i++) ans=max(ans,2*a[i]-a[i-1]-a[1]);
	for(i=1;i<=n-2;i++) ans=max(ans,a[n]+a[i+1]-2*a[i]);
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

