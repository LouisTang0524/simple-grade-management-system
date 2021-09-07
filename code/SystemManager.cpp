#include "SystemManager.h"
#include "Class.h"
#define TOTAL_SCHOLARSHIP 10

SystemManager::SystemManager() {

}

SystemManager::~SystemManager() {

}

//��ʾ�˵�
void SystemManager::showMenu() {
	cout << "-------�༶�ɼ�����---------" << endl;
	cout << "============================" << endl;
	cout << "-------1.����°༶---------" << endl;
	cout << "-------2.�����ѧ��---------" << endl;
	cout << "-------3.��ʾ������Ϣ-------" << endl;
	cout << "-------4.���Ұ༶-----------" << endl;
	cout << "-------5.����ѧ��-----------" << endl;
	cout << "-------6.ɾ���༶-----------" << endl;
	cout << "-------7.ɾ��ѧ��-----------" << endl;
	cout << "-------8.�޸�ѧ����Ϣ-------" << endl;
	cout << "-------9.���ϵͳ-----------" << endl;
	cout << "-------10.��ѡ��ѧ��--------" << endl;
	cout << "-------0.�˳�ϵͳ-----------" << endl;
	cout << "============================" << endl;
}

//�˳�ϵͳ
void SystemManager::exitSystem() {
	cout << "��ӭ�´�ʹ�á�" << endl;
	system("pause");
	exit(0);
}

//��ʼ���γ̣�����¼��γ������ɼ�Ȩ��
void SystemManager::initLessons(vector<Lesson>& lessons) {
	//int total;
	//cout << "�����뱾ѧ�ڿγ�������";
	//cin >> total;
	//vector<Lesson> lessons(total);
	for (size_t i = 0; i < lessons.size(); i++) {
		cout << "�������" << i + 1 << "�ſγ�����";
		string name;
		cin >> name;
		lessons[i].setName(name);
		cout << "�������" << i + 1 << "�ſγ̵ĳɼ�Ȩ�أ�С��1��С������";
		double weight;
		cin >> weight;
		lessons[i].setWeight(weight);
		lessons[i].setGrade(0);
	}
}

//��Ӱ༶
void SystemManager::addClass(vector<Lesson>& lessons) {
	Class newClass;
	cout << "������༶��ţ�" << endl;
	int id;
	cin >> id;

	newClass.setClassId(id);
	myClass.push_back(newClass);
	myClass.back().addStudent(lessons);

	system("pause");
	system("cls");
}

//��ʾ���а༶
void SystemManager::showAll() {
	if (myClass.size() == 0) {
		cout << "ϵͳ�����κ���Ϣ" << endl;
	}
	else {
		for (size_t i = 0; i < myClass.size(); i++) {
			myClass[i].showClass();
		}
	}

	system("pause");
	system("cls");
}

//�����ѧ����������༶����
//����ҵ������ѧ��
//���û�ҵ�����ӣ�����ӡ��ʾ��Ϣ
void SystemManager::addStudent(vector<Lesson>& lessons) {
	cout << "������༶��ţ�" << endl;
	int id;
	cin >> id;

	bool flag = false;
	size_t i;
	for (i = 0; i < myClass.size(); i++) {
		if (id == myClass[i].getClassId()) {
			myClass[i].addStudent(lessons);
			flag = true;
			break;
		}
	}
	if (!flag) {
		cout << "���޴˰࣬������Ӱ༶" << endl;
	}

	system("pause");
	system("cls");
}

