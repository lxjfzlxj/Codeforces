# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 100010
# define K 30
std::vector<int> e1[N],e2[N],vt;
int a[K],b[K],key[K<<1],kn,dfn[N],dfnn,siz[N],dep[N],son[N],ltop[N],fat[N],sta[N],top,fa[N],zt[N],f[1<<20|10];
void dfs1(int x,int fa) {
	dfn[x]=++dfnn; dep[x]=dep[fa]+1;
	siz[x]=1; son[x]=0; fat[x]=fa;
	for(auto v:e1[x]) if(v!=fa) {
		dfs1(v,x);
		siz[x]+=siz[v];
		if(!son[x] || siz[v]>siz[son[x]]) son[x]=v;
	}
}
void dfs2(int x,int t) {
	ltop[x]=t;
	if(son[x]) dfs2(son[x],t);
	for(auto v:e1[x]) if(v!=fat[x] && v!=son[x]) {
		dfs2(v,v);
	}
}
int lca(int x,int y) {
	while(ltop[x]!=ltop[y]) {
		if(dep[ltop[x]]>dep[ltop[y]]) x=fat[ltop[x]];
		else y=fat[ltop[y]];
	}
	return dep[x]<dep[y]?x:y;
}
void build() {
	int i,l;
	std::sort(key+1,key+kn+1,[&](const int &i,const int &j){return dfn[i]<dfn[j];});
	kn=std::unique(key+1,key+kn+1)-key-1;
	sta[top=1]=1;
	for(i=1;i<=kn;i++) if(key[i]!=key[i-1] && key[i]!=1) {
		l=lca(sta[top],key[i]);
//		printf("%d %d lca:%d\n",sta[top],key[i],l);
		if(l!=sta[top]) {
			while(top>1 && dfn[sta[top-1]]>=dfn[l]) {
				e2[sta[top-1]].push_back(sta[top]);
				top--;
			}
			if(l!=sta[top]) {
				e2[l].push_back(sta[top]);
				sta[top]=l;
			}
		}
		sta[++top]=key[i];
	}
	for(i=1;i<top;i++) e2[sta[i]].push_back(sta[i+1]);
}
void cmin(int &x,int y) {y<x?x=y:0;}
void _() {
	int n,k,i,x,y,l,tot;
	scanf("%d",&n);
	for(i=1;i<=n;i++) e1[i].clear();
	for(i=1;i<=n;i++) e2[i].clear();
	for(i=1;i<n;i++) {
		scanf("%d%d",&x,&y);
		e1[x].push_back(y);
		e1[y].push_back(x);
	}
	dfnn=0; dep[1]=0;
	dfs1(1,1); dfs2(1,1);
	kn=0;
	scanf("%d",&k); tot=1<<k;
	for(i=1;i<=k;i++) {
		scanf("%d%d",a+i,b+i);
		key[++kn]=a[i];
		key[++kn]=b[i];
	}
	build();
	for(i=1;i<=n;i++) fa[i]=0;
	for(i=1;i<=n;i++) {
		for(auto j:e2[i]) fa[j]=i;
	}
	for(i=1;i<=n;i++) zt[i]=0;
	for(i=1;i<=k;i++) {
		l=lca(a[i],b[i]);
		for(x=a[i];x!=l;x=fa[x]) zt[x]|=1<<i-1;
		for(y=b[i];y!=l;y=fa[y]) zt[y]|=1<<i-1;
	}
	vt.clear();
	for(i=1;i<=n;i++) {
		if(fa[i]) vt.push_back(i);
	}
	for(i=1;i<tot;i++) f[i]=2e9;
	for(i=0;i<tot;i++) {
		for(auto v:vt) {
			if((i|zt[v])>i) cmin(f[i|zt[v]],f[i]+1);
		}
	}
	printf("%d\n",f[tot-1]);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

