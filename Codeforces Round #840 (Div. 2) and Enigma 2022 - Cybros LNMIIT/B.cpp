# include <bits/stdc++.h>
# define N 100010
# define report(args...) return printf(args), void()
int mn[N];
struct pair{
	int h,p;
}a[N];
int min(int x,int y) {return x<y?x:y;}
void _() {
	int n,k,i,pos,dmg=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i].h);
	for(i=1;i<=n;i++) scanf("%d",&a[i].p);
	std::sort(a+1,a+n+1,[](const pair &i,const pair &j)->bool{return i.h<j.h;});
	mn[n+1]=2e9;
	for(i=n;i>=1;i--) mn[i]=min(mn[i+1],a[i].p);
	pos=1;
	while(1) {
		dmg+=k;
		while(pos<=n && a[pos].h<=dmg) pos++;
		if(pos>n) report("YES\n");
		k-=mn[pos];
		if(k<=0) report("NO\n");
	}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

