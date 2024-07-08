# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
	int n,i,zt=1,fst,lst,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		if(i==1) {
			fst=lst=x;
			putchar('1');
			continue;
		}
		if(zt==2 && x<lst || (zt==1 && x<lst || zt==2 && x>=lst) && x>fst) putchar('0');
		else {
			putchar('1');
			if(x<lst) zt++;
			lst=x;
		}
	}
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

