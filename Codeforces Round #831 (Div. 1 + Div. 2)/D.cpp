# include <bits/stdc++.h>
# define N 100010
int buc[N];
void _() {
	int n,m,k,i,x,dep=0,rem=0;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=k;i++) {
		scanf("%d",&x);
		buc[x]=i;
	}
	for(i=k;i>=1;i--) {
		if(buc[i]>dep) {
			rem+=buc[i]-dep-1;
			dep=buc[i];
			if(rem+3>=n*m) return puts("TIDAK"), void();
		} else {
			rem--;
		}
	}
	puts("YA");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

