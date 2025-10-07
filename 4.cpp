#include <iostream>
#include <windows.h>

using namespace std;

struct TNode;
typedef TNode* PNode;
//структура элемента списка
struct TNode
{
	string Data;
	PNode Next;
};
//добавить элемент в начало списка
void AddFirst(PNode& First, string Data)
{
	PNode p = new TNode;
	p->Data = Data;
	p->Next = First;
	First = p;
}
//добавить элемент в конец списка
void AddLast(PNode& First, string Data)
{
	PNode p1, p2 = First;
	while (p2->Next != NULL)
		p2 = p2->Next;
	p1 = new TNode;
	p1->Data = Data;
	p2->Next = p1;
	p1->Next = NULL;
}
//ввод элементов списка, пока не будет введен 0
void InputList1(PNode& First)
{
	string Data;
	cout << "Введите следующий элемент списка (0 - закончить): \n";
	while (Data != "0")
	{
		cin >> Data;
		if (Data != "0")
			AddFirst(First, Data);
	}
}
//обход и печать списка
void PrintList(PNode First)
{
	PNode p = First;
	while (p)
	{
		cout << p->Data; if (p->Next) cout << ", ";
		p = p->Next;
	}
	cout << endl;
}
string DelFirst(PNode& First)
{
	PNode p = First;
	string t = First->Data;
	First = First->Next;
	delete p;
	return t;
}


void Complement(PNode& First, PNode& Second, int count, int firstnumber) {
	int i = 1;
	PNode p = First, q = NULL;
	while (p && i < firstnumber) {
		AddFirst(q, p->Data);
		p = p->Next;
		i++;
	}
	if (firstnumber != 1) First = q;
	i = 0;
	while (p) {
		if (i < count)
			AddLast(Second, DelFirst(p));
		else
			AddLast(First, DelFirst(p));
		i++;
	}
}




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	PNode First = NULL, Second = NULL;
	int cnt, frst;
	InputList1(First); InputList1(Second);
	cout << "Укажиите количество людей для перевода во вторую группу:\n";
	cin >> cnt;
	cout << "Укажите номер студента, с которого начинается отсчёт:\n";
	cin >> frst;
	system("cls");
	cout << "Список первой группы\n";
	PrintList(First);
	cout << "Список второй группы\n";
	PrintList(Second);
	cout << endl;

	Complement(First, Second, cnt, frst);

	cout << "Итоговый список первой группы\n";
	PrintList(First);
	cout << "Итоговый список второй группы\n";
	PrintList(Second);

	return 0;
}