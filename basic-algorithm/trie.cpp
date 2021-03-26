
#include <iostream>
#include <vector>

using namespace std;


class Trie{

private:
  bool isEnd;
  vector<Trie *> next;

public:
  Trie(){
    isEnd = false;
    next = vector<Trie *>(26, nullptr);
  }

  void insert(string word){
    Trie *node = this;

    for(char c : word){
      int idx = c - 'a';
      if(node->next[idx] == nullptr){
        node->next[idx] = new Trie();
      }
      node = node->next[idx]; 
    }
    node->isEnd = true;
  }

  bool search(string word){
    Trie *node = this;

    for(char c : word){
      node = node->next[c - 'a'];
      if(node == nullptr) return false;
    }
    return node->isEnd;
  }

  bool isStartWith(string prefix){
    Trie *node = this;

    for(char c : prefix){
      node = node->next[c - 'a'];
      if(node == nullptr) return false;
    }
    return true;
  }
};


int main(){
  Trie t;
  t.insert("and");
  cout << t.search("and") << endl;
  cout << t.search("ad") << endl;
  
  cout << t.isStartWith("an") << endl;
  cout << t.isStartWith("ad") << endl;
}