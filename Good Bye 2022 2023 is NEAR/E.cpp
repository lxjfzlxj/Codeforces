# include <bits/stdc++.h>
# define N 300010
# define MOD 998244353
bool tag[N];
int fa[N],cnt[N],u[N],v[N],p2[N],f[N][2],las[N],ip2[N];
const int i2=(MOD+1)/2;
struct pair{
	int id,x;
};
std::vector<pair> e[N];
void dfs(int x,int ff) {
	fa[x]=ff; cnt[x]=tag[x];
	for(auto v:e[x]) if(v.x!=ff) {
		dfs(v.x,x);
		cnt[x]+=cnt[v.x];
	}
}
int qpow(int x,int p) {
	int res=1;
	while(p) {
		if(p&1) res=1ll*res*x%MOD;
		x=1ll*x*x%MOD; p>>=1;
	}
	return res;
}
void _() {
	int n,k,i,ans=0,x,ta,tb;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;i++) scanf("%d",&x), tag[x]=true;
	for(i=1;i<n;i++) {
		scanf("%d%d",u+i,v+i);
		e[u[i]].push_back((pair){i,v[i]});
		e[v[i]].push_back((pair){i,u[i]});
	}
	dfs(1,0);
	p2[0]=ip2[0]=1;
	for(i=1;i<=n;i++) p2[i]=p2[i-1]*2%MOD;
	for(i=1;i<=n;i++) ip2[i]=1ll*ip2[i-1]*i2%MOD;
	for(i=1;i<=n;i++) f[i][tag[i]]=1;
	for(i=1;i<n;i++) {
		if(fa[v[i]]==u[i]) std::swap(u[i],v[i]);
		f[u[i]][0]=1ll*f[u[i]][0]*p2[i-las[u[i]]-1]%MOD;
		f[u[i]][1]=1ll*f[u[i]][1]*p2[i-las[u[i]]-1]%MOD;
		f[v[i]][0]=1ll*f[v[i]][0]*p2[i-las[v[i]]-1]%MOD;
		f[v[i]][1]=1ll*f[v[i]][1]*p2[i-las[v[i]]-1]%MOD;
		ta=1ll*f[u[i]][1]*f[v[i]][0]%MOD*ip2[i-1]%MOD;
		tb=1ll*f[u[i]][0]*f[v[i]][1]%MOD*ip2[i-1]%MOD;
		ans=((1ll*ta*(cnt[u[i]]-1)%MOD*(k-cnt[u[i]]+1)+1ll*tb*(cnt[u[i]]+1)%MOD*(k-cnt[u[i]]-1)
			 +1ll*((p2[i]-ta-tb)%MOD+MOD)*cnt[u[i]]%MOD*(k-cnt[u[i]]))%MOD*p2[n-1-i]+ans)%MOD;
		f[u[i]][0]=(0ll+f[u[i]][0]*2-tb+ta+MOD)%MOD;
		f[u[i]][1]=(0ll+f[u[i]][1]*2-ta+tb+MOD)%MOD;
		f[v[i]][0]=(0ll+f[v[i]][0]*2-ta+tb+MOD)%MOD;
		f[v[i]][1]=(0ll+f[v[i]][1]*2-tb+ta+MOD)%MOD;
		las[u[i]]=las[v[i]]=i;
	}
	printf("%d",1ll*ans*ip2[n-1]%MOD*qpow(1ll*k*(k-1)/2%MOD,MOD-2)%MOD);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

