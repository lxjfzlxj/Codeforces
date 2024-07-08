# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 1000010
int pos[N];
void _() {
	int i,st,ad=0,x,mx=0,cnt=0;
	scanf("%d",&st); pos[st]=1;
	for(i=1;i<=400;i++) {
		printf("+ %d\n",x=rand()); fflush(stdout);
		ad+=x;
		scanf("%d",&x);
		if(x>mx) mx=x;
	}
	printf("- %d\n",ad-1); fflush(stdout);
	scanf("%d",&x); if(!pos[x]) pos[x]=2;
	for(i=3;i<=300;i++) {
		puts("+ 1"); fflush(stdout);
		scanf("%d",&x); if(!pos[x]) pos[x]=i;
	}
	if(mx+1-300>0) printf("+ %d\n",mx+1-300);
	else printf("- %d\n",300-mx-1);
	fflush(stdout);
	while(1) {
		scanf("%d",&x);
		if(pos[x]) return printf("! %d\n",mx+1+300*cnt-pos[x]), fflush(stdout), void();
		cnt++;
		puts("+ 300"); fflush(stdout);
	}
}

int main() {
	int T=1;
	srand(time(0));
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

