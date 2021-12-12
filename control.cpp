#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
#define ll long long
const int mod=1000000007;
map<string,bool> ok;
map<string,string> mp;
string name[500];
void init()
{
	ok["A1"]=1; mp["A1"]="Burn wood.";
	name[1]="Wood";
}
void display(string s)
{
	if(ok[s]) cout<<s<<" - "<<mp[s]<<endl;
}
int main()
{
	init();
	ifstream fi;
	ofstream fo;
	MAIN:
	system("cls");
	printf("---- materials -----\n");
	fi.open("nona3");
	int n;
	fi>>n;
	printf("n=%d\n",n);
	int ta;
	for(int i=1;i<=n;i++)
	{
		fi>>ta;
		cout<<name[i]<<" - "<<ta<<endl;
	}
	fi.close();
	printf("---- operations ----\n");
	display("A1");
	char ch=getchar();
	if(ch=='a'||ch=='A')
	{
		printf("A?\n");
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
			fo<<'A'<<ta;
			fo.close();
			fo.open("nona2");
			fo<<1;
			fo.close();
			goto MAIN;
		}
	}
	printf("Undefined.");
	system("pause");
	goto MAIN;
	return 0;
}

