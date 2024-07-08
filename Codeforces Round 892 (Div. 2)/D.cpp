# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int l[N],r[N],a[N],b[N],x[N],num[N*5],num_n,f[N*5];
std::vector<int> ad[N*5],dl[N*5],qry[N*5];
std::multiset<int> mt;
void _() {
	int n,i,q;
	scanf("%d",&n);
	num_n=0;
	for(i=1;i<=n;i++) {
		scanf("%d%d%d%d",l+i,r+i,a+i,b+i);
		num[++num_n]=l[i]; num[++num_n]=r[i];
		num[++num_n]=a[i]; num[++num_n]=b[i];
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++) {
		scanf("%d",x+i);
		num[++num_n]=x[i]; 
	}
	std::sort(num+1,num+num_n+1);
	num_n=std::unique(num+1,num+num_n+1)-num-1;
	for(i=1;i<=num_n;i++) {
		ad[i].clear();
		dl[i].clear();
		qry[i].clear();
	}
	for(i=1;i<=n;i++) {
		l[i]=std::lower_bound(num+1,num+num_n+1,l[i])-num;
		r[i]=std::lower_bound(num+1,num+num_n+1,r[i])-num;
		a[i]=std::lower_bound(num+1,num+num_n+1,a[i])-num;
		b[i]=std::lower_bound(num+1,num+num_n+1,b[i])-num;
		ad[b[i]].push_back(b[i]);
		dl[l[i]].push_back(b[i]);
	}
	mt.clear();
	for(i=num_n;i>=1;i--) {
		f[i]=i;
		for(auto j:ad[i]) mt.insert(j);
		if(!mt.empty()) f[i]=f[*(--mt.end())];
		for(auto j:dl[i]) mt.erase(mt.find(j));
	}
	for(i=1;i<=q;i++) {
		x[i]=std::lower_bound(num+1,num+num_n+1,x[i])-num;
		printf("%d ",num[f[x[i]]]);
	}
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

