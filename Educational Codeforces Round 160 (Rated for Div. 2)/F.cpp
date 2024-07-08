# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 300010
char s[N];
template<int MX>
struct Suffix_Array{
	int n,sa[MX],fir[MX],sec[MX],buc[MX],rk[MX],height[MX],rmq[MX][22],lg2[MX];
	char s[MX];
	void calc() {
		int i,k,j,mx=256,tot,las,t;
		n=strlen(s+1);
		for(i=1;i<=n;i++) buc[fir[i]=(int)s[i]]++;
		for(i=1;i<=mx;i++) buc[i]+=buc[i-1];
		for(i=n;i>=1;i--) sa[buc[fir[i]]--]=i;
		for(k=1;k<n;k<<=1) {
			tot=0;
			for(i=n-k+1;i<=n;i++) sec[++tot]=i;
			for(i=1;i<=n;i++) {
				if(sa[i]>k) sec[++tot]=sa[i]-k;
			}
			memset(buc,0,mx+5<<2);
			for(i=1;i<=n;i++) buc[fir[i]]++;
			for(i=1;i<=mx;i++) buc[i]+=buc[i-1];
			for(i=n;i>=1;i--) sa[buc[fir[sec[i]]]--]=sec[i];
			memcpy(sec,fir,n+5<<2);
			fir[sa[1]]=tot=1;
			for(i=2;i<=n;i++) {
				if(sec[sa[i]]==sec[sa[i-1]] && sec[sa[i]+k]==sec[sa[i-1]+k]) fir[sa[i]]=tot;
				else fir[sa[i]]=++tot;
			}
			mx=tot;
		}
		for(i=1;i<=n;i++) rk[sa[i]]=i;
		las=0;
		for(i=1;i<=n;i++) {
			if(rk[i]==1) continue;
			if(las) las--;
			while(s[i+las]==s[sa[rk[i]-1]+las]) las++;
			height[rk[i]]=las;
		}
		for(i=1;i<=n;i++) rmq[i][0]=height[i];
		for(i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
		for(j=1;j<=lg2[n];j++) {
			for(i=1,t=n-(1<<j)+1;i<=t;i++) {
				rmq[i][j]=std::min(rmq[i][j-1],rmq[i+(1<<j-1)][j-1]);
			}
		}
	}
	int query(int l,int r) {
		int k;
		l=rk[l]; r=rk[r];
		if(l>r) std::swap(l,r);
		l++; k=lg2[r-l+1];
		return std::min(rmq[l][k],rmq[r-(1<<k)+1][k]);
	}
};
Suffix_Array<N<<1> SA;
int n,odd[N],even[N];
long long dt[N][26],c[N];
int lcp(int l,int r) {
	if(l<1 || r>n) return 0;
	return std::min(std::min(l,n-r+1),SA.query(r,n*2+1-l));
}
bool islexi(int x1,int y1,int x2,int y2) {
	if(!x2) return y1<s[x1]-'a';
	if(x1==x2) return y1<y2;
	return y2>s[x2]-'a';
}
void _() {
	int i,ad,ansid=0,j;
	long long sum=0,ans,val;
	char ansc;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++) SA.s[i]=s[i];
	for(i=n+1;i<=n*2;i++) SA.s[i]=s[2*n+1-i];
	SA.calc();
	for(i=1;i<=n;i++) {
		odd[i]=lcp(i,i); sum+=odd[i];
		if(i-odd[i]>=1 && i+odd[i]<=n) {
			ad=lcp(i-odd[i]-1,i+odd[i]+1)+1;
			dt[i-odd[i]][s[i+odd[i]]-'a']+=ad;
			dt[i+odd[i]][s[i-odd[i]]-'a']+=ad;
		}
		c[i-odd[i]+1]++; c[i]-=odd[i]; c[i+1]+=odd[i]-1;
		c[i+1]+=odd[i]-1; c[i+2]-=odd[i]; c[i+odd[i]+1]++;
	}
	for(i=1;i<n;i++) {
		even[i]=lcp(i,i+1); sum+=even[i];
		if(i-even[i]>=1 && i+even[i]+1<=n) {
			ad=lcp(i-even[i]-1,i+even[i]+2)+1;
			dt[i-even[i]][s[i+even[i]+1]-'a']+=ad;
			dt[i+even[i]+1][s[i-even[i]]-'a']+=ad;
		}
		c[i-even[i]+1]++; c[i+1]--; c[i+2]--; c[i+even[i]+2]++;
	}
	for(i=1;i<=n;i++) c[i]+=c[i-1];
	for(i=1;i<=n;i++) c[i]+=c[i-1];
	ans=sum;
	for(i=1;i<=n;i++) {
		for(j=0;j<26;j++) if(j!=s[i]-'a') {
			val=sum-c[i]+dt[i][j];
			if(val>ans || val==ans && islexi(i,j,ansid,ansc-'a')) {
				ans=val; ansid=i; ansc=j+'a';
			}
		}
	}
	if(ansid) s[ansid]=ansc;
	printf("%lld\n%s",ans,s+1);
}

int main() {
	int T=1;
//	scanf("%d",&T);
	while(T--) _();
	return 0;
}

