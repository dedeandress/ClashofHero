#include<iostream>
#include<string>
#include<time.h>
#include <unistd.h>

using namespace std;

class Soldier{
protected:
	char name[100];
	int HP;
	int level;
	int att;
	int cost;
	int price;
	int slot;
public:
	Soldier(){};
	void setName(char name[]){
		strcpy(this->name,name);
	}
	void setHP(int HP){
		this->HP=HP;
	}
	void setPrice(int price){
		this->price=price;
	}
	void setSlot(int slot){
		this->slot=slot;
	}
	void setLevel(int level){
		this->level=level;
	}
	void setAtt(int att){
		this->att=att;
	}
	void setCost(int cost){
		this->cost=cost;
	}
	char *getName(){
		return this->name;
	}
	int getHP(){
		return this->HP;
	}
	int getPrice(){
		return this->price;
	}
	int getSlot(){
		return this->slot;
	}
	int getLevel(){
		return this->level;
	}
	int getAtt(){
		return this->att;
	}
	int getCost(){
		return this->cost;
	}
	void upgradeSoldier(){
		level+=1;
		HP+=20;
		att+=20;
	}
};

class Player:public Soldier{
protected:
	int money;
	int thropy;
	int XP;
public:
	Player(){};
	void setXP(int XP){
		this->XP=XP;
	}
	void setMoney(int money){
		this->money=money;
	}
	void setThropy(int thropy){
		this->thropy=thropy;
	}
	int getXP(){
		return XP;
	}
	int getMoney(){
		return money;
	}
	int getThropy(){
		return thropy;
	}
	void SumXP(int Xp){
		XP+=Xp;
	}
	void SumThropy(int THROPY){
		thropy+=THROPY;
	}
	void sumMoney(int MONEY){
		money+=MONEY;
	}
	void sumLevel(int LEVEL){
		level+=LEVEL;
	}
	void sumAttack(int ATTACK){
		att+=ATTACK;
	}
};

class Enemy:public Player{
protected:
	int deff;
public:
	Enemy(){};
	void setDeff(int deff){
		this->deff=deff;
	}
	int getDeff(){
		return deff;
	}
	void LoseMoney(int MONEY){
		money-=MONEY;
	}
	void LoseThropy(int THROPY){
		thropy-=THROPY;
	}
};

int nSoldier=0;
Player newPlayer;
Enemy enemys[10];
Soldier soldiers[12];
Soldier soldierMatch[12];
int nPlayer=9;

void enter(){
	for(int i=0;i<25;i++) cout<<endl;
}

void setSoldier(){
	soldiers[0].setName("Barbarian");
	soldiers[0].setLevel(1);
	soldiers[0].setHP(150);
	soldiers[0].setAtt(50);
	soldiers[0].setPrice(0);
	soldiers[0].setCost(2);
	soldiers[0].setSlot(1);
	soldiers[1].setName("Archer");
	soldiers[1].setLevel(1);
	soldiers[1].setHP(50);
	soldiers[1].setAtt(70);
	soldiers[1].setPrice(0);
	soldiers[1].setCost(1);
	soldiers[1].setSlot(1);
	soldiers[2].setName("Giant");
	soldiers[2].setLevel(1);
	soldiers[2].setHP(220);
	soldiers[2].setAtt(20);
	soldiers[2].setPrice(0);
	soldiers[2].setCost(5);
	soldiers[2].setSlot(5);
	nSoldier+=3;
}
void setENEMY(){
	enemys[0].setName("Wendy");
	enemys[0].setAtt(1000);
	enemys[0].setDeff(612);
	enemys[0].setMoney(146000);
	enemys[0].setLevel(10);
	enemys[0].setXP(0);
	enemys[0].setThropy(1000);
	enemys[1].setName("Newt");
	enemys[1].setAtt(777);
	enemys[1].setDeff(900);
	enemys[1].setMoney(120000);
	enemys[1].setLevel(20);
	enemys[1].setXP(0);
	enemys[1].setThropy(500);
	enemys[2].setName("Jack");
	enemys[2].setAtt(1700);
	enemys[2].setDeff(1200);
	enemys[2].setMoney(175000);
	enemys[2].setLevel(22);
	enemys[2].setXP(0);
	enemys[2].setThropy(1300);
	enemys[3].setName("Leonard");
	enemys[3].setAtt(500);
	enemys[3].setDeff(600);
	enemys[3].setMoney(160000);
	enemys[3].setLevel(15);
	enemys[3].setXP(0);
	enemys[3].setThropy(1200);
	enemys[4].setName("Edward");
	enemys[4].setAtt(600);
	enemys[4].setDeff(800);
	enemys[4].setMoney(200000);
	enemys[4].setLevel(20);
	enemys[4].setXP(0);
	enemys[4].setThropy(1800);
	enemys[5].setName("Bill");
	enemys[5].setAtt(2000);
	enemys[5].setDeff(1560);
	enemys[5].setMoney(120000);
	enemys[5].setLevel(11);
	enemys[5].setXP(0);
	enemys[5].setThropy(1500);
	enemys[6].setName("Suerra");
	enemys[6].setAtt(3000);
	enemys[6].setDeff(1200);
	enemys[6].setMoney(120000);
	enemys[6].setLevel(20);
	enemys[6].setXP(0);
	enemys[6].setThropy(1700);
	enemys[7].setName("Putri");
	enemys[7].setAtt(1300);
	enemys[7].setDeff(1200);
	enemys[7].setMoney(180000);
	enemys[7].setLevel(11);
	enemys[7].setXP(0);
	enemys[7].setThropy(1000);
}

