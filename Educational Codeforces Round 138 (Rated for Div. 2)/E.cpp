# include <bits/stdc++.h>
# define N 200010
# define NM 400010
std::vector<char> s[N];
std::vector<int> dis[N];
std::vector<bool> vis[N];
std::deque<std::pair<int,int>> dq,pre[N];
int n,m,dx[4]={-1,0,0,1},dy[4]={0,-1,1,0};
bool check(int x,int y) {
	int i,xx,yy;
	if(s[x][y]=='#') return true;
	for(i=0;i<4;i++) {
		xx=x+dx[i]; yy=y+dy[i];
		if(xx>=1 && xx<=n && yy>=1 && yy<=m && s[xx][yy]=='#') return false;
	}
	return true;
}
void push(int u,int v,int uu,int vv) {
	if(s[uu][vv]=='#') {
		if(dis[u][v]<dis[uu][vv]) {
			dis[uu][vv]=dis[u][v];
			pre[uu][vv]=std::make_pair(u,v);
			dq.push_front((std::make_pair(uu,vv)));
		}
	} else {
		if(dis[u][v]+1<dis[uu][vv]) {
			dis[uu][vv]=dis[u][v]+1;
			pre[uu][vv]=std::make_pair(u,v);
			dq.push_back((std::make_pair(uu,vv)));
		}
	}
}
void bfs() {
	int i,u,v,j,ii,jj;
	std::pair<int,int> head;
	dq.clear();
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) dis[i][j]=2e9, vis[i][j]=false;
	}
	for(i=1;i<=n;i++) if(check(i,1)) {
		if(s[i][1]=='#') {
			dis[i][1]=0;
			pre[i][1]=std::make_pair(0,0);
			dq.push_front(std::make_pair(i,1));
		} else {
			dis[i][1]=1;
			pre[i][1]=std::make_pair(0,0);
			dq.push_back(std::make_pair(i,1));
		}
	}
	while(!dq.empty()) {
		head=dq.front(); dq.pop_front();
		u=head.first; v=head.second;
		if(vis[u][v]) continue;
		vis[u][v]=true;
		if(v==m) {
			puts("YES");
			for(i=u,j=v;i && j;i=ii,j=jj) {
				s[i][j]='#';
				ii=pre[i][j].first;
				jj=pre[i][j].second;
			}
			for(i=1;i<=n;i++) printf("%s\n",++s[i].begin());
			return;
		}
		if(u>1 && check(u-1,v+1)) push(u,v,u-1,v+1);
		if(u<n && check(u+1,v+1)) push(u,v,u+1,v+1);
		if(u>1 && v>1 && check(u-1,v-1)) push(u,v,u-1,v-1);
		if(u<n && v>1 && check(u+1,v-1)) push(u,v,u+1,v-1);
	}
	puts("NO");
}
void _() {
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n+3;i++) {
		s[i].resize(m+3);
		dis[i].resize(m+3);
		vis[i].resize(m+3);
		pre[i].resize(m+3);
	}
	for(i=1;i<=n;i++) scanf("%s",++s[i].begin());
	bfs();
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

