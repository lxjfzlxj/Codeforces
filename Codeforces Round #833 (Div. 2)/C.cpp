# include <bits/stdc++.h>
# define N 200010
int a[N];
long long sum[N];
std::map<long long,int> mp;
int max(int x,int y) {return x>y?x:y;}
void _() {
	int n,i,ans=0,r,j,mx;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		sum[i]=sum[i-1]+a[i];
	}
	for(i=1;i<=n && a[i];i++) {
		if(!sum[i]) ans++;
	}
	for(;i<=n;i++) {
		for(r=i+1;r<=n && a[r];r++); r--;
		mx=0; mp.clear();
		for(j=i;j<=r;j++) mx=max(mx,++mp[sum[j]]);
		ans+=mx; i=r;
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

