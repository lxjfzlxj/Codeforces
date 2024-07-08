# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N],b[N];
void _() {
	int n,i,l,r,mid;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",a+i);
	if(a[1]>n) report("NO\n");
	a[0]=2e9;
	for(i=1;i<=n;i++) {
		l=0; r=n;
		while(l<r) {
			mid=l+r+1>>1;
			if(a[mid]>=i) l=mid;
			else r=mid-1;
		}
		b[i]=l;
	}
	for(i=1;i<=n && a[i]==b[i];i++);
	puts(i<=n?"NO":"YES");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

