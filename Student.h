#pragma once
#include <iostream>
#include "Person.h"
#include "Course.h"
#include <vector>
using namespace std;

class Student: public Person		//�̳�ӵ��name��sex����
{
private:
	string stuNum;							//ѧ��
	int classSum;							//�γ�����
	string stuInstitude;					//ѧԺ
	string stuMajor;						//רҵ
	string stuClass;							//�༶
	string password;						//��¼����

	
public:
	vector<Course> courses;			//ѧ����Ҫ�ϵĿγ�
	/*���캯��*/
	Student(string name="Unknown",string sex="Sex",string stuNum="150101",string stuInstitude="Unknown",string stuMajor="Unknown",
		string stuClass="Unknown",string password="150000");
	//~Student();

	/*��ȡ������Ϣ*/
	string getStuNum();
	int getClassSum();
	string getPassword();
	string getStuInstitude();
	string getStuMajor();
	string getStuClass();

	/*����������Ϣ*/
	void setStuNum(string newNum);
	void setClassSum(int newNum);
	void setPassword(string newPassword);
	void setStuInstitude(string newInstitude);
	void setStuMajor(string newMajor);
	void setStuClass(string newClass);
	void setAllData(string name,string sex,string stuNum,string stuInstitude,string stuMajor,string stuClass,string password);
	
	/*��Ա����*/
	void showStuInfo();									//���ѧ��������Ϣ��ѧ�š��������Ա�ѧԺ��רҵ���༶��
	void showAllCourses();								//������пγ�����

	bool is_ExistCourse(Course &c,int& index);	//�жϸ�ѧ���Ƿ������ſ�; �����ڣ���index��¼��λ�ã���������index=-1	
	bool is_ExistCourse(Course &c);					//�жϸ�ѧ���Ƿ������ſΣ�����¼�γ�λ�ã�
	bool is_IDPass(string password);				//�����Ƿ���֤ͨ��
	void addCourse(Course &c);						//��ӿγ�
	void deleCourse(Course &c);						//ɾ���γ�

	void deleCourse(int i)
	{
		deleCourse(courses[i]);
	}

	bool is_CourseEmpty()
	{
		if (courses.empty()) return true;
		else return false;
	}


	void showAllCoursesScore();
};