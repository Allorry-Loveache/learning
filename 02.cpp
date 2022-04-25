/*
	�غ���ս����Ϸ
	�������� ս���� ����ֵ ǹ
	ǹ���� ���� ɱ���� �������� ��ǰ�ص���
	�������� ����ֵ ����ֵ ������ ������䵯��
	ս������ �����ܹ��Թ�������˺������� ս����+����ֵ ���ڹ���ֵ
	ÿ�����߶Թ������ǹɱ�������˺� ÿ�ι���ʹ��һ���ӵ� 
	����ÿ�غϿ��Զ����ߵ�ս������ɹ��������½�
	�����ߵĲ����ԶԹ�������˺�ʱ �ͻᱻ�������� ��Ϸ����
	�����߻��ܹ���ʱ ���ߵ�ս����������������ֵ ���һ�ù������ϵĵ��� 
	���߾����������� ��ս��������һ����ֵ�Ϳ������� ���Ҳ�������ֵ�ĳɳ� 
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
				cout<<"�������� ��ǰ�ȼ�Ϊ"<<level<<endl;
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
			cout<<"Ŀǰ�������ԣ�force["<<force<<"]��experience["<<experience<<"]"<<endl;
			_sleep(500);
			cout<<"Ŀǰ��ӵ�еĵ���������"<<this->bullet_num<<endl;
			_sleep(500);
			cout<<"չʾ������������"<<endl;
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
			cout<<"����["<<id<<"]������ֵΪ"<<hp<<"��������Ϊ"<<attack<<"����������õ�ս����Ϊ��"<<force<<endl;
			_sleep(500);
			cout<<"������ֻ��������Ի��"<<bullet_num<<"�ĵ��в���"<<endl;
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
			cout<<"�����ѡ����������"<<endl;
			cout<<"����[1]������������ ӵ�нϸߵĳ�ʼս���� �����������ӵľ���ֵ�Ƚϵ�"<<endl;
			cout<<"����[2]���ɳ������� �������Ի�þ޶�ľ���ֵ ���ǳ�ʼս�����ϵ�"<<endl;
			cout<<"����[3]������������ ƽƽ���������"<<endl;
			string name[]={"","����������","�ɳ�������","����������"};
			int x;
			cin>>x;
			system("cls");
			cout<<"��ѡ����"<<name[x]<<endl;
			if(x==1) s.set_Soldier(1,2000,0,50,5,2);
			if(x==2) s.set_Soldier(1,1000,0,400,5,1);
			if(x==3) s.set_Soldier(1,1500,0,100,5,1);
		}
		void Select_Gun(Soldier &s)
		{
			_sleep(1000);
			system("cls"); 
			cout<<"����Ϊ��������ѡ��һ��ǹ"<<endl;
			Gun USP("USP",40,20,20);
			Gun UZI("UZI",10,40,40);
			cout<<"����[1]�����ǹеUSP"<<endl;
			USP.disp(); 
			cout<<"����[2]�����ǹеUZI"<<endl;
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
				cout<<"����ʹ��ǹе���� �������ֵ��п��ˣ�"<<endl;
				return;
			}
			cout<<"����ʹ��ǹе["<<s.get_gun_name()<<"]��������"<<endl;
			_sleep(500); 
			int w=s.fire();
			cout<<"���߶Թ��������["<<w<<"]�˺�"<<endl;
			m.modify_hp(w);
			int r=rand()%2;
			if(r)
			{
				_sleep(500);
				cout<<"Ч����Ⱥ���Թ�������˶���["<<int(0.8*w)<<"]�˺�"<<endl; 
				m.modify_hp(0.8*w);
			}
		}
		bool Soldier_run()
		{
			int x=rand()%2;
			if(x)
			{
				cout<<"����ʹ��������ս����"<<endl;
				_sleep(1000);
				cout<<"���ѳɹ���"<<endl;
				return 1;
			}
			else
			{
				cout<<"����ʹ��������ս����"<<endl;
				_sleep(1000);
				cout<<"����ʧ�ܣ�"<<endl;
				return 1;
			}
		}
		void monster_attack(Soldier &s,monster &m)
		{
			cout<<"����ʹ���˹����ͻ�"<<endl;
			_sleep(1000);
			cout<<"��������������["<<m.get_attack()<<"]�˺�"<<endl;
			s.change_force(m.get_attack());
			_sleep(1000);
			int r=rand()%2;
			if(r)
			{
				s.change_force(0.8*m.get_attack());
				cout<<"���������������ٴζ����������["<<0.8*m.get_attack()<<"]�˺�"<<endl;
				_sleep(1000);
			}
		}
		void Soldier_load(Soldier &s)
		{
			if(s.load()) cout<<"�ϵ��ɹ���"<<endl;
			else cout<<"������������ �ϵ�ʧ�ܣ�"<<endl;
			_sleep(1000);
		}
		void end_game()
		{
			cout<<"��Ϸ����"<<endl; 
			exit(0);
		}
		int fight(Soldier &s,monster &m)
		{
			while(1)
			{
			    system("cls");
				if(s.get_fpe()<=m.get_force())
				{
					cout<<"�޷����ܹ��� ����������"<<endl;
					_sleep(2000);
					return -1;
				}
				int opt;
				cout<<"��������չʾ"<<endl;
				s.disp();
				cout<<"��������չʾ"<<endl;
				m.disp();
				cout<<"��������Ļغϣ�"<<endl;
				cout<<"����[1]���Թ������ǹе������"<<endl;
				cout<<"����[2]����ǹе�����ϵ���"<<endl;
				cout<<"����[3]������ս�����ˣ�"<<endl;
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
					cout<<"���ܹ����ù���Я������ ���ս����������"<<endl;
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
				cout<<"ѡ��һ�����￪ʼս��"<<endl;
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
			cout<<"��ӭ�������ߵ�ð����;"<<endl;
			cout<<"����������ʼ��Ϸ"<<endl;
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

