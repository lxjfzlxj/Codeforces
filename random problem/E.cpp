# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
std::vector<int> e[N];
int top[N],son[N],siz[N],dep[N],fat[N],dfl[N],dfr[N],dfn=0,dfa[N],intvn,anc[N][20];
std::pair<int,int> dm[N<<2],ansdm,intv[N<<1],zero=std::make_pair(0,0);
void dfs1(int x,int fa) {
	dep[x]=dep[fa]+1;
	dfl[x]=++dfn; dfa[dfn]=x;
	siz[x]=1; fat[x]=fa;
	for(auto v:e[x]) if(v!=fa) {
		dfs1(v,x);
		siz[v]+=siz[x];
		if(!son[x] || siz[v]>siz[son[x]]) son[x]=v;
	}
	dfr[x]=dfn;
}
void dfs2(int x,int t) {
	top[x]=t;
	if(son[x]) dfs2(son[x],t);
	for(auto v:e[x]) if(v!=fat[x] && v!=son[x]) {
		dfs2(v,v);
	}
}
int lca(int x,int y) {
	while(top[x]!=top[y]) {
		if(dep[top[x]]>dep[top[y]]) x=fat[top[x]];
		else y=fat[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
int calcdis(int x,int y) {
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
std::pair<int,int> merge(std::pair<int,int> pr1,std::pair<int,int> pr2) {
	if(pr1==zero) return pr2;
	int a[4]={pr1.first,pr1.second,pr2.first,pr2.second},i,j,mx=0,val;
	std::pair<int,int> ans;
	for(i=0;i<4;i++) {
		for(j=i+1;j<4;j++) {
			val=calcdis(a[i],a[j]);
			if(val>mx) mx=val, ans=std::make_pair(a[i],a[j]);
		}
	}
	return ans;
}
void build(int x,int l,int r) {
	if(l==r) {
		dm[x]=std::make_pair(dfa[l],dfa[l]);
		return;
	}
	int mid=l+r>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	dm[x]=merge(dm[x<<1],dm[x<<1|1]);
}
void query(int x,int xl,int xr,int ql,int qr) {
	if(ql<=xl && xr<=qr) {
		ansdm=merge(ansdm,dm[x]);
		return;
	}
	int mid=xl+xr>>1;
	if(ql<=mid) query(x<<1,xl,mid,ql,qr);
	if(qr>mid) query(x<<1|1,mid+1,xr,ql,qr);
}
int calcnb(int x,int y) {
	int c=dep[x]-dep[y]-1,i;
	for(i=0;(1<<i)<=c;i++) {
		if((c>>i)&1) x=anc[x][i];
	}
	return x;
}
void _() {
	int n,q,i,j,x,y,s,k,cnt=0,r,nb;
	scanf("%d%d",&n,&q);
	for(i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs1(1,1); dfs2(1,1);
	build(1,1,n);
	for(i=1;i<=n;i++) anc[i][0]=fat[i];
	for(j=1;(1<<j)<=n;j++) {
		for(i=1;i<=n;i++) anc[i][j]=anc[anc[i][j-1]][j-1];
	}
	while(q--) {
		scanf("%d%d",&s,&k);
		cnt++; intvn=0;
		for(i=1;i<=k;i++) {
			scanf("%d",&x);
			if(dfl[s]>=dfl[x] && dfl[s]<=dfr[x]) {
				nb=calcnb(s,x);
				intv[++intvn]=std::make_pair(1,dfl[nb]-1);
				intv[++intvn]=std::make_pair(dfr[nb]+1,n);
			} else {
				intv[++intvn]=std::make_pair(dfl[x],dfr[x]);
			}
		}
		std::sort(intv+1,intv+intvn+1);
		intv[++intvn]=std::make_pair(n+1,n+1);
		ansdm=std::make_pair(0,0);
		r=0;
		for(i=1;i<=intvn;i++) {
			if(intv[i].first>r+1) query(1,1,n,r+1,intv[i].first-1);
			r=std::max(r,intv[i].second); 
		}
		printf("%d\n",std::max(calcdis(s,ansdm.first),calcdis(s,ansdm.second)));
	}
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

