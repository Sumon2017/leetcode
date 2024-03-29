/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
    vector<Node*>mymap;
    
    void dfs(Node* node , Node* deep_copy){
        
        for(int i=0;i<node->neighbors.size();i++){
            if(mymap[node->neighbors[i]->val] == nullptr){
                Node* temp = new Node(node->neighbors[i]->val);
                deep_copy->neighbors.push_back(temp);
                mymap[temp->val]=temp;
                dfs(node->neighbors[i],temp);
            }
            else{
                deep_copy->neighbors.push_back(mymap[node->neighbors[i]->val]);
            }
        }
        
    }
    
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)return nullptr;
        for(int i=0 ; i<=101; i++)mymap.push_back(nullptr);
        Node* first = new Node(node->val);
        mymap[node->val]=first;
        dfs(node,first);
        return first;
    }
};