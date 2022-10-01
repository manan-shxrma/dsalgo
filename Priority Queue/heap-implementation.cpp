#include <bits/stdc++.h>
using namespace std;

class PriorityQueue{
    vector<int> pq;
    public:
    PriorityQueue(){

    }
    int getSize(){
        return pq.size();
    }

    bool isEmpty(){
        return pq.size()==0;
    }

    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int data){
        pq.push_back(data);
        int CI = pq.size() - 1;
        while(CI>0){
            int PI = (CI - 1)/2;
            if(pq[CI]<pq[PI]){
                swap(pq[CI], pq[PI]);
                CI = PI;
            }
            else{
                break;
            }
        }
    }

    int removeMin(){
        if(isEmpty()){
            return 0;
        }
        int ans = pq[0];
        swap(pq[0], pq[pq.size()-1]);
        pq.pop_back();

        int pi = 0;
        while(true){
            int lci = 2*pi + 1;
            int rci = 2*pi + 2;
            int mini = pi;
            if(lci < pq.size() && pq[lci] < pq[mini]){
                mini = lci;
            }
            if(rci < pq.size() && pq[rci] < pq[mini]){
                mini = rci;
            }
            if(mini==pi) {
                break;
            }
            swap(pq[pi], pq[mini]);
            pi = mini;
        }
        return ans;
    }

};

int main(){
    PriorityQueue q;
    q.insert(100);
    q.insert(10);
    q.insert(15);
    q.insert(4);
    q.insert(17);
    q.insert(21);
    q.insert(67);
    cout<<q.getSize()<<endl;
    cout<<q.getMin()<<endl;
    while(!q.isEmpty()){
        cout<<q.removeMin()<<" ";
    }
    return 0;
}