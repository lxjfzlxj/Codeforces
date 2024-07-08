# include <bits/stdc++.h>
# define N 100010
int a[N],sx[N],pre[N],nex[N],L,R;
long long sum[N];
int min(int x,int y) {return x<y?x:y;}
void upd(int l,int r) {
	if(r-l<R-L) L=l, R=r;
}
void _() {
	int n,q,i,las,l,r,j;
	long long tar;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) {
		scanf("%d",a+i);
		sum[i]=sum[i-1]+a[i];
		sx[i]=sx[i-1]^a[i];
	}
	for(i=1,las=0;i<=n;i++) {
		pre[i]=las;
		if(a[i]) las=i;
	}
	for(i=n,las=n+1;i>=1;i--) {
		nex[i]=las;
		if(a[i]) las=i;
	}
	while(q--) {
		scanf("%d%d",&l,&r);
		tar=sum[r]-sum[l-1]-(sx[r]^sx[l-1]);
		if(!tar) {
			printf("%d %d\n",l,l);
			continue;
		}
		for(j=r;pre[j]>=l && sum[pre[j]]-sum[l-1]-(sx[pre[j]]^sx[l-1])==tar;j=pre[j]);
		L=l; R=j;
		for(i=nex[l];i<=r;i++) {
			while(nex[j]<=r && sum[j]-sum[i-1]-(sx[j]^sx[i-1])<tar) j=nex[j];
			if(sum[j]-sum[i-1]-(sx[j]^sx[i-1])<tar) break;
			upd(i,j);
		}
		printf("%d %d\n",L,R);
	}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

