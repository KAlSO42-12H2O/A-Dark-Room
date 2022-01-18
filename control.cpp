#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
#define ll long long
const int mod=1000000007;
bool ok[505];
map<string,string> mp;
string name[500];
string qq[505];
const int x[55]={20,40,60,80,100,150,200,250,300,400,500,700,900,1200,1500,2000,2500,3000,4000,6000,10000};
int a1;
void init()
{
	qq[1]="A1";
	qq[2]="A2";
	qq[3]="X1";
	qq[4]="A3";
	qq[5]="A4";
	qq[6]="B1";
	qq[7]="Y1";
	ok[1]=ok[2]=ok[3]=ok[4]=ok[5]=ok[6]=ok[7]=ok[8]=1;
	mp["A1"]="Burn wood.";
	name[1]="Wood";
	mp["A2"]="Gather wood.";
	mp["A3"]="Cook meat.";
	mp["A4"]="Go hunting.";
	mp["B1"]="Make a stick.(100 wood)";
	mp["X1"]="Explore the forest.";
	mp["Y1"]="Attack!!!";
}
void display(int s)
{
	if(ok[s])
	{
		cout<<qq[s]<<" - "<<mp[qq[s]];
		cout<<endl;
	}
}
string hh;
int tot_op;
void download()
{
	ifstream fi;
	fi.open("nona2");
	fi>>tot_op;
	for(int i=1;i<=tot_op;i++) fi>>ok[i];
	fi.close();
}
int main()
{
	init();
	ifstream fi;
	ofstream fo;
//	fi.open("nona2");
//	int yy;
//	if(fi>>yy) download();
//	fi.close();
//	int ta;
	MAIN:
	fi.open("nona2");
	fi>>tot_op;
	for(int i=1;i<=tot_op;i++) fi>>ok[i];
	fi.close();
	system("cls");
	printf("---- operations ----\n");
	for(int i=1;i<=tot_op;i++)
		if(ok[i]) display(i);
	char ch=getchar();
	if(ch=='a'||ch=='A')
	{
		printf("A?\n");
		int ta;
		scanf("%d",&ta);
		if(ta<=0||ta>4)
		{
			printf("undefined.\n");
			system("pause");
			goto MAIN;
		}
		else
		{
			
			fo.open("nona1");
			fo<<'A'<<ta;
			fo.close();
		}
	}
	if(ch=='b'||ch=='B')
	{
		printf("B?\n");
		int ta;
		scanf("%d",&ta);
		if(ta<=0||ta>1)
		{
			printf("undefined.\n");
			system("pause");
			goto MAIN;
		}
		else
		{
			if(ta==1) ok[6]=0;
			fo.open("nona1");
			fo<<'B'<<ta;
			fo.close();
		}
	}
	if(ch=='x'||ch=='X')
	{
		printf("X?\n");
		int ta;
		scanf("%d",&ta);
		if(ta<=0||ta>1)
		{
			printf("undefined.\n");
			system("pause");
			goto MAIN;
		}
		else
		{
			if(ta==1&&!ok[3])
			{
				printf("undefined.\n");
				system("pause");
				goto MAIN;
			}
			if(ta==1)
				ok[3]=0;
//			fo.open("nona2");
//			fo<<1;
			fo.open("nona1");
			fo<<'X'<<ta;
			fo.close();
			
		}
	}
	if(ch=='y'||ch=='Y')
	{
		printf("Y?\n");
		int ta;
		scanf("%d",&ta);
		if(ta<=0||ta>1)
		{
			printf("undefined.\n");
			system("pause");
			goto MAIN;
		}
		else
		{

			fo.open("nona1");
			fo<<'Y'<<ta;
			fo.close();
		}
	}
	fi.open("nona1");
	while(1)
	{
		fi>>hh;
		fi.close();
		fi.open("nona1");
		if(hh=="NaN") break;
	}
	fi.close();
	goto MAIN;
	return 0;
}

