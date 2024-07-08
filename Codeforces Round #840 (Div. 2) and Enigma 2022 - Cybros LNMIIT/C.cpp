# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N];
int abs(int x) {return x>=0?x:-x;}
long long max(long long x,long long y) {return x>y?x:y;}
void _() {
	int n,i,mx=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	if(n>3) {
		for(i=1;i<=n;i++) {
			if(a[i]>mx) mx=a[i];
		}
		printf("%lld\n",1ll*mx*n);
	}
	else if(n==2) {
		printf("%lld\n",max(a[1]+a[2],abs(a[1]-a[2])*2));
	}
	else printf("%lld\n",max(max(max(3ll*a[1],3ll*a[3]),max(3ll*abs(a[1]-a[2]),3ll*abs(a[2]-a[3]))),0ll+a[1]+a[2]+a[3]));
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

