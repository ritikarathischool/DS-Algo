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
#define inf 1e17
bool cmp(pair<ll,ll> p1,pair<ll,ll> p2)
{
	if(p1.fi!=p2.fi) return p1.fi<p2.fi;
	else return p1.se<p2.se;
}
int main()
{
	boost
	ll n,m;
	cin>>n>>m;
	ll a[n],c[n];
	vector<pair<ll,ll> >  co;
	for(ll i=0;i<n;i++) 
	{
		cin>>a[i];
	}
	for(ll i=0;i<n;i++)
	{
		cin>>c[i];
		co.pb(mp(c[i],i));
	}
	sort(co.begin(),co.end());
	pair<ll,ll> ord[m];
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		ord[i]=mp(a-1,b);
	}
	ll k=0;
	for(ll i=0;i<m;i++)
	{
		ll cost=0;
		ll tj=ord[i].fi;
		ll dj=ord[i].se;
		if(a[tj]<dj)
		{
			cost+=a[tj]*c[tj];
			dj-=a[tj];
			a[tj]=0;
			for(ll j=k;j<n&&dj>0;j++)
			{
				//debug3(cost,co[j].se,j);
				if(a[co[j].se]<dj)
				{
					cost+=a[co[j].se]*c[co[j].se];
					dj-=a[co[j].se];
					a[co[j].se]=0;
					k++;
				}
				else
				{
					cost+=dj*c[co[j].se];
					a[co[j].se]-=dj;
					dj=0;
				}
			}	
		}
		else
		{
			cost+=c[tj]*dj;
			a[tj]-=dj;
			dj=0;
		}
		if(dj==0)
		cout<<cost<<endl;
		else cout<<0<<endl;
	}
	
	return 0;
}