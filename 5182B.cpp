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
#define debug(x) printf("%d\n",x)
#define present(c,x) ((c).find(x) != (c).end())
#define null NULL
#define mp make_pair
int main()
{
	ll b;
	scanf("%lld",&b);
	ll co=0;
	for(ll i=1;i*i<=b;i++)
	{
		if(b%i==0)
		{
			co++;
			if(b/i!=i) co++;
		}
	}
	printf("%lld",co);
	return 0;
}