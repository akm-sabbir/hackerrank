#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

char C='a';
template<typename T>
class trieTree{
public:
	T size;
	T data;
	int isLeaf;
	int isWord;
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
	}
};

class treeNode{
public:
	int count;
	char data;
	
	treeNode *leftChild;
	treeNode *rightChild;
	treeNode():leftChild(NULL), rightChild(NULL){
		//this->isLeaf = 0;
		//this->isWord = 0;
	}
	bool operator()(treeNode *a, treeNode *b){ return a->count > b->count; }

};
void lowerChar(string &str){
	std::transform(str.begin(),str.end(),str.begin(),::tolower);
}

priority_queue<treeNode*, vector<treeNode*>, treeNode> pq;
vector<string> suffixGen(string str){
	vector<string> suffixes;
	for (int i = 0; i < str.size(); i++){
		suffixes.push_back(str.substr(i,str.size()));
	}
	return suffixes;
}
//  insert data into trie data structure
int insertTri(trieTree<int> *trie,string str){
	if (str.size() == 1 && trie->dataChain[str[0]-C] == NULL){
		trieTree<int> *tempTri = new trieTree<int>(30);
		tempTri->init();
		tempTri->data = str[0];
		tempTri->isWord = 1;
		tempTri->isLeaf = 1;
		trie->dataChain[str[0]-C] = tempTri;
		return 0;
	}
	else if (str.size() == 1){
		trie->dataChain[str[0]-C]->isWord = 1;
		return 0;
	}
	else{
		if (trie->dataChain[str[0]-C] != NULL){
			//trie->dataChain[str[0]] = new trieTree<int>(200);
			insertTri(trie->dataChain[str[0]-C], str.substr(1, str.size()));
		}
		else{
			
			trie->dataChain[str[0]-C] = new trieTree<int>(200);
			trie->dataChain[str[0]-C]->data = str[0];
			trie->dataChain[str[0]-C]->init();
			insertTri(trie->dataChain[str[0]-C], str.substr(1, str.size()));
		}
	}

	return 1;
}
treeNode* treeInsert(treeNode *child1, treeNode *child2){
	treeNode *newNode = new treeNode();
	newNode->count = child1->count + child2->count;
	newNode->data = '\0';
	if (child1->data > child2->data){
		newNode->leftChild = child2;
		newNode->rightChild = child1;
	}
	else{
		newNode->leftChild = child1;
		newNode->rightChild = child2;
	}
	return newNode;
}
// huffman code generation 
treeNode* build_huffman(){
	while (pq.size() != 1){
		treeNode* c1 = pq.top();
		pq.pop();
		treeNode *c2 = pq.top();
		pq.pop();
		pq.push(treeInsert(c1, c2));
	}
	return pq.top();
}

void create_code(treeNode * root, string &con,map<char,string> &result){
	if (root->data != '\0'){
		result.insert(make_pair(root->data,con));
		return;
	}
	if (root->leftChild != NULL){
		con.push_back('0');
		//cout <<"left"<<" "<< con <<" "<<root->data<< endl;
		create_code(root->leftChild, con, result);
		con.pop_back();
	}
	if (root->rightChild != NULL){
		con.push_back('1');
		//cout << "right" << " " << con <<" " << root->data <<endl;
		create_code(root->rightChild, con, result);
		con.pop_back();
	}
	return;
}
// Traversing Trie data structure
void dfsTraversal(trieTree<int> *root,string &str){
	if (root == NULL){
		cout << "Done inorder traversal" << endl;
		return;
	}
	for (unsigned int i = 0; i < root->size; i++){
		if (root->dataChain[i] != NULL){
			str.push_back((char)( i+C));
			
			if (root->dataChain[i]->isWord == 1 || root->dataChain[i]->isLeaf == 1)
				cout << str << endl;
			dfsTraversal(root->dataChain[i],str);
			str.pop_back();
		
		}
	}
	return;
}
void dfsForcounter(trieTree<int> *root, string str,int &counter){
	if (root == NULL){
		return;
	}

	for (unsigned int i = 0; i < root->size; i++){
		if (root->dataChain[i] != NULL && str.size() == 1){
			if (root->dataChain[i]->isWord == 1 && ((char)(i+C)) == str[0])
				counter += 1;
			return;
		}
		else if (root->dataChain[i] != NULL){
			if (((char)(i+C)) == str[0])
				dfsForcounter(root->dataChain[i], str.substr(1, str.size()), counter);
			else
				dfsForcounter(root->dataChain[i], str, counter);
		}
		
	}
	return;
}
int main(){
    
    int n;
	string str;
	vector<string> strList;
	
	cin >> n;
	strList.reserve(n);
	trieTree<int> *trieRoot = new trieTree<int>(30);
	trieRoot->init();
	while (n--){
		cin >> str;
		strList.push_back(str);
	}
	sort(strList.begin(),strList.end());
	cin >> n;
    vector<string> strList2;
	while (n--){
		cin >> str;
		strList2.push_back(str);
	}
    int counter = 0;
    for (int i = 0; i < strList2.size(); i++){
        counter = 0;
        int start = 0;
        int end = strList.size()-1;
        
        while(start <= end){
            int mid =  (start+end)/2;
            if(strList[mid][0] == strList2[i][0]){
                for(int j = mid ; j< strList.size(); j++){
                    if(strList[j] == strList2[i])
                        counter++;
                    if(strList[j][0] != strList2[i][0])
                        break;
                }
                for(int j = mid-1 ; j>= 0; j--){
                    if(strList[j] == strList2[i])
                        counter++;
                    if(strList[j][0] != strList2[i][0])
                        break;
                }
                break;
            }else{
                if(strList[mid][0] < strList2[i][0])
                    start = mid+1;
                else
                    end = mid - 1;
                    
            }
            
        }
        cout << counter <<endl;
       
    }
	

}
int main2(){
	int n;
	string str;
	vector<string> strList;
	
	cin >> n;
	strList.reserve(n);
	trieTree<int> *trieRoot = new trieTree<int>(30);
	trieRoot->init();
	while (n--){
		cin >> str;
		strList.push_back(str);
	}
	for (int i = 0; i < strList.size(); i++){
		//cout << "input str: " << strList[i] << endl;
		vector<string> tempList = suffixGen(strList[i]);
		for (int j = 0; j < tempList.size(); j++){
			//cout << tempList[j] << endl;
			insertTri(trieRoot,tempList[j]);
		}
	}
	cin >> n;
	strList.clear();
	while (n--){
		cin >> str;
		strList.push_back(str);
	}
	int counter = 0;
	for (int i = 0; i < strList.size(); i++){
		dfsForcounter(trieRoot,strList[i],counter);
		cout << counter << endl;
		counter = 0;
	}
	return 1;
}
int main_1_(){
	string str;
	vector<pair<char, int>> vec;
	string strings("abac");
	vector<string> var = suffixGen(strings);
	trieTree<int> *trieRoot = new trieTree<int>(200);
	trieRoot->init();
	//trieRoot->data = NULL;
	cout << "Start of trie Execution" << endl;
	for (vector<string>::iterator it = var.begin(); it != var.end(); it++){
		string tempStr = *it;
		insertTri(trieRoot,tempStr);
	}
	string str1;
	dfsTraversal(trieRoot,str1);
	cout << "End of trie Execution" << endl;
	vec.push_back(make_pair('a',5));
	vec.push_back(make_pair('b', 9));
	vec.push_back(make_pair('c', 12));
	vec.push_back(make_pair('d', 13));
	vec.push_back(make_pair('e', 16));
	vec.push_back(make_pair('f', 45));
	for (int i = 0; i < vec.size(); i++){
		treeNode *tn = new treeNode();
		tn->data = vec[i].first;
		tn->count = vec[i].second;
		pq.push(tn);
	}
	map<char, string> resultMap;
	treeNode * ht = build_huffman();
	create_code(ht, str, resultMap);
	for (map<char, string>::iterator it = resultMap.begin(); it != resultMap.end(); it++)
		cout << it->first << " " << it->second << endl;

	return -1;
}