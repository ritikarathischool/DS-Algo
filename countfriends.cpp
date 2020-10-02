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
vector<ll> v[100001];
ll visited[100001];
ll dfs(ll ver,ll id)
{
	visited[ver]=id;
	ll sum=0;
	for(ll i=0;i<v[ver].size();i++)
	{
		if(visited[v[ver][i]]==0)
		{
			sum+=dfs(v[ver][i],id);
		}
	}
	return sum+1;
}
int main()
{
	boost
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll a,b;
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	ll sum[n+1]={0};
	for(ll i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			sum[i]=dfs(i,i);
		}
	}
	for(ll i=1;i<=n;i++)
	{
		cout<<sum[visited[i]]-1<<" ";
	}
	return 0;
}