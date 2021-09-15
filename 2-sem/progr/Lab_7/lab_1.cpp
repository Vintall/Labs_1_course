#include <iostream>
#include <windows.h>

using namespace std;

HANDLE cons;
const double PI = 3.141592653589793238463;
void SaluteVoid()
{
	SetConsoleTextAttribute(cons, 03);
	cout << "..........................." << endl;
	cout << "| ������������ ������ �1  |" << endl;
	cout << "| �������� ������ ��-19-2 |" << endl;
	cout << "|     ��������� �����     |" << endl;
	cout << "'''''''''''''''''''''''''''" << endl;
}

void Task1()
{
	SaluteVoid();
	cout << "|       ������ �1         |" << endl;
	cout << "'''''''''''''''''''''''''''" << endl;
	SetConsoleTextAttribute(cons, 06);
	int a, b, h;
	cout << "������� �������� � = [a, b]" << endl;
	SetConsoleTextAttribute(cons, 14);
	cout << "a = "; cin >> a; 
	cout << "b = "; cin >> b; cout << endl;
	SetConsoleTextAttribute(cons, 06);
	cout << "������� ��� X = h (������: h = 4  x0 = 1   x1 = 5)" << endl;
	SetConsoleTextAttribute(cons, 14);
	cout << "h = "; cin >> h; cout << endl;
	SetConsoleTextAttribute(cons, 06);
	cout << endl;
	cout << "........................." << endl;
	
	double y;
	for (int x = a; x <= b; x += h)
	{
		if (x > -1 &&  x < 1)
		{
			y = 1.1 * (pow(exp(1), (-1) * x)) + abs(cos(sqrt(x * PI))) - 3 / 8;
			cout << x << "     " << y << endl;
		}
		else if (x > 3 && x <= 5)
		{
			y = pow(x, 25);
			cout << x << "     " << y << endl;
		}
		else 
		{
			y = pow(x, -50);
			cout << x << "     " << y << endl;
		}
	}
	cout << endl;
	system("Pause");
	system("cls");
}

void Task2()
{
	SaluteVoid();
	cout << "|       ������ �2         |" << endl;
	cout << "'''''''''''''''''''''''''''" << endl;
	SetConsoleTextAttribute(cons, 06);
	double x, e, s;
	s = PI/2;
	
	cout << "������� x (x > 1)" << endl;
	cin >> x;
	cout << "������� � - �������� ���������� ����� ����" << endl;
	cin >> e; cout << endl;
	for (int i = 0; i < 5; i++)
		s += pow(-1, i + 1) / ((2 * i + 1) * pow(x, 2 * i + 1));
	cout << "����� ������ ���� ��������� ���� = " << s << endl;

	double sum2 = PI / 2;
	int itCount = 1;
	
	double a = - 1 / x;
	while (abs(a) >= e)
	{
		sum2 += a;
		a = pow(-1, itCount + 1) / ((2 * itCount + 1) * pow(x, 2 * itCount + 1));
		itCount++;
	}
	cout << "����� ���� � ��������� '�'= " << sum2 << endl;
	cout << "���������� �������� = " << itCount << endl;

	cout << "arctg(" << x << ")= " << atan(x) << endl;

	
	system("Pause");
	system("cls");
}

void Menu()
{
	SaluteVoid();
	cout << "|      ������� ����       |" << endl;
	cout << "'''''''''''''''''''''''''''" << endl;
	SetConsoleTextAttribute(cons, 06);
	cout << "������� ����� ������ � ������� ENTER" << endl;
	cout << "0) �����" << endl;
	cout << "1) ������ �1" << endl;
	cout << "2) ������ �2" << endl;
	SetConsoleTextAttribute(cons, 14);
	cout << "������� � ������ - ";
	int num; cin >> num;
	SetConsoleTextAttribute(cons, 06);
	system("cls");
	switch (num)
	{
		case 0:
			exit(0);
		break;

		case 1:
			Task1();
		break;

		case 2:
			Task2();
		break;

		default:
			SetConsoleTextAttribute(cons, 79);
			cout << "������ �����, ���������� ��� ���!" << endl;

			Menu();
		break;
	}
	Menu();
}

void Task1_CMD(int a, int b, int h)
{
	SetConsoleTextAttribute(cons, 06);
	double y;
	for (int x = a; x <= b; x += h)
	{
		if (x > -1 && x < 1) // -1 - ODZ
		{
			y = 1.1 * (pow(exp(1), (-1) * x)) + abs(cos(sqrt(x * PI))) - 3 / 8;
			cout << x << "     " << y << endl;
		}
		else if (x > 3 && x <= 5)
		{
			y = pow(x, 25);
			cout << x << "     " << y << endl;
		}
		else
		{
			y = pow(x, -50);
			cout << x << "     " << y << endl;
		}
	}
	cout << endl;
	system("Pause");
	system("cls");
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cons = GetStdHandle(STD_OUTPUT_HANDLE);
	if (__argc == 4)
	Task1_CMD(atoi(__argv[1]), atoi(__argv[2]), atoi(__argv[3]));
	
	Menu();
}
