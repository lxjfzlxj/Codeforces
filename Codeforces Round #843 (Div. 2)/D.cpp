#include <bits/stdc++.h>
#define report(args...) return printf(args), void()
#define N 300010
int a[N],mn[N],pr[N],pr_n=0,s,t,dis[N],pf[N],pg[N],ans[N],ans_n=0;
bool p[N],vis[N];
std::vector<int> ff[N],gg[N];
std::queue<int> qu;
void bk(int id,int x) {
	while(x>1) {
		int fac=mn[x];
		ff[fac].push_back(id);
		gg[id].push_back(fac);
		while(x%fac==0) x/=fac;
	}
}
void bfs(int sid) {
	int i,head;
	if(s==t) {
		printf("1\n%d",s);
		return;
	}
	for(auto x:gg[sid]) {
		dis[x]=1;
		vis[x]=true;
		pg[x]=sid;
		pf[x]=0;
		qu.push(x);
	}
	while(!qu.empty()) {
		head=qu.front(); qu.pop();
		for(auto x:ff[head]) {
			if(x==t) {
				printf("%d\n",dis[head]+1);
				for(int tp=head;tp;tp=pf[tp]) ans[++ans_n]=pg[tp];
				for(i=ans_n;i>=1;i--) printf("%d ",ans[i]);
				printf("%d ",t);
				return;
			}
			for(auto y:gg[x]) {
				if(!vis[y]) {
					dis[y]=dis[head]+1;
					vis[y]=true;
					pg[y]=x;
					pf[y]=head;
					qu.push(y);
				}
			}
		}
	}
	puts("-1");
}
void _() {
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=2;i<=300000;i++) {
		if(!p[i]) pr[++pr_n]=i, mn[i]=i;
		for(j=1;j<=pr_n && i*pr[j]<=300000;j++) {
			p[i*pr[j]]=true;
			mn[i*pr[j]]=pr[j];
			if(!(i%pr[j])) break;
		}
	}
	for(i=1;i<=n;i++) {
		bk(i,a[i]);
	}
	scanf("%d%d",&s,&t);
	bfs(s);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

