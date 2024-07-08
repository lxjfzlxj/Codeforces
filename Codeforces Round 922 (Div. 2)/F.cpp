# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
std::vector<int> e[N];
int dep[N],mxdep[N],dec[N],dec_n=0;
void dfs(int x) {
	int i,siz;
	mxdep[x]=dep[x];
	for(auto v:e[x]) {
		dep[v]=dep[x]+1;
		dfs(v);
		mxdep[x]=std::max(mxdep[x],mxdep[v]);
	}
	std::sort(e[x].begin(),e[x].end(),[](const int &i,const int &j){return mxdep[i]<mxdep[j];});
	for(i=0,siz=e[x].size();i<siz-1;i++) {
		if(dep[x]<mxdep[e[x][i]]-dep[x]) dec[++dec_n]=mxdep[e[x][i]]-dep[x]-dep[x];
	}
}
void _() {
	int n,i,k,x,ans;
	scanf("%d%d",&n,&k);
	for(i=2;i<=n;i++) {
		scanf("%d",&x);
		e[x].push_back(i);
	}
	dfs(1);
	ans=(n-1)*2-mxdep[1];
	std::sort(dec+1,dec+dec_n+1,[](const int &i,const int &j){return i>j;});
	for(i=1;i<=dec_n && i<=k;i++) ans-=dec[i];
	printf("%d\n",ans);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

