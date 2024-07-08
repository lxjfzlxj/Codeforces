# include <bits/stdc++.h>
# define N 200010
struct pair{
	int x,y;
}a[N];
bool cmp(const pair &i,const pair &j) {return i.x>j.x;}
long long min(long long x,long long y) {return x<y?x:y;}
int max(int x,int y) {return x>y?x:y;}
void _() {
	int n,i,mx=0;
	long long sum=0,ans=9e18;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x<a[i].y) std::swap(a[i].x,a[i].y);
		sum+=a[i].y;
		mx=max(mx,a[i].y);
	}
	std::sort(a+1,a+n+1,cmp);
	for(i=1;i<=n && a[i].x>=mx;i++) {
		ans=min(ans,sum+a[i].x);
		sum+=a[i].x-a[i].y;
	}
	printf("%lld\n",ans*2);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

