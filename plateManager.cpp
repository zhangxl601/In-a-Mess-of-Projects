#include "plateManager.h"
#include <iostream>
#include <qDebug>
#include <stdlib.h>
#include <vector>
#include <QDateTime>
//#include <QSrand>
using namespace std;


plateManager::plateManager()
{
	this->plates = new plate();
}

plateManager::~plateManager()
{
    delete plates;
}

void plateManager::insertPlate()
{
	cout << "请选择输入数据的方式（1：手动输入/2：随机生成）：";
	int type;
	cin >> type;
	if (type == 1) {
		plate* next = new plate();
		next->setNumber(1);
		next->next = this->plates->next;
		this->plates->next = next;
		next->next->before = next;
		next->before = this->plates;
	}
	else if (type == 2) {
		cout << "请输入你要随机生成牌照的数量：";
		int number;
		cin >> number;
		for (int i = 0; i < number; i++) {
			plate* next = new plate();
			next->setNumber(2);
			next->next = this->plates->next;
			this->plates->next = next;
			if (next->next) {
				next->next->before = next;
			}
			next->before = this->plates;
		}
	}
	else {
		cout << "输入错误" << endl;
		this->insertPlate();
	}
}

void plateManager::showPaltes() {
	plate* p = this->plates->next;
	int count = 1;
	while (p) {
		cout << count << ":\t" << p->number << "\t";
		p = p->next;
		count++;
	}
	cout << endl;
}

void plateManager::sortOnce(int bit) {
	plate* plates = this->plates;
	plate* result = new plate();
	plate* endPoint = result;
	if ((int)plates->next->number[bit] <= 57) {
		for (int i = 0; i < 10; i++) {
			plate* temp = plates->next;
			while (temp) {
				if (temp->number[bit] - 48 == i) {
					endPoint->next = temp;
					endPoint = temp;
					temp->before->next = temp->next;
					if (temp->next) {
						temp->next->before = temp->before;
					}
					temp = temp->next;
					endPoint->next = NULL;
					continue;
				}
				temp = temp->next;
			}
		}
	}
	else {
		for (int i = 0; i < 26; i++) {
			plate* temp = plates->next;
			while (temp) {
				if (temp->number[bit] - 65 == i) {
					endPoint->next = temp;
					endPoint = temp;
					temp->before->next = temp->next;
					if (temp->next) {
						temp->next->before = temp->before;
					}
					temp = temp->next;
					endPoint->next = NULL;
					continue;
				}
				temp = temp->next;
			}
		}
	}
	plate* temp = result;
	while (temp) {
		if (temp->next) {
			temp->next->before = temp;
		}
		temp = temp->next;
	}
	this->plates = result;
}

void plateManager::sort() {

//	cout << "排序开始..." << endl;
//	for (int i = 7; i >= 0; i--) {
//		this->sortOnce(i);
//	}
    //	cout << "排序完成..." << endl;
}

QString plateManager::sort(QString carNumber)
{
    return QString();
}

void plateManager::run() {
    int type = 0;
	do {
		cout << "请选择需要的操作" << endl;
		cout << "1：录入信息" << endl;
		cout << "2：排序" << endl;
		cout << "3：输出车牌信息" << endl;
		//cout << "" << endl;
		cout << "0：退出系统" << endl;
		cin >> type;
		switch (type) {
		case 1:
			this->insertPlate();
			break;
		case 2:
			this->sort();
			break;
		case 3:
			this->showPaltes();
			break;
		}
	} while (type != 0);
    qDebug()<<type;
}

QString plateManager::getRandomString(int length)
{
    const char ch[] = "123456789ABCDE123456789FGHIJKL123456789MNOPQRS123456789TUVWXYZ123456789";
    int size = sizeof(ch);

//    char* str1 = new char[length + 1];
    QString str;
    int num = 0;
    for (int i = 0; i < length; ++i)
    {
        num = rand() % (size - 1);
//        str1[i] += ch[num];
        str += ch[num];
    }

    QString res(str);
//    delete [] str;
    return res;
}


