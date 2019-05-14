/*
NAMA PROGRAM : EXERCISE-2
NAMA		 : ANNE AUDISTYA F
NPM			 : 140810180059
TANGGAL		 : 14 MEI 2019
*/

#include<iostream>
using namespace std;

struct ElemenQueue {
    char info;
    ElemenQueue* next;
};
typedef ElemenQueue* pointer;
typedef pointer List;

struct Queue {
    List Head;
    List Tail;
};
Queue Q;

void createList(Queue& Q){
	Q.Head = NULL;
    Q.Tail = NULL;
}

void createElemt(pointer& pBaru){
	pBaru=new ElemenQueue;
	cout<<"Input : ";
	cin>>pBaru->info;
	pBaru->next=NULL;
}

void cetak(Queue Q){
    pointer pBantu=Q.Head;
    if(Q.Head == NULL && Q.Tail == NULL){
        cout << "\n\t***Data masih kosong***" << endl;
    }else{
        while(pBantu != NULL){
            cout << pBantu->info;
            pBantu=pBantu->next;
        }
    }
}


void insertQueue( Queue& Q, pointer pBaru){
    if (Q.Head==NULL && Q.Tail==NULL) { // kosong
        Q.Head = pBaru;
        Q.Tail = pBaru;
    }
    else { // ada isi
        Q.Tail->next = pBaru;
        Q.Tail = pBaru;
    }
}

void deleteQueue(Queue& Q, pointer& pHapus){
    if (Q.Head==NULL && Q.Tail==NULL) { //kasus kosong
        pHapus=NULL;
        cout<<"List Queue kosong "<<endl;
    }
    else if (Q.Head->next==NULL) { // kasus isi 1 elemen
        pHapus=Q.Head;
        cout << pHapus->info<< endl;
        Q.Head=NULL;
        Q.Tail=NULL;
    }
    else { // kasus > 1 elemen
        pHapus=Q.Head;
        cout << pHapus->info<< endl;
        Q.Head=Q.Head->next;
        pHapus->next=NULL;
    }
}

int main(){
    Queue Q;
    pointer pBaru,pHapus;
    List l;
    int n;

    createList(Q);
    cout<<"Banyak Elemen : ";cin>>n;
    for(int i=0; i<n; i++)
    {
        createElemt(pBaru);
        insertQueue(Q,pBaru);
    }
    cout <<endl;
    cout << "POP : "<<endl;
    for(int i=0;i<n;i++){
    deleteQueue(Q,pHapus);
    }
}

