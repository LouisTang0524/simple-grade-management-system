#include <iostream>
using namespace std;
#include "SystemManager.h"

int main() {
	SystemManager manager;
	int choice = -1;

	//��ʼ���γ̣�����¼��γ������ɼ�Ȩ��
	int total;
	cout << "�����뱾ѧ�ڿγ�������";
	cin >> total;
	vector<Lesson> lessons(total);  //����һ��������������û�����Ŀγ���Ϣ
	manager.initLessons(lessons);
	system("cls");

	//�����û������ѡ�����ִ����Ӧ����
	while (true)
	{
		manager.showMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://����°༶
			manager.addClass(lessons);
			break;
		case 2://�����ѧ��
			manager.addStudent(lessons);
			break;
		case 3://��ʾ������Ϣ
			manager.showAll();
			break;
		case 4://���Ұ༶
			manager.searchClass();
			break;
		case 5://����ѧ��
			manager.searchStudent();
			break;
		case 6://ɾ���༶
			manager.deleteClass();
			break;
		case 7://ɾ��ѧ��
			manager.deleteStudent();
			break;
		case 8://�޸�ѧ����Ϣ
			manager.changeStudent();
			break;
		case 9://���ϵͳ
			manager.clearAll();
			break;
		case 10://��������ѡ��ѧ������༶����
			manager.rankForScholarship();
			{
				cout << "�Ƿ��������༶������1���ǡ�2����";
				int choice1 = 2;
				cin >> choice1;
				if (choice1 == 1) {
					manager.chooseBestClass();//��������༶
				}
				else {
					system("cls");
				}
			}
			break;
		case 0:  //�˳�ϵͳ
			manager.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}