#include <iostream>
#include <conio.h>
using namespace std;

const int MAX_STACK = 5;
struct Stack{
	int elemen[MAX_STACK];
	int top;
};

void createStack(Stack &s){
	s.top = -1;
}

bool isEmpty(Stack s){
	return s.top == -1;
}

bool isFull(Stack s){
	return s.top == MAX_STACK-1;
}

void push(Stack &s, int i){
	s.top++;
	s.elemen[s.top] = i;
}

void pop(Stack &s, int &i){
	i = s.elemen[s.top];
	s.top--;
}




int main () {
	int pilih;
	int masuk;
	Stack s;
	createStack(s);
	a :
	system("cls");
	
	
	cout << "Implementasi Stack dengan Array" << endl;
	cout << "===============================" << endl << endl;

	cout << "Menu :" << endl;
	cout << "1. Push Data" << endl;
	cout << "2. Pop Data" << endl;
	cout << "3. Tampil Isi Stack" << endl;
	cout << "4. Kosongkan Stack" << endl;
	cout << "5. Keluar" << endl;
	cout << "Masukkan Pilihan [1..5] : "; cin >> pilih;
	system("cls");
	
switch(pilih) {
	case 1 :
		if (isFull(s)){
			cout << "Stack penuh, push dibatalkan...";
			getch();
			goto a;
			break;
		}
		else {
			cout << "Push Data" << endl;
			cout << "=========" << endl << endl;
			cout << "Masukkan Data : "; cin >> masuk;
			push(s, masuk);
			cout << "Data " << masuk << " berhasil dimasukkan...";
			getch();
			goto a;
			break;
		}

	case 2 :
		if (isEmpty(s)){
			cout << "Stack kosong, pop dibatalkan...";
			goto a;
			break;
		}
		else {
			cout << "Pop Data" << endl;
			cout << "========" << endl << endl;
			pop(s, masuk);
			cout << "Data " << masuk << " berhasil dikeluarkan...";
			getch();
			goto a;
			break;
		}
	case 3 :
		if (isEmpty(s)) {
			cout << "Stack masih kosong..";
			getch();
			goto a;
			break;
	}
		else {
			cout << "Isi Stack mulai dari posisi top: ";
			for(int i=s.top; i>=0; i--)
			cout << s.elemen[i] << " ";
			break;
	}
	case 4 :
		s.top = -1;
		cout << "Stack berhasil dikosongkan...";
		getch();
		goto a;
		break;
	case 5 :
		return 0;
	
}

}

		




