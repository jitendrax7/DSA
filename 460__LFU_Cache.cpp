#include <iostream>
#include <unordered_map>
using namespace std;



class LFUCache {
    public:
        class Node {
        public:
            int key, value, count;
            Node* prev;
            Node* next;
            Node(int k, int val ){
                key = k;
                value = val;
                count = 1;
                prev=next = NULL;
            }
        };

        class Nodelist{
            public:
                Node* head;
                Node* tail;
                
                Nodelist(){
                    head = NULL;
                    tail = NULL;
                }

                bool empty(){
                    return !head;
                }

                void addNode(Node * newNode){
                    if(!head){
                        head = tail = newNode;
                        
                    }else{
                        newNode->next = head;
                        head->prev = newNode;
                        head = newNode;
                    }
                }

                Node* deleteNode(Node* node = NULL){
                    if(!node) node = tail;

                    if(node == head && node == tail){
                        head = tail = NULL;
                    }else{
                        if(node==head){
                            head = head->next;
                            if(head) head->prev = NULL;
                        }else if(node==tail){
                            tail = tail->prev;
                            tail->next = NULL;
                        }else{        
                            node->prev->next = node->next;
                            node->next->prev = node->prev;
                        }
                        node->next = node->prev = NULL; 
                    }    
                    
                    return node;
                }
        };

        

        unordered_map<int,Nodelist> freqlist; 
        unordered_map<int,Node*> keyNode; 

        int capacity;
        int least_freq;
        int curr_size;

        void updatefrequency(Node* node){
            int old_freq = node->count;

            freqlist[old_freq].deleteNode(node);

            if(old_freq==least_freq && freqlist[old_freq].empty()) least_freq++;

            node->count++;

            freqlist[node->count].addNode(node);
        }

        LFUCache(int c) {
            capacity = c;
            least_freq = 1;
            curr_size = 0;
        }
        
        int get(int key) {
            if(keyNode.find(key)!= keyNode.end()){
                Node* node = keyNode[key];
                updatefrequency(node);
                return node->value;
            }
            return -1;
        }
        
        void put(int key, int value) {

            if(capacity==0) return;

            if (keyNode.find(key)!= keyNode.end()){
                Node* node = keyNode[key];
                node->value = value;
                updatefrequency(node);
                return;
            }

            if(curr_size==capacity){
                Node* node = freqlist[least_freq].deleteNode();
                keyNode.erase(node->key);
                delete node;
                curr_size--;
            }

            least_freq = 1;

            Node * newnode = new Node(key ,value);
           
            freqlist[least_freq].addNode(newnode);
            keyNode[key] = newnode;
            curr_size ++;
        }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


int main(){

    LFUCache obj =  LFUCache(2);

    obj.put(1,1);
    obj.put(2,2);
    cout<<obj.get(1)<<" ";
    obj.put(3,3);
    cout<<obj.get(2)<<" ";
    cout<<obj.get(3)<<" ";
    obj.put(4,4);
    cout<<obj.get(1)<<" ";
    cout<<obj.get(3)<<" ";
    cout<<obj.get(4)<<" ";


    return 0;
}