//���༶��Ų��Ұ༶
//����ҵ����ӡ�ð༶��������Ϣ
//����Ҳ������ӡ��ʾ��Ϣ
void SystemManager::searchClass() {
	if (myClass.size() == 0) {
		cout << "ϵͳ�����κ���Ϣ" << endl;
	}
	else {
		cout << "������༶��ţ�" << endl;
		int id;
		cin >> id;

		bool flag = false;
		size_t i;
		for (i = 0; i < myClass.size(); i++) {
			if (id == myClass[i].getClassId()) {
				myClass[i].showClass();
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "���޴˰�" << endl;
		}

	}

	system("pause");
	system("cls");
}

//����������ѧ��
//����ҵ����ӡ��ѧ������Ϣ
//����Ҳ������ӡ��ʾ��Ϣ
void SystemManager::searchStudent() {
	if (myClass.size() == 0) {
		cout << "ϵͳ�����κ���Ϣ" << endl;
	}
	else {
		cout << "������������" << endl;
		string name;
		cin >> name;

		bool flag = false;
		size_t i, j;
		for (i = 0; i < myClass.size(); i++) {
			for (j = 0; j < myClass[i].myStudent.size(); j++) {
				if (name == myClass[i].myStudent[j].getName()) {
					myClass[i].myStudent[j].showStudent();
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (!flag) {
			cout << "���޴���" << endl;
		}

	}

	system("pause");
	system("cls");
}

//ɾ���༶���Ȱ��հ༶��Ų��Ұ༶
//����ҵ��������ʾ��Ϣ���û��ٴ�ȷ�ϣ�ȷ�Ϻ�ִ��ɾ��������ִ��
//����Ҳ����������ʾ��Ϣ
void SystemManager::deleteClass() {
	if (myClass.size() == 0) {
		cout << "ϵͳ�����κ���Ϣ" << endl;
	}
	else {
		cout << "������༶��ţ�" << endl;
		int id;
		cin >> id;

		bool flag = false;
		size_t i;
		int choice = 2;
		for (i = 0; i < myClass.size(); i++) {
			if (id == myClass[i].getClassId()) {
				myClass[i].showClass();
				flag = true;
				cout << "ȷ��ɾ����1���ǡ�2����";
				cin >> choice;
				if (choice == 1) {
					myClass.erase(myClass.begin() + i);
					cout << "ɾ���ɹ�" << endl;
					break;
				}
			}
		}
		if (!flag) {
			cout << "���޴˰�" << endl;
		}

	}

	system("pause");
	system("cls");
}

//ɾ��ѧ�����Ȱ���ѧ����������
//����ҵ��������ʾ��Ϣ���û��ٴ�ȷ�ϣ�ȷ�Ϻ�ִ��ɾ��������ִ��
//����Ҳ����������ʾ��Ϣ
void SystemManager::deleteStudent() {
	if (myClass.size() == 0) {
		cout << "ϵͳ�����κ���Ϣ" << endl;
	}
	else {
		cout << "������������" << endl;
		string name;
		cin >> name;

		bool flag = false;
		size_t i, j;
		int choice = 2;
		for (i = 0; i < myClass.size(); i++) {
			for (j = 0; j < myClass[i].myStudent.size(); j++) {
				if (name == myClass[i].myStudent[j].getName()) {
					myClass[i].myStudent[j].showStudent();
					flag = true;
					cout << "ȷ��ɾ����1���ǡ�2����";
					cin >> choice;
					if (choice == 1) {
						myClass[i].myStudent.erase(myClass[i].myStudent.begin() + j);
						myClass[i].decreaseClassSize();
						cout << "ɾ���ɹ�" << endl;
					}
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (!flag) {
			cout << "���޴���" << endl;
		}

	}

	system("pause");
	system("cls");
}

//�޸�ѧ����Ϣ���Ȱ�����������
//����ҵ���ִ���޸Ĳ���
//����Ҳ������ӡ��ʾ��Ϣ
void SystemManager::changeStudent() {
	if (myClass.size() == 0) {
		cout << "ϵͳ�����κ���Ϣ" << endl;
	}
	else {
		cout << "������������" << endl;
		string name;
		cin >> name;
		bool flag = false;
		size_t i, j;
		for (i = 0; i < myClass.size(); i++) {
			for (j = 0; j < myClass[i].myStudent.size(); j++) {
				if (name == myClass[i].myStudent[j].getName()) {
					myClass[i].myStudent[j].showStudent();
					myClass[i].myStudent[j].changeStudent();
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (!flag) {
			cout << "���޴���" << endl;
		}

	}

	system("pause");
	system("cls");

}

//��գ�ɾ�������а༶��Ϣ
//ִ�в���ǰ�����ʾ��Ϣ���û�ȷ���Ƿ�ִ����ղ���
//������ִ�в�����������ִ��
void SystemManager::clearAll() {
	if (myClass.size() == 0) {
		cout << "ϵͳ�����κ���Ϣ" << endl;
	}
	else {
		cout << "�Ƿ�ȷ����գ�1���ǡ�2����";
		int choice = 2;
		cin >> choice;
		if (choice == 1) {
			myClass.clear();
			cout << "��ճɹ�" << endl;
		}
	}

	system("pause");
	system("cls");
}

//��ѡ��ѧ��
//������ѧ���������У�ǰʮ����ý�ѧ��
void SystemManager::rankForScholarship() {
	if (myClass.size() == 0) {
		cout << "ϵͳ�����κ���Ϣ" << endl;
		system("pause");
		system("cls");
		return;
	}
	int totalSize = 0;
	for (size_t i = 0; i < myClass.size(); i++) {
		totalSize += myClass[i].getClassSize();
	}  //����ϵͳ��ѧ������

	//��̬�����ڴ洴��һ�����飬����ϵͳ������ѧ����Ϣ
	Student** studentArray = new Student*[totalSize];
	int already = 0;
	for (size_t i = 0; i < myClass.size(); i++) {
		for (size_t j = 0; j < myClass[i].myStudent.size(); j++) {
			studentArray[already] = &(myClass[i].myStudent[j]);
			studentArray[already]->setHasScholarship(false);
			already++;
		}
	}

	//���ռ�Ȩƽ���ɼ���������
	sorting(studentArray, totalSize);

	//ǰʮ����ý�ѧ�����������������ʮ������ȫ����ý�ѧ��
	//�������������ʮ������ǰʮ����ý�ѧ��
	//ͬʱ���������Ϣ
	cout << "��ý�ѧ���������" << endl;
	if (totalSize <= TOTAL_SCHOLARSHIP) {
		for (int i = 0; i < totalSize; i++) {
			studentArray[i]->setHasScholarship(true);
			studentArray[i]->showStudent();
		}
	}
	else {
		for (int i = 0; i < TOTAL_SCHOLARSHIP; i++) {
			studentArray[i]->setHasScholarship(true);
			studentArray[i]->showStudent();
		}
	}

	//�ͷŶ�̬������ڴ�
	delete[] studentArray;

}

//���ɼ�����
void SystemManager::sorting(Student** studentArray, int totalSize) {
	int i, j;
	for (i = 0; i < totalSize - 1; i++) {
		for (j = 0; j < totalSize - 1; j++) {
			if (studentArray[j]->getAverageGrade() < studentArray[j + 1]->getAverageGrade()) {
				swap(studentArray[j], studentArray[j + 1]);
			}
		}
	}
}

//��������༶
void SystemManager::chooseBestClass() {
	//�������а༶�İ༶�÷�
	for (size_t i = 0; i < myClass.size(); i++) {
		myClass[i].calculateClassScore();
	}

	//ѡ������༶
	Class* bestClassPtr = &myClass[0];
	for (size_t i = 0; i < myClass.size(); i++) {
		if (myClass[i].getClassScore() > bestClassPtr->getClassScore()) {
			bestClassPtr = &myClass[i];
		}
	}

	//��ӡ����༶
	bestClassPtr->showClass();
	cout << "�༶�÷֣�\t" << bestClassPtr->getClassScore() << endl;

	system("pause");
	system("cls");
}