/*
  Vivek Rathi
  CSE 2nd Year
  MNNIT
*/
#include<bits/stdc++.h>
using namespace std;
#define M 998244353
#define ll long long int
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define present(c,x) ((c).find(x) != (c).end())
#define null NULL
#define mp make_pair
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define inf 1e17
ll fact[1000001];
ll ifact[1000001];
long long int modpower(long long int a,long long int b,long long int c)
{
	if(b==0)
	{
		return 1;
	}
	long long int m=modpower(a,b/2,c)%c;
	if(b%2==0)
	{
		return (m*m)%c;
	}
	else
	{
		return (((m*m)%c)*a)%c;
	}
}
int main()
{
	boost
	fact[0]=1;
	ifact[0]=1;
	for(ll i=1;i<1000001;i++)
	{
		fact[i]=(fact[i-1]*i)%M;
		ifact[i]=modpower(fact[i],M-2,M);
	}
	ll n,m,k;
	cin>>n>>m>>k;
	ll total=((((fact[n+m-2])*(ifact[n-1]))%M)*ifact[m-1])%M;
	for(ll i=0;i<k;i++)
	{
		ll x,y,cx,cy;
		cin>>x>>y;
		cx=x,cy=y;
		x=n-x;
		y=y-1;
		cx=cx-1;
		cy=n-cy;
		ll temp1 = (((((fact[x+y])*(ifact[x]))%M)*ifact[y])%M);
		ll temp2 = (((((fact[cx+cy])*(ifact[cx]))%M)*ifact[cy])%M);
		total=((total-(temp1*temp2)%M + M)%M);
	}
	cout<<(total)<<endl;
	return 0;
}