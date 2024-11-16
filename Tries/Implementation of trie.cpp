/*

LeetCode-208. Implement Trie (Prefix Tree)
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as 
autocomplete and spellchecker.
Implement the Trie class:
Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 
*/
// A trie is a data structure that consists of a struct or class of data members boolean variable(flag) and a pointer of same class or struct.
// struct Node
// {
//     Node*links[26]; //a Node can store at max all alphabetical characters 26 characters 
//     bool flag=false;
// };
struct Node{
    Node *links[26];
    bool flag=false;
    Node(){
         for(int i=0; i<26; i++) { //Set all the links to nullptr
            links[i]=nullptr;
        }
    }
    bool containsKey(char ch){
        if(links[ch -'a']!=nullptr)  return true;
        else return false;
    }
    void put(char ch,Node*node){
        links[ch-'a']=node;
    }
    Node* getLink(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){ 
        return flag;
    }
};

class Trie {
    Node *root;
public:
    Trie() {
        root=new Node; 
    }
    
    void insert(string word) {
        Node*node=root; //Start with root node
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node()); //Create a new node and insert character
            }
            node=node->getLink(word[i]); //Update the node address with the reference of thet character
        }
        node->setEnd();  // At the end set flag of last characters reference node as  true indicating end of string
    }
    // To search if any word exists or not
    bool search(string word) {
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))  return false; //Word doesnt exist
            else
            node=node->getLink(word[i]);
        }
        return node->isEnd(); // If the reference of last letter contains true it means the wprd exist else not
        
    }
    // Returns if a prefix exists or not
    bool startsWith(string prefix) {
        Node*node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i]))  return false;
            else
            node=node->getLink(prefix[i]);
        }       
        return true; //Succesfully reached to the reference of last character -> prefix exists
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */