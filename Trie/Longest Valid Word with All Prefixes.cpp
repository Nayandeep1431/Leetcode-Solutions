int n;

class Node {
public:
    Node* links[26] = {nullptr};
    bool flag = false;
    int cntPrefix = 0;

    bool containsKey(char ch) {
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

    void increasePrefix() {
        cntPrefix++;
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
            if (!node->containsKey(ch))
                node->put(ch, new Node());

            node = node->get(ch);
            node->increasePrefix();
        }

        node->setEnd();
    }

    bool check(string s) {
        Node* node = root;

        for (char ch : s) {
            if (!node->containsKey(ch))
                return false;

            node = node->get(ch);

            if (!node->isEnd())
                return false;
        }

        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {

        Trie trie;

        for (auto &s : words)
            trie.insert(s);

        string ans = "";

        for (auto &s : words) {
            if (trie.check(s)) {
                if (s.length() > ans.length())
                    ans = s;
                else if (s.length() == ans.length() && s < ans)
                    ans = s;
            }
        }

        return ans;
    }
};
