#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

class AhoCora{
	struct Trie{
		vector<Trie *> next;
		Trie *fail;
		vector<int> termId;
		int alphaCnt;
		Trie(int alphaCnt){
			this->alphaCnt = alphaCnt;
			next = vector<Trie *>(alphaCnt, NULL);
		}
		void insert(string& str, int pos, int id){
			int to = char2id(str[pos]);
			if(next[to] == NULL) next[to] = new Trie(alphaCnt);
			if(pos == (int)str.size() - 1) {
				termId.push_back(id);
				return;
			}
			next[to]->insert(str, pos + 1, id);
		}

		int char2id(char c){
			return c - 'a';
		}
	};
	int alphaCnt;
	Trie *root;
public:
	AhoCora(vector<string>& init, int alphaCnt){
		this->alphaCnt = alphaCnt;
		root = new Trie(alphaCnt);
		for(int i = 0 ; i < (int)init.size(); i++){
			root->insert(init[i], 0, i);
		}
	}
	void calcFailFunc(){
		queue<Trie *> q;
		q.push(root);
		while(!q.empty()){

			Trie *prev = q.front();
			q.pop();
			for(int to = 0 ; to < alphaCnt; to++){
				if(prev->next[to] == NULL) continue;
				Trie *cur = prev->next[to];
				Trie *mov = prev;
				while(mov != root) {
					if(mov->next[to]) cur->fail = mov->fail;
					mov = mov->fail;
				}
			}

		}

	}
	int char2id(char c){
		return c - 'a';
	}
	vector<pair<int,int> > getMatched(string& str){
		return vector<pair<int,int> >();
	}
};	

vector<string> vs;
int main() {
	vs.push_back("abcd");
	vs.push_back("abdd");
	vs.push_back("abde");
	AhoCora aho(vs, 26);

	return 0;
}