int isemail(char email[]){
    int len = strlen(email);
    if(len < 8 || len > 50){
        return 0;
    }
    char temp[50];
    strncpy(temp, email + len - 12, 12);
    temp[12] = '\0';
    if(strcmp(temp, "@binus.ac.id") != 0){
        return 0;
    }
    return 1;
}

void login(){
    char email[100];
	char nickName[41];
	 for(int i=0;i<=100;i++){
		 enter();
		 cout<<endl<<"Loading.."<<i<<"%"<<endl;
		 system("cls");
    }
	enter();
    cout<<"LOADING COMPLETE"<<endl;
	cin.get();
	enter();
	cout<<"Welcome To Clash of Hero"<<endl;
	cout<<"Press Enter to Continue"<<endl;
	cin.get();
	enter();
	do{
        cout<<"Input Email[yourname@binus.ac.id]: ";
        cin.getline(email, 100, '\n'); cin.clear();cin.sync();
    }
    while(isemail(email) == 0);
	cout<<"Input Your NickName : ";
	cin.getline(nickName,100,'\n'); cin.clear(); cin.sync();
	newPlayer.setName(nickName);
	newPlayer.setAtt(100);
	newPlayer.setThropy(0);
	newPlayer.setMoney(100000);
	newPlayer.setXP(0);
	newPlayer.setLevel(1);
	cout<<"You're registered!!!"<<endl;
	cin.get();
}

void listSoldier(){
	cout<<"List Soldier"<<endl;
	cout<<"====================="<<endl<<endl;
	cout<<"+-----------------------------------------------------------+"<<endl;
	printf("%-10s|%-10s|%-10s|%-10s|%-10s|%-5s|\n","Nama","Level","Attack","HP","Cost","Slot");
	cout<<"+-----------------------------------------------------------+"<<endl;
	for(int i=0;i<nSoldier;i++){
		printf("%-10s|%-10d|%-10d|%-10d|%-10d|%-5d|\n",soldiers[i].getName(),soldiers[i].getLevel(),soldiers[i].getAtt(),soldiers[i].getHP(),soldiers[i].getCost(),soldiers[i].getSlot());
	}
	cout<<"+-----------------------------------------------------------+"<<endl;
}

void SoldierUp(){
	int flag=0;
	char input[30];
	int index=-1;
	listSoldier();
	do{
		cout<<"Input Soldier name for training ["<<"Exit"<<" for cancel training] :";
		cin>>input; cin.clear(); cin.sync();
		for(int i=0;i<nSoldier;i++){
			if(strcmp(input,soldiers[i].getName())==0){
				index=i;
			}
		}
		if(index>=0&&soldiers[index].getCost()<=newPlayer.getMoney()){
			enter();
			soldiers[index].upgradeSoldier();
			int sum=newPlayer.getMoney()-soldiers[index].getCost();
			newPlayer.setMoney(sum);
			char up[20]="Upgrading......";
			for(int i=0;i<15;i++){
				cout<<up[i]; usleep(500);
			}
			cout<<endl<<"Your soldier upgraded!!!"<<endl;
			cin.get();
			flag=1;
		}else if(soldiers[index].getCost()>newPlayer.getMoney()){
			cout<<"You don't have money"<<endl;
			cin.get();
			flag=1;
		}else if(strcmp(input,"Exit")==0){
			flag=1;
		}
	}while(index==-1&&flag==0);
}

