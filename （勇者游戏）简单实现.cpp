/*
	回合制战斗游戏
	勇者属性 战斗力 经验值 枪
	枪属性 名字 杀伤力 弹夹容量 当前载弹量
	怪物属性 生命值 怪物值 攻击力 怪物掉落弹夹
	战斗过程 勇者能够对怪物造成伤害的条件 战斗力+经验值 大于怪物值
	每次勇者对怪物产生枪杀伤力的伤害 每次攻击使用一颗子弹 
	怪物每回合可以对勇者的战斗力造成攻击力点下降
	当勇者的不足以对怪物造成伤害时 就会被怪物吞噬 游戏结束
	当勇者击败怪物时 勇者的战斗力将会提升怪物值 并且获得怪物身上的弹夹 
	勇者具有升级能力 当战斗力到达一定阈值就可以升级 并且产生经验值的成长 
*/
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <vector>
#include <windows.h>
#include <ctime>
using namespace std;
class Gun{
	private:
		string name;
		int lethality,capacity,bullet;
	public:
		Gun(string name,int lethality,int capacity,int bullet)
		{
			this->name=name;
			this->lethality=lethality;
			this->capacity=capacity;
			this->bullet=bullet;
		}
		Gun(const Gun &w)
		{
			this->name=w.name;
			this->lethality=w.lethality;
			this->capacity=w.capacity;
			this->bullet=w.bullet;
		}
		void set_Gun(const Gun &w)
		{
			this->name=w.name;
			this->lethality=w.lethality;
			this->capacity=w.capacity;
			this->bullet=w.bullet;
		}
		int fire()
		{
			if(bullet)	
			{
				bullet--;
				return lethality;	
			}
			return -1;
		}
		bool check_bullet()
		{
			if(bullet) return 1;
			return 0;
		}
		string get_name()
		{
			return name;
		}
		void load()
		{
			bullet=capacity;
		}
		void disp()
		{
			cout<<"The Gun's name is"<<setw(6)<<name;
			//_sleep(500);
			cout<<",the gun's lethality is"<<setw(4)<<lethality;
			//_sleep(500);
			cout<<",the gun's capacity is"<<setw(4)<<capacity;
			//_sleep(500);
			cout<<",the gun's bullet is"<<setw(4)<<bullet<<endl;
			//_sleep(500);
		}
};
class Soldier{
	private:
		int id,force,experience,up_num;
		int bullet_num,level;
		Gun weapon;
	public: 
		Soldier(int id,int force,int experience,int up_num,int level,Gun _weapon):weapon(_weapon) 
		{
			this->up_num=up_num;
			this->id=id;
			this->force=force;
			this->experience=experience;
			this->level=level;
		}
		int get_fpe()
		{
			return experience+force;
		}
		void set_Soldier(int id,int force,int experience,int up_num,int level,int bullet_num)
		{
			this->up_num=up_num;
			this->id=id;
			this->force=force;
			this->experience=experience;
			this->bullet_num=bullet_num;
			this->level=level;
		}
		void set_Soldier_Gun(Gun weapon)
		{
			this->weapon=weapon;
		}
		void add_force(int num)
		{
			force+=num;
		}
		void level_up()
		{
			experience+=up_num;
		}
		void check_level()
		{
			while(force/1000>level) 
			{
				level++,level_up();
				cout<<"勇者升级 当前等级为"<<level<<endl;
				_sleep(300);
				system("cls"); 
			}
		}
		string get_gun_name()
		{
			return weapon.get_name();
		}
		void change_force(int num)
		{
			force=max(force-num,0);
		}
		bool load()
		{
			if(bullet_num) 
			{
				bullet_num--;
				weapon.load();
				return 1;
			}
			return 0;
		}
		bool check_bullet()
		{
			return weapon.check_bullet();
		}
		int fire()
		{
			return weapon.fire();
		}
		void disp()
		{
			cout<<"目前您的属性：force["<<force<<"]，experience["<<experience<<"]"<<endl;
			_sleep(500);
			cout<<"目前您拥有的弹夹数量："<<this->bullet_num<<endl;
			_sleep(500);
			cout<<"展示您的武器属性"<<endl;
			_sleep(500);
			weapon.disp();
		}
};
class monster{
	private:
		int id,hp,attack,force,bullet_num;
	public:
		monster(int id)
		{
			this->id=id;
			this->hp=(rand()%10+1)*50;
			this->attack=(rand()%10+1)*50;
			this->force=(rand()%10+1)*70;
			this->bullet_num=(rand()%3+1);
		}
		void modify_hp(int num)
		{
			hp-=num;
			if(hp<0) hp=0;
		}
		int get_hp()
		{
			return hp;
		}
		void disp()
		{
			cout<<"怪物["<<id<<"]的生命值为"<<hp<<"，攻击力为"<<attack<<"，击败它获得的战斗力为："<<force<<endl;
			_sleep(500);
			cout<<"击败这只怪物你可以获得"<<bullet_num<<"的弹夹补给"<<endl;
			_sleep(500);
		}
		int get_attack()
		{
			return attack;
		}
		int get_force()
		{
			return force;
		}
		int get_id()
		{
			return id;
		}
};
class Game{
	private:
		vector <monster> mons;
		int siz;
	public:
		void Select_Soldier(Soldier &s)
		{
			cout<<"你可以选择三种勇者"<<endl;
			cout<<"键入[1]：攻击型勇者 拥有较高的初始战斗力 但是升级增加的经验值比较低"<<endl;
			cout<<"键入[2]：成长型勇者 升级可以获得巨额的经验值 但是初始战斗力较低"<<endl;
			cout<<"键入[3]：均衡型勇者 平平无奇的勇者"<<endl;
			string name[]={"","攻击型勇者","成长型勇者","均衡型勇者"};
			int x;
			cin>>x;
			system("cls");
			cout<<"您选择了"<<name[x]<<endl;
			if(x==1) s.set_Soldier(1,2000,0,50,5,2);
			if(x==2) s.set_Soldier(1,1000,0,400,5,1);
			if(x==3) s.set_Soldier(1,1500,0,100,5,1);
		}
		void Select_Gun(Soldier &s)
		{
			_sleep(1000);
			system("cls"); 
			cout<<"现在为您的勇者选择一把枪"<<endl;
			Gun USP("USP",40,20,20);
			Gun UZI("UZI",10,40,40);
			cout<<"键入[1]：获得枪械USP"<<endl;
			USP.disp(); 
			cout<<"键入[2]：获得枪械UZI"<<endl;
			UZI.disp();
			int opt; 
			cin>>opt;
			if(opt==1) s.set_Soldier_Gun(USP);
			if(opt==2) s.set_Soldier_Gun(UZI); 
		}
		void Soldier_attack(Soldier &s,monster &m)
		{
			if(!s.check_bullet())
			{
				cout<<"勇者使用枪械攻击 但他发现弹夹空了！"<<endl;
				return;
			}
			cout<<"勇者使用枪械["<<s.get_gun_name()<<"]攻击怪物"<<endl;
			_sleep(500); 
			int w=s.fire();
			cout<<"勇者对怪物造成了["<<w<<"]伤害"<<endl;
			m.modify_hp(w);
			int r=rand()%2;
			if(r)
			{
				_sleep(500);
				cout<<"效果拔群！对怪物造成了额外["<<int(0.8*w)<<"]伤害"<<endl; 
				m.modify_hp(0.8*w);
			}
		}
		bool Soldier_run()
		{
			int x=rand()%2;
			if(x)
			{
				cout<<"勇者使用了逃跑战术！"<<endl;
				_sleep(1000);
				cout<<"逃脱成功！"<<endl;
				return 1;
			}
			else
			{
				cout<<"勇者使用了逃跑战术！"<<endl;
				_sleep(1000);
				cout<<"逃脱失败！"<<endl;
				return 1;
			}
		}
		void monster_attack(Soldier &s,monster &m)
		{
			cout<<"怪物使用了怪力猛击"<<endl;
			_sleep(1000);
			cout<<"怪物对勇者造成了["<<m.get_attack()<<"]伤害"<<endl;
			s.change_force(m.get_attack());
			_sleep(1000);
			int r=rand()%2;
			if(r)
			{
				s.change_force(0.8*m.get_attack());
				cout<<"产生连击！怪物再次对勇者造成了["<<0.8*m.get_attack()<<"]伤害"<<endl;
				_sleep(1000);
			}
		}
		void Soldier_load(Soldier &s)
		{
			if(s.load()) cout<<"上弹成功！"<<endl;
			else cout<<"弹夹数量不足 上弹失败！"<<endl;
			_sleep(1000);
		}
		void end_game()
		{
			cout<<"游戏结束"<<endl; 
			exit(0);
		}
		int fight(Soldier &s,monster &m)
		{
			while(1)
			{
			    system("cls");
				if(s.get_fpe()<=m.get_force())
				{
					cout<<"无法击败怪物 被怪物吞噬"<<endl;
					_sleep(2000);
					return -1;
				}
				int opt;
				cout<<"勇者属性展示"<<endl;
				s.disp();
				cout<<"怪物属性展示"<<endl;
				m.disp();
				cout<<"现在是你的回合！"<<endl;
				cout<<"键入[1]：对怪物进行枪械攻击！"<<endl;
				cout<<"键入[2]：对枪械进行上弹！"<<endl;
				cout<<"键入[3]：进行战术撤退！"<<endl;
				cin>>opt;
				system("cls");
				if(opt==1) Soldier_attack(s,m);
				if(opt==2) Soldier_load(s);
				if(opt==3) 
				{
					if(Soldier_run()) return 0;	
				}
				if(!m.get_hp()) 
				{
					s.add_force(m.get_force());
					cout<<"击败怪物！获得怪物携带弹夹 获得战斗力增长！"<<endl;
					_sleep(2000);
					return 1;
				}
				else monster_attack(s,m);
				_sleep(2000);
			}

		}
		void monster_rand()
		{
			monster m1(++siz);
			mons.push_back(m1); 
		}
		void play_game(Soldier &s)
		{
			while(1)
			{
				srand(time(0));
				system("cls");
				cout<<"选择一个怪物开始战斗"<<endl;
				monster_rand();
				for(int i=0;i<mons.size();i++)
					mons[i].disp();
				int x;
				cin>>x;
				for(int i=0;i<mons.size();i++)
				if(x==mons[i].get_id())
				{
					x=i;
					break;
				}
				int result=fight(s,mons[x]);
				if(result==-1) end_game();
				if(result==1) mons.erase(mons.begin()+x);
				s.check_level();
			}
		}
		void start()
		{
			for(int i=1;i<=5;i++) monster_rand();
			cout<<"欢迎来到勇者的冒险旅途"<<endl;
			cout<<"点击任意键开始游戏"<<endl;
			getchar();
			system("cls"); 
		}
};
int main()
{
	Game g;
	Soldier s(1,1,1,1,1,Gun("1",1,1,1));
	g.start();
	g.Select_Soldier(s);
	g.Select_Gun(s);
	g.play_game(s);
	return 0;
}

