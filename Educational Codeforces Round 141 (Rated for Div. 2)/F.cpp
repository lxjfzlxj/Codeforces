# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 3010
int a[N],b[N],S,T,fir[N<<1],bef[N<<1],e_n=1,col1[N],col2[N],q[N<<1],dis[N<<1],ee[N];
bool vis[N];
struct edge{
	int nex,to,val;
}e[N*6];
int min(int x,int y) {return x<y?x:y;}
void add(int x,int y,int w) {
	e[++e_n]=(edge){bef[x],y,w}; bef[x]=e_n;
	e[++e_n]=(edge){bef[y],x,0}; bef[y]=e_n;
}
bool bfs() {
	int head=1,tail=0,i;
	memcpy(fir,bef,sizeof(bef));
	memset(dis,0,sizeof(dis));
	q[++tail]=S; dis[S]=1;
	while(head<=tail) {
		for(i=fir[q[head]];i;i=e[i].nex) {
			if(e[i].val && !dis[e[i].to]) {
				dis[e[i].to]=dis[q[head]]+1;
				q[++tail]=e[i].to;
			}
		}
		head++;
	}
	return dis[T];
}
int dfs(int x,int flow) {
	int ans=0,d;
	if(x==T || !flow) return flow;
	for(int &i=fir[x];i;i=e[i].nex) {
		if(e[i].val && dis[x]+1==dis[e[i].to] && (d=dfs(e[i].to,min(flow,e[i].val)))) {
			e[i].val-=d; e[i^1].val+=d;
			ans+=d; flow-=d;
			if(!flow) break;
		}
	}
	return ans;
}
int Dinic() {
	int ans=0;
	while(bfs()) ans+=dfs(S,2e9);
	return ans;
}
void _() {
	int n,i,j,c1=0,c2=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	memset(vis,false,sizeof(vis));
	for(i=1;i<=n;i++) if(!vis[i]) {
		col1[i]=++c1; vis[i]=true;
		for(j=a[i];!vis[j];j=a[j]) col1[j]=c1, vis[j]=true;
	}
	memset(vis,false,sizeof(vis));
	for(i=1;i<=n;i++) if(!vis[i]) {
		col2[i]=++c2; vis[i]=true;
		for(j=b[i];!vis[j];j=b[j]) col2[j]=c2, vis[j]=true;
	}
	S=c1+c2+1; T=S+1;
	for(i=1;i<=c1;i++) add(S,i,1);
	for(i=c1+1;i<=c1+c2;i++) add(i,T,1);
	for(i=1;i<=n;i++) {
		add(col1[i],c1+col2[i],1);
		ee[i]=e_n-1;
	}
	printf("%d\n",n-Dinic());
	for(i=1;i<=n;i++) {
		if(e[ee[i]].val) printf("%d ",i);
	}
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

