# include <bits/stdc++.h>
# define N 800010
# define MOD 998244353
int op[N],xx[N],t[50],t_n=0,p2[50];
int min(int x,int y) {return x<y?x:y;}
void _() {
	int n,i,j,sub=0,ans=0,lim,ex=1,sum;
	scanf("%d",&n);
	p2[0]=1;
	for(i=1;(p2[i]=p2[i-1]*2)<=1e9;i++);
	for(i=1;i<=n;i++) {
		scanf("%d",op+i);
		if(op[i]<=2) scanf("%d",xx+i);
		if(op[i]==2) sub=min(sub+xx[i],1e9); 
		else if(op[i]==3) xx[i]=sub, sub=min(sub*2,1e9);
	}
	sub=0;
	for(i=n;i>=1;i--) {
		if(op[i]==2) {
			sub+=xx[i];
			if(sub>=1e9) break;
		}
		else if(op[i]==3) {
			if(!xx[i]) ex=ex*2%MOD;
			else if(xx[i]<1e9) t[++t_n]=xx[i];
		}
		else {
			if(xx[i]<=sub) continue;
			lim=xx[i]-sub;
			sum=1;
			for(j=1;j<=t_n;j++) {
				if(t[j]<lim) sum=(sum+p2[t_n-j])%MOD, lim-=t[j];
			}
			ans=(1ll*sum*ex+ans)%MOD;
		}
	}
	printf("%d",ans);
}

int main() {
	int T=1;
	while(T--) _();
	return 0;
}

