#include <iostream>
#include <conio.h>
#include <queue>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};
Node *root=NULL, *n=NULL, *temp=NULL;

Node *createNode(int data){
	n = new Node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void insert(Node *&root, int data){
	if (root==NULL)
		root = createNode(data);
	else if (data <= root->data)
		insert(root->left, data);
	else if (data > root->data)
		insert(root->right, data);
}

void levelOrder(){
	if (root==NULL) return;
	
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		cout << q.front()->data << " ";
	if(q.front()->left != NULL)
		q.push(q.front()->left);
	if(q.front()->right != NULL)
		q.push(q.front()->right);
	q.pop();
	}
}

void preOrder(Node *root){
	if (root==NULL) return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root){
	if (root==NULL) return;

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

void inOrderDESC(Node *root){
	if (root==NULL) return;

	inOrderDESC(root->right);
	cout << root->data << " ";
	inOrderDESC(root->left);
}

void postOrder(Node *root){
	if (root==NULL) return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

bool cari(Node *root, int data){
	if (root==NULL)
		return false;
	else if(data < root->data)
		return cari(root->left, data);
	else if(data > root->data)
		return cari(root->right, data);
	else
		return true;
}

Node *cariMin(Node *root){
	if (root==NULL)
		return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}

void hapus(Node *&root, int data){
	if (root==NULL)
		return;
	else if(data < root->data)
		return hapus(root->left, data);
	else if(data > root->data)
		return hapus(root->right, data);
	else{
		// kasus I
		if (root->left == NULL && root->right == NULL){
			delete(root);
			root=NULL;
		}
		// kasus II
		else if (root->left == NULL){
			temp = root;
			root = root->right;
			delete(temp);
			temp=NULL;
		}
		else if (root->right == NULL){
			temp = root;
			root = root->left;
			delete(temp);
			temp=NULL;
		}
		// kasus III
		else{
			temp = cariMin(root->right);
			root->data = temp->data;
			hapus(root->right, root->data);
		}
	}
}



int main (){
	int pil;
	int pil2;
	int masuk;
	
	
	a :
	system("cls");
	cout << "Menu" << endl;
	cout << "1. Insert Node" << endl;
	cout << "2. Pencarian Data" << endl;
	cout << "3. Hapus Node" << endl;
	cout << "4. Binary Tree Traversal" << endl;
	cout << "5. Keluar" << endl;
	cout << "Masukkan pilihan [1..5] : "; cin >> pil;
	system("cls");

switch(pil){
	case 1	:
		cout << "Masukkan data : "; cin >> masuk;
		insert(root, masuk);
		cout << "Data " << masuk << " berhasil dimasukkan";
		getch();
		goto a;
		break;	
	case 2 :
		cout << "Masukkan data yang akan dicari : "; cin >> masuk;
		if(cari(root, masuk)){
			cout << "Data " << masuk << " ditemukan...";
			getch();
			goto a;
			break;
		}
		else {
			cout << "Data " << masuk << " tidak ditemukan...";
			getch();
			goto a;
			break;
		}
		
	case 3 :
		if(root == NULL){
			cout << "Tree masih kosong...";
			getch();
			goto a;
			break;
		}
		else if (root != NULL){
			cout << "Masukkan data yang akan dihapus : "; cin >> masuk;
			if(cari(root, masuk)){
				hapus(root, masuk);
				cout << "Data " << masuk << " berhasil dihapus...";
				getch();
				goto a;
				break;
			}
			else {
				cout << "Data " << masuk << " tidak ditemukan...";
				getch();
				goto a;
				break;
			}	
		}
		
	case 4 :
		if(root == NULL){
			cout << "Tree masih kosong...";
			getch();
			goto a;
			break;
		}
		else {
			cout << "Binary Tree Traversal" << endl;
			cout << "=====================" << endl << endl;
			cout << "1. Level Order" << endl;
			cout << "2. Preorder" << endl;
			cout << "3. Inorder (ASC)" << endl;
			cout << "4. Inorder (DESC)" << endl;
			cout << "5. Postorder" << endl;
			cout << "6. Batal" << endl;
			cout << "Masukkan pilihan [1..6] : "; cin >> pil2;
			system("cls");
			switch (pil2){
				case 1 :
					cout << "Binary Tree Traversal" << endl;
					cout << "=====================" << endl << endl;
					cout << "Level Order : ";
					levelOrder();
					getch();
					goto a;
					break;
				case 2 :
					cout << "Binary Tree Traversal" << endl;
					cout << "=====================" << endl << endl;
					cout << "Preorder : ";
					preOrder(root);
					getch();
					goto a;
					break;
				case 3 :
					cout << "Binary Tree Traversal" << endl;
					cout << "=====================" << endl << endl;
					cout << "Inorder (ASC) : ";
					inOrder(root);
					getch();
					goto a;
					break;
				case 4 :
					cout << "Binary Tree Traversal" << endl;
					cout << "=====================" << endl << endl;
					cout << "Inorder (DESC) : ";
					inOrderDESC(root);
					getch();
					goto a;
					break;
				case 5 :
					cout << "Binary Tree Traversal" << endl;
					cout << "=====================" << endl << endl;
					cout << "Postorder : ";
					postOrder(root);
					getch();
					goto a;
					break;
				case 6 :
					goto a;
					break;
			}
		}

	case 5 :
		return 0;

}

}	
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


