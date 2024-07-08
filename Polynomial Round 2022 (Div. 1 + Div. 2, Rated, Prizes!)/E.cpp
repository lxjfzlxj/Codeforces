# include <bits/stdc++.h>
# define N 200010
std::vector<int> e[N];
int a[N<<1],b[N<<1],f[N][20];
bool tag[N];
void dfs(int x,int fa) {
	f[x][0]=fa;
	for(auto v:e[x]) if(v!=fa) {
		dfs(v,x);
	}
}
int jump(int x,int d) {
	int i;
	for(i=0;(1<<i)<=d;i++) {
		if((d>>i)&1) x=f[x][i];
	}
	return x;
}
int calc(int *a,int m) {
	int i,ans=0,x;
	memset(tag,0,sizeof(tag));
	tag[1]=1;
	for(i=1;i<=m;i++) {
		for(x=a[i];!tag[x];x=f[x][0]) {
			ans+=2; tag[x]=1;
		}
	}
	return ans;
}
void _() {
	int n,d,i,j,x,y,m1,m2;
	scanf("%d%d",&n,&d);
	for(i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,1);
	for(j=1;(1<<j)<=n;j++) {
		for(i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
	}
	scanf("%d",&m1);
	for(i=1;i<=m1;i++) scanf("%d",a+i);
	scanf("%d",&m2);
	for(i=1;i<=m2;i++) scanf("%d",b+i);
	for(i=1;i<=m1;i++) b[++m2]=jump(a[i],d);
	for(i=1;i<=m2;i++) a[++m1]=jump(b[i],d);
	printf("%d",calc(a,m1)+calc(b,m2));
}

int main() {
	int T=1;
	while(T--) _();
	return 0;
}

