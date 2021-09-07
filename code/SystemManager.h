#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "Class.h"

class SystemManager {
public:
	//���캯��
	SystemManager();
	//��������
	~SystemManager();
	//��ʾ�˵�
	void showMenu();
	//�˳�ϵͳ
	void exitSystem();
	//��ʼ���γ̣�����¼��γ������ɼ�Ȩ��
	void initLessons(vector<Lesson>& lessons);
	//����°༶�������°༶�����ѧ��
	void addClass(vector<Lesson>& lessons);
	//��ʾ���а༶
	void showAll();
	//�����ѧ��
	void addStudent(vector<Lesson>& lessons);
	//���༶��Ų��Ұ༶
	void searchClass();
	//����������ѧ��
	void searchStudent();
	//ɾ���༶
	void deleteClass();
	//ɾ��ѧ��
	void deleteStudent();
	//�޸�ѧ����Ϣ
	void changeStudent();
	//��գ�ɾ�������а༶��Ϣ
	void clearAll();
	//��������ѡ��ѧ��
	void rankForScholarship();
	//���ɼ�����
	void sorting(Student** studentArray, int totalSize);
	//��������༶
	void chooseBestClass();

	vector<Class> myClass;  //ϵͳ�еİ༶

private:
};