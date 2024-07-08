# include <bits/stdc++.h>
# define N 100010
char s[N];
int buc[10];
int max(int x,int y) {return x>y?x:y;}
void _() {
	int n,i,j,mx,cnt,ans=0;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++) {
		for(j=0;j<10;j++) buc[j]=0;
		mx=cnt=0;
		for(j=i;j<=n && mx<=10;j++) {
			buc[s[j]-'0']++;
			if(buc[s[j]-'0']==1) cnt++;
			mx=max(mx,buc[s[j]-'0']);
			if(mx<=cnt) ans++;
		}
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

