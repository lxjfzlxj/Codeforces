# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
typedef std::set<int>::iterator iter; 
int a[N];
std::multiset<int> st1,st2;
void erase(int x) {
	iter it=st1.find(x),jt=it,kt=it; kt++;
	if(it!=st1.begin()) st2.erase(st2.find(*it-*(--jt)));
	if(kt!=st1.end()) st2.erase(st2.find(*kt-*it));
	if(it!=st1.begin() && kt!=st1.end()) st2.insert(*kt-*jt);
	st1.erase(st1.find(x));
}
void insert(int x) {
	st1.insert(x);
	iter it=st1.find(x),jt=it,kt=it; kt++;
	if(it!=st1.begin()) st2.insert(*it-*(--jt));
	if(kt!=st1.end()) st2.insert(*kt-*it);
	if(it!=st1.begin() && kt!=st1.end()) st2.erase(st2.find(*kt-*jt));
}
void _() {
	int n,q,i,x,y;
	iter it,jt;
	scanf("%d",&n);
	st1.clear(); st2.clear(); st2.insert(0);
	for(i=1;i<=n;i++) scanf("%d",a+i), st1.insert(a[i]);
	for(it=st1.begin();it!=st1.end();it++) {
		jt=it; jt++;
		if(jt!=st1.end()) st2.insert(*jt-*it);
	}
	scanf("%d",&q);
	while(q--) {
		scanf("%d%d",&x,&y);
		erase(a[x]);
		a[x]=y;
		insert(a[x]);
		printf("%d ",*(--st1.end())+*(--st2.end()));
	}
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

