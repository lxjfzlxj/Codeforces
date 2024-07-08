# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 3010
char s[N];
int n,cnt[2][N],l0[N][N],l1[N][N],r0[N][N],r1[N][N],mx[N],ans[N];
int binaryr1(int pos,int k) {
	int l=0,r=n,mid;
	while(l<r) {
		mid=l+r+1>>1;
		if(r1[mid][pos]<=k) l=mid;
		else r=mid-1;
	}
	return l;
}
int binaryr0(int pos,int k) {
	int l=0,r=n,mid;
	while(l<r) {
		mid=l+r+1>>1;
		if(r0[mid][pos]<=k) l=mid;
		else r=mid-1;
	}
	return l;
}
void _() {
	int k,i,j;
	scanf("%d%d%s",&n,&k,s+1);
	for(i=1;i<=n;i++) {
		cnt[0][i]=cnt[0][i-1];
		cnt[1][i]=cnt[1][i-1];
		cnt[s[i]-'0'][i]++;
	}
	for(int len=1;len<=n+2;len++) for(i=0;i<=n+2;i++) {
		l0[len][i]=r0[len][i]=l1[len][i]=r1[len][i]=2e9;
	}
	for(i=1;i<=n;i++) {
		for(j=i;j<=n;j++) {
			l0[j-i+1][j]=std::min(l0[j-i+1][j],cnt[1][j]-cnt[1][i-1]);
//			printf("l0 %d %d:%d %d %d %d\n",j-i+1,j,l0[j-i+1][j],j,i-1,cnt[1][j]-cnt[1][i-1]);
			r0[j-i+1][i]=std::min(r0[j-i+1][i],cnt[1][j]-cnt[1][i-1]);
			l1[j-i+1][j]=std::min(l1[j-i+1][j],cnt[0][j]-cnt[0][i-1]);
			r1[j-i+1][i]=std::min(r1[j-i+1][i],cnt[0][j]-cnt[0][i-1]);
		}
	}
//	for(int len=1;len<=n;len++) for(i=1;i<=n;i++) printf("l0 %d %d = %d\n",len,i,l0[len][i]);
	for(int len=1;len<=n;len++) for(i=1;i<=n;i++) l0[len][i]=std::min(l0[len][i],l0[len][i-1]);
	for(int len=1;len<=n;len++) for(i=1;i<=n;i++) l1[len][i]=std::min(l1[len][i],l1[len][i-1]);
	for(int len=1;len<=n;len++) for(i=n;i>=1;i--) r0[len][i]=std::min(r0[len][i],r0[len][i+1]);
	for(int len=1;len<=n;len++) for(i=n;i>=1;i--) r1[len][i]=std::min(r1[len][i],r1[len][i+1]);
//	for(int len=1;len<=n;len++) for(i=1;i<=n;i++) printf("l0 %d %d = %d\n",len,i,l0[len][i]);
	memset(mx,128,n+5<<2);
	memset(ans,0,sizeof(ans));
	for(i=1;i<n;i++) {
//		printf("i:%d\n",i);
		for(int len=0;len<=i;len++) {
			if(l0[len][i]<=k) {
				int bb=binaryr1(i+1,k-l0[len][i]);
				mx[len]=std::max(mx[len],bb);
//				printf("1 update %d %d\n",len,bb);
			}
			if(l1[len][i]<=k) {
				int bb=binaryr0(i+1,k-l1[len][i]);
				mx[bb]=std::max(mx[bb],len);
//				printf("2 update %d %d\n",bb,len);
			}
		}
	}
	for(i=0;i<=n;i++) if(mx[i]>=0) {
		for(j=1;j<=n;j++) ans[j]=std::max(ans[j],i*j+mx[i]);
	}
	if(cnt[0][n]<=k) {
		for(j=1;j<=n;j++) ans[j]=std::max(ans[j],n);
	}
	if(cnt[1][n]<=k) {
		for(j=1;j<=n;j++) ans[j]=std::max(ans[j],n*j);
	}
	for(i=1;i<=n;i++) printf("%d ",ans[i]);
	puts("");
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

