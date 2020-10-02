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

set<ll> s[200001];
int main()
{
	boost
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		ll f[n];
		map<ll,ll> m;
		map<ll,ll> cnt;
		for(ll i=0;i<=n;i++)
		{
			s[i].clear();
		}
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			cin>>f[i];
			cnt[a[i]]+=f[i];
			m[a[i]]++;
			ll temp=m[a[i]];
			if(temp>1)
			{
				s[temp-1].erase(a[i]);
				s[temp].insert(a[i]);
			}
			else
			{
				s[1].insert(a[i]);
			}
		}
		ll ans=0;
		vector<ll> prev;
		set<ll> has;
		for(ll i=1;i<=n;i++)
		{
			if(!s[i].empty())
			{
				ans+=i;
				has.insert(i);
				ll siz=s[i].size()-1;
				ll temp=prev.size();
				for(ll j=prev.size()-1,k=0;j>=0&&k<min(temp,siz);j--,k++)
				{
					ans+=prev[j];
					has.insert(prev[j]);
					prev.pop_back();
				}
			}
			else
				prev.pb(i);
		}
		priority_queue<pair<ll,ll> > pq;
		for(ll i=0;i<n;i++)
		{
			if(cnt[a[i]]!=-1)
			{
				//debug1(a[i]);
				pq.push(mp(cnt[a[i]],cnt[a[i]]-m[a[i]]));
				cnt[a[i]]=-1;
			}
		}
		ll ans2=0;
		for(ll i=n;i>=1;i--)
		{
			if(has.find(i)!=has.end())
			{
				priority_queue<pair<ll,ll> > temppq;
				while((!pq.empty())&&pq.top().fi+abs(pq.top().se)<i)
				{	
					temppq.push(pq.top());
					pq.pop();
				}
				pair<ll,ll> temp=pq.top();
				//debug3(i,temp.fi,temp.se);
				//debug1(pq.size());
				pq.pop();
				ans2+=min(temp.fi,i);
				while(!temppq.empty())
				{
					pq.push(temppq.top());
					temppq.pop();
				}
			}
			

		}
		cout<<ans<<" "<<ans2<<endl;
	}
	return 0;
}
