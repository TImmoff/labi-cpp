// tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct User {
    int number;
    string name;
};

struct Tree {
	int info;
	Tree* left, * right;
} *root;
struct User A[8] =
{
  { 10, "Sandra Adams"},
  { 6, "Ali Connors" },
  { 25, "Trevor Hansen" },
  { 1, "Tucker Smith" },
  { 8, "Britta Holt" },
  { 20, "Boris Godunov" },
  { 30, "Jane Smith" },
  { 21, "Sandra Williams" },
};
struct User Abalanced[8] =
{
  { 1, "Tucker Smith" },
  { 6, "Ali Connors" },
  { 8, "Britta Holt" },
  { 10, "Sandra Adams"},
  { 20, "Boris Godunov" },
  { 21, "Sandra Williams" },
  { 25, "Trevor Hansen" },
  { 30, "Jane Smith" },
};
struct User B[8] =
{ 
  { 7, "Sandra Adams"},
  { 4, "Ali Connors" },
  { 9, "Trevor Hansen" },
  { 6, "Tucker Smith" },
  { 2, "Britta Holt" },
  { 8, "Boris Godunov" },
  { 10, "Jane Smith" },
  { 5, "Sandra Williams" },
};
User creat()
{
    User mas;
    cout << "enter letter-";
    cin >> mas.name;
    cout << "enter number";
    cin >> mas.number;
    return mas;
}

Tree* List(string fi, int inf) {
    Tree* t = new Tree; // Захват памяти
    t->info.name = fi; // Формирование информационной части
    t->info.number = inf;
    t->left = t->right = NULL; // Формирование адресных частей
    return t; // Возврат созданного указателя
}
void Add_from_arr(Tree* p, User a)
{
    if (p != NULL)
    {
        if (p->info.number > a.number)Add_from_arr(p->left, a);
        else Add_from_arr(p->right, a);
    }
    else
    {
        p = new Tree;
        p->left = p->right = NULL;
        p->info = a;
    }
}

Tree* Load_tree_from_arr(Tree* root, User* data, int length) {
    Tree* Prev = NULL, * t;
    // Prev – родитель текущего элемента
    int  find=0;
    string c;
    if (length < 1) return root;
    if (!root) {   	       // Если дерево не создано
        root = List(data[0].name, data[0].number);   /* Создаем адрес корня root, который первоначально – лист*/
    }
    //---------- Добавление элементов -----------
    for (int i = 1; i < length; i++)
    {
        t = root;
        // Текущий указатель установили на корень
        find = 0;
        // Признак поиска
        while (t && !find) {
            Prev = t;
            if (data[i].number == t->info.number)
                find = 1;
            // Ключи должны быть уникальны
            else
                if (data[i].number < t->info.number) t = t->left;
                else   t = t->right;
        }
        // Если нашли место с адресом Prev
        if (!find) {			//  if (find == 0)	
  // Создаем новый узел, являющийся листом
            t = List(data[i].name, data[i].number);
            // и присоединяем его, либо
            if (data[i].number < Prev->info.number)
                // на левую ветвь,
                Prev->left = t;
            // либо на правую ветвь
            else    Prev->right = t;
        }
    }
    return root;
}
Tree* Create(Tree* root) {
    Tree* Prev = NULL, * t;
    // Prev – родитель текущего элемента
    int b, find;
    string c;
    if (!root) {   	       // Если дерево не создано
        cout << "Input Root(name)-";
        cin >> c;
        cout << "Input Root(number) : ";
        cin >> b;
        root = List(c, b);   /* Создаем адрес корня root, который первоначально – лист*/
    }
    //---------- Добавление элементов -----------
    while (1) {				//  while (true)
        cout << "Input info(name) : ";
        cin >> c;
        cout << " Input info(number) :  ";
        cin >> b;
        if (b < 0) break;
        // Признак выхода – отрицательное число
        t = root;
        // Текущий указатель установили на корень
        find = 0;
        // Признак поиска
        while (t && !find) {
            Prev = t;
            if (b == t->info.number)
                find = 1;
            // Ключи должны быть уникальны
            else
                if (b < t->info.number) t = t->left;
                else   t = t->right;
        }
        // Если нашли место с адресом Prev
        if (!find) {			//  if (find == 0)	
  // Создаем новый узел, являющийся листом
            t = List(c, b);
            // и присоединяем его, либо
            if (b < Prev->info.number)
                // на левую ветвь,
                Prev->left = t;
            // либо на правую ветвь
            else    Prev->right = t;
        }
    }	 		// Конец цикла while ( 1 )
    return root;
}
void Load_tree_from_input(Tree* root, int key, string keyfio) {
    Tree* prev = NULL, * t; // prev – указатель предка нового листа
    bool find = true;
    t = root;
    while (t && find) {
        prev = t;
        if (key == t->info.number && keyfio == t->info.name) {
            find = false; // Ключ должен быть уникален
            cout << "Dublucate Key!";
        }
        else
            if (key < t->info.number) t = t->left;
            else t = t->right;
    }
    if (find) { // Нашли нужное место
        t = List(keyfio, key); // Создаем новый лист
        if (key < prev->info.number) prev->left = t;
        else prev->right = t;
    }
}

void View_Tree(Tree* p, int level) {
    string str;
    int right = 0;
    if (p) {
        View_Tree(p->right, level + 1); // Правое поддерево
        for (int i = 0; i < level; i++) str = str + " ";
        //Form1->Memo1->Lines->Add(str + IntToStr(p->info));
        cout << str << p->info.number << '(' << p->info.name<< ')' << endl;
        View_Tree(p->left, level + 1); // Левое поддерево
    }
}
void View_inReverse(Tree* p, int level = 0) {
    string str;
    if (p) {
        View_inReverse(p->right, level + 1);
        for (int i = 0; i < level; i++) str = str + " ";
        cout << str << p->info.number << '(' << p->info.name << ')';
        View_inReverse(p->left, level + 1);
    }
}
void View_inDirect(Tree* p, int level = 0) {
    string str;
    if (p) {
        View_inDirect(p->right, level + 1);
        for (int i = 0; i < level; i++) str = str + " ";
        View_inDirect(p->left, level + 1);
        cout << str << p->info.number << '(' << p->info.name << ')';

    }
}
void View_inRaise(Tree* p, int level = 0) {
    string str;
    if (p) {
        View_inRaise(p->left, level + 1);
        for (int i = 0; i < level; i++) str = str + " ";
        cout << str << p->info.number << '(' << p->info.name << ')';

        View_inRaise(p->right, level + 1);
    }
}

int View_Tree_right(Tree* p, int level = 0) {
    string str;
    int count = 0;
    if (p) {

        count += View_Tree_right(p->right, level + 1);// Правое поддерево
        for (int i = 0; i < level; i++) str = str + " ";

        cout << str << p->info.name << endl;
        if (level != 0)
            count += View_Tree_right(p->left, level + 1); // Левое поддерево

        count += 1;
    }
    return count;
}
int View_Tree_left(Tree* p, int level = 0) {
    string str;
    int count = 0;
    if (p) {

        count += View_Tree_left(p->left, level + 1); // Левое поддерево

        if (level != 0)
            count += View_Tree_left(p->right, level + 1);// Правое поддерево

        count += 1;
    }
    return count;
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
