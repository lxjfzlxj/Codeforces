# include <bits/stdc++.h>
# define N 200010
int n,a[N],dfl[N],dfr[N],dfn=0,sum[N],g[N][32],pos[N],ans[N],ans_n=0;
bool f[N][32];
std::vector<int> e[N];
void dfs(int x) {
	dfl[x]=++dfn;
	pos[dfn]=x;
	sum[x]=a[x];
	for(auto v:e[x]) {
		dfs(v);
		sum[x]^=sum[v];
	}
	dfr[x]=dfn;
}
void prt(int x,int y) {
	if(!x) return;
	if(x<=n) ans[++ans_n]=pos[x];
	prt(g[x][y],y^sum[pos[g[x][y]]]);
}
void _() {
	int i,j,x;
	scanf("%d",&n);
	if(!(n&1)) return printf("2\n1 1"), void();
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=2;i<=n;i++) {
		scanf("%d",&x);
		e[x].push_back(i);
	}
	dfs(1);
	f[1][0]=true;
	for(i=1;i<=n;i++) {
		x=pos[i];
		if((dfr[x]-dfl[x]+1)%2==0) {
			for(j=0;j<32;j++) if(f[i][j]) {
				f[dfr[x]+1][j^sum[x]]=true;
				g[dfr[x]+1][j^sum[x]]=i;
			}
		}
		for(j=0;j<32;j++) if(f[i][j]) {
			f[i+1][j]=true;
			g[i+1][j]=g[i][j];
		}
	}
	if(!f[n+1][sum[1]]) return puts("-1"), void();
	prt(n+1,sum[1]);
	ans[++ans_n]=1;
	printf("%d\n",ans_n);
	for(i=1;i<=ans_n;i++) printf("%d ",ans[i]);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

