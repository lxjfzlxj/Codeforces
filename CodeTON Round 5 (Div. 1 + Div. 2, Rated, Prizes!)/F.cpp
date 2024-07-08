# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 5010
std::vector<int> e[N];
int dis[N],ans[N],q[N];
bool vis[N];
void bfs(int s) {
	int head=1,tail=0,u,sum=0;
	memset(vis,false,sizeof(vis));
	vis[s]=true; dis[s]=0; q[++tail]=s;
	while(head<=tail) {
		u=q[head]; head++;
		for(auto v:e[u]) if(!vis[v]) {
			vis[v]=true;
			dis[v]=dis[u]+1;
			q[++tail]=v;
			sum+=dis[v];
			ans[tail]=std::min(ans[tail],sum);
		}
	}
}
void _() {
	int x,y,n,i;
	scanf("%d",&n);
	for(i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	memset(ans,63,sizeof(ans));
	ans[0]=ans[1]=0;
	for(i=1;i<=n;i++) bfs(i);
	for(i=0;i<=n;i++) printf("%d ",i*(n-1)-ans[i]*2);
	puts("");
}

int main() {
	int T=1;
	// scanf("%d",&T);
	while(T--) _();
	return 0;
}