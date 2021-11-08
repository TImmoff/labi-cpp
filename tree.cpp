// tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct Tree {
	int info;
	Tree* left, * right;
} *root;
Tree* List(int inf) {
	Tree* t = new Tree; // Захват памяти
	t->info = inf; // Формирование информационной части
	t->left = t->right = NULL; // Формирование адресных частей
	return t; // Возврат созданного указателя
}
void Add_List(Tree* root, int key) {
	Tree* prev, * t; // prev – указатель предка нового листа
	bool find = true;
	t = root;
	while (t && find) {
		prev = t;
		if (key == t->info) {
			find = false; // Ключ должен быть уникален
			cout<<"Dublucate Key!";
		}
		else
			if (key < t->info) t = t->left;
			else t = t->right;
	}
	if (find) { // Нашли нужное место
		t = List(key); // Создаем новый лист
		if (key < prev->info) prev->left = t;
		else prev->right = t;
	}
}
void View_Tree(Tree* p, int level) {
	string str;
	if (p) {
		View_Tree(p->right, level + 1); // Правое поддерево
		for (int i = 0; i < level; i++) str = str + " ";
		//Form1->Memo1->Lines->Add(str + IntToStr(p->info));
		View_Tree(p->left, level + 1); // Левое поддерево
	}
}
Tree* Del_Info(Tree* root, int key) {
	Tree* Del, * Prev_Del, * R, * Prev_R;
	// Del, Prev_Del – удаляемый узел и его предыдущий (предок); 
	// R, Prev_R – элемент, на который заменяется удаленный узел, и его предок;
	Del = root;
	Prev_Del = NULL;
	//-------- Поиск удаляемого элемента и его предка по ключу key ---------
	while (Del != NULL && Del->info != key) {
		Prev_Del = Del;
		if (Del->info > key) Del = Del->left;
		else Del = Del->right;
	}
	if (Del == NULL) { // Элемент не найден
		cout<<"NOT Key!";
		return root;
	}
	//-------------------- Поиск элемента R для замены --------------------------------
	if (Del->right == NULL) R = Del->left;
	else
		if (Del->left == NULL) R = Del->right;
		else {
			//---------------- Ищем самый правый узел в левом поддереве -----------------
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) {
				Prev_R = R;
				R = R->right;
			}
			//----------- Нашли элемент для замены R и его предка Prev_R -------------
			if (Prev_R == Del) R->right = Del->right;
			else {
				R->right = Del->right;
				Prev_R->right = R->left; 36
					R->left = Prev_R;
			}
		}
	if (Del == root) root = R; // Удаляя корень, заменяем его на R
	else
		//------- Поддерево R присоединяем к предку удаляемого узла -----------
		if (Del->info < Prev_Del->info)
			Prev_Del->left = R; // На левую ветвь
		else Prev_Del->right = R; // На правую ветвь
	delete Del;
	return root;
}
void Del_Tree(Tree* t) {
	if (t != NULL) {
		Del_Tree(t->left); // На левую ветвь
		Del_Tree(t->right); // На правую ветвь
		delete t;
	}
}


int main()
{
	int in;
	char a = ' ';
	while (a != 'e')
	{
		cout << "Choose c-create";
		cin >> a;
			switch (a)
			{
			case'c':
					if (root != NULL) Del_Tree(root);
					root = in;
					//--------------------- Текст функции-обработчика кнопки Просмотреть -----
					if (root == NULL) cout << " Create TREE !";
						else {
							cout << "---------- View -----------";
							View_Tree(root, 0);
						}
					//--------------------- Текст функции-обработчика кнопки Добавить -----------
						if (root == NULL) root = ;
						else Add_List(root, StrToInt(Edit1->Text));
					//--------------------- Текст функции-обработчика кнопки Удалить INFO ----
					------ -
						int b = StrToInt(Form1->Edit1->Text);
					root = Del_Info(root, b);
					//--------------------- Текст функции-обработчика кнопки ОЧИСТИТЬ -------
					--------
						Del_Tree(root);
					ShowMessage(" Tree Delete!");
					root = NULL;
					//--------------------- Текст функции-обработчика кнопки EXIT -----------------
					if (root != NULL) {
						Del_Tree(root);
						ShowMessage(" Tree Delete!");
					}

			}
	
	}
}
