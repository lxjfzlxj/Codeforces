# include <bits/stdc++.h>
# define N 500010
int buc[N];
void _() {
	int n,k,i,x;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		buc[x]++;
	}
	for(i=1;i<k;i++) if(buc[i]) {
		if(buc[i]%(i+1)) return puts("No"), void();
		buc[i+1]+=buc[i]/(i+1);
	}
	puts("Yes");
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

