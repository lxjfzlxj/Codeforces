# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 500010
int n,m,id[N],a[N],pos[N],sum[N];
int get(int num,int ban) {
	if(num<0) num=0;
	if(pos[ban]<=num) return sum[num]-a[ban]+a[id[num+1]];
	else return sum[num];
}
bool check(int mid) {
	return mid>1 && get(n-mid+1,n-mid+1)<=m || a[n-mid+1]+get(n-mid-1,n-mid+1)<=m;
}
void _() {
	int i,l,r,mid;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		id[i]=i;
	}
	std::sort(id+1,id+n+1,[](int i,int j)->bool{return a[i]<a[j];});
	for(i=1;i<=n;i++) {
		pos[id[i]]=i;
		sum[i]=sum[i-1]+a[id[i]];
	}
	l=1; r=n+1;
	while(l<r) {
		mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

