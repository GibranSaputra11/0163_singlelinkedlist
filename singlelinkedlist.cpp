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

}