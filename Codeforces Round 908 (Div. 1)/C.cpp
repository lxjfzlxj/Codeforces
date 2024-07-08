# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define M 100010
int c[M];
long long a[M],cnt[M],imp[M],l[M],r[M],sc[M];
struct pair{
	int pos;
	long long siz;
};
std::vector<pair> vec[M];
std::map<long long,int> mp;
void _() {
	int m,i,j,tot=0,vcnt=0;
	long long sr=0,sl=0,ans=9e18,val,nd,ad;
	scanf("%d",&m);
	for(i=1;i<=m;i++) {
		scanf("%d%lld%lld",c+i,l+i,r+i);
		sr+=r[i]; sl+=l[i]; sc[i]=0;
		for(j=1;j<=c[i];j++) scanf("%lld",a+j);
		for(j=1;j<=c[i];j++) scanf("%lld",cnt+j), sc[i]+=cnt[j];
		for(j=1;j<=c[i];j++) {
			if(!mp[a[j]]) mp[a[j]]=++tot, imp[tot]=a[j];
			vec[mp[a[j]]].push_back((pair){i,cnt[j]});
		}
	}
	for(i=1;i<=tot;i++) if(imp[i]>=sl && imp[i]<=sr) {
		vcnt++; val=sr; ad=0;
		for(auto j:vec[i]) {
			val-=r[j.pos];
			nd=sc[j.pos]-j.siz;
			if(nd<l[j.pos]) val+=l[j.pos], ad+=l[j.pos]-nd;
			else if(nd>r[j.pos]) val+=r[j.pos];
			else val+=nd;
		}
		if(val>=imp[i]) ans=std::min(ans,ad);
		else ans=std::min(ans,imp[i]-val+ad);
	}
	if(vcnt<sr-sl+1) puts("0");
	else printf("%lld\n",ans);
	mp.clear();
	for(i=1;i<=tot;i++) vec[i].clear();
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

