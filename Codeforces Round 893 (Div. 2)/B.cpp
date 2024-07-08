# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define M 100010
int a[M],b[M];
void _() {
	int n,m,d,i,sum,ans=2e9,cnt=0;
	scanf("%d%d%d",&n,&m,&d); sum=m;
	for(i=1;i<=m;i++) scanf("%d",a+i);
	a[0]=1-d; a[++m]=n+1;
	for(i=1;i<=m;i++) {
		b[i]=(a[i]-a[i-1]-1)/d;
		sum+=b[i];
//		printf("%d:%d\n",i,b[i]);
	}
	ans=sum;
	for(i=1;i<m;i++) {
		int val=sum-b[i]-b[i+1]+(a[i+1]-a[i-1]-1)/d-1;
		if(val<ans) ans=val, cnt=1;
		else if(val==ans) cnt++;
	} 
	printf("%d %d\n",ans,cnt);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

