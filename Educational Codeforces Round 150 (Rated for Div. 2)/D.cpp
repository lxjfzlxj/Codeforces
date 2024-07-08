# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 2010
int l[N],r[N],num[N<<1],num_n;
std::vector<int> st[N<<1],ed[N<<1];
std::multiset<int> mt;
int work(int s) {
	int i,ans=2e9;
	std::multiset<int>::iterator it;
	mt.clear();
	for(i=s;i<=num_n;i++) {
		for(auto x:st[i]) mt.insert(r[x]);
		if(mt.size()>=2) ans=std::min(ans,*(++mt.begin()));
		for(auto x:ed[i]) {
			if((it=mt.find(r[x]))!=mt.end()) mt.erase(it);
		}
	}
	return ans;
}
void _() {
	int n,i,ans=0,t;
	scanf("%d",&n);
	num_n=0;
	for(i=1;i<=n;i++) {
		scanf("%d%d",l+i,r+i);
		num[++num_n]=l[i];
		num[++num_n]=r[i];
	}
	std::sort(num+1,num+num_n+1);
	num_n=std::unique(num+1,num+num_n+1)-num-1;
	for(i=1;i<=num_n;i++) {
		st[i].clear();
		ed[i].clear();
	}
	for(i=1;i<=n;i++) {
		l[i]=std::lower_bound(num+1,num+num_n+1,l[i])-num;
		r[i]=std::lower_bound(num+1,num+num_n+1,r[i])-num;
		st[l[i]].push_back(i);
		ed[r[i]].push_back(i);
	}
	for(i=1;i<=num_n;i=t+1) {
		if((t=work(i))>1e9) break;
		else ans+=2;
	}
	printf("%d\n",n-ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

