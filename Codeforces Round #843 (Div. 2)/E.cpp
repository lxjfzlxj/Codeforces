#include <bits/stdc++.h>
#define report(args...) return printf(args), void()
# define N 200010
int a[N],pre[N],nex[N];
long long v[N];
struct pair{
	int id;
	long long num;
};
std::set<pair> st;
long long abss(long long x) {
	return x>=0?x:-x;
}
bool operator <(const pair &i,const pair &j) {
	return i.num<j.num || i.num==j.num && i.id<j.id;
}
void del(int x) {
	pre[nex[x]]=pre[x];
	nex[pre[x]]=nex[x];
}
void _() {
	int n,i,x,y,m=0;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	x=6;
	for(i=1;i<=n;i++) if(a[i]) {
		if(a[i]>0) y=1;
		else if(a[i]<0) y=-1;
		if(x!=y) v[++m]=a[i];
		else v[m]+=a[i];
		x=y;
	}
//	for(i=1;i<=m;i++) printf("%d ",v[i]);
//	puts("");
	for(i=1;i<=m;i++) pre[i]=i-1, nex[i]=i+1;
	pre[0]=nex[m+1]=-1;
	nex[0]=1; pre[m+1]=m;
	st.clear();
	for(i=1;i<=m;i++) v[i]=abss(v[i]), st.insert((pair){i,v[i]});
	while(!st.empty()) {
		auto it=st.begin(); pair pr=*it; st.erase(it);
		ans=pr.num; del(pr.id);
		if(pre[pr.id] && nex[pr.id]!=m+1) {
			int ls=pre[pr.id],nx=nex[pr.id];
			st.erase((pair){ls,v[ls]});
			st.erase((pair){nx,v[nx]});
			st.insert((pair){ls,v[ls]+=v[nx]-ans});
			del(nx);
		}
	}
	printf("%lld\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

