#include"fun.h"

friends* add_friends(friends*& head)
{
	char tele[12];
	char na[10];
	friends* p, * q;

	if (friends::num == 0)//if there is no friend;
	{
		cout << "please write down the name of your friend" << endl;
		cin >> na;
		cout << "please write down the telephone_number of the friend" << endl;
		cin >> tele;

		p = new friends(tele, na);

		head = p;

		p->next = NULL;

	}
	else//there are existed friends
	{
		cout << "please write down the name of your friend" << endl;
		cin >> na;
		cout << "please write down the telephone_number of the friend" << endl;
		cin >> tele;

		p = new friends(tele, na);

		q = head;

		while (q->next != NULL)
		{
			q = q->next;
		}

		q->next = p;

		p->next = NULL;
	}

	cout << "creat successfully" << endl;

	return head;
}
void show_all(friends* head)
{
	friends* p;
	p = head;
	if (friends::num == 0)
	{
		cout << "no people" << endl;
	}
	else
	{

		p->show();
		while (p->next != NULL)
		{

			p = p->next;

			p->show();


		}
	}
}
