# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 60
int a[N][N],c1[N],c2[N],S,T,ans=0,dis[N<<1],e_n=1,fir[N<<1];
bool vis[N<<1];
std::queue<int> q;
struct edge{
	int nex,to,val,w;
}e[N*N+N+N<<1];
void add(int x,int y,int val,int w) {
	e[++e_n]=(edge){fir[x],y,val,-w}; fir[x]=e_n;
	e[++e_n]=(edge){fir[y],x,0,w}; fir[y]=e_n;
}
bool SPFA() {
	int head,i;
	memset(dis,63,T+5<<2);
	dis[S]=0; q.push(S);
	while(!q.empty()) {
		head=q.front(); vis[head]=false; q.pop();
		for(i=fir[head];i;i=e[i].nex) {
			if(e[i].val && dis[head]+e[i].w<dis[e[i].to]) {
				dis[e[i].to]=dis[head]+e[i].w;
				if(!vis[e[i].to]) q.push(e[i].to), vis[e[i].to]=true;
			}
		}
	}
	return dis[T]<dis[0];
}
int dfs(int x,int flow) {
	int flans=0,d,i;
	if(x==T) return flow;
	vis[x]=true;
	for(i=fir[x];i && flow;i=e[i].nex) {
		if(e[i].val && !vis[e[i].to] && dis[x]+e[i].w==dis[e[i].to]) {
			d=dfs(e[i].to,std::min(e[i].val,flow));
			if(!d) dis[e[i].to]=2e9;
			e[i].val-=d; e[i^1].val+=d;
			flow-=d; flans+=d;
			ans+=d*e[i].w;
		}
	}
	vis[x]=false;
	return flans;
}
int Dinic() {
	int flans=0;
	while(SPFA()) flans+=dfs(S,2e9);
	return flans;
}
void _() {
	int n,m,i,j,fl,cnt1=0,cnt2=0,lc1=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) scanf("%d",a[i]+j), lc1+=a[i][j];
	}
	for(i=1;i<=n;i++) scanf("%d",c1+i), cnt1+=c1[i];
	for(i=1;i<=m;i++) scanf("%d",c2+i), cnt2+=c2[i];
	S=n+m+1; T=S+1;
	for(i=1;i<=n;i++) add(S,i,c1[i],0);
	for(i=1;i<=m;i++) add(n+i,T,c2[i],0);
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) add(i,n+j,1,a[i][j]);
	}
	fl=Dinic(); ans=-ans;
	if(fl!=cnt1 || fl!=cnt2) report("-1");
	printf("%d",cnt1+lc1-2*ans);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

