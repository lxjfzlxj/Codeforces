# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 2010
int a[N],now,mxn,mnn;
int __(char c) {
	if(c=='>') return 1;
	else if(c=='<') return -1;
	else return 0;
}
void fix(int val) {
	if(val>now) {
		int c=val-now;
		while(c--) {
			printf("? %d\n",mxn); fflush(stdout);
			scanf("%*s"); 
		}
	} else {
		int c=now-val;
		while(c--) {
			printf("? %d\n",mnn); fflush(stdout);
			scanf("%*s");
		}
	}
	now=val;
}
void solve(int l,int r,std::vector<int> vec) {
	if(l>r) return;
	if(l==r) {
		a[vec[0]]=l;
		assert(vec.size()==1);
		return;
	}
	int mid=l+r>>1;
	char ch[5];
	std::vector<int> v1,v2;
	v1.clear(); v2.clear();
	for(auto x:vec) {
//		printf("now:%d go to %d\n",now,mid);
		fix(mid);
		printf("? %d\n",x); fflush(stdout);
		scanf("%s",ch);
		if(ch[0]=='>') now++, v2.push_back(x);
		else if(ch[0]=='<') now--, v1.push_back(x);
		else a[x]=now;
	}
	solve(l,mid-1,v1);
	solve(mid+1,r,v2);
}
void _() {
	int i,n,mx=-1,mn=2e9;
	now=0; mxn=0; mnn=0;
	char ch[10];
	scanf("%d",&n);
	memset(a,0,n<<2);
	for(i=1;i<=n;i++) {
		printf("? %d\n",i); fflush(stdout);
		scanf("%s",ch);
		now+=__(ch[0]);
		if(now>mx) mx=now, mxn=i;
		if(ch[0]!='<') {
			while(ch[0]!='=') {
				printf("? %d\n",i); fflush(stdout);
				scanf("%s",ch);
				now+=__(ch[0]);
			}
			if(now>mx) mx=now, mxn=i;
		}
	}
	now=n;
	for(i=1;i<=n;i++) {
		printf("? %d\n",i); fflush(stdout);
		scanf("%s",ch);
		now+=__(ch[0]);
		if(now<mn) mn=now, mnn=i;
		if(ch[0]!='>') {
			while(ch[0]!='=') {
				printf("? %d\n",i); fflush(stdout);
				scanf("%s",ch);
				now+=__(ch[0]);
			}
			if(now<mn) mn=now, mnn=i;
		}
	}
	std::vector<int> vec;
	vec.clear();
	for(i=1;i<=n;i++) {
		if(i!=mxn && i!=mnn) vec.push_back(i);
	}
	a[mnn]=1; a[mxn]=n;
	do {
		printf("? %d\n",mnn); fflush(stdout);
		scanf("%s",ch);
	} while(ch[0]!='=');
	now=1;
//	printf("[]%d %d\n",mxn,mnn);
	solve(2,n-1,vec);

	printf("! ");
	for(i=1;i<=n;i++) printf("%d ",a[i]), assert(a[i]);
	puts("");
	fflush(stdout);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

