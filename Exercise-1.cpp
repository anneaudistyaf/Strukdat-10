/*
NAMA PROGRAM : EXERCISE-1
NAMA		 : ANNE AUDISTYA F
NPM			 : 140810180059
TANGGAL		 : 14 MEI 2019
*/

#include <iostream>

using namespace std;

const int maxElemen = 255;
struct Queue{
    char isi[maxElemen];
    int head; // depan
    int tail; // belakang
};
void createQueue (Queue& Q);
void createElement(char& elemen);
void insertQueue(Queue& Q, char elemen);
void deleteQueue(Queue& Q, char& elemenHapus);

int main()
{
    Queue Q;
    char elemenHapus,elemen;
    int n;
    createQueue(Q);
    cout << "Banyak elemen : ";cin >> n;
    for(int i=0;i<n;i++){
        createElement(elemen);
        insertQueue(Q,elemen);
    }
    cout << endl;
    cout << "POP :"<<endl;
    for(int i=0;i<n;i++){
        deleteQueue(Q,elemenHapus);
        cout << endl;
    }
    return 0;
}
void createQueue (Queue& Q){
    Q.head = 0;
    Q.tail = -1;
}

void createElement(char& elemen){
    cout<<"Input: ";cin>>elemen;
}

void insertQueue(Queue& Q, char elemen) {
    if (Q.tail==maxElemen-1){
        cout<<"Antrian sudah penuh"<<endl;
    }
    else {
        Q.tail=Q.tail + 1;
        Q.isi[Q.tail] = elemen;
    }
}

void deleteQueue(Queue& Q, char& elemenHapus){
    if (Q.head>Q.tail){ // atau Q.tail=-1
        cout<<"Antrian kosong"<<endl;
    }
    else {
        elemenHapus= Q.isi[Q.head];
        cout << elemenHapus; //Q.head=0
        for (int i=0;i<Q.tail;i++){ // Geser ke depan
            Q.isi[i]=Q.isi[i+1];
        }
        Q.tail=Q.tail-1;
    }
}
