# include <bits/stdc++.h>
# define N 500010
# define MOD 998244353 
int n,a[N],b[N],ls[N],rs[N],val[N<<1],ans=0;
void dfs1(int x) {
	if(x>=n) {
		val[x]=a[x-n+1];
		return;
	}
	dfs1(ls[x]);
	dfs1(rs[x]);
	val[x]=1ll*val[ls[x]]*val[rs[x]]%MOD;
}
int dfs2(int x,int sum) {
	if(x>=n) {
		ans=(1ll*sum*(b[x-n+1]-1)+ans)%MOD;
		printf("%d ",ans);
		return b[x-n+1];
	}
	int mul=1;
	mul=1ll*mul*dfs2(ls[x],(sum+val[ls[x]])%MOD)%MOD;
	sum=1ll*sum*mul%MOD;
	mul=1ll*mul*dfs2(rs[x],(sum+val[rs[x]])%MOD)%MOD;
	return mul;
}
int main() {
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	for(i=1;i<n;i++) scanf("%d%d",ls+i,rs+i);
	dfs1(1);
	for(i=1;i<=n*2-1;i++) ans=(ans+val[i])%MOD; 
	dfs2(1,val[1]);
	return 0;
}
