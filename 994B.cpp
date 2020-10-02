#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ax[4],ay[4],bx[4],by[4];
	for(int i=0;i<4;i++)
	{
		scanf("%d%d",&ax[i],&ay[i]);
	}
	for(int i=0;i<4;i++)
	{
		scanf("%d%d",&bx[i],&by[i]);
	}
	double aslope[4],bslope[4];
	for(int i=0;i<4;i++)
	{
		if(i==3)
		{
			aslope[i]=(double)(ay[i]-ay[0])/(ax[i]-ax[0]);
			bslope[i]=(double)(by[i]-by[0])/(ax[i]-ax[0]);
			continue;
		}
		else
		{
			aslope[i]=(double)(ay[i]-ay[i+1])/(ax[i]-ax[i+1]);
			bslope[i]=(double)(by[i]-by[i+1])/(ax[i]-ax[i+1]);
		}
		
	}
	double aline[4],bline[4],flager=0;
	for(int i=0;i<4&&flager==0;i++)
	{
		int flag=0;
		aline[0] = aslope[0]*bx[i]-aslope[0]*ax[0]-by[i]+ay[0];
		aline[1] = aslope[1]*bx[i]-aslope[1]*ax[1]-by[i]+ay[1];
		aline[2] = aslope[2]*bx[i]-aslope[2]*ax[2]-by[i]+ay[2];
		aline[3] = aslope[3]*bx[i]-aslope[3]*ax[3]-by[i]+ay[3];
		if(aline[0]>=0&&aline[2]<=0) flag++;
		if(aline[0]<=0&&aline[2]>=0) flag++;
		if(aline[1]>=0&&aline[3]<=0) flag++;
		if(aline[1]<=0&&aline[3]>=0) flag++;
		if(flag>=2) flager=1;
	}
	for(int i=0;i<4&&flager==0;i++)
	{
		int flag=0;
		bline[0] = bslope[0]*ax[i]-bslope[0]*bx[0]-ay[i]+by[0];
		bline[1] = bslope[1]*ax[i]-bslope[1]*bx[1]-ay[i]+by[1];
		bline[2] = bslope[2]*ax[i]-bslope[2]*bx[2]-ay[i]+by[2];
		bline[3] = bslope[3]*ax[i]-bslope[3]*bx[3]-ay[i]+by[3];
		if(bline[0]>=0&&bline[2]<=0) flag++;
		if(bline[0]<=0&&bline[2]>=0) flag++;
		if(bline[1]>=0&&bline[3]<=0) flag++;
		if(bline[1]<=0&&bline[3]>=0) flag++;
		cout<<flag;
		if(flag>=2) flager=1;
	}
	if(flager==1) printf("YES");
	else printf("NO");
	return 0;
}
