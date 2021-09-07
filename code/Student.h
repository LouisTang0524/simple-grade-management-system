#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Lesson.h"

class Student {
public:
	//���캯��
	Student();
	//��������
	~Student();
	//��������
	void setName(string name);
	//��ȡ����
	string getName();
	//��ȡѧ����ƽ���ɼ�
	double getAverageGrade();
	//����ѧ�����ſεĳɼ�
	void setGrade(vector<Lesson>& lessons);
	//��ʾѧ����Ϣ
	void showStudent();
	//�޸�ѧ����Ϣ
	void changeStudent();
	//����ѧ���Ƿ��ý�ѧ��
	void setHasScholarship(bool hasScholarship);
	//��ȡѧ���Ƿ��ý�ѧ��
	bool getHasScholarship();
	//��ȡѧ���Ƿ�ȫ���γ̶�����
	bool getIsPassed();

	vector<Lesson> myLesson;  //ѧ���Ŀγ���ɵ�����

private:
	string s_Name;  //ѧ������
	double s_AverageGrade;  //��Ȩ��ѧ����ƽ���ɼ�
	bool s_hasScholarship;  //�Ƿ��ý�ѧ��
	bool s_isPassed;  //�Ƿ�ȫ���γ̶�����

};