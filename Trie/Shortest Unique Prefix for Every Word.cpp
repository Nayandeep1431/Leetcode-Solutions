class Node {
public:
    Node* links[26] = {nullptr};
    bool flag = false;
    int cnt = 0;

    bool contains(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }

    void increaseCnt() {
        cnt++;
    }

    int getCnt() {
        return cnt;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string s) {
        Node* node = root;

        for (char ch : s) {
            if (!node->contains(ch))
                node->put(ch, new Node());

            node = node->get(ch);
            node->increaseCnt();
        }

        node->setEnd();
    }

    string uniquePrefix(string s) {
        Node* node = root;
        string ans = "";

        for (char ch : s) {
            node = node->get(ch);
            ans.push_back(ch);

            if (node->getCnt() == 1)
                break;
        }

        return ans;
    }
};

class Solution {
public:
    vector<string> findPrefixes(vector<string>& arr) {

        Trie trie;

        for (auto &word : arr)
            trie.insert(word);

        vector<string> ans;

        for (auto &word : arr)
            ans.push_back(trie.uniquePrefix(word));

        return ans;
    }
};
