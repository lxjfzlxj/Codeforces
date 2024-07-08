# include <bits/stdc++.h>
# define N 200010
std::map<int,int> mp[2];
int a[N],sum[N],nex[N];
long long szero[N];
void _() {
	int n,q,i,l,r;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		sum[i]=sum[i-1]^a[i]; 
		szero[i]=szero[i-1]+a[i];
	}
	for(i=n;i>=0;i--) {
		if(!mp[!(i%2)].count(sum[i])) nex[i]=n+1;
		else nex[i]=mp[!(i%2)][sum[i]];
		mp[i%2][sum[i]]=i;
	}
	while(q--) {
		scanf("%d%d",&l,&r);
		if(szero[r]==szero[l-1]) puts("0");
		else if(sum[r]!=sum[l-1]) puts("-1");
		else if((r-l+1)%2) puts("1");
		else if(!a[l] || !a[r]) puts("1");
		else puts(nex[l-1]<=r?"2":"-1");
	}
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}
