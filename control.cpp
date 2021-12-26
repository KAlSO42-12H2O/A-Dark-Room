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
void init()
{
	qq[1]="A1";
	qq[2]="A2";
	qq[3]="X1";
	qq[4]="A3";
	qq[5]="A4";
	ok[1]=ok[2]=ok[3]=ok[4]=ok[5]=1;
	mp["A1"]="Burn wood.";
	name[1]="Wood";
	mp["A2"]="Gather wood.";
	mp["A3"]="Cook meat.";
	mp["A4"]="Go hunting.";
	mp["X1"]="Explore the forest.";
}
void display(int s)
{
	if(ok[s])
	cout<<qq[s]<<" - "<<mp[qq[s]]<<endl;
}
int main()
{
	init();
	ifstream fi;
	ofstream fo;
	int ta;
	MAIN:
	system("cls");
	printf("---- operations ----\n");
	fi.open("nona4");
	fi>>ta;
	fi.close();
	for(int i=1;i<=ta;i++)
	display(i);
	
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
			goto MAIN;
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
			
//			fo.close();
			goto MAIN;
		}
	}
	printf("undefined.");
	system("pause");
	goto MAIN;
	return 0;
}

