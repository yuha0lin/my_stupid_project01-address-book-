#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class friends
{
public:
	friends* next;
	friends();
	friends(char* nu, char* na);
	int stunum;

	void file_write(fstream& f);

	void delete_friends();//É¾
	void edit_info();//¸Ä
	friends* search(friends* head);//²é
	void show();
	static int num;
private:
	char tele_num[11];
	char name[10];
};
