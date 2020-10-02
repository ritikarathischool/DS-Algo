#include<bits/stdc++.h>
using namespace std;
#define boost ios::sync_with_stdio(0); cin.tie(0)
typedef long long ll;
 
vector<ll> solve(string A,string B)
{
	ll i,j,k,la=A.length(),lb=B.length();
 
	ll p=31,mod=1e9+9;
 
	ll powr[max(la,lb)+1];
 
	powr[0]=1;
 
	for(i=1;i<=max(la,lb);i++)
		powr[i]=(powr[i-1]*p)%mod;
 
	vector<ll> hash1(la+1,0);
	
	for(i=0;i<la;i++)
	{
		hash1[i+1]=(hash1[i]+(A[i]-'a')*powr[i])%mod;
	}
 
	ll hash2=0;
 
	for(i=0;i<lb;i++)
		hash2=(hash2+(B[i]-'a')*powr[i])%mod;
 
	vector<ll>res;
 
	for(i=0;i+lb-1<la;i++)
	{
		ll curr_hash=(hash1[i+lb]-hash1[i]+mod)%mod;
 
		if(curr_hash==(hash2*powr[i])%mod)
			res.push_back(i+1);
	}
 
	return res;
}
 
int main(int argc, char const *argv[])
{
 
	boost;
 
	ll t;
 
	cin >> t;
 
	while(t--)
	{
		string A,B;
 
		ll i,j,k,la,lb;
 
		cin >> A >> B;
 
		vector<ll>res = solve(A,B);
 
		if(res.size()>0)
		{
			cout << res.size() << endl;
			for(i=0;i<res.size();i++)
				cout << res[i] << " ";
			cout << endl;
		}
		else
			cout << "Not Found" << endl;
		cout << endl;
	}
	
	return 0;
} 