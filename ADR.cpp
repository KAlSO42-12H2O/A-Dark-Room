#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
#define ll long long
const int mod=1000000007;
#define wood 1
int num[25];
int cntc=1;
map<string,double> lst;
int main()
{
	ifstream fi;
	ofstream fo;
	printf("The room is freezing.\n");
	Sleep(5000);
	printf("Burn some wood.\n");
	Sleep(1000);
	num[1]=20;
	string op;
	int ttt;
	while(1)
	{
		fo.open("nona3");
		fo<<cntc<<endl;
		for(int i=1;i<=cntc;i++)
			fo<<num[i]<<endl;
		fo.close();
		fi.open("nona1");
		fi>>op;
		fi.close();
		fi.open("nona2");
		fi>>ttt;
		if(!ttt) continue;
		fo.open("nona2");
		fo<<0;
		fo.close();
//		printf("1 - Burn Wood. Cost: Wood x1\n");
//		scanf("%d",&op);
		if(op=="A1")
		{
			if((clock()-lst[op])/CLOCKS_PER_SEC<3.0)
			{
				printf("Wait %.1f seconds.\n",3.0-(clock()-lst[op])/CLOCKS_PER_SEC);
				continue;
			}
			num[wood]--;
			lst[op]=clock();
			printf("The Wood is burning.\n");
		}
		Sleep(500);
	}
	return 0;
}

