#pragma once
#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Course.h"
#include <vector>
using namespace std;

class Teacher: public Person			//�̳�ӵ��name��sex����
{
private:
	string workNum;									//����
	int classSum;										//�γ�����
	int stuSum;											//ѧ������
	string password;									//��¼����
	vector<Course> courses;						//�γ�����
	vector<Student*> students;					//ѧ������
public:

	/*���캯��*/
	Teacher(string name="Unknown",string sex="Unknown",string workNum="100100",string password="000000");
	~Teacher();
	
	/*��Ա���Ի�ȡ*/
	string getWorkNum();
	string getPassword();
	int getClassSum();
	string getCourseName(int index);				//��ȡ��ʦ���̵�index���γ̵Ŀ�Ŀ����
	string getCourseClassNum(int index);		//��ȡ��ʦ���̵�index���γ̵İ༶����

	/*��Ա�����޸�*/
	void setWorkNum(string workNum);
	void setPassword(string password);
	void setClassSum(int sum);
	void setAllData(string name,string sex,string workNum,int classSum,string password);		//���ý�ʦ���л�����Ϣ

	/*��Ա����*/
	void showTeacherInfo();										//��ӡ��ʦ������Ϣ�����š��������Ա����̿�Ŀ��
	void showTeacherAllCourses();								//��ӡ��ʦ�����еĿγ����ƣ������γ�vector�����ÿγ̵�print������
	void showScore();													//��ӡĳ�ſ��µ�����ѧ������
	
	void addCourse(Course &c);									//���ӿγ�
	void deleteCourse(Course &c);								//ɾ��ĳһ�ſγ�
	bool is_ExistCourse(Course &c,int &index);			//�ж��Ƿ���ڿγ�c�������ڣ���index��¼��λ�ã�����������index=-1;
	bool is_ExistCourse(Course &c);							//�ж��Ƿ���ڿγ�c������¼�γ�λ�ã�

	void addStudent(Student &s);								//����һ��ѧ��
	void deleStudent(Student &s);								//ɾ��һ��ѧ��
	bool is_ExistStudent(Student &s);							//�ж��Ƿ����ѧ��s������¼�γ�λ�ã�
	bool is_ExistStudent(Student &s,int &index);			//�ж��Ƿ����ѧ��s�������ڣ���index��¼��λ�ã�����������index=-1;

	bool addStuMark();												//���ĳ��ѧ����ĳ�ſγ��µ�ĳ��ɼ����Ҳ���ѧ�����γ̡�������Ŀʱ�������ʾ��Ϣ��������false

	bool is_IDPass(string password);							//�����Ƿ���֤ͨ��
	
	//void showCourseOfStudents();							//��ӡĳ�ſ��µ�����ѧ��
	/*
	void amendCheck();												//�޸Ŀ��˱�׼
	void copy(Teacher &t);											//��㿽�������ã�
	*/

	//********************************************CZH��

	bool is_CourseEmpty()
	{
		if (courses.empty()) return true;
		else return false;
	}

	bool ofr(int n)//����±��Ƿ�Խ��
	{
		if (n < 1 || n > courses.size()) { cout << "���������������룡\n"; return true;}
		else { system("cls"); return false; }
	}

	void showCourseInfo(int n)
	{
		courses[n - 1].showInfo();
	}

	void createCheck(int n,string nm)
	{
		courses[n - 1].createCheck(nm);
	}

	void delCheck(int n, int index)
	{
		courses[n - 1].deleteCheck(index);
	}

	void resetScoreRate(int n)
	{
		courses[n - 1].resetScoreRate();
	}

	void syncCourse(Course &myCourse, int n)
	{
		if (myCourse.getNumber() == courses[n - 1].getNumber())
			myCourse = courses[n - 1];
	}
	//***************************************************ZiQin ���� 2016-6-21
	string getCourseID(int index);
	int getCourseTime(int index);
	int getCourseCheckNum(int index);
	string getCheckName(int index, int cindex);
	double getCheckRate(int index, int cindex);
	string getClassID(int index);
	string getTeachID(int index);
	void initialCheck(string name[], double rate[], int size, int index);
	void setCourse(string name, string cID, string tID, int time);
};