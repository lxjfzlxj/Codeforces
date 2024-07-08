# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 110
int g[N][N],mn[N],ans[N][N],ans_n=0;
bool vis[N];
void _() {
	int n,m,i,j,k,x,y,w,r,minn;
	long long sum=0;
	scanf("%d%d",&n,&m);
	memset(g,127,sizeof(g));
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&w);
		g[x][y]=g[y][x]=w;
	}
	for(i=1;i<n;i++) mn[i]=g[i][n];
	vis[n]=true;
	for(r=1;r<n;r++) {
		minn=g[0][0];
		for(i=1;i<=n;i++) {
			if(!vis[i] && (mn[i]<minn || mn[i]==minn && k==1)) {
				minn=mn[i]; k=i;
			}
		}
		if(minn==g[0][0]) report("inf\n");
		if(minn) {
			ans_n++; sum+=minn;
			for(i=1;i<=n;i++) {
				if(!vis[i]) ans[ans_n][i]=1;
			}
			ans[ans_n][0]=minn;
		}
		if(k==1) break;
		vis[k]=true;
		for(i=1;i<=n;i++) {
			if(!vis[i]) {
				if(mn[i]<g[0][0]) mn[i]-=minn;
				mn[i]=std::min(mn[i],g[k][i]);
			}
		}
		
	}
	printf("%lld %d\n",sum,ans_n);
	for(i=1;i<=ans_n;i++) {
		for(j=1;j<=n;j++) putchar(ans[i][j]+'0');
		printf(" %d\n",ans[i][0]);
	}
}

int main() {
	int T=1;
	// scanf("%d",&T);
	while(T--) _();
	return 0;
}