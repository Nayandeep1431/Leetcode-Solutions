struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
}; 

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkPrefix(string s) {
        Node* node = root;
        for (int i = 0; i < s.length(); i++) {
            if (node->containsKey(s[i])) {
                node = node->get(s[i]);
                if (!node->isEnd()) return false;
            } else {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    string longestString(vector<string> &words) {
        Trie trie;
        for (auto &it : words) {
            trie.insert(it);
        }

        string ans = "";
        for (auto &it : words) {
            if (trie.checkPrefix(it)) {
                if (it.length() > ans.length() || (it.length() == ans.length() && it < ans))
                    ans = it;
            }
        }
        return ans;
    }
};
