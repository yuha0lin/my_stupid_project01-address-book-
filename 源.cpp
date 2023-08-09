#include<iostream>
#include<fstream>
#include"fun.h"
#include"class.h"

int main()
{
	fstream f_file;

	f_file.open("C:\\Users\\lenovo\\Desktop\\garbage.txt", ios::in | ios::out);
	if (!f_file)
		cerr << "cant open" << endl;//打开文件

	friends* head;
	friends* p,*q;
	p = NULL;
	head = NULL;

	int peo_num,i;
	//读入人数
	f_file>> peo_num;

	//遍历文件输入

	if (peo_num != 0)
	{
		char tele_num[12];
		char name[10];
		f_file >> name;
		f_file >> tele_num;

		p = new friends(tele_num,name);
		 
		head = p;

		for (i = 1; i < peo_num; i++)
		{
			f_file >> name;
			f_file >> tele_num;

			q = new friends(tele_num, name);

			p->next = q;
			p = q;
		}

		p->next = NULL;
	}
	

	int f = 1;

	

	//read file

	show_all(head);

	while (f != 0)
	{
		cout << "0 退出" << endl;
		cout << "1 查找" << endl;
		cout << "2 新建" << endl;
		cout << "3 浏览" << endl;

		cin >> f;
		switch (f)
		{
		case 0:
			break;
		case 1:
			p->friends::search(head);
			break;
		case 2:
			p = add_friends(head);
			break;
		case 3:
			show_all(head);
			break;
		default:
			cout << "你说nm呢" << endl;
		}

	}

	

	cout << "out" << endl;

	f_file.seekg(0, ios::beg);

	//第一行写入人数
	f_file << friends::num << endl;

	p = head;
	
	do {

		p->file_write(f_file);

		if (p->next != NULL)
			p = p->next;
		else
			break;

	} while (true);


	f_file.close();
	

	cout << "out" << endl;
}