# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
struct edge{
	int to,val;
	edge(int t,int v) {to=t; val=v;}
};
std::vector<edge> e[N];
int f[N],ans;
void dfs(int x,int fa,int las) {
	ans=std::max(ans,f[x]);
	for(auto i:e[x]) if(i.to!=fa) {
		f[i.to]=f[x]+(i.val<las);
		dfs(i.to,x,i.val);
	}
}
void _() {
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++) e[i].clear();
	for(i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		e[x].emplace_back(y,i);
		e[y].emplace_back(x,i);
	}
	f[1]=0; ans=0; dfs(1,0,2e9);
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

