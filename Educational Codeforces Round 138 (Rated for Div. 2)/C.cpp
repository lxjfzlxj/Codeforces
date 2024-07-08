# include <bits/stdc++.h>
# define N 110
int n,a[N];
bool check(int k) {
	int i,j;
	for(i=1,j=n;i<=k;i++) {
		while(j>=1 && a[j]>k-i+1) j--;
		if(j<=i-1) return false;
		j--;
	}
	return true;
}
void _() {
	int i,l,r,mid;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	l=0; r=n;
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

