# include <bits/stdc++.h>
# define N 200010
int n,a[N],b[N],tr[N],id[N],idn,id2[N],id2n,now;
std::map<int,int> mp;
bool cmp(const int &i,const int &j) {return b[i]<b[j] || b[i]==b[j] && i<j;}
void add(int x,int y) {
	int i;
	for(i=x;i<=n;i+=i&(-i)) tr[i]+=y; 
}
int query(int x) {
	int i,ans=0;
	for(i=x;i>=1;i-=i&(-i)) ans+=tr[i];
	return ans;
}
bool work(int l,int r) {
	int i,nd=1;
	while(now<id2n && b[id2[now+1]]<=b[id[l]]) now++, add(id2[now],1);
	for(i=l;i<r;i++) {
		if(query(id[i+1]-1)-query(id[i])!=id[i+1]-id[i]-1) nd++;
	}
	if(mp[b[id[l]]]<nd) return false;
	for(i=l;i<=r;i++) add(id[i],1);
	return true;
}
void _() {
	int i,j,m,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	for(i=1;i<=n;i++) scanf("%d",b+i);
	scanf("%d",&m);
	mp.clear();
	for(i=1;i<=m;i++) {
		scanf("%d",&x);
		mp[x]++;
	}
	memset(tr,0,n+5<<2);
	idn=id2n=0;
	for(i=1;i<=n;i++) {
		if(a[i]==b[i]) id2[++id2n]=i;
		else if(a[i]<b[i]) return puts("NO"), void();
		else id[++idn]=i;
	}
	std::sort(id+1,id+idn+1,cmp);
	std::sort(id2+1,id2+id2n+1,cmp);
	now=0;
	for(i=1;i<=idn;i=j) {
		for(j=i;j<=idn && b[id[j]]==b[id[i]];j++);
		if(!work(i,j-1)) return puts("NO"), void();
	}
	puts("YES");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

