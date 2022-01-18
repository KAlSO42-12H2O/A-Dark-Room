#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
#define ll long long
const int mod=1000000007;
#define wood 1
#define charcoal 2
#define meat 3
#define cookedmeat 4
#define stick 1001
int num[2005];
int cntc=1,cntm=0;
map<string,double> lst;
int tot_op=1;
bool ok[1005];
void scene_unlock()
{
	if(tot_op==1)
	{
		if(num[wood]<=4)
		{
			printf("You are running out of wood.\n");
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
	if(tot_op==3)
	{
		if(num[charcoal]>=15)
		{
			printf("It's time to cook some meat!\n");
			printf("(You need: charcoal x1, meat x3)\n");
			tot_op=4;
		}
	}
	if(tot_op==4)
	{
		if(num[cookedmeat]>=3)
		{
			printf("Running out of meat.\n");
			Sleep(1000);
			printf("Let's go hunting!\n");
			tot_op=5;
		}
	}
	if(tot_op==5)
	{
		if(num[cookedmeat]>=10)
		{
			printf("Preparing to get outside!\n");
			tot_op=6;
		}
	}
	if(tot_op==6)
	{
		if(num[stick]>=1)
		{
			printf("Time to go away!\n");
			tot_op=7;
		}
	}
}
void download()
{
	ifstream fi;
	ofstream fo;
	fi.open("nona3");
	fi>>cntc;
	for(int i=1;i<=cntc;i++)
		fi>>num[i];
	fi>>cntm;
	for(int i=1;i<=cntm;i++)
		fi>>num[i+1000];
	fi.close();
	fi.open("nona2");
	fi>>tot_op;
	for(int i=1;i<=tot_op;i++) fi>>ok[i];
	fi.close();
}
int main()
{
	srand(time(0));
	ifstream fi;
	ofstream fo;
	fi.open("nona3");
	int yy;
	for(int i=1;i<=1000;i++) ok[i]=1;
	if(fi>>yy)
	{
		printf("Loading data...\n");
		download();
		printf("Completed!\n");
//		fo.open("nona2");
//		fo<<tot_op<<endl;
//		for(int i=1;i<=tot_op;i++) fo<<ok[i]<<' ';
//		fo.close();
	}
	else
	{
		num[1]=8;
		tot_op=1;
		fo.open("nona2");
		fo<<tot_op<<endl;
		for(int i=1;i<=tot_op;i++) fo<<ok[i]<<' ';
		fo.close();
		printf("The room is freezing.\n");
		Sleep(5000);
		printf("Burn some wood.\n");
		Sleep(1000);
		
//		fill(ok,ok+100,true);
	}
	fi.close();
	string op="NaN";
	fo.open("nona3");
	fo<<cntc<<endl;
	for(int i=1;i<=cntc;i++)
		fo<<num[i]<<endl;
	fo<<cntm<<endl;
	for(int i=1;i<=cntm;i++)
		fo<<num[1000+i]<<endl;
	fo.close();
	while(1)
	{
		fo.open("nona2");
		fo<<tot_op<<endl;
		for(int i=1;i<=tot_op;i++) fo<<ok[i]<<' ';
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
		
		
		
//		printf("1 - Burn Wood. Cost: Wood x1\n");
//		scanf("%d",&op);
//		cout<<"op="<<op<<endl;
		if(op=="A1")
		{
			if((clock()-lst[op])/CLOCKS_PER_SEC<3.0)
			{
				printf("Wait %.1f seconds.\n",3.0-(clock()-lst[op])/CLOCKS_PER_SEC);
				goto CC;
			}
			if(num[wood]<1)
			{
				printf("Not enough wood.\n");
				goto CC;
			}
			num[wood]-=1;
			lst[op]=clock();
			printf("The Wood is burning.\n");
			if(tot_op>=3)
			{
				if(rand()%3)
				{
					printf("You collected charcoal!\n");
					num[charcoal]++;
				}
			}
			
		}
		if(op=="A2")
		{
			if((clock()-lst[op])/CLOCKS_PER_SEC<10.0)
			{
				printf("Wait %.1f seconds.\n",10.0-(clock()-lst[op])/CLOCKS_PER_SEC);
				goto CC;
			}
			num[wood]+=10;
			lst[op]=clock();
			printf("Rotten branches and dead leaves lie on the ground.\n");
		}
		if(op=="A3")
		{
			if(num[charcoal]<1)
			{
				printf("Not enough charcoal.\n");
				goto CC;
			}
			if(num[meat]<3)
			{
				printf("Not enough meat.\n");
				goto CC;
			}
			num[charcoal]-=1;
			num[meat]-=3;
			
//			lst[op]=clock();
			if(rand()%100)
			{
				num[cookedmeat]+=1;
				if(cntc<=3) cntc=4;
				printf("It's so delicious!\n");
			}
			else
			{
				printf("Oops, it's burnt.\n");
				Sleep(1000);
				printf("It turned into charcoal!\n");
				num[charcoal]+=5;
			}
		}
		if(op=="A4")
		{
			if((clock()-lst[op])/CLOCKS_PER_SEC<5.0)
			{
				printf("Wait %.1f seconds.\n",5.0-(clock()-lst[op])/CLOCKS_PER_SEC);
				goto CC;
			}
			int yy=rand()%3+3;
			num[meat]+=yy;
			lst[op]=clock();
			printf("You got meat x%d\n",yy);
		}
		if(op=="B1")
		{
			if(num[wood]<100)
			{
				printf("Not enough wood.\n");
				goto CC;
			}
			num[wood]-=100;
			if(cntm<1) cntm=1;
			num[stick]++;
			ok[6]=0;
			printf("It protects you a little.\n");
		}
		
		if(op=="X1")
		{
			printf("You found something black.\n");
			Sleep(1000);
			printf("You also found some meat.\n");
			num[charcoal]+=10;
			num[meat]+=15;
			ok[3]=0;
			cntc=3;
		}
		if(op=="Y1")
		{
			printf("You now have %d cooked meat.\n",num[cookedmeat]);
			printf("Are you sure?(Y/N)\n");
			string ta;
			cin>>ta;
			if(ta[0]=='Y')
			{
				printf("Take how many cooked meat?\n");
				int x;
				while(scanf("%d",&x))
				{
					if(x>=0&&x<=num[cookedmeat]) break;
					printf("Invalid number.\n");
				}
				num[cookedmeat]-=x;
				fo.open("nona4");
				fo<<1<<' '<<x;
				fo.close();
				system("TTT.exe");
				fi.open("nona4");
				int ta;
				fi>>ta;
				fi.close();
				if(ta)
				{
					printf("You win!\n");
					fi>>ta;
					num[cookedmeat]+=ta;
					ta=rand()%10+1;
					num[meat]+=ta;
					printf("You get %d meat.\n",ta);
					ta=rand()%5+1;
					num[charcoal]+=ta;
					printf("You get %d charcoal.\n",ta);
				}
				else
				{
					printf("You lose!\n");
				}
			}
		}
		fo.open("nona3");
		fo<<cntc<<endl;
		for(int i=1;i<=cntc;i++)
			fo<<num[i]<<endl;
		fo<<cntm<<endl;
		for(int i=1;i<=cntm;i++)
			fo<<num[1000+i]<<endl;
		fo.close();
		scene_unlock();
		goto CC;
		CC:
		fo.open("nona1");
		fo<<"NaN";
		fo.close();
//		Sleep(500);
	}
	return 0;
}

