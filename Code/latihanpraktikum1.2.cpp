#include <iostream>
#include <conio.h>
using namespace std;

const int MAX_QUEUE = 5;
struct Queue{
	int elemen[1000];
	int rear;
	int front;
	int jml;
};

void createQ(Queue &q){
	q.front = 0;
	q.rear = -1;
	q.jml = 0;
}

bool isFull(Queue q){
	return q.jml == MAX_QUEUE;
}

bool isEmpty(Queue q){
	return q.jml == 0;
}

void enQ(Queue &q, int i){
	if(isFull(q)) return;
	q.rear++;
	q.jml++;
	q.elemen[q.rear] = i;
}

void deQ(Queue &q, int &i){
	if(isEmpty(q)) return;
	i = q.elemen[q.front];
	q.front++;
	q.jml--;
}


int main () {
	int pilih;
	int masuk;
	Queue q;
	createQ(q);
	a :
	system("cls");
	
	
	cout << "Implementasi Queue dengan Array" << endl;
	cout << "===============================" << endl << endl;
	cout << "Menu : " << endl;
	cout << "1. Enqueue Data" << endl;
	cout << "2. Dequeue Data" << endl;
	cout << "3. Tampil Isi Queue" << endl;
	cout << "4. Kosongkan Queue" << endl;
	cout << "5. Keluar" << endl; 
	cout << "Masukkan Pilihan [1..5] : "; cin >> pilih;
	system("cls");

switch(pilih) {
	case 1 :
		if(isFull(q)) {
			cout << "Queue Penuh, enqueue dibatalkan...";
			getch();
			goto a;
			break;
	}
		else {
			cout << "Enqueue" << endl;
			cout << "=======" << endl << endl;
			cout << "Masukkan Data : "; cin >> masuk;
			enQ(q, masuk);
			cout << "Data " << masuk << " berhasil dimasukkan...";
			getch();
			goto a;
			break;
	}
	
	case 2 :
		if(isEmpty(q)){
			cout << "Queue kosong, dequeue dibatalkan";
			getch();
			goto a;
			break;
		}
		else {
			cout << "Dequeue" << endl;
			cout << "=======" << endl << endl;
			cout << "Data " << masuk << " berhasil dikeluarkan...";
			deQ(q, masuk);
			getch();
			goto a;
			break;
		}
		
	case 3:
		if (isEmpty(q)){
			cout << "Queue masih kosong...";
			getch();
			goto a;
			break;
		}
		else {
			cout << "Isi Queue mulai dari posisi front : ";
			for (int i=q.front; i<=q.rear; i++)
			cout << q.elemen[i] << " ";
			getch();
			goto a;
			break;
		}
	
	case 4 :
		q.front = 0;
		q.rear = -1;
		q.jml = 0;
		cout << "Queue berhasil dikosongkan";
		getch();
		goto a;
		break;
	
	case 5 :
		return 0 ;

	}
	
}
	




		
	
