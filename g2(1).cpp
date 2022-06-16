#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const double pi=acos(-1);
class shape{
	public:
		virtual double area()=0;
		virtual void disp(ofstream& fout)=0;
};
class point{
	private:
		double x,y;
	public:
		point(double x,double y)
		{
			this->x=x;
			this->y=y;
		}
		double dist(const point&t)
		{
			return sqrt((x-t.x)*(x-t.x)+(y-t.y)*(y-t.y));
		}
		double getx()
		{
			return x;
		}
		double gety()
		{
			return y;
		}
};
class triangle:public shape{
	private:
		point p1,p2,p3;
	public:
		triangle(double x1,double y1,double x2,double y2,double x3,double y3):p1(x1,y1),p2(x2,y2),p3(x3,y3)
		{
			
		}
		double area()
		{
			double p=(p1.dist(p2)+p2.dist(p3)+p3.dist(p1))/2;
			return sqrt(p*(p-p1.dist(p2))*(p-p2.dist(p3))*(p-p3.dist(p1)));
		}
		void disp(ofstream& fout)
		{
			fout<<"triangle "<<p1.getx()<<" "<<p1.gety()<<" "<<p2.getx()<<" "<<p2.gety()<<" "<<p3.getx()<<" "<<p3.gety()<<endl;
		}
};
class circle:public shape{
	private:
		point center;
		double radius;
	public:
		circle(double x,double y,double r):center(x,y),radius(r)
		{
			
		}
		double area()
		{
			return pi*radius*radius;
		}
		void disp(ofstream& fout)
		{
			fout<<"circle "<<center.getx()<<" "<<center.gety()<<" "<<radius<<endl;
		}
};
class rectangle:public shape{
	private:
		point p1,p2;
	public:
		rectangle(double x1,double y1,double x2,double y2):p1(x1,y1),p2(x2,y2)
		{
			
		}
		double area()
		{
			double len1=p2.gety()-p1.gety();
			double len2=p2.getx()-p1.getx();
			return len1*len2;
		}
		void disp(ofstream& fout)
		{
			fout<<"rectangle "<<p1.getx()<<" "<<p1.gety()<<" "<<p2.getx()<<" "<<p2.gety()<<endl;
		}
};
vector <shape*> vec;
bool comp(shape* t1,shape *t2)
{
	return t1->area()<t2->area();
}
int main()
{
	ifstream fin("shape.txt");
	string str;
	while(getline(fin,str))   //先读入整整一行
	{
		shape* now;
		stringstream sin(str);  
		vector <double> vin;
		double x;
		while(sin>>x) vin.push_back(x);  //以空格为间隔，把一行分成好几份
		if(vin.size()==3) now=new circle(vin[0],vin[1],vin[2]);
		if(vin.size()==4) now=new rectangle(vin[0],vin[1],vin[2],vin[3]);
		if(vin.size()==6) now=new triangle(vin[0],vin[1],vin[2],vin[3],vin[4],vin[5]);
		vec.push_back(now);
	}
	fin.close();
	sort(vec.begin(),vec.end(),comp);
	ofstream fout("result.txt");
	for(auto it=vec.begin();it!=vec.end();it++)
		(*it)->disp(fout);
	fout.close();
	return 0;
}
