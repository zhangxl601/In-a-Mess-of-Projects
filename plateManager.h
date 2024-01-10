//#pragma once
#include <QString>
#include<stdlib.h>
#include"plate.h"

class plateManager
{
public:
	plateManager();
	~plateManager();
	void insertPlate();
	void showPaltes();
    void sort();
    QString sort(QString carNumber);
	void sortOnce(int bit);
	void run();

//**new****
    QString getRandomString(int length);
public:
	int plateNumber = 0;
    plate* plates = nullptr;

//**new****
    QString m_carNumber;
};

