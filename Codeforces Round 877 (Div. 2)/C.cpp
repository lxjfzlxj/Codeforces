# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
int n,m;
void prt(int id) {
	int i;
	for(i=(id-1)*m+1;i<=id*m;i++) printf("%d ",i);
	puts("");
}
bool isp(int x) {
	int i;
	for(i=2;i*i<=x;i++) {
		if(x%i==0) return false;
	}
	return true;
}
void _() {
	int i;
	scanf("%d%d",&n,&m);
	if(isp(m)) {
		for(i=2;i<=n;i+=2) prt(i);
		for(i=1;i<=n;i+=2) prt(i);
	} else {
		for(i=1;i<=n;i++) prt(i);
	}
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

