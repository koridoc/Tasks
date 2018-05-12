#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

struct TNode{
	int count;
	char ch;
	TNode *left, *right;
	
	TNode(TNode *left, TNode *right) : left(left), right(right) {
		count = left->count + right->count;
		ch = '\0';
	}
	TNode(char ch, int count) : ch(ch), count(count) {
		left = right = nullptr;
	}
	~TNode(){
		if(left) delete left;
		if(right) delete right;
	}

	friend bool operator<(const TNode &left, const TNode &right){
		if (left.count == right.count)
			return left.ch < right.ch;

		return left.count < right.count;
	}

	static bool comp(const TNode *a, const TNode *b) {
		return (*a) < (*b);
	}
};

class haffman{
public:
	void compess(string s) {
		for(auto i: s)
			charMap[i]++;
		auto tree = buildTree();
		buildCT(tree);

		if(tree->ch != '\0')
			codeTable[tree->ch] = "0";
		
		string str = getCmpStr(s);

		cout<<codeTable.size()<<" "<<str.size()<<endl;
		for (auto i : codeTable) {
			cout<<i.first<<": "<<i.second<<endl;
		}
		cout<<str;
	};
	string getCmpStr(string s){
		string str = "";
		for (auto i:s)
			str+=codeTable[i];
		return str;
	};

private:
	map<char,int> charMap;
	map<char,string> codeTable;
	string code;

	TNode *buildTree() {
		list<TNode *> q;
		
		for (auto i: charMap){
			q.push_back(new TNode(i.first,i.second));
		}
		while (q.size() != 1){
			q.sort(TNode::comp);
			TNode *left = q.front(); q.pop_front();
			TNode *right = q.front(); q.pop_front();
			q.push_back(new TNode(left, right));
		}
		return q.front();
	}

	void buildCT(TNode *node) {
		if (node->right != nullptr) {
			code += '0';
			buildCT(node->right);
		}
		if(node->left != nullptr){
			code+='1';
			buildCT(node->left);
		}
		if (node->ch != '\0')
			codeTable[node->ch] = code;
		if(!code.empty()) code.pop_back();
	};
};



int main(){
	haffman cmp;
	string s = "";
	map<string,char> q;
	cout<<s;
	getline(cin,s);
	cmp.compess(s);

	//getchar();
	return 0;
}