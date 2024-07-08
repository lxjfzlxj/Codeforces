# include <bits/stdc++.h>
# define N 200010
char s[N];
void _() {
	int n,i,l,r;
	scanf("%d%s",&n,s+1);
	if(s[1]=='0') l=r=1;
	else l=r=2;
	printf("1 ");
	for(i=2;i<n;i++) {
		if(s[i]=='0') l=1;
		else l++, r=i+1;
		printf("%d ",r-l+1);
	}
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

