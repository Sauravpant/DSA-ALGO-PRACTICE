/*
 Leetcode 211. Design Add and Search Words Data Structure
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 
*/

// Approach: For search functionality ---- if '.' is encountered then we have to try all the characters from that trie structure as '.' can be matched with any character so we recursively traverse
// in the word and if '.' is encountered we try all characters from that trie Node ,if we reach at the Trie node where there is true it means word exists else not.

class Node{
    public:
    Node *links[26];
    bool flag;
    Node(){
        flag=false;
        for(int i=0;i<26;i++) 
          links[i]=nullptr;
    }
    bool containsKey(char ch){
        return (links[ch-'a']!=nullptr);
    }
    Node* getLink(char ch){
        return links[ch-'a'];
    }

    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
};

class WordDictionary {
    Node*root;
    bool isValid(string word,int index,Node*node){
        if(index==word.length())  return node->flag;
        if(word[index]=='.'){
            for(int i=0;i<26;i++){
                if(node->links[i]!=nullptr && isValid(word,index+1,node->links[i]))
                return true;
            }
            return false;
        } 
        else {
            if(!node->containsKey(word[index]))  return false;
            return isValid(word,index+1,node->getLink(word[index]));
        }
    }
public:
    WordDictionary() {
        root=new Node(); 
    }
    
    void addWord(string word) {
        Node*node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->getLink(word[i]);
        }
        node->flag=true;  
    }
    
    bool search(string word) {
        Node*node=root;
        return isValid(word,0,node);

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */