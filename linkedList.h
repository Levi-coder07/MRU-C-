#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "Node.h"
#include "iterator.h"
using namespace std;
template <class T>

class LinkedList{
    private: 
        template<class U> friend class MRU;
        int size;
        Node<T>*head;
    public:
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList<T> &);
        LinkedList<T>& operator= (const LinkedList<T>&C);
        LinkedList<T>& operator=(LinkedList<T>&&C);
        LinkedList( LinkedList<T> &&);
        void push_front1(T x);
        void push_back(T x);
        void insert(T x,int pos);
        void remove(int pos);
        int getPosition(T x);
        friend std::ostream& operator <<(std::ostream &salida1,const LinkedList& C){
            Node<T>* actual = C.head; 
            while(actual!=nullptr){
                salida1 << actual->getValue()<<" ";
                actual = actual->getNextNode();
            }
            salida1 <<" [" <<C.size<<"]";
            return salida1;
        }
        bool search(T x);
        void removebyv(T x);
        Iterator1<T> begin();
        Iterator1<T> end();
       
};

template <class T>
LinkedList<T>::LinkedList(){
            this->head= nullptr;
            this->size = 0;
        }
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& C){
        cout<<"Copy constructor used"<<endl;
        this->size = 0;
        this->head = nullptr;
        Node<T> * actual = C.head;
        while(actual){
            this->push_back(actual->value);
            actual = actual->next;
        }
        } 
template <class T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>&C){
            cout<<"Copy assignment used"<<endl;
            this->size = 0;
            this->head = nullptr;
            Node<T> * actual = C.head;
            while(actual){
            this->push_back(actual->value);
            actual = actual->next;
        }
            return *this;
        }       
template <class T>        
LinkedList<T>::LinkedList( LinkedList<T>&& C){
        cout<<"Move constructor used"<<endl;
        this->size = C.size;
        C.size = 0;
        this->head = C.head;
        C.head = nullptr;
        }   
template <class T>         
 LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&&C){
            cout<<"Move assignment used"<<endl;
            this->size = C.size;
            C.size = 0;
            this->head = C.head;
            C.head = nullptr;
            return *this;
        }                  
template <class T>        
LinkedList<T>::~LinkedList(){
    Node <T>* actual= head;
    Node<T> * nextnode= nullptr;
    while(actual!=nullptr){
        nextnode = actual->next;//Tendremos el link al siguiente nodo
        delete actual;
        actual = nextnode;
    }
}
template <class T>  
Iterator1<T> LinkedList<T>::begin(){
    return Iterator1<T> (this->head);
}
template <class T>
Iterator1<T> LinkedList<T>::end(){
    Node<T>* actual = head;
    while(actual!=nullptr){
        actual= actual->next;
    }
    return actual;
}
template <class T>
void LinkedList<T>::push_front1(T x){
    if(head ==nullptr){
        //caso donde la lista este vacia
        head = new Node<T>(x);
    }else{
        Node<T>* actual = head;
        Node<T>* temp = new Node<T>(x);
        head = temp;
        temp->next =actual ;  
    }
    ++size;
}

template <class T>
void LinkedList<T>::push_back(T x){
    Node<T>* actual = head;
    if(head ==nullptr){
        //caso donde la lista este vacia
        head = new Node<T>(x);
    }else{
        while(actual->next!=nullptr){
            actual = actual->next;
        }
        Node<T>* temp = new Node<T>(x);
        actual->next = temp;
    }
    ++size;   
}
template <class T>
void LinkedList<T>::insert(T x, int pos){
    Node<T>* actual = head;
    Node<T>* actual3 = head;
    int i = 0;
    if(head ==nullptr){
        //caso donde la lista este vacia
        head = new Node<T>(x);
    }   
    else {
        while(actual->next!=nullptr){
            if(pos==0){
                Node<T>* actual = head;
                Node<T>* temp = new Node<T>(x);
                head = temp;
                temp->next =actual ; 
                break; 
            }
            else if(pos-1==i){
                Node<T>* temp = new Node<T>(x);
                Node<T>* temp2 = actual->next;//Guardo donde apunta actual->next para poder enlazar la lista
                actual->next=temp;//actualizo a donde apunta actual->next a el nodo que he creado 
                temp->next = temp2;//Enlazo el nuevo nodo a temp 2
                break;
            }
            ++i;
            actual = actual->next;
            if(actual->next==nullptr){
                Node<T>* temp = new Node<T>(x);
                actual->next = temp;
                break;
            }
        }
        size++;
    }
}
template <class T>
void LinkedList<T>::remove(int pos){
    Node<T>* actual = head;
    if(pos==0){
            head = actual->next;
            delete actual;
            size--;
            return;
    }
    for (int i=0;i<=size;i++){
        if(pos-1==i){
        //actual=actual->next;
        //actual apunta al pos-1
        Node <T>* actual2=actual->next;//actual 2 apunta al elemnto que quiero remover
        actual->next =actual2->next;//aqui reasigno actual al siguiente elemento
        delete actual2;
        break;
        }
        actual=actual->next;
        
    }
    size--;
}
template <class T>
bool LinkedList<T>::search(T x){
    Node<T>* actual = head;
    while (actual!=nullptr){
        if(actual->value==x){
            
            return true;
        }
        actual = actual->next;
    }
    
    return false;
}
template <class T>
int LinkedList<T>::getPosition(T x){
    Node<T>* actual = head;
    int pos = 0;
    while (actual!=nullptr){
        if(actual->value==x){
            return pos;
        }
        actual = actual->next;
        pos++;
    }
    return 0;
}
template <class T>
void LinkedList<T>::removebyv(T x){
    Node<T>* actual = head;
    Node<T>* actual3 = head;
    while (actual!=nullptr){
        if(actual->value==x){
            Node <T>* actual2=actual3->next;//actual 2 apunta al elemnto que quiero remover
            actual3->next =actual2->next;//aqui reasigno actual al siguiente elemento
            delete actual2;
            break;
        }
        actual3 = actual;
        actual = actual->next;
    }
    size--;
}


#endif 
