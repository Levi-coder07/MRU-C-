#include <iostream>
#include "linkedList.h"
#include "Node.h"
template <class T>
class MRU
{
private:
    template<class U> friend class LinkedList;
    int bufferpool;
    Node<T> *MostRecentrlyUsed;
public:
    MRU(/* args */);
    LinkedList<T> MRUAlgorithm(T array[],int size);
    LinkedList<T> MRUAlgorithm2(T array[],int size);
    ~MRU();
    int getBufferpool();
    void setBufferpool(int x);
    
};

template <class T>
MRU<T>::MRU(/* args */)
{
    this->bufferpool = 0;
}
template <class T>
MRU<T>::~MRU()
{
}
template <class T>
int MRU<T>::getBufferpool(){
    return bufferpool;
}
template <class T>
void MRU<T>::setBufferpool(int x){
    this->bufferpool = x;
}
template <class T>
LinkedList<T> MRU<T>::MRUAlgorithm2(T array[], int size){
    LinkedList<T> frames;
    Node<T>*  actual = nullptr;
    int hit = 0, miss = 0;
    T MostRU;
    //Node<T> *MostRU= nullptr;
    int number = 0;
    for(int i = 0 ; i<size;i++){
        if(frames.head ==nullptr){
            frames.head = new Node<T>(array[i]);
            frames.size++;
            actual = frames.head;
            MostRU= actual->value;
            //cout<<actual->value;
            miss++;
            number++;
            cout<<frames<<" -> ";
            cout<<"MISS"<<endl;
        }else if(number<this->bufferpool){
        
            if(frames.search(array[i])==true){
                MostRU = actual->value;
                //cout<<actual->value;

                cout<<frames<<" -> ";
                cout<<"HIT"<<endl;
                hit++;
            }else{
                frames.push_back(array[i]);
                actual = actual->next;
                MostRU= actual->value;
                //cout<<actual->value;
                cout<<frames<<" -> ";
                cout<<"MISS"<<endl;
                miss++;
                number++;
            }
            
        }else{
            //cout<<frames<<endl;
            if(frames.search(array[i])==true){
                int pos = frames.getPosition(MostRU);
                int pos2 = frames.getPosition(array[i]);
                frames.remove(pos2);
                //cout<<frames<<endl;
                frames.push_back(array[i]);
                MostRU=array[i];
                //MostRU
                //cout<<MostRU<<" ";
                cout<<frames<<" -> ";
                cout<<"HIT"<<endl;
                 hit++;
            }else{
                int pos = frames.getPosition(MostRU);
                MostRU=array[i];
                //cout<<MostRU<<" ";
                frames.remove(pos);
                //cout<<frames<<endl;
                frames.push_back(array[i]);
                cout<<frames<<" ->< ";
                cout<<"MISS"<<endl;
                miss++;
            }
        }
    }
    cout<<"Hit rate: "<<hit<<"Miss Rate: "<<miss<<endl;
    return frames;

}
template <class T>
LinkedList<T> MRU<T>::MRUAlgorithm(T array[], int size){
    LinkedList<T> frames;
    Node<T>*  actual = nullptr;
    int hit = 0, miss = 0;
    T MostRU;
    int number = 0;
    for(int i = 0 ; i<size;i++){
        if(frames.head ==nullptr){
            frames.head = new Node<T>(array[i]);
            frames.size++;
            actual = frames.head;
            MostRU= actual->value;
            //cout<<actual->value;
            miss++;
            number++;
            cout<<frames<<" -> "<<MostRU<<" -> ";
            cout<<"MISS"<<endl;
        }else if(number<this->bufferpool){
            if(frames.search(array[i])==true){
                MostRU = actual->value;
                //cout<<actual->value;
                cout<<frames<<" -> "<<MostRU<<" -> ";
                cout<<"HIT"<<endl;
                hit++;
            }else{
                frames.push_back(array[i]);
                actual = actual->next;
                MostRU= actual->value;
                cout<<frames<<" -> "<<MostRU<<" -> ";
                cout<<"MISS"<<endl;
                miss++;
                number++;
            }
        }else{
            if(frames.search(array[i])==true){
                MostRU=array[i];
                cout<<frames<<" -> "<<MostRU<<" -> ";
                cout<<"HIT"<<endl;
                hit++;
            }else{
                int pos = frames.getPosition(MostRU);
                frames.remove(pos);
                frames.insert(array[i],pos);
                MostRU=array[i];
                cout<<frames<<" -> "<<MostRU<<" -> ";
                cout<<"MISS"<<endl;
                miss++;
            }
        }
    }
    cout<<"Hit rate: "<<hit<<" Miss Rate: "<<miss<<endl;
    return frames;

}
int main(){
    string array[] = {"A","B","D","D","E","A","E","C","A","B","C","A","E"};
    //int array[] = {1,2,3,4,5,1,2,3,4,1,2};
    int size = sizeof(array) / sizeof(string);
    int n = 4;
    MRU<string> Most;
    Most.setBufferpool(n);
    //cout<<Most.getBufferpool();
    LinkedList<string> C = Most.MRUAlgorithm(array,size);
    cout<<C;
}