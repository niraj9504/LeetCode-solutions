class node{
    public:
    node* links[26];
    bool flag=false;
    
    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,node* curr){
        links[ch-'a']=curr;
    }
    node* get(char ch){
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
    
public:
    node* root;
    Trie() {
        root=new node();
    }
    
    void insert(string word) {
        node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containKey(word[i])){
                curr->put(word[i],new node());
            }
            curr=curr->get(word[i]);
        }
        curr->setEnd();
    }
    
    bool search(string word) {
        node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containKey(word[i])){
                return false;
            }
            curr=curr->get(word[i]);
        }
        return curr->isEnd();
    }
    
    bool startsWith(string word) {
         node* curr=root;
        for(int i=0;i<word.size();i++){
            if(!curr->containKey(word[i])){
                return false;
            }
            curr=curr->get(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */