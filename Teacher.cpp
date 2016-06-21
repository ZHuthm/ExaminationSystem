#include "Teacher.h"
#include <iomanip>
#include <cstdio>

Teacher::Teacher(string name,string sex,string workNum,string password):Person(name,sex)
{
	this->workNum=workNum;
	this->classSum=0;
	this->stuSum=0;
	this->password=password;
}
Teacher::~Teacher()
{
	 
}

/*��Ա���Ի�ȡ*/
string Teacher::getWorkNum()
{
	return this->workNum;
}
string Teacher::getPassword()
{
	return this->password;
}
int Teacher::getClassSum()
{
	return this->classSum;
}
string Teacher::getCourseName(int index)				//��ȡ��ʦ���̵�index���γ̵Ŀ�Ŀ����
{
	return this->courses[index].getName();
}
string Teacher::getCourseClassNum(int index)		//��ȡ��ʦ���̵�index���γ̵İ༶����
{
	//return courses[in.size();
	return "aa";
}


/*��Ա�����޸�*/
void Teacher::setWorkNum(string workNum)
{
	this->workNum=workNum;
}
void Teacher::setPassword(string password)
{
	this->password=password;
}
void Teacher::setClassSum(int classSum)
{
	this->classSum=classSum;
}
void Teacher::setAllData(string name,string sex,string workNum,int classSum,string password)		//���ý�ʦ���л�����Ϣ
{
	this->name=name;
	this->sex=sex;
	this->workNum=workNum;
	this->classSum=classSum;
	this->password=password;
}

/*��Ա����*/
void Teacher::showTeacherInfo()											//��ӡ��ʦ������Ϣ�����š��������Ա����̿�Ŀ��
{
	cout<<setw(8)<<this->workNum<<setw(8)<<this->name<<setw(6)<<this->sex<<"   ";
	for (int i = 0; i < this->classSum; i++)
		cout << left << setw(10) << courses[i].getName();
	cout << right << endl;
}
void Teacher::showTeacherAllCourses()					//��ӡ��ʦ�����еĿγ����ƣ������γ�vector�����ÿγ̵�print������
{
	for(int i=0;i<this->classSum;i++)
	{
		cout<<"���γ�"<<i+1<<"��"<<endl;
		courses[i].showInfo();
	}
	cout<<endl;
}
//void showScore();												//��ӡĳ�ſ��µ�����ѧ������
//void showCourseOfStudents();							//��ӡĳ�ſ��µ�����ѧ��

//void Teacher::amendCheck()												//�޸Ŀ��˱�׼
//{
//}
//void Teacher::copy(Teacher &t)											//��㿽�������ã�
void Teacher::addCourse(Course &c)									//���ӿγ̣�����һ���γ̣�Ȼ����Ҫ������γ̼ӵ���Ŀγ�vector��ߣ�
{
	courses.push_back(c);
	this->classSum++;
}
void Teacher::deleteCourse(Course &c)								//ɾ��ĳһ�ſγ̣��ȱ�����ʦ�µ�ѧ��vector����ɾ����ʦ�Ŀγ̼�¼��
{
	int loc;
	if(this->is_ExistCourse(c,loc))
	{
		for (int i = 0; i < students.size(); i++)
		{
			Student stu = *students[i];
			if (stu.is_ExistCourse(c))
			{
				stu.deleCourse(c);
			}
		}
		vector<Course>::iterator iter=courses.begin()+loc;
		courses.erase(iter);
		this->classSum--;
	}else
	{
		cout << this->name << "��ʦû��<" << c.getName() << ">���ſγ�" << endl;
	}
}
bool Teacher::is_ExistCourse(Course &c,int &index)				//�жϸý�ʦ�Ƿ������ſ�;���ڣ���index��¼��λ�ã������ڣ�index=-1
{
	for(index=0;index<this->classSum;index++)
	{
		if(courses[index].getNumber()==c.getNumber())	return true;		// if�γ̱��ƥ��
	}
	index=-1;
	return false;
}
bool Teacher::is_ExistCourse(Course &c)				//�жϸý�ʦ�Ƿ������ſ�
{
	for(int i=0;i<this->classSum;i++)
	{
		if(courses[i].getNumber()==c.getNumber())	return true;		// if�γ̱��ƥ��
	}
	return false;
}

void Teacher::addStudent(Student &s)
{
	students.push_back(&s);
	this->stuSum++;
}
void Teacher::deleStudent(Student &s)
{
	int loc;			//��¼ѧ��λ��
	if(this->is_ExistStudent(s,loc))
	{
		vector<Student*>::iterator it=students.begin()+loc;
		
		this->stuSum--;
		this->students.erase(it);
	}else
	{
		cout<<this->name<<"��ʦû��"<<s.getName()<<"ѧ����ɾ��ʧ��"<<endl;
	}
}
bool Teacher::is_ExistStudent(Student &s,int &index)				//�жϸý�ʦ�Ƿ������ѧ��;���ڣ���index��¼��λ�ã������ڣ�index=-1
{
	for(index=0;index<this->students.size();index++)
	{
		if((*students[index]).getStuNum()==s.getStuNum())	return true;		// if�γ̱��ƥ��
	}
	index=-1;
	return false;
}
bool Teacher::is_ExistStudent(Student &s)				//�жϸý�ʦ�Ƿ������ѧ��
{
	for(int i=0;i<this->students.size();i++)
	{
		if((*students[i]).getStuNum()==s.getStuNum())	return true;		// if�γ̱��ƥ��
	}
	return false;
}