void ranking(){
	cout<<"List Ranking"<<endl;
	cout<<"=================================="<<endl;
	cout<<"+-----------------------------------------------+"<<endl;
	printf("|%-25s|%-10s|%-10s|\n","Nama","Thropy","Level");
	cout<<"+-----------------------------------------------+"<<endl;
	int j=0;
	int flag=0;
	for(int i=0;i<nPlayer-1;i++){
		for(int j=0;j<nPlayer-1;j++){
			if(enemys[j].getThropy()<enemys[j+1].getThropy()){
				Enemy Temp=enemys[j];
				enemys[j]=enemys[j+1];
				enemys[j+1]=Temp;
			}
		}
	}
	for(int i=0;i<nPlayer;i++){
			if(newPlayer.getThropy()<enemys[j].getThropy()){
				printf("|%-25s|%-10d|%-10d|\n",enemys[j].getName(),enemys[j].getThropy(),enemys[j].getLevel());
				j++;
			}else if(flag==0){
				printf("|%-25s|%-10d|%-10d|\n",newPlayer.getName(),newPlayer.getThropy(),newPlayer.getLevel());
				flag=1;
			}else if(flag==1){
				printf("|%-25s|%-10d|%-10d|\n",enemys[j].getName(),enemys[j].getThropy(),enemys[j].getLevel());
				j++;
			}
	}
	cout<<"+-----------------------------------------------+"<<endl;
	cin.get();
}

void viewStatus(){
	cout<<"Your status"<<endl;
	cout<<"=========================="<<endl;
	cout<<"Level       : "<<newPlayer.getLevel()<<endl;
	cout<<"Attack      : "<<newPlayer.getAtt()<<endl;
	cout<<"Money       : $"<<newPlayer.getMoney()<<endl;
	cout<<"Tropy       : "<<newPlayer.getThropy()<<endl;
	cout<<"Xp          : "<<newPlayer.getXP()<<endl;
	cin.get();
}

Soldier SoldierTemp[10];
int SoldierTempFlag[8]={0,0,0,0,0,0,0};

void setSoldierTemp(){
	SoldierTemp[0].setName("Wizard");
	SoldierTemp[0].setAtt(120);
	SoldierTemp[0].setHP(100);
	SoldierTemp[0].setCost(6);
	SoldierTemp[0].setPrice(10000);
	SoldierTemp[0].setLevel(5);
	SoldierTemp[0].setSlot(3);
	SoldierTemp[1].setName("Dragon");
	SoldierTemp[1].setAtt(220);
	SoldierTemp[1].setHP(200);
	SoldierTemp[1].setCost(7);
	SoldierTemp[1].setSlot(5);
	SoldierTemp[1].setPrice(30000);
	SoldierTemp[1].setLevel(5);
	SoldierTemp[2].setName("Pekka");
	SoldierTemp[2].setAtt(500);
	SoldierTemp[2].setHP(300);
	SoldierTemp[2].setCost(10);
	SoldierTemp[2].setPrice(50000);
	SoldierTemp[2].setLevel(15);
	SoldierTemp[2].setSlot(8);
	SoldierTemp[3].setName("Minion");
	SoldierTemp[3].setAtt(200);
	SoldierTemp[3].setHP(100);
	SoldierTemp[3].setCost(3);
	SoldierTemp[3].setPrice(80000);
	SoldierTemp[3].setLevel(15);
	SoldierTemp[3].setSlot(2);
	SoldierTemp[4].setName("Hog Rider");
	SoldierTemp[4].setAtt(350);
	SoldierTemp[4].setHP(200);
	SoldierTemp[4].setCost(8);
	SoldierTemp[4].setPrice(120000);
	SoldierTemp[4].setLevel(35);
	SoldierTemp[4].setSlot(4);
	SoldierTemp[5].setName("Golem");
	SoldierTemp[5].setAtt(200);
	SoldierTemp[5].setHP(500);
	SoldierTemp[5].setCost(10);
	SoldierTemp[5].setPrice(170000);
	SoldierTemp[5].setLevel(35);
	SoldierTemp[5].setSlot(5);
	SoldierTemp[6].setName("Lava Hound");
	SoldierTemp[6].setAtt(500);
	SoldierTemp[6].setHP(500);
	SoldierTemp[6].setCost(12);
	SoldierTemp[6].setPrice(300000);
	SoldierTemp[6].setLevel(40);
	SoldierTemp[6].setSlot(6);
}

void buySoldier(){
	cout<<"List Soldier"<<endl;
	cout<<"====================="<<endl<<endl;
	cout<<endl<<"Level Requitment is 5"<<endl;
	cout<<"====================="<<endl;
	cout<<"+------------------------------------------------------+"<<endl;
	cout<<"|Nama      |Attack    |Hp        |Cost      |Price     |"<<endl;
	cout<<"+------------------------------------------------------+"<<endl;
	for(int i=0;i<2;i++){
		if(SoldierTempFlag[i]==0&&SoldierTemp[i].getLevel()!=1){
			printf("|%-10s|%-10d|%-10d|%-10d|%-10d|\n",SoldierTemp[i].getName(),SoldierTemp[i].getAtt(),SoldierTemp[i].getHP(),SoldierTemp[i].getCost(),SoldierTemp[i].getPrice());
		}
	}
	cout<<endl<<"+------------------------------------------------------+"<<endl;
	cout<<"Level Requitment is 15"<<endl;
	cout<<"====================="<<endl;
	cout<<"+------------------------------------------------------+"<<endl;
	cout<<"|Nama      |Attack    |Hp        |Cost      |Price     |"<<endl;
	cout<<"+------------------------------------------------------+"<<endl;
	for(int i=2;i<4;i++){
		if(SoldierTempFlag[i]==0&&SoldierTemp[i].getLevel()!=1){
			printf("|%-10s|%-10d|%-10d|%-10d|%-10d|\n",SoldierTemp[i].getName(),SoldierTemp[i].getAtt(),SoldierTemp[i].getHP(),SoldierTemp[i].getCost(),SoldierTemp[i].getPrice());
		}
	}
	cout<<endl<<"+------------------------------------------------------+"<<endl;
	cout<<"Level Requitment is 35"<<endl;
	cout<<"====================="<<endl;
	cout<<"+------------------------------------------------------+"<<endl;
	cout<<"|Nama      |Attack    |Hp        |Cost      |Price     |"<<endl;
	cout<<"+------------------------------------------------------+"<<endl;
	for(int i=4;i<6;i++){
		if(SoldierTempFlag[i]==0&&SoldierTemp[i].getLevel()!=1){
			printf("|%-10s|%-10d|%-10d|%-10d|%-10d|\n",SoldierTemp[i].getName(),SoldierTemp[i].getAtt(),SoldierTemp[i].getHP(),SoldierTemp[i].getCost(),SoldierTemp[i].getPrice());
		}
	}
	cout<<endl<<"+------------------------------------------------------+"<<endl;
	cout<<"Level Requitment is 40"<<endl;
	cout<<"====================="<<endl;
	cout<<"+------------------------------------------------------+"<<endl;
	cout<<"|Nama      |Attack    |Hp        |Cost      |Price     |"<<endl;
	cout<<"+------------------------------------------------------+"<<endl;
	for(int i=6;i<7;i++){
		if(SoldierTempFlag[i]==0&&SoldierTemp[i].getLevel()!=1){
			printf("|%-10s|%-10d|%-10d|%-10d|%-10d|\n",SoldierTemp[i].getName(),SoldierTemp[i].getAtt(),SoldierTemp[i].getHP(),SoldierTemp[i].getCost(),SoldierTemp[i].getPrice());
		}
	}
	cout<<"+------------------------------------------------------+"<<endl;
	int flag=1;
	char input[100];
	int index=-1;
	do{
		index=-1;
		flag=1;
		cout<<"Input soldier name :";
		cin.getline(input,100,'\n'); cin.sync(); cin.clear();
		for(int i=0;i<7;i++){
			if(strcmp("Wizard",input)!=0&&strcmp("Dragon",input)!=0&&strcmp("Pekka",input)!=0&&strcmp("Hog Rider",input)!=0&&strcmp("Golem",input)!=0&&strcmp("Lava Hound",input)!=0&&strcmp("Minion",input)!=0){
				flag=1;
			}else{
				if(SoldierTempFlag[i]==1){
					flag=1;
				}else if(strcmp(SoldierTemp[i].getName(),input)==0){
					if(newPlayer.getLevel()<SoldierTemp[i].getLevel()||newPlayer.getMoney()<SoldierTemp[i].getPrice()){
						cout<<"Sorry your level or money not enough"<<endl;
						flag=1;
					}else{
						index=i;
						flag=1;
					}
					break;
				}
			}
		}
	}while(flag!=1);
	if(index>=0){
		SoldierTemp[index].setLevel(1);
		soldiers[nSoldier]=SoldierTemp[index];
		nSoldier++;
		cout<<soldiers[nSoldier-1].getName()<<" is created"<<endl;
		int money=newPlayer.getMoney()-SoldierTemp[index].getPrice();
		newPlayer.setMoney(money);
	}
	cin.get();
}

int sumSLot(int Level){
	if(Level>=1||Level<=5) return 10;
	if(Level>=6||Level<=15) return 20;
	if(Level>=16||Level<=35) return 30;
	if(Level>=36||Level<=40) return 40;
	if(Level>=41) return 50;
}

void findMatch(){
	int nSoldierMatch=0;
	int maxSLot=sumSLot(newPlayer.getLevel()),index=-1,index2=-1,flag=1,sum,inputQuan,inputSlot,sumSLotMatch,TotalCost,randomPlayer,AttackMatch=0,HPMatch=0;
	char input[20],choice;
	listSoldier();
	do{
		index=-1;
		cout<<"Input soldier name for battle :";
		cin>>input; cin.clear(); cin.sync();
		for(int i=0;i<nSoldier;i++){
			if(strcmp(input,soldiers[i].getName())==0){
				index=i;
			}
		}
		if(index==-1){
			cout<<input<<" is nothing in the list of soldier"<<endl;
			flag=1;
		}else{
			inputSlot=0;
			cout<<"Input quantity soldier [your slot : "<<maxSLot<<"] :"; 
			cin>>inputSlot; cin.clear(); cin.sync(); 
			inputQuan=inputSlot*soldiers[index].getSlot();
			TotalCost=inputSlot*soldiers[index].getCost();
			if(inputQuan>maxSLot||TotalCost>newPlayer.getMoney()){
				flag=1;
				cout<<"Sorry your slot or money not enough"<<endl;
			}else{
				index2=-1;
				for(int i=0;i<nSoldierMatch;i++){
					if(strcmp(soldierMatch[i].getName(),soldiers[index].getName())==0){
						index2=i;
					}
				}
				if(index2==-1){
					soldierMatch[nSoldierMatch]=soldiers[index];
					soldierMatch[nSoldierMatch].setSlot(inputSlot);
					nSoldierMatch++;
				}else{
					sumSLotMatch=soldierMatch[index2].getSlot()+inputSlot;
					soldierMatch[index2].setSlot(sumSLotMatch);
				}
				sum=newPlayer.getMoney()-TotalCost;
				newPlayer.setMoney(sum);
				maxSLot-=inputQuan;
				if(maxSLot>0){
					flag=1;
				}else{
					flag=0;
				}
			}
		}
	}while(flag!=0);
	enter();
	cout<<"List Soldier"<<endl;
	cout<<"====================="<<endl;
	cout<<"+-------------------------------------------+"<<endl<<endl;
	printf("|%-10s|%-10s|%-10s|%-10s|\n","Nama","Attack","Hp","Quantity");
	cout<<"+-------------------------------------------+"<<endl;
	int tempAttack=0;
	int tempHP=0;
	for(int i=0;i<nSoldierMatch;i++){
		tempAttack+=soldierMatch[i].getAtt()*soldierMatch[i].getSlot();
		tempHP+=soldierMatch[i].getHP()*soldierMatch[i].getSlot();
		printf("|%-10s|%-10d|%-10d |%-10d|\n",soldierMatch[i].getName(),soldierMatch[i].getAtt(),soldierMatch[i].getHP(),soldierMatch[i].getSlot());
	}	
	cout<<"+-------------------------------------------+"<<endl;
	cout<<"Press enter to find match..."<<endl;
	cin.get();
	AttackMatch+=tempAttack;
	HPMatch+=tempHP;
	do{
		enter();
		char str[100]="Searching.............";
		for(int i=0;i<23;i++){
			cout<<str[i]; usleep(500);
		}
		srand(time(NULL));
		randomPlayer=rand()%7+0;
		cout<<endl<<"Your status"<<endl;
		cout<<"============================"<<endl;
		cout<<"Level   : "<<newPlayer.getLevel()<<endl;
		cout<<"Tropy   : "<<newPlayer.getThropy()<<endl;
		cout<<"Attack  : "<<AttackMatch<<endl;
		cout<<"HP      : "<<HPMatch<<endl;
		cout<<"Money   : $"<<newPlayer.getMoney()<<endl;
		cout<<"============================"<<endl;
		cout<<"Enemy status"<<endl;
		cout<<"============================"<<endl;
		cout<<"Name    : "<<enemys[randomPlayer].getName()<<endl;
		cout<<"Level   : "<<enemys[randomPlayer].getLevel()<<endl;
		cout<<"Tropy   : "<<enemys[randomPlayer].getThropy()<<endl;
		cout<<"Attack  : "<<enemys[randomPlayer].getAtt()<<endl;
		cout<<"Defence : "<<enemys[randomPlayer].getDeff()<<endl;
		cout<<"Money   : $"<<enemys[randomPlayer].getMoney()<<endl;
		cout<<"============================"<<endl;
		do{
			cout<<"Attack "<<enemys[randomPlayer].getName()<<" [Y/N] :";
			cin>>choice; cin.clear(); cin.sync();
		}while(choice!='Y'&&choice!='N');
	}while(choice!='Y');
	enter();
	int DamageUser=AttackMatch-enemys[randomPlayer].getDeff();
	int DamageEnemy=enemys[randomPlayer].getDeff()-HPMatch;
	if(DamageUser>=DamageEnemy){
		cout<<"Congratulations you won the battle"<<endl;
		cout<<"You got 25 XP"<<endl;
		cout<<"You got $"<<enemys[randomPlayer].getMoney()<<endl;
		cout<<"You got 25 Tropy"<<endl;
		newPlayer.SumXP(25);
		newPlayer.sumMoney(enemys[randomPlayer].getMoney());
		newPlayer.SumThropy(25);
		if(enemys[randomPlayer].getMoney()!=0){
			enemys[randomPlayer].LoseMoney(enemys[randomPlayer].getMoney());
		}else if(enemys[randomPlayer].getThropy()!=0){
			enemys[randomPlayer].LoseThropy(25);
		}
	}else{
		cout<<"You lose"<<endl;
		cout<<"You got 5 XP"<<endl;
		cout<<"You got 5 Tropy"<<endl;
		newPlayer.SumXP(5);
		newPlayer.SumThropy(5);
		enemys[randomPlayer].SumXP(25);
		enemys[randomPlayer].SumThropy(25);
	}
	if(newPlayer.getXP()>=100){
		newPlayer.sumLevel(1);
		newPlayer.sumAttack(20);
		newPlayer.setXP(0);
	}else if(enemys[randomPlayer].getXP()>=100){
		enemys[randomPlayer].sumLevel(1);
		enemys[randomPlayer].sumAttack(20);
		enemys[randomPlayer].setXP(0);
	}
	cin.get();
}

void menu(){
	enter();
	login();
	setSoldier();
	setENEMY();
	setSoldierTemp();
	int choose=0;
	do{
		enter();
		cout<<"Hello, "<<newPlayer.getName()<<endl;
		cout<<"1. Find match"<<endl;
		cout<<"2. Soldier"<<endl;
		cout<<"3. Buy soldier"<<endl;
		cout<<"4. Ranking"<<endl;
		cout<<"5. View Status"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Choose :";
		cin>>choose; cin.clear(); cin.sync();
		enter();
		switch(choose){
		case 1:
			findMatch();
			break;
		case 2:
			SoldierUp();
			break;
		case 3:
			buySoldier();
			break;
		case 4:
			ranking();
			break;
		case 5:
			viewStatus();
			break;
		case 6:
			cout<<"Thank You for Playing"<<endl; usleep(500);
			cout<<"Code By :"<<endl; usleep(500);
			cout<<"Dede Andres - 2001544801"<<endl; usleep(500);
			cout<<"Kevin Leonardo - 2001539972"<<endl;usleep(500);
			cout<<"Hengky Chandra - 2001541554"<<endl;usleep(500);
			cout<<"Wendy Chandra - 2001546946"<<endl;usleep(500);
			cout<<"Wendy Chen - 2001541075"<<endl;usleep(500);
			break;
		}
	}while(choose!=6);
}

int main(){
	menu();
	cin.get();
	return 0;
}