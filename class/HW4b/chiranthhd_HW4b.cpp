#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

class LL{
private:
  class Node{
  public:
	  int data;
	  Node* next;
	  Node(int v, Node* n) : data(v), next(n) {}
  };
      
  Node* head;
  Node* tail;

public:
  
  LL(){
	  head = nullptr;
    tail = nullptr;
  }
     
  void addEnd(int v) {
    if (head == nullptr){
	    head = new Node(v, nullptr);
    }

    Node* p;
   	for ( p=head; p->next != nullptr;p = p->next)
	  {}
	  p->next = new Node(v , nullptr);
    tail = p->next;
  }

  void addStart (int v) {
    head = new Node (v,head);

    Node* p;
    for ( p=head; p->next != nullptr;p = p->next)
    {}
    tail = p;
	}

  int removeEnd () {
    if ( head == nullptr )
       cout << "List is empty" << endl;
    if ( head -> next == nullptr){
       int temp = head->data;
	     head = nullptr;
       tail = nullptr;
	     return temp;
    }
         
	  Node*  p;
	  for ( p=head; p->next->next != nullptr; p = p->next)
	  {}
	  int temp = p->next->data;
	  p->next = nullptr;
    tail = p;
	  return temp;
  }

  int removeStart() {
    if ( head == nullptr )
      cout << "List is empty" << endl;
	
	  int temp = head->data;
	  head = head->next;
	  return temp;
  }
  int printTail(){
     return tail->data;



  }
  friend ostream& operator <<(ostream& s, const LL& list) {
      for (Node* p = list.head; p!=nullptr; p=p->next)
	    s << p->data << ",";
	    return s;
   }

  int getSize(){
    int size=1;
    Node* p;
    for (p=head ; p!=tail ; p=p->next)
      size++;
    return size;
  }
};



vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string tok;
  
    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }
    return internal;
}

vector<uint64_t> splitInt(string str, char delimiter) {
    vector<uint64_t> internal;
    stringstream ss(str);
    string tok;
  
    while(getline(ss, tok, delimiter)) {
        uint64_t tmp=0;
        tmp = atoi(tok.c_str());
        internal.push_back(tmp);
    }
    return internal;
}

 

int main() {
  fstream myFile("HW4b.txt", ios_base::in);
  int capacity;

  LL a;
 
  string instruct;
  
  if(myFile.is_open()){
    while( getline(myFile,instruct,'\n')){  
      if(instruct == ""){
        continue;
      }
      
      vector<string> sep;
      sep.reserve(100);
      sep = split(instruct, ' ');
      
      if (sep[0] == "ADD_FRONT"){
        vector<uint64_t> sep1 = splitInt(sep[1], ':');
        for (uint64_t j = sep1[0]; j <= sep1[2] ; j+=sep1[1]){  
           a.addStart(j);
        }
      }
      
      if (sep[0] == "ADD_BACK"){
        vector<uint64_t> sep1 = splitInt(sep[1], ':');
        for (uint64_t j = sep1[0]; j <= sep1[2] ; j+=sep1[1]){
           a.addEnd(j) ;
        }
      }
      
      if (sep[0] == "REMOVE_FRONT"){
        vector<uint64_t> sep3 = splitInt(sep[1],' ');
        for (int i =0; i < sep3[0]; i++)
           a.removeStart();
      }
      
      if (sep[0] == "REMOVE_BACK"){
        vector<uint64_t> sep4 = splitInt(sep[1], ' ');
        for (int i =0; i < sep4[0]; i++)
           a.removeEnd();
      }

      if (sep[0] == "OUTPUT"){
        cout << endl;
        cout << a << '\n';
        cout << "Tail is pointing to : " << a.printTail() << endl;
        cout << "Size is " << a.getSize() << endl;
      }
      
    }
  }
  
}



































