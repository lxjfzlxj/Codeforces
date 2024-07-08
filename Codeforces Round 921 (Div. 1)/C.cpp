# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define MOD 999999893
struct pair{
	int a,b;
	pair(int _a,int _b) {a=_a; b=_b;}
};
int qpow(int x,int p) {
	int res=1;
	while(p) {
		if(p&1) res=1ll*res*x%MOD;
		x=1ll*x*x%MOD; p>>=1;
	}
	return res;
}
pair operator +(const pair &i,const pair &j) {
	return pair(i.a+j.a,i.b+j.b);
}
pair operator -(const pair &i,const pair &j) {
	return pair(i.a-j.a,i.b-j.b);
}
pair operator *(const pair &i,const pair &j) {
	return pair((1ll*i.a*j.a+2ll*i.b*j.b)%MOD,(1ll*i.a*j.b+1ll*i.b*j.a)%MOD);
}
pair operator /(const pair &i,const int &j) {
	int inv=qpow((j+MOD)%MOD,MOD-2);
	return pair(1ll*i.a*inv%MOD,1ll*i.b*inv%MOD);
}
pair operator /(const pair &i,const pair &j) {
	return i*pair(j.a,(MOD-j.b)%MOD)/((1ll*j.a*j.a-2ll*j.b*j.b%MOD+MOD)%MOD);
}
void _() {
	int n;
	scanf("%d",&n);
	pair sum=pair(0,2)*(n%2?pair(MOD-1,qpow(2,n/2)):pair((qpow(2,n/2)-1+MOD)%MOD,0))/pair(MOD-1,1);
	pair res=(sum/2-pair(0,1))/(sum/2+pair(0,1));
	printf("%d\n",res.b);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}

