#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
#define ll long long
const int mod=1000000007;
#define wood 1
#define charcoal 2
#define meat 3
int num[25];
int cntc=1;
map<string,double> lst;
int tot_op=1;
void scene_unlock()
{
	if(tot_op==1)
	{
		if(num[wood]<=4)
		{
			printf("You are burning out of wood.");
			tot_op=2;
		}
	}
	if(tot_op==2)
	{
		if(num[wood]>=20)
		{
			printf("Some small bright things appeared.\n");
			Sleep(3000);
			printf("Oh no! It's FIRE!\n");
			Sleep(5000);
			printf("The fire is burning...\n");
			int yy=15;
			while(yy--)
			{
				num[wood]--;
				Sleep(1000);
			}
			printf("You lost some wood.\n");
			Sleep(1000);
			printf("Luckily, you aren't hurt.\n");
			Sleep(2000);
			printf("It seems interesting to explore the forest.\n");
			tot_op=3;
		}
	}
}
int main()
{
	srand(time(0));
	ifstream fi;
	ofstream fo;
	printf("The room is freezing.\n");
	Sleep(5000);
	printf("Burn some wood.\n");
	Sleep(1000);
	num[1]=8;
	string op="NaN";
	int ttt;
	while(1)
	{
		Sleep(500);
		fo.open("nona3");
		fo<<cntc<<endl;
		for(int i=1;i<=cntc;i++)
			fo<<num[i]<<endl;
		fo.close();
		fo.open("nona4");
		fo<<tot_op;
		fo.close();
		fi.open("nona1");
		fi>>op;
		fi.close();
		/*fi.open("nona2");
		fi>>ttt;
//		cout<<op<<' '<<ttt<<endl;
		
		fi.close();*/

		if(op=="NaN") continue;
//		Sleep(500);
		
		fo.open("nona1");
		fo<<"NaN";
		fo.close();
		
//		printf("1 - Burn Wood. Cost: Wood x1\n");
//		scanf("%d",&op);
//		cout<<"op="<<op<<endl;
		if(op=="A1")
		{
			if((clock()-lst[op])/CLOCKS_PER_SEC<3.0)
			{
				printf("Wait %.1f seconds.\n",3.0-(clock()-lst[op])/CLOCKS_PER_SEC);
				continue;
			}
			if(num[wood]<1)
			{
				printf("Not enough wood.\n");
				continue;
			}
			num[wood]-=1;
			lst[op]=clock();
			printf("The Wood is burning.\n");
		}
		if(op=="A2")
		{
			if((clock()-lst[op])/CLOCKS_PER_SEC<10.0)
			{
				printf("Wait %.1f seconds.\n",10.0-(clock()-lst[op])/CLOCKS_PER_SEC);
				continue;
			}
			num[wood]+=10;
			lst[op]=clock();
			printf("Rotten branches and dead leaves lie on the ground.\n");
		}
		if(op=="X1")
		{
			printf("You found something black.\n");
			Sleep(1000);
			printf("You also found some meat.\n");
			num[charcoal]+=10;
			num[meat]+=5;
			cntc=3;
		}
		scene_unlock();
//		Sleep(500);
	}
	return 0;
}

