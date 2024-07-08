# include <bits/stdc++.h>
# define N 100010
char s[N];
void _() {
	int n,i,cnt=0;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++) {
		if(s[i]!=s[i-1]) cnt++;
	}
	printf("%d\n",cnt-1>=0?cnt-1:0);
}

int main() {
	int T=1;
	scanf("%d",&T);
	s[0]='0';
	while(T--) _();
	return 0;
}

