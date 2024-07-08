# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 300010
# define MOD 998244353
std::vector<int> e[N];
int f[N][3];
void inc(int &x,int y) {(x+=y)>=MOD?x-=MOD:0;}
void dfs(int x,int fa) {
	int val1=0,val2=1,val3=0;
	for(auto v:e[x]) if(v!=fa) {
		dfs(v,x);
		inc(val1,f[v][2]);
		val2=1ll*val2*(f[v][0]+f[v][1])%MOD;
		inc(val3,f[v][1]);
	}
	f[x][0]=1;
	f[x][1]=val2;
	f[x][2]=(val1+val3)%MOD;
}
void _() {
	int n,i,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++) e[i].clear();
	for(i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,1);
	printf("%d\n",(0ll+f[1][0]+f[1][1]+f[1][2])%MOD);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}
