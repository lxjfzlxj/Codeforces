# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
char s[N],rmx[N];
int val[256],sum[N],sta[N],top,sums[N],rsum[N];
int max(int x,int y) {return x>y?x:y;}
int bin(char c) {
	int l=0,mid,r=top;
	while(l<r) {
		mid=l+r+1>>1;
		if(s[sta[mid]]<c) r=mid-1;
		else l=mid;
	}
	return r;
}
void _() {
	int n,i,pos,ans=-2e9;
	char c;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+val[s[i]];
	rmx[n+1]=0; rsum[n+1]=0;
	for(i=n;i>=1;i--) {
		if(s[i]>=rmx[i+1]) {
			rmx[i]=s[i];
			rsum[i]=rsum[i+1]+val[s[i]];
		} else {
			rmx[i]=rmx[i+1];
			rsum[i]=rsum[i+1]-val[s[i]];
		}
	}
	for(i=1,top=0;i<=n;i++) {
		for(c='A';c<='E';c++) {
			pos=bin((char)std::max(c,rmx[i+1]));
			ans=max(ans,2*sums[pos]-sum[i-1]+rsum[i+1]+(c>=rmx[i+1]?val[c]:-val[c]));
		}
		while(top && s[sta[top]]<s[i]) top--;
		sta[++top]=i;
		sums[top]=sums[top-1]+val[s[i]];
	}
	printf("%d\n",ans);
}

int main() {
	int T=1;
	scanf("%d",&T);
	val['A']=1; val['B']=10; val['C']=100; val['D']=1000; val['E']=10000;
	while(T--) _();
	return 0;
}

