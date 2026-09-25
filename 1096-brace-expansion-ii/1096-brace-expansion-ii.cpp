#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node {
public:
    Node* par = NULL;
    vector<Node> child, chain;
    vector<string> values;

    Node() {
        child.clear();
        chain.clear();
        values.clear();
    }
};

void reccur(string bef, ll idx, Node* inp) {
    vector<Node>* chain = &(inp->chain);
    if(idx == chain->size()) {
        inp->values.push_back(bef);
        return ;
    }
    for(int i = 0; i < (*chain)[idx].values.size(); i++) {
        reccur(bef + (*chain)[idx].values[i], idx+1, inp);
    }
}

void eval(Node* inp, bool isChild) {
    // Assume that each chain has been resolved
    if (isChild) {
        for (int i = 0; i < inp->child.size(); i++){
            Node* now = &(inp->child[i]);
            for(int j = 0; j < now->values.size(); j++) {
                inp->values.push_back(now->values[j]);
            }
        }
    } else {
        reccur("", 0, inp);
    } 
}

class Solution {
public:
    vector<string> braceExpansionII(string inp) {
        Node root;
        root.par = &root;
        Node* nowNode = &root;
        for (int i = 0; i < inp.size(); i++) {
            char now = inp[i];
            if(now == '{') {
                Node newNode;
                newNode.par = nowNode;
                nowNode->chain.push_back(newNode);
                newNode.par = &(nowNode->chain.back());
                nowNode->chain.back().child.push_back(newNode);
                nowNode = &(nowNode->chain.back().child.back());
            } else if (now == '}') {
                // Evalute string and jump back!
                eval(nowNode, false);
                nowNode = nowNode->par;
                eval(nowNode, true);
                nowNode = nowNode->par;
            } else if (now == ',') {
                eval(nowNode, false);
                Node newNode;
                nowNode = nowNode->par;
                newNode.par = nowNode;
                nowNode->child.push_back(newNode);
                nowNode = &(nowNode->child.back());
            } else {
                Node newNode;
                string cst = "";
                cst += now;
                newNode.values.push_back(cst);
                nowNode->chain.push_back(newNode);
            }
        }

        eval(nowNode, false);
        sort(root.values.begin(), root.values.end());
        root.values.erase(unique(root.values.begin(), root.values.end()), root.values.end());
        return root.values;
    }
};