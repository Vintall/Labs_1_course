#include <iostream>
#include <ctime>

using namespace std;

void Menu();
void ArrayFill();
void ArrayShow();
void Task1();
void Task2();
int mass[100], elem_count = 0, mass2[100], elem_count2 = 0;

void ArrayFill()
{
	cout << "������� ���-�� ��������� ������� (0,100]" << endl;
	cin >> elem_count; cout << endl;
	if (elem_count <= 0 && elem_count > 100)
	{
		cout << "������ �����. ��� ������ � ������� ���� ������� Enter" << endl;
		system("Pause");
		return;
	}
	int r1, r2;
	cout << "������� �������� ����� ��������� �������" << endl;
	cout << "mass[1...n] = [a, b];  a < b" << endl;
	cout << "������� � = "; cin >> r1; cout << endl;
	cout << "������� b = "; cin >> r2; cout << endl;

	if (r1 >= r2)
	{
		cout << "������ �����. ��� ������ � ������� ���� ������� Enter" << endl;
		system("Pause");
		return;
	}

	for (int i = 0; i < elem_count; i++)
		mass[i] = r1 + rand() % (r2 - r1);


	cout << "�������� �������. ��� ������ � ������� ���� ������� Enter" << endl;
	system("Pause");
}
void ArrayShow()
{
	if (elem_count > 0 && elem_count <= 100)
		for (int i = 0; i < elem_count; i++)
			cout << mass[i] << endl;
	else
	{
		cout << "������. ������������ ������. ��� ������ � ������� ���� ������� ENTER" << endl;
		system("Pause");
	}

	cout << "�������� �������. ��� ������ � ������� ���� ������� Enter" << endl;
	system("Pause");
}
void Task1()
{
	if (!(elem_count > 0 && elem_count <= 100))
	{
		cout << "������. ������������ ������. ��� ������ � ������� ���� ������� ENTER" << endl;
		system("Pause");
	}
	else
	{
		elem_count2 = 0;
		int max_index = 0;
		for (int i = 0; i < elem_count; i++)
		{
			if (mass[max_index] < mass[i])
				max_index = i;
		}

		for (int i = max_index+1; i < elem_count; i++)
		{
			if (mass[i] % 2 == 0)
			{
				elem_count2++;
				mass2[elem_count2 - 1] = mass[i];
				cout << mass2[elem_count2 - 1] << endl;
			}
		}
	cout << "�������� �������. ��� ������ � ������� ���� ������� Enter" << endl;
	system("Pause");
	}
}
void Task2()
{
	if (elem_count > 0)
	{
		for (int i = 0; i < elem_count; i++)
			cout << "mass[" << i+1 << "]=" << mass[i] << "  ";
		cout << endl;
		cout << "������� 'I' ����� ��������, � �������� ���������� ������� �������� (0, mass.Length) - ";
		int i_;
		cin >> i_; cout << endl;
		cout << "������� 'K' ���-�� ��������� ��������� (I, mass.Length - 1) - ";
		int k_;
		cin >> k_; cout << endl;

		if (i_ > 0 && i_ <= elem_count && k_ <= elem_count - i_ + 1 && k_ >= 0)
		{
			for (int i = i_ - 1; i < elem_count; i++)
				if (i + k_ < elem_count)
					mass[i] = mass[i + k_];
			
			elem_count -= k_;
			
			if (elem_count != 0)
			{
				for (int i = 0; i < elem_count; i++)
					cout << "mass[" << i+1 << "]=" << mass[i] << "  ";
				cout << endl;
			}
			else cout << "�� ������� ������" << endl;
			cout << "�������� �������. ��� ������ � ������� ���� ������� Enter" << endl;
			system("Pause");
		}
		else
		{
			cout << "������. ������������ ������. ��� ������ � ������� ���� ������� ENTER" << endl;
			system("Pause");
		}
	}
	else
	{
		cout << "������ ����" << endl;
		cout << "��� ������ � ������� ���� ������� Enter" << endl;
		system("Pause");
	}
}

void Menu()
{
	cout << "0) �����" << endl;
	cout << "1) ��������� ������" << endl;
	cout << "2) ������� ������ �� �����" << endl;
	cout << "3) ������� 1" << endl;
	cout << "4) ������� 2" << endl;
	
	cout << "������� ����� ������ ���� ��� �������� � ����" << endl;
	cout << "������� � ������ - ";
	int a;
	cin >> a;

	switch (a)
	{
	//-0-0-0-0-0-0
	case 1:
		ArrayFill();
		system("cls");
		Menu();
	break;
	//-0-0-0-0-0-0
	case 2:
		ArrayShow();
		system("cls");
		Menu();
	break;
	//-0-0-0-0-0-0
	case 3:
		Task1();
		system("cls");
		Menu();
	break;
	//-0-0-0-0-0-0
	case 4:
		Task2();
		system("cls");
		Menu();
	break;
	//-0-0-0-0-0-0
	case 0:
		exit(0);
	break;
	//-0-0-0-0-0-0
	default:
		system("cls");
		cout << "������ �����. ���������� ��� ���" << endl << endl;
		Menu();
	break;
	//-0-0-0-0-0-0
	}

}


int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	Menu();
	return 0;
}