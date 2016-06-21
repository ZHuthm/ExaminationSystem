#ifndef COURSE_H_
#define COURES_H_
#pragma once
#include <iostream>
#include <string>
#include "Check.h"

class Course {
private:
	// number�Ǹ��ſεı�ţ���9λ��ǰ��λ�ǿ�Ŀ��ţ���6λ���ον�ʦ���
	std::string number;
	std::string name;
	Check check;
	int time;
	std::string classID, teacherID;
public:
	// courseID�ǿ�Ŀ��ţ�teacherID�ǽ�ʦ���
	Course();
	Course(std::string nm, int t, std::string courseID, std::string teacherID);
	~Course() {}

	// ����һ�ֿ���
	void createCheck(std::string nm);
	// ɾ��һ�ֿ���
	void deleteCheck(int index);
	// ��¼�ɼ�
	void enrollScore(int index, double sc);
	// ɾ���ɼ�������ɼ����ᱻ����Ϊ0��
	void deleteScore(int index, int n);
	// ���óɼ�
	void resetScore(int index, int n, double sc);
	// ���ø�������ռ�ֱܷ���
	void resetScoreRate();
	// ��ʾһ�ֿ������
	void showCheck(int index);
	// ��ʾ�ÿγ̵ķ�������
	void showAllScore();
	// ��øÿγ̵��ܷ�
	double getScore();
	// ��ʾ���ſεĻ�����Ϣ
	void showInfo();

	std::string getName();
	void setName(std::string nm);
	int getTime();
	void setTime(int t);
	std::string getNumber();
	void setNumber(std::string courseID, std::string teacherID);
	int getCheckNum();
	std::string getTeacherID();
	std::string getClassID();
	std::string getCheckName(int index);
	double getCheckRate(int index);
	void initialCheck(std::string name[], double rate[], int size);
	double getOneScore(int index, int cindex);
	int getOneScoreNum(int index);
	void insertScore(int index, double sc);
};

#endif // COURSE_H_
