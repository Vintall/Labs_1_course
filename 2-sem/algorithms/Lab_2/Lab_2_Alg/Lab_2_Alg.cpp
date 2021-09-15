#include <iostream>
#include <ctime>

using namespace std;
void Menu();

struct Queue
{
private:
	const int n_max = 250;
	int elem[250];
public:
	int n;
	Queue()
	{
		n = 0;
	}
	void AddElem(int elem)
	{
		if (n < 250)
		{
			n++;
			this->elem[n - 1] = elem;
		}
	}
	int TakeElem()
	{
		if (n > 0)
		{
			int out = elem[0];
			for (int i = 0; i < n - 1; i++)
				elem[i] = elem[i + 1];
			n--;
			return out;
		}
		cout << "������!" << endl;
		return -1;
	}
	void Clear()
	{
		n = 0;
	}
	void ShowQueue()
	{
		for (int i = 0; i < n; i++)
		{
			int buff = TakeElem();
			cout << buff << endl;
			AddElem(buff);
		}
	}
};
Queue qu;
int mass[20];
int mass_count = 0;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	Menu();
	system("Pause");
}
void MassInit()
{
	int a, b;
	cout << "������� ������ ������� (0, 20]";
	cin >> mass_count;
	if (mass_count <= 0 && mass_count > 20)
	{
		cout << "������ �����" << endl;
		return;
	}
	cout << "������� �������� ��������� ����� [a, b] && (a, b) > 0" << endl;
	cout << "������� a - ";
	cin >> a;
	cout << endl;
	cout << "������� b - ";
	cin >> b;
	if (a < 0 || b < 0)
	{
		cout << "������ �����" << endl;
		return;
	}
	if (a > b) swap(a, b);
	for (int i = 0; i < 20; i++)
		mass[i] = rand() % (b - a) + a;
}

void Menu()
{
	bool menu_i = true;
	while (menu_i)
	{
		system("cls");
		cout << "1) �������� �������" << endl;
		cout << "2) �������� �������" << endl;
		cout << "3) ������� �������� �� �����" << endl;
		cout << "4) �������� ���������" << endl;
		cout << "5) ������� ���-�� ���������, ������ ������� � ���������� ��������" << endl;
		cout << "6) ������������� ��������� ������" << endl;
		cout << "7) ������ - ��������" << endl;
		cout << "8) �����" << endl;
		cout << endl;
		cout << "������� ����� ������, � �������� ������ ������� - ";
		int n_; cin >> n_; cout << endl;
		switch (n_)
		{
		case 1:
			cout << "������� �������" << endl;
			int el; cin >> el; cout << endl;
			qu.AddElem(el);
			system("Pause");
			break;
		case 2:
			qu.TakeElem();
			system("Pause");
			break;
		case 3:
			if (qu.n != 0)
			qu.ShowQueue();
			system("Pause");
			break;
		case 4:
			qu.Clear();
			system("Pause");
			break;
		case 5:
			cout << "� ������� " << mass_count << " ���������" << endl;
			if (mass_count != 0)
			cout << "������ ������� - 0, � ���������� - " << mass_count - 1 << endl;
			else cout << "������ ������� - 0, � ���������� - 0" << endl;
			system("Pause");
			break;
		case 6:
			MassInit();
			system("Pause");
			break;
		case 7:
		{
			for (int i = 0; i < mass_count; i++)
				cout << mass[i] << endl;
				cout << endl;

			int non_par = 0;
			for (int i = 0; i < mass_count; i++)
			{
				if (mass[i] != 0)
				{
					if (mass[i] % 2 == 0)
						cout << mass[i] << endl;
					else
					{
						qu.AddElem(mass[i]);
						non_par++;
					}
				}
			}
			for (int i = 0; i < non_par; i++)
				cout << qu.TakeElem() << endl;
			system("Pause");
			cout << endl;
			break;
		}
		case 8:
			menu_i = 0;
			break;
		default:
			menu_i = 0;
			break;
		}
	}
}