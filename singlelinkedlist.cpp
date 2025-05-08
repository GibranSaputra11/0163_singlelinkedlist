#include <iostream>
#include <string.h>
using namespace std;

class Node{
    public:
    int noMhs;
    Node *next;
};

class SingleLinkdlist {
    Node *START;
    public:
    SingleLinkdlist(){
        START = NULL;
    }
    
    void addNode(){ //method pertama
        int nim;
        cout << "\nMasukan Nomor Mahasiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs){
            if ((START != NULL) && (nim == START->noMhs)){
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while ((current != NULL) && (nim >= current->noMhs)){
            if (nim == current->noMhs){
                cout << "\nDuplikasi noMhs tidak diijinkan\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty(){ // metod tipe bolean
        return (START == NULL);
    }

    bool Search(int nim, Node **previous, Node **current){ // add metod
        *previous = START;
        *current = START;

        while ((*current != NULL) && (nim != (*current)->noMhs)){
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);
    }

    bool delNode(int nim){
        Node *current, *previous;
        if (Search(nim, &previous, &current))
            return false;
        
        if  (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }

    void traverse(){
        if (listEmpty()){
            cout << "\nList Kosong\n";
        }
        else{
            cout << "\nData didalam list adalah: \n";
            Node *currentNode = START;
            while (currentNode != NULL){
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main(){
    SingleLinkdlist mhs;
    int nim;
    char ch;
    while (1){
        cout << endl 
             << "Menu";
        cout << endl
             << "1. Menambah data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;
        cout << endl
             << "Masukan pilihan (1-5): ";
        cin >> ch;
        switch (ch){
            case '1':{
                mhs.addNode();
            }
            break;

            case '2':{
                if (mhs.listEmpty()){
                    cout << endl
                         << "List Kosong" << endl;
                    break;
                }
                cout << endl
                     << "\nMasukan no mahasiswa yang akan di hapus : ";
                cin >> nim;
                if (mhs.delNode(nim) == false)
                    cout << endl
                         << "Data tidak ditemukan" << endl;
                else
                    cout << endl
                         << "Data dengan nomor mahasiswa " << nim << " berhasil dihapus " << endl;
            }
            break;
            case '3':{
                mhs.traverse();
            }
        }
    }   

}