/*
Nama		: Kevin Dyandradiva
NPM			: 140810180046
Nama Program: Soal 1
Tanggal     : 24 April 2019
*/


#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

struct ElemtList{
	char nama[20];
	int jumlah;
	int harga;
	int total;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
	First=NULL;
}
void createElmt(pointer& pBaru){
	pBaru=new ElemtList;
	cout<<"Nama Makanan     : ";cin.ignore();cin.getline(pBaru->nama,30);
	cout<<"Jumlah Makanan   : ";cin>>pBaru->jumlah;
	cout<<"Harga            : ";cin>>pBaru->harga;
	pBaru->next=NULL;
}
void insertFirst(List& First, pointer pBaru){
	if(First==NULL){
		First=pBaru;
	}else{
		pBaru->next=First;
		First=pBaru;
	}
}
void traversal(List First){
	pointer pBantu;
	int i=1;
	if(First==NULL){
		cout<<"List Kosong"<<endl;
	}else{
		pBantu=First;
		do{
			cout<<"Pesanan ke-"<<i<<endl;
			cout<<"Nama Makanan   : "<<pBantu->nama<<endl;
			cout<<"Jumlah Makanan : "<<pBantu->jumlah<<endl;
			cout<<"Harga          : "<<pBantu->total<<endl;
			pBantu=pBantu->next;
			i++;
		}while(pBantu!=NULL);
	}
	cout<<endl;
}
void insertLast(List& First, pointer pBaru){
	pointer last;
	if(First==NULL){
		First=pBaru;
	}else{
		last=First;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

int main(){
	pointer p;
	List Lalala;
	int pil,n,total,harga,jumlah;
	total==harga*jumlah;
	char loop='Y';
	do{
		system("CLS");
		cout<<"Banyak Pesanan : ";cin>>n;
		createList(Lalala);
		for(int i=0; i<n; i++){
			cout<<"\nData Pesanan ke-"<<i+1<<endl;
			createElmt(p);
			insertLast(Lalala,p);
		}
		do{
			system("CLS");
			cout<<"1. Buat Pesanan Baru"<<endl;
			cout<<"2. Tambah Pesanan"<<endl;
			cout<<"3. Cetak Pesanan"<<endl;
			do{
				cin>>pil;
			}while(pil<1 || pil>3);
			switch(pil){
				case 1:
					createElmt(p);
					insertFirst(Lalala,p);
					cout<<"\nData berhasil dibuat!\n";
					getch();
					break;
				case 2:
					createElmt(p);
					insertLast(Lalala,p);
					cout<<"\nData berhasil dibuat!\n";
					getch();
					break;
				case 3:
					traversal(Lalala);
					cout<<"\nKembali ke menu? (Y/N) ";
					do{
						cin>>loop;
					}while(loop!='Y' && loop!='y' && loop!='N' && loop!='n');
					break;
			}
		}while(loop=='Y' || loop=='y');
	}while(loop=='s');
}
