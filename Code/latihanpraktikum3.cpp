#include <iostream>
#include <conio.h>
using namespace std;


struct Node{
	int data;
	Node *next;
	Node *prev;
};
Node *n=NULL, *head=NULL, *tail=NULL, *x=NULL;

void buatNodeBaru(int i){
	n = new Node;
	n->data = i;
	n->prev = NULL;
	head = n;
	tail = n;
	tail->next = NULL;
}

void tambahDiBelakang(int i){
	n = new Node;
	n->data = i;
	n->prev = tail;
	tail->next = n;
	tail = n;
	tail->next = NULL;
}

void tambahDiDepan(int i){
	n = new Node; 
	n->data = i; 
	n->next = head;
	head->prev = n;
	n->prev = NULL;
	head = n;
}

void tambahDiTengah(int i, int j){
	x = head;
	while(x->data != j) x=x->next;
	n = new Node; 
	n->data = i; 
	n->next = x->next; 
	x->next = n; 
	n->prev = x;
	x = n->next;
	x->prev = n;
}

void hapusDiDepan(){
	x = head;
	head = x->next;
	head->prev = NULL;
	delete(x);
	x = NULL;
}

void hapusDiBelakang(){
	x = tail;
	tail = tail->prev;
	tail->next = NULL;
	delete(x);
	x = NULL;
}

void hapusDiTengah(int i){
	n = NULL;
	x = head;
	while(x->data != i){
		n = x;
		x = x->next;
	}
	n->next = x->next;
	x = x->next;
	delete(x->prev);
	x->prev = n;
}

void tampilDariDepan(){
	x = head;
	while(x != NULL){
		cout << x->data << " ";
		x = x->next;
	}
}

void tampilDariBelakang(){
	x = tail;
	while(x != NULL){
		cout << x->data << " ";
		x = x->prev;
	}
}


int main() {
	int pil;
	int pil2;
	int pil3;
	int pil4;
	int masuk;
	int masuk2;
	
	mulai:
	system("cls");
	cout << "Menu : " << endl;
	cout << "1. Buat Node Awal" << endl;
	cout << "2. Tambah Node" << endl;
	cout << "3. Hapus Node" << endl;
	cout << "4. Tampil Data" << endl;
	cout << "5. Keluar" << endl;
	cout << "Masukkan pilihan [1..5] : "; cin >> pil;
	system("cls");

switch (pil){
	case 1 :
		if(head == NULL){
			cout << "Buat Node Baru" << endl;
			cout << "==============" << endl << endl;
			cout << "Masukkan nilai : "; cin >> masuk;
			buatNodeBaru(masuk);
			cout << "Nilai " << masuk << " berhasil dimasukkan di node awal.";
			getch();
			goto mulai;
			break;
		}
		else {
			cout << "Node Awal/Baru sudah dibuat...";
			getch();
			goto mulai;
			break;
		}
		
	case 2 :
		if(head == NULL){
			cout << "Node Awal/Baru belum dibuat...";
			getch();
			goto mulai;
			break;
		}
		else {
			cout << "Pilihan" << endl;
			cout << "1. Tambah Node di Depan" << endl;
			cout << "2. Tambah Node di Belakang" << endl;
			cout << "3. Tambah Node di Tengah" << endl;
			cout << "4. Batal" << endl;
			cout << "Masukkan pilihan [1..4] : "; cin >> pil2;
			system("cls");
			switch (pil2){
				case 1 :
					cout << "Tambah Node di Depan" << endl;
					cout << "====================" << endl << endl;
					cout << "Masukkan nilai : "; cin >> masuk;
					tambahDiDepan(masuk);
					cout << "Node dengan nilai " << masuk << " berhasil ditambahkan pada posisi depan.";
					getch();
					goto mulai;
					break;
				case 2 :
					cout << "Tambah Node di Belakang" << endl;
					cout << "=======================" << endl << endl;
					cout << "Masukkan nilai : "; cin >> masuk;
					tambahDiBelakang(masuk);
					cout << "Node dengan nilai " << masuk << " berhasil ditambahkan pada posisi belakang";
					getch();
					goto mulai;
					break;
				case 3 :
					if(head == tail){
						cout << "Penambahan data gagal, jumlah Node harus minimal 2!!";
						getch();
						goto mulai;
						break;
					}
					else {
						cout << "Tambah Node di Tengah" << endl;
						cout << "=====================" << endl << endl;
						cout << "Node dimasukkan setelah node dengan nilai : "; cin >> masuk2;
						x = head;
						while(x!=NULL){
							if(masuk2 == x->data){
								if(masuk2 != tail->data){
									cout << "Masukkan nilai pada Node yang baru : "; cin >> masuk;
									tambahDiTengah(masuk, masuk2);
									cout << "Node dengan nilai " << masuk << " berhasil ditambahkan setelah node dengan nilai " << masuk2;
									getch();
									goto mulai;
									break;
								}
								else if(masuk2 == tail->data){
									cout << "Penambahan data gagal, node dengan nilai " << masuk2 << " berada pada posisi belakang!!";
									getch();
									goto mulai;
									break;
								}
							}
									x = x->next;
								}
									cout << "Node dengan nilai " << masuk2 << " tidak ditemukan!!";
									getch();
									goto mulai;
									break;
								}
				case 4 :
					goto mulai;
					break;
			}
		}			
	
	case 3 :
		if(head == NULL){
			cout << "Node Awal/Baru belum dibuat...";
			getch();
			goto mulai;
			break;
		}
		else {
			cout << "Pilihan : " << endl;
			cout << "1. Hapus Node di Depan" << endl;
			cout << "2. Hapus Node di Belakang" << endl;
			cout << "3. Hapus Node di Tengah" << endl;
			cout << "4. Batal" << endl;
			cout << "Masukkan pilihan [1..4] : "; cin >> pil3;
			system("cls");
			switch (pil3){
				case 1 :
					cout << "Node pada posisi depan dengan nilai " << head->data << " berhasil dihapus";
					hapusDiDepan();
					getch();
					goto mulai;
					break;
				case 2 :
					cout << "Node pada posisi belakang dengan nilai " << tail->data << " berhasil dihapus";
					hapusDiBelakang();
					getch();
					goto mulai;
					break;
				case 3 :
					cout << "Hapus Node di Tengah" << endl;
					cout << "====================" << endl << endl;
					cout << "Masukkan nilai pada Node yang akan dihapus : "; cin >> masuk;
					x = head;
					while(x!=NULL){
						if(masuk == x->data){
							if(head->data != x->data && tail->data != x->data){
								hapusDiTengah(masuk);
								cout << "Node dengan nilai " << masuk << " berhasil dihapus..";
								getch();
								goto mulai;
								break;
							}
							else if(head->data == x->data || tail->data == x->data){
								cout << "Penghapusan data gagal, node dengan nilai " << masuk << " berada pada posisi depan atau belakang!!" << endl;
								cout << "Gunakan Menu Penghapusan di Depan atau Penghapusan di Belakang!!";
								getch();
								goto mulai;
								break;
							}
						}
							x = x->next;
						}
							cout << "Node dengan nilai " << masuk << " tidak ditemukan!!";
							getch();
							goto mulai;
							break;
							
				case 4 :
					goto mulai;
			}
		}			
	
	case 4 :
		if(head == NULL){
			cout << "Node Awal/Baru belum dibuat...";
			getch();
			goto mulai;
			break;
		}
		else {
			cout << "Pilihan : " << endl;
			cout << "1. Tampil dari depan" << endl;
			cout << "2. Tampil dari belakang" << endl;
			cout << "3. Batal" << endl;
			cout << "Masukkan pilihan [1..3] : "; cin >> pil4;
			system("cls");
			switch (pil4){
				case 1 : 
					cout << "Isi Linked List" << endl;
					cout << "===============" << endl << endl;
					tampilDariDepan();
					getch();
					goto mulai;
					break;
				case 2 :
					cout << "Isi Linked List" << endl;
					cout << "===============" << endl << endl;
					tampilDariBelakang();
					getch();
					goto mulai;
					break;
				case 3 :
					goto mulai;
					break;
			}
					}
	
	case 5 : 
		return 0;
		break;
	}

}






				
		
										
								
							
						
									
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

