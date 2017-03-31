#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
#include<fstream>
#include<sstream>
using namespace std;

char C = 'a';
template<typename T>
class trieTree{
public:
	T size;
	T data;
	int isLeaf;
	int isWord;
	int total;
	trieTree** dataChain;
	void init(){
		for (int i = 0; i < this->size; i++)
			this->dataChain[i] = NULL;
	}
	trieTree(T s) {
		this->size = s;
		dataChain = new trieTree*[this->size];
		this->isWord = 0;
		this->isLeaf = 0;
		this->data = '\0';
		this->total = 0;
	}
};

class treeNode{
public:
	int count;
	char data;

	treeNode *leftChild;
	treeNode *rightChild;
	treeNode() :leftChild(NULL), rightChild(NULL){
		//this->isLeaf = 0;
		//this->isWord = 0;
	}
	bool operator()(treeNode *a, treeNode *b){ return a->count > b->count; }

};
void lowerChar(string &str){
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}


vector<string> suffixGen(string str){
	vector<string> suffixes;
	for (int i = 0; i < str.size(); i++){
		suffixes.push_back(str.substr(i, str.size()));
	}
	return suffixes;
}
//  insert data into trie data structure
int insertTri(trieTree<int> *trie, string str){
	
	if (str.size() == 1 && trie->dataChain[str[0] - C] == NULL){
		trieTree<int> *tempTri = new trieTree<int>(30);
		tempTri->init();
		tempTri->data = str[0];
		tempTri->isWord = 1;
		tempTri->isLeaf = 1;
		tempTri->total = 1;
		trie->dataChain[str[0] - C] = tempTri;
		return 0;
	}
	else if (str.size() == 1){
		if (trie->dataChain[str[0] - C]->isWord == 0){
			trie->dataChain[str[0] - C]->isWord = 1;
			trie->dataChain[str[0] - C]->total += 1;
			return 1;
		}
		else
			return 1;
		
	}
	else{
		if (trie->dataChain[str[0] - C] != NULL){
			//trie->dataChain[str[0]] = new trieTree<int>(200);
			if (trie->dataChain[str[0] - C]->isWord == 1)
				return 1;
			int temptotal = insertTri(trie->dataChain[str[0] - C], str.substr(1, str.size()));
			trie->dataChain[str[0] - C]->total += temptotal;
			return temptotal;
		}
		else{

			trie->dataChain[str[0] - C] = new trieTree<int>(30);
			trie->dataChain[str[0] - C]->data = str[0];
			trie->dataChain[str[0] - C]->init();
			int temptotal = insertTri(trie->dataChain[str[0] - C], str.substr(1, str.size()));
			//trie->dataChain[str[0] - C]->total += temptotal;
			return temptotal;
		}
	}

	//return 1;
}

void dfsTraversal(trieTree<int> *root, int &counter){
	if (root == NULL){
		//cout << "Done inorder traversal" << endl;
		return;
	}
	for (unsigned int i = 0; i < root->size; i++){
		if (root->dataChain[i] != NULL){
			//str.push_back((char)(i + C));

			if (root->dataChain[i]->isWord == 1 || root->dataChain[i]->isLeaf == 1)
				counter += 1;
			dfsTraversal(root->dataChain[i], counter);
			//str.pop_back();

		}
	}
	return;
}

trieTree<int>* dfsForcounter(trieTree<int> *root, string str){
	if (root == NULL){
		return NULL;
	}

	if (root->dataChain[str[0] - C] != NULL && str.size() == 1){
		return root->dataChain[str[0] - C];
	}
	else if (root->dataChain[str[0] - C] != NULL){

		return dfsForcounter(root->dataChain[str[0] - C], str.substr(1, str.size()));
	}
	else
	{
		return NULL;
	}

}

int main(){
	//freopen("input.txt", "r", stdin);
	int N;
	string str;
	getline(cin, str);
	//int table[100][30];
	std::string::size_type sz;
	N = std::stoi(str, &sz);
	string op, s;
	//cout << N << endl;
	trieTree<int> *root = new trieTree<int>(30);
	root->init();
	int setting = 0;
	while (N--){
		getline(cin, str);
		if (insertTri(root, str) == 1){
			setting = 1;
			break;
		}
		
	}

	if (setting == 1){
		cout << "BAD SET" << endl;
        cout << str << endl;
    }
	else
		cout << "GOOD SET" << endl;
	return 0;
}