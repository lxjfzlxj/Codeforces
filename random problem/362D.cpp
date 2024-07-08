# include <bits/stdc++.h>
# define N 100010
struct edge{
	int to,val;
};
struct pair{
	int x;
	long long val;
};
bool operator <(const pair &i,const pair &j) {return i.val<j.val || i.val==j.val && i.x<j.x;}
std::set<pair> st;
std::vector<edge> e[N];
bool vis[N];
long long sum;
int tx=0,ty=0;
void dfs(int fr,int x) {
	if(x!=fr) tx=x, ty=fr;
	vis[x]=true;
	for(auto ee:e[x]) {
		sum+=ee.val;
		if(!vis[ee.to]) dfs(fr,ee.to);
	}
}
int main() {
	int x,y,l,n,m,p,q,i;
	pair pr1,pr2;
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&l);
		e[x].push_back((edge){y,l});
		e[y].push_back((edge){x,l});
	}
	for(i=1;i<=n;i++) if(!vis[i]) {
		sum=0; dfs(i,i);
		st.insert((pair){i,sum/2});
	}
	if(q>st.size() || p<st.size()-q || st.size()==n && p && q==n) return puts("NO"), 0;
	puts("YES");
	while(st.size()>q) {
		p--;
		pr1=*st.begin(); st.erase(st.begin());
		pr2=*st.begin(); st.erase(st.begin());
		printf("%d %d\n",tx=pr1.x,ty=pr2.x);
		pr2.val+=pr1.val+std::min(pr1.val+pr2.val+1,1000000000ll);
		st.insert(pr2);
	}
	while(p--) printf("%d %d\n",tx,ty);
	return 0;
} 
