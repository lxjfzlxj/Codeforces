# include <bits/stdc++.h>
# define N 100010
# define MOD 998244353
int a[N],b[N],ans,vc,ec;
bool vis[N],self[N],issf;
std::vector<int> e[N];
void dfs(int x) {
	vis[x]=1;
	vc++; ec+=e[x].size();
	if(self[x]) issf=1;
	for(auto v:e[x]) {
		if(!vis[v]) dfs(v);
	}
}
void _() {
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) e[i].clear(), self[i]=0;
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	for(i=1;i<=n;i++) {
		if(a[i]==b[i]) self[a[i]]=1;
		e[a[i]].push_back(b[i]);
		e[b[i]].push_back(a[i]);
	}
	for(i=1;i<=n;i++) vis[i]=0;
	ans=1;
	for(i=1;i<=n;i++) if(!vis[i]) {
		vc=ec=issf=0; dfs(i); ec/=2;
		if(ec>vc) return puts("0"), void();
		else if(ec==vc-1) ans=1ll*ans*vc%MOD;
		else if(ec==vc) {
			if(issf) ans=1ll*ans*n%MOD;
			else ans=ans*2%MOD;
		}
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

