class WordDictionary {
public:
    struct trienode {
        trienode *children[26];
        bool endofword;
    };

    trienode *getnode() {
        trienode *newnode = new trienode();
        newnode->endofword = false;
        for (int i = 0; i < 26; i++) {
            newnode->children[i] = NULL;
        }
        return newnode;
    }

    trienode *root;

    WordDictionary() {
        root = getnode();
    }

    void addWord(string word) {
        trienode *crawler = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (crawler->children[idx] == NULL) {
                crawler->children[idx] = getnode();
            }
            crawler = crawler->children[idx];
        }
        crawler->endofword = true;
    }

    bool searchHelper(string &word, int idx, trienode *node) {
        if (idx == word.size()) return node->endofword;

        char ch = word[idx];
        if (ch == '.') {
            // Try all 26 possible children
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && searchHelper(word, idx + 1, node->children[i]))
                    return true;
            }
            return false;
        } else {
            int i = ch - 'a';
            if (node->children[i] == NULL) return false;
            return searchHelper(word, idx + 1, node->children[i]);
        }
    }

    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
