#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Student.h"

class Class {
public:
	//���캯��
	Class();
	//��������
	~Class();
	//���ѧ��
	void addStudent(vector<Lesson>& lessons);
	//���ð༶���
	void setClassId(int id);
	//��ȡ�༶���
	int getClassId();
	//��ȡ�༶����
	int getClassSize();
	//��ʾ�༶��Ϣ��ѧ����Ϣ
	void showClass();
	//�༶������һ
	void increaseClassSize();
	//�༶������һ
	void decreaseClassSize();
	//���㱾���л�ý�ѧ�������
	void setScholarshipStudent();
	//��ȡ�����л�ý�ѧ�������
	int getScholarshipStudent();
	//����༶�÷�
	void calculateClassScore();
	//��ȡ�༶�÷�
	double getClassScore();

	vector<Student> myStudent;  //�ð༶��ѧ����ɵ�����

private:
	int classSize;  //�༶������
	int classId;  //�༶���
	int scholarshipStudent;  //��ý�ѧ�������
	double classScore;  //�༶�÷�

};