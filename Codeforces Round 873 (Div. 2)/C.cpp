# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
# define MOD 1000000007
int a[N],b[N];
void _() {
	int n,i,j,cnt,ans=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	std::sort(a+1,a+n+1);
	std::sort(b+1,b+n+1);
	for(j=i=n,cnt=0;j>=1;j--) {
		while(i>=1 && a[i]>b[j]) i--, cnt++;
		if(cnt<=0) report("0\n");
		ans=1ll*ans*cnt%MOD;
		cnt--;
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

