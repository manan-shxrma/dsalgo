#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    class Node{
        public:
        int data;
        Node* prev;
        Node* next;
        Node(int val){
            data = val;
            prev = NULL;
            next = NULL;
        }
    };
    Node* head = new Node(-1);
    Node* tail = new Node(-1);
    
    void addNode(Node* newNode){
        Node *temp = head->next;
        head->next = newNode;
        newNode->next = temp;
        temp->prev = newNode;
        newNode->prev = head;
    }
    
    void deleteNode(Node* del){
        del->next->prev = del->prev;
        del->prev->next = del->next;
        delete del;
    }
    int pageFaults(int N, int C, int pages[]){
        head->next = tail;
        tail->prev= head;
        int size = 0;
        unordered_map<int,Node*> map;
        int ans = 0;
        
        for(int i=0;i<N;i++){
           if(map.find(pages[i])!= map.end()){
               deleteNode(map[pages[i]]);
               map[pages[i]] = new Node(pages[i]);
               addNode(map[pages[i]]);
           } 
           else if(size<C){
               map[pages[i]] = new Node(pages[i]);
               addNode(map[pages[i]]);
               size++;
               ans++;
           }
           else{
               map.erase(tail->prev->data);
               deleteNode(tail->prev);
               map[pages[i]] = new Node(pages[i]);
               addNode(map[pages[i]]);
               ans++;
           }
        }
        return ans;
    }
};

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,c;
    cin>>n;
    int pages[n];
    for(int i=0;i<n;i++){
      cin>>pages[i];
    }
    cin >> c;
    
    Solution ob;
    cout<< ob.pageFaults(n,c,pages)<<endl;
  }
  return 0;
}
