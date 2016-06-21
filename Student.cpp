#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Student::Student(string name,string sex,string stuNum,string stuInstitude,string stuMajor,
	string stuClass,string password):Person(name,sex)
{
	this->stuNum=stuNum;
	this->stuInstitude=stuInstitude;
	this->stuMajor=stuMajor;
	this->stuClass=stuClass;
	this->classSum=0;
	this->password=password;
}

/*��ȡ������Ϣ*/
string Student::getStuNum()
{
	return this->stuNum;
}
int Student::getClassSum()
{
	return this->classSum;
}
string Student::getPassword()
{
	return this->password;
}
string Student::getStuInstitude()
{
	return this->stuInstitude;
}
string Student::getStuMajor()
{
	return this->stuMajor;
}
string Student::getStuClass()
{
	return this->stuClass;
}

/*����������Ϣ*/
void Student::setStuNum(string newNum)
{
	this->stuNum=newNum;
}
void Student::setClassSum(int newNum)
{
	this->classSum=newNum;
}
void Student::setPassword(string newPassword)
{
	this->password=newPassword;
}
void Student::setStuInstitude(string newInstitude)
{
	this->stuInstitude=newInstitude;
}
void Student::setStuMajor(string newMajor)
{
	this->stuMajor=newMajor;
}
void Student::setStuClass(string newClass)
{
	this->stuClass=newClass;
}
void Student::setAllData(string name,string sex,string stuNum,string stuInstitude,string stuMajor,string stuClass,string password)
{
	this->name=name;
	this->sex=sex;
	this->stuNum=stuNum;
	this->stuInstitude=stuInstitude;
	this->stuMajor=stuMajor;
	this->stuClass=stuClass;
	this->password=password;
	this->classSum=0;
}

/*��Ա����*/
void Student::showStuInfo()			//���ѧ��������Ϣ��ѧ�š��������Ա�ѧԺ��רҵ���༶��
{
	cout<<setw(10)<<this->stuNum<<setw(8)<<this->name<<setw(6)<<this->sex<<setw(14)<<this->stuInstitude
		<<setw(12)<<this->stuMajor<<setw(12)<<this->stuClass<<endl;
}
void Student::showAllCourses()				//�������ÿ�ſγ̵Ŀγ̱�źͿγ�����
{
	for(int i=0;i<this->classSum;i++)
	{
		cout<<setw(5)<<i+1<<"."<<setw(12)<<this->courses[i].getNumber()<<setw(15)<<this->courses[i].getName()<<endl;
	}
	cout<<endl;
}
void Student::addCourse(Course &c)						//��ӿγ�
{
	this->courses.push_back(c);
	this->classSum++;
}
void Student::deleCourse(Course &c)					//ɾ���γ�
{
	int loc;
	if(this->is_ExistCourse(c,loc))			//�жϸ�ѧ���Ƿ�������ſγ̣�loc��¼���ſγ���vector�е�λ�ã���������loc=-1;
	{
		vector<Course>::iterator it=courses.begin()+loc;
		courses.erase(it);
		this->classSum--;
	}else
	{
		cout<<this->name<<"û��<"<<c.getName()<<">���ſγ�"<<endl;
	}
}
bool Student::is_ExistCourse(Course &c,int &index)				//�жϸ�ѧ���Ƿ������ſ�;���ڣ���index��¼��λ�ã������ڣ�index=-1
{
	for(index=0;index<this->classSum;index++)
	{
		if(courses[index].getNumber()==c.getNumber())	return true;		// if�γ̱��ƥ��
	}
	index=-1;
	return false;
}
bool Student::is_ExistCourse(Course &c)				//�жϸ�ѧ���Ƿ������ſ�
{
	for(int i=0;i<this->classSum;i++)
	{
		if(courses[i].getNumber()==c.getNumber())	return true;		// if�γ̱��ƥ��
	}
	return false;
}
bool Student::is_IDPass(string password)					//�����Ƿ���֤ͨ��
{
	if(this->password==password) return true;
	else return false;
}

/****************************CZH��****************************/
void Student::showAllCoursesScore()				
{
	for (int i = 0; i < this->classSum; i++)
	{
		cout << setw(5) << i + 1 << "." << setw(12) << this->courses[i].getNumber() << setw(15) << this->courses[i].getName() <<setw(6)<<courses[i].getScore()<< endl;
	}
	cout << endl;
}