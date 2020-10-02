/*
  Vivek Rathi
  CSE 2nd Year
  MNNIT
*/
#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
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
#define inf 1e18
#define flush fflush(stdout);
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
ll modpower(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}
//-------------------------------Template--Above------------------------------------------------

int main()
{
	boost
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll b[n];
		for(ll i=0;i<n;i++)
		{
			cin>>b[i];
		}
		double p[n];
		for(ll i=0;i<n;i++)
		{
			cin>>p[i];
		}
		double dp[n][33][2];
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<33;j++)
			{
				for(ll k=0;k<2;k++)
				{
					dp[i][j][0]=1.0;
					dp[i][j][1]=0.0;
				}
			}
		}
		ll k=0;
		while(b[0]!=0)
		{
			if(b[0]%2==0)
			{
				dp[0][k][0]=1;
				dp[0][k][1]=0;
			}
			else
			{
				dp[0][k][0]=1-p[0];
				dp[0][k][1]=p[0];
			}
			b[0]/=2;
			k++;	
		}
		for(ll i=1;i<n;i++)
		{
			ll j=0;
			while(b[i]!=0)
			{
				if(b[i]%2==0)
				{
					dp[i][j][0]=dp[i-1][j][0];
					dp[i][j][1]=dp[i-1][j][1];
				}
				else
				{
					dp[i][j][0]=dp[i-1][j][1]*p[i]+dp[i-1][j][0]*(1-p[i]);
					dp[i][j][1]=dp[i-1][j][1]*(1-p[i])+dp[i-1][j][0]*p[i];	
					//debug3(j,dp[i][j][0],dp[i][j][1]);
					//debug1(p[i]);
				}
				j++;
				b[i]/=2;
			}
			for(ll l=j;l<33;l++)
			{
				dp[i][l][0]=dp[i-1][l][0];
				dp[i][l][1]=dp[i-1][l][1];
			}
		}
		double expval=0.0;
		double pp=1;
		for(ll i=0;i<33;i++)
		{
			expval+=pp*dp[n-1][i][1];
			//debug2(i,dp[n-1][i][1]);
			pp*=2;
		}
		printf("%.10lf\n",expval);
	}
	return 0;
}
