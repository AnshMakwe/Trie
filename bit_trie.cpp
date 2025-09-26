struct Node{
    Node* link[2];
    bool containsKey(int bit){
        return link[bit] != NULL;
    }
    void put(int bit, Node* node){
        link[bit] = node;
    }
    Node* get(int bit){
        return link[bit];
    }
};
class Trie{
private:
    Node* root;
    
public:
    Trie(){
            root = new Node();
        }
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; --i){
            int bit = (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node* node = root;
        int maxi = 0;
        for(int i=31; i>=0; --i){
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit)){
                maxi = maxi | (1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxi;
    }

};
