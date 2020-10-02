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

ll findpar(ll node,ll par[]){

	if(par[node]==node)
		return node;
	return par[node]=findpar(par[node],par);
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

	//factorial();

	cin >> t;

	for(cs=1;cs<=t;cs++)
	{   
		ll i,j,k,n,q,x,y,m,a,b,c,sum=0,c0=0,c1=0,cn0=0,cn1=0,l,r,ans=0;

		cin >> n;

		ll par[n+1];

		for(i=1;i<=n;i++)
			par[i]=i;

		for(i=0;i<n-1;i++){

			cin >> a >> b;
			
			ll pa=findpar(a,par);
			ll pb=findpar(b,par);
			if(pb==b)
				par[pb]=pa;
		}

		set<ll>pars;

		for(i=1;i<=n;i++){
			pars.insert(findpar(i,par));
		}

		ans=pars.size()-1;

		cout << ans << endl;

	} 


	return 0;
}   