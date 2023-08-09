#include"class.h"

int friends::num = 0;

friends::friends()
{
	cout << "none" << endl;
}
friends::friends(char* nu, char* na)
{

	int i;
	for (i = 0; i < 11; i++)
		tele_num[i] = nu[i];

	strcpy_s(name, na);
	num++;
	stunum = num;//±àºÅ
	
}

void friends::file_write(fstream& f)
{
	f << name<<endl;

	int i;

	for (i = 0; i < 11; i++)
		f << tele_num[i];

	f << "\n";

}

void friends::show()
{
	cout << name << endl;
	int i;
	for (i = 0; i < 11; i++)
		cout << tele_num[i];
	cout << "\n";
}

friends* friends::search(friends* head)
{
	friends* q;
	char name[10];

	cout << "who you want to search" << endl;
	cin >> name;

	q = head;

	if (friends::num == 0)//no friends;
	{
		cout << "cant find the man" << endl;
		return NULL;
	}

	do {


		if (strcmp(q->name, name) == 0)
		{
			q->show();
			return q;
		}
		if (q->next == NULL)
		{
			cout << "cant find the man " << endl;
			return NULL;
		}

		q = q->next;
	} while (true);

}