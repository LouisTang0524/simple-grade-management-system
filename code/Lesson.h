#pragma once
#include <string>
#include <iostream>
using namespace std;

class Lesson {
public:
	//���캯��
	Lesson();
	//���ƹ��캯��
	Lesson(const Lesson& l);
	//��������
	~Lesson();
	//����Ȩ��
	void setWeight(double weight);
	//��ȡȨ��
	double getWeight();
	//���ÿγ���
	void setName(string name);
	//��ȡ�γ���
	string getName();
	//���ÿγ̳ɼ�
	void setGrade(int grade);
	//��ȡ�γ̳ɼ�
	int getGrade();
	//�ж��Ƿ񼰸�
	bool isPassed();
private:
	string l_Name;  //�γ���
	double l_Weight;  //�γ̳ɼ�Ȩ��
	int l_Grade;  //�γ̳ɼ�
};