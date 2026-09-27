class PrefixTree {
public:
    struct trieNode{
        trieNode *children[26];
        bool endofword;
    };
    trieNode *getNode(){
        trieNode*  newNode= new trieNode();
        newNode->endofword= false;
        for(int i=0;i<26;i++){
            newNode->children[i]=NULL;
        }
        return newNode;

    }
    trieNode *root;
    PrefixTree() {
        root= getNode();
    }
    
    void insert(string word) {
        trieNode *crawler=root;
        for(int i=0;i<word.size();i++){
            int idx= word[i]-'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]= getNode();
            }
            crawler= crawler->children[idx];
        }
        crawler->endofword=true;
    }
    
    bool search(string word) {

        trieNode *crawler=root;
        for(int i=0;i<word.size();i++){
            int idx= word[i]-'a';
            if(crawler->children[idx]==NULL){
                return false;
            }
            crawler= crawler->children[idx];
        }
        return(crawler!= NULL && crawler->endofword);
    }
    
    bool startsWith(string prefix) {
        int i=0;
        trieNode *crawler=root;
        for( i=0;i<prefix.size();i++){
            int idx= prefix[i]-'a';
            if(crawler->children[idx]==NULL){
                return false;
            }
            crawler= crawler->children[idx];
        }
        if(i==prefix.size()){
            return true;
        }
        return false;
        
    }
};
