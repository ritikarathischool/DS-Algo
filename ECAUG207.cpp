/*
  KUNAL ANAND
  MNNIT ALLAHABAD
*/  

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<assert.h>

using namespace std;
using namespace __gnu_pbds;

#define boost ios_base::sync_with_stdio(0); cin.tie(0)
#define debug1(x) cout << # x << " " << x << endl;
#define debug2(x,y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define debug3(x,y,z) cout << #x << " " << x << " " << #y << " " << y << " " << #z << " " << z << endl;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define fbo find_by_order
#define ook order_of_key
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long int
#define ld long double
#define pll pair<long long int,long long int>
#define cse(x) cout << "Case #" << x << ": "
const ll INF=1e18;
const ll mod=1e9+7;
const ll MAX_SZ=5000000;


/*********************************TEMPLATE ABOVE****************************************************/

ll powmod(ll x,ll y)
{
    if(y==0)
        return 1;
    ll a=powmod(x,y/2);
    a=(a*a)%mod;
    if(y%2)
        a=(a*x%mod)%mod;
    return a;
}

ll fact[1000005];

void factorial(){

    fact[0]=1;

    for(ll i=1;i<=1000000;i++)
        fact[i]=(i*fact[i-1])%mod;
}

ll nCr(ll n,ll r){

	if(n<r)
		return 0;

    if(r==0||r==n)
        return 1;
    ll a=fact[n];
    ll b=(fact[n-r]*fact[r])%mod;
    ll c=powmod(b,mod-2);
    a=(a*c)%mod;
    return a;
}

ll LCM(ll a,ll b){

	ll x=__gcd(min(a,b),max(a,b));

	return (a*b)/x;
}

vector<ll>graph[200005];

bool visited[200005];

ll minc,mino;

ll dfs(ll node,ll n){

	ll i,j,k,cnt=0,maxi=0;

	visited[node]=true;

	for(i=0;i<graph[node].size();i++){

		if(!visited[graph[node][i]]){

			j=dfs(graph[node][i],n);

			cnt+=j;
			maxi=max(maxi,j);
		}
	}

	maxi=max(maxi,n-1-cnt);

	if(maxi<minc){
		mino=node;
		minc=maxi;
	}
	else if(maxi==minc){
		mino=min(mino,node);
	}

	return cnt+1;
}

int main()
{
	ofstream fout;
	ifstream fin;
	boost;
	ll t,cs;
	t=1;
	//fin.open("input.txt");
	//fout.open("output.txt");

	factorial();

	cin >> t;

	for(cs=1;cs<=t;cs++)
	{   
		ll i,j,k,n,q,x,y,m,a,b,c,sum=0,c0=0,c1=0,cn0=0,cn1=0,l,r,ans=0;

		cin >> n;

		for(i=1;i<n;i++){
			cin >> a >> b;

			graph[a].pb(b);
			graph[b].pb(a);
		}

		mino=minc=LLONG_MAX;

		dfs(1,n);

		cout << mino << " " << minc << endl;

		for(i=1;i<=n;i++){
			graph[i].clear();
			visited[i]=false;
		}
		
	} 


	return 0;
}   