# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 1000010
long long a[N],num[N];
int num_n,buc[N];
void work1(int x,int l,int r) {
	
}
void _() {
	int n,k,i,cnt1=0,cnt2=0;
	long long m;
	scanf("%d%lld%d",&n,&m,&k);
	for(i=1;i<=n;i++) {
		scanf("%lld",a+i);
		num[i]=a[i];
	}
	std::sort(num+1,num+n+1);
	num_n=std::unique(num+1,num+n+1)-num-1;
	memset(buc,0,sizeof(buc));
	for(i=1;i<=n;i++) buc[std::lower_bound(num+1,num+num_n+1,a[i])-num]++;
//	for(i=1;i<=num_n;i++) printf("%d ",buc[i]);
//	puts("");
	for(j=1;j<=num_n && cnt2<=k-1;j++) cnt2+=buc[j];
	if(num[1]>0) {
		work1(0,0,j);
		work2(0,num[1],0,j);
	}
	for(i=1;i<=num_n;i++) {
		
	}
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

