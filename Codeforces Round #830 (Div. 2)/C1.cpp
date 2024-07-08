# include <bits/stdc++.h>
# define N 100010
int a[N],sx[N],L,R;
long long sum[N];
void upd(int l,int r) {
	if(!L || r-l<R-L) L=l, R=r;
}
void _() {
	int n,q,i,j;
	long long tar,now;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		sum[i]=sum[i-1]+a[i];
		sx[i]=sx[i-1]^a[i];
	}
	tar=sum[n]-sx[n];
	L=R=0;
	for(i=1,j=0,now=0;i<=n;i++) {
		now=sum[j]-sum[i-1]-(sx[j]^sx[i-1]);
		while(i>j || j<n && now<tar) {
			j++;
			now=sum[j]-sum[i-1]-(sx[j]^sx[i-1]);
		}
		if(now==tar) upd(i,j);
	}
	while(q--) scanf("%*d%*d");
	printf("%d %d\n",L,R);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