bool Teacher::addStuMark()					//���ĳ��ѧ����ĳ�ſγ��µ�ĳ��ɼ����Ҳ���ѧ�����γ̡�������Ŀʱ�������ʾ��Ϣ��������false
{		//ѧ��->�γ�->��Ŀ->��ӳɼ�
	if(students.size()<=0) 
	{
		cout<<"����ʦ��û���κ�ѧ�����޷����ѧ���ɼ���"<<endl;
		system("pause");
		return false;
	}
	
	cout<<setw(5)<<"���"<<setw(10)<<"ѧ��"<<setw(8)<<"����"<<setw(4)<<"�Ա�"<<setw(14)<<"ѧԺ"
	<<setw(12)<<"רҵ"<<setw(12)<<"�༶"<<endl;
	for(int i=0;i<students.size();i++)
	{
		cout<<setw(4)<<i+1<<".";
		students[i]->showStuInfo();
	}
	cout<<endl;

	bool flag=true;			//�����ж������Ƿ����
	string answer;
	string NO_len;
	do{
		cout<<"��������Ҫ��ӳɼ�ѧ���ı�ţ�";
		cin>>answer;
		char temp_num[20];			//��ѧ������(int)ת��Ϊ(string)��NO_Len
		sprintf_s(temp_num,"%d",students.size());
		NO_len=temp_num;
		if( ! (answer>="1" && answer<= NO_len ) )		
		{
			cout<<"����������룡"<<endl;
			system("pause");
			flag=0;
		}else flag=1;
	}while(flag==0);
	int index1= atoi(answer.c_str()) -1;		//���-1=����λ��
	
	if(students[index1]->courses.size()<=0)
	{
		cout<<students[index1]->getName()<<"û�вμ��κογ̣��޷���ӳɼ���"<<endl;
		system("pause");
		return false;
	}

	cout<<setw(6)<<"���"<<setw(12)<<"�γ̱��"<<setw(15)<<"�γ�����"<<endl;
	students[index1]->showAllCourses();			//��ӡindex1��ѧ�������пγ�
	flag=true;			//��ʼ��flag
	do{
		cout<<"������"<<students[index1]->getName()<<"��Ҫ��ӳɼ��Ŀγ̱�ţ�";
		cin>>answer;
		char temp_num[20];
		sprintf_s(temp_num,"%d",students[index1]->getClassSum());
		NO_len=temp_num;
		if(!(answer>="1"&&answer<=NO_len))		//+1+'0'ʹ��Ŵ�����תΪ�ַ�������answer���бȽ�
		{
			cout<<"����������룡"<<endl;
			system("pause");
			flag=0;
		}else flag=1;
	}while(flag==0);

	int index2=atoi(answer.c_str())-1;			//��ʦ����ѧ�� ѧ�������γ� index1Ϊѧ���±�  index2Ϊ�γ��±�
	if(students[index1]->courses[index2].getCheckNum()<=0)			
	{
		cout<<students[index1]->getName()<<"ѧ����"<<students[index1]->courses[index2].getName()<<"����û�п�����Ŀ��"
			<<"�޷���ӳɼ���"<<endl;
		system("pause");
		return false;
	}
	
	students[index1]->courses[index2].showAllScore();
	flag=true;			//��ʼ��flag
	do{
		cout<<"������"<<students[index1]->getName()<<"��Ҫ���"
			<<students[index1]->courses[index2].getName()<<"�ɼ�����Ŀ��ţ�";
		cin>>answer;
		char temp_num[20];
		sprintf_s(temp_num,"%d",students[index1]->courses[index2].getCheckNum());
		NO_len=temp_num;
		if(!(answer>="1"&&answer<=NO_len))		//+1+'0'ʹ��Ŵ�����תΪ�ַ�������answer���бȽ�
		{
			cout<<"����������룡"<<endl;
			system("pasue");
			flag=0;
		}else flag=1;
	}while(flag==0);
	int index3= atoi(answer.c_str()) -1;		//indexΪĳѧ��ĳ�ſ��µĵ� index3 ��������Ŀ

	double inScore;
	while(1)
	{
		cout<<"��������ĳɼ���";
		cin>>inScore;
		if(inScore<=100&&inScore>=0) break;
		else
		{
			cout<<"����������롣�������������������ĳɼ�"<<endl;
			system("pause");
		}
	}
	students[index1]->courses[index2].enrollScore(index3,inScore);
	cout<<"�����ɼ�¼��ɹ�����"<<endl;
	students[index1]->courses[index2].showAllScore();
	system("pause");
	return true;
}

bool Teacher::is_IDPass(string password)							//�����Ƿ���֤ͨ��
{
	if(this->password==password) return true;
	else return false;
}

string Teacher::getCourseID(int index)
{
	return courses[index].getNumber();
}

int Teacher::getCourseTime(int index)
{
	return courses[index].getTime();
}

int Teacher::getCourseCheckNum(int index)
{
	return courses[index].getCheckNum();
}

string Teacher::getCheckName(int index, int cindex)
{
	return courses[index].getCheckName(cindex);
}

double Teacher::getCheckRate(int index, int cindex)
{
	return courses[index].getCheckRate(cindex);
}

string Teacher::getClassID(int index)
{
	return courses[index].getClassID();
}

string Teacher::getTeachID(int index)
{
	return courses[index].getTeacherID();
}

void Teacher::initialCheck(string name[], double rate[], int size, int index)
{
	courses[index].initialCheck(name, rate, size);
}

void Teacher::setCourse(string name, string cID, string tID, int time)
{
	Course c(name, time, cID, tID);
	courses.push_back(c);
}
