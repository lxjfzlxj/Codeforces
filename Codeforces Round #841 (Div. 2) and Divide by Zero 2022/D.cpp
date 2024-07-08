# include <bits/stdc++.h>
# define N 1000010
std::vector<int> a[N],sum[N];
int n,m;
bool check(int mid) {
	int i,j;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+(a[i][j]<mid);
		}
	}
	for(i=1;i+mid-1<=n;i++) {
		for(j=1;j+mid-1<=m;j++) {
			if(!(sum[i+mid-1][j+mid-1]-sum[i-1][j+mid-1]-sum[i+mid-1][j-1]+sum[i-1][j-1])) return true;
		}
	}
	return false;
}
void _() {
	int i,j,r,l,mid;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++) {
		a[i].resize(m+1);
		sum[i].resize(m+1);
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	l=1; r=(n<m?n:m);
	while(l<r) {
		mid=l+r+1>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

