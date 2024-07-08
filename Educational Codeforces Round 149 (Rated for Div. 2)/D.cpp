# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
char s[N];
int col[N];
void _() {
	int n,i,j,las=0,now=0,sgn=0,cnt=1;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++) {
		if(s[i]=='(') now++;
		else now--;
		if(!now) {
			if(!sgn) sgn=(s[i]==')')?1:2;
			for(j=las+1;j<=i;j++) col[j]=(s[i]==')')?sgn:3-sgn;
			las=i;
		}
	}
	if(now) report("-1\n");
	for(i=1;i<=n;i++) {
		if(col[i]==2) cnt=2;
	}
	printf("%d\n",cnt);
	for(i=1;i<=n;i++) printf("%d ",col[i]);
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

