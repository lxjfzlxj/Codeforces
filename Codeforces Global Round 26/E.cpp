# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
std::vector<int> e[N];
int f[N][2],ans,deg[N];
void dfs1(int x,int fa) {
	f[x][0]=0;
	f[x][1]=1;
	for(auto v:e[x]) {
		if(v!=fa) {
			dfs1(v,x);
			f[x][0]+=std::max(f[v][0],f[v][1]);
			f[x][1]+=f[v][0];
		}
	}
//	printf("%d:%d %d\n",x,f[x][0],f[x][1]);
}
void dfs2(int x,int fa,int nw0,int nw1) {
//	printf("dfs2 %d %d %d\n",x,nw0,nw1);
	if(deg[x]==1) {
		int sum=std::max(nw0,nw1)+1;
		for(auto v:e[x]) if(v!=fa) {
			sum+=std::max(f[v][0],f[v][1]);
		}
		ans=std::max(ans,sum);
	}
	int f0=f[x][0]+std::max(nw0,nw1),f1=f[x][1]+nw0;
	for(auto v:e[x]) if(v!=fa) {
		dfs2(v,x,f0-std::max(f[v][0],f[v][1]),f1-f[v][0]);
	}
}
void _() {
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++) e[i].clear(), deg[i]=0;
	for(i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
		deg[x]++; deg[y]++;
	}
	dfs1(1,1);
	ans=std::max(f[1][1],f[1][0]);
	dfs2(1,1,0,0);
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

