#include <iostream>
#include <vector>
#include <string>


using namespace std;

class trie {
private:
   	class Node {
	public:
	   char str;
	   Node* parents;
	   Node* children[26];
	   vector <string> occurances;
	   Node ( char s, Node* n) : str(s) , next(n) {}
	
	};
	
	vector<string> in;
	Node* root;

public:
	trie (vector<string> vec) {
		root = nullptr;
	/*	in = vec;
		cout << "Size is :" << in.size() << endl;
		for (int i = 0 ; i < in.size(); i++){
			cout << in[i]<< endl ;
		}*/
	
	}
	
	void add (char* s){
			if (root == nullptr){
				root = new Node(s,nullptr);
			}
			Node* p;
			for ( p = root; p->next != nullptr; p=p->next){
			


			}
			p = new Node(in[i],nullptr);

	//	}
	}
	
	void print (){
		cout << "Inside print" << endl;
		Node* p;
		for (p = root; p->next != nullptr; p=p->next){
			cout << p->alpha << endl;
		}
	


	}

};



int main(){
   vector <string> vec;
   //vec = {"chiranth"};
   trie a();
   a.add();
   a.print();

}
