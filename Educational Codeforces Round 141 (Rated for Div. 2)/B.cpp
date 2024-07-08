# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 55
bool vis[N][N];
int ans[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void _() {
	int n,i,j,dir=0,x=1,y=1;
	scanf("%d",&n);
	memset(vis,true,sizeof(vis));
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) vis[i][j]=false;
	}
	for(i=1;i<=n*n;i++) {
		ans[x][y]=i%2?(i+1)/2:n*n+1-i/2;
		vis[x][y]=true;
		if(vis[x+dx[dir]][y+dy[dir]]) dir=(dir+1)%4;
		x+=dx[dir]; y+=dy[dir];
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) printf("%d ",ans[i][j]);
		puts("");
	}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

