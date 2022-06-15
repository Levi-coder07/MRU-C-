#ifndef _NODE_H_
#define _NODE_H_
template <class T>
class Node{
        template<class U> friend class LinkedList;
        template<class U> friend class Iterator1;
        template<class U> friend class MRU;
        T value;
        Node<T> *next;
    public:
        Node(T _value = 0 , Node<T>* _next = nullptr): 
            value(_value), next(_next){}
        //Node(int x);
        ~Node<T>();
        //friend std::ostream& operator <<(std::ostream &salida1,const LinkedList& C);
        void setNextNode(Node *next);
        void setValue(T value);
        Node<T>* getNextNode();
        T getValue();

};
/*Node::Node(int x){
    this->value=x;
    this->next =nullptr;
}*/
template <class T>
Node<T>::~Node(){
    
}
template <class T>
void Node<T>::setNextNode(Node<T> *next){
            this->next=next;
        }
template <class T>
void Node<T>::setValue(T value){
            this->value=value;
}
template <class T>
Node<T>* Node<T>::getNextNode(){
    return next;
}
template <class T>
T Node<T>::getValue(){
    return value;
}

#endif 
/*#ifndef __NODE_H__
#define __NODE_H__

class Node {    
    private:
        int value;
        Node *next;
    public:
        Node(int _value = 0 , Node* _next = nullptr): 
            value(_value), next(_next){}

		int getValue() const;
        void setValue(int);

		Node* getNext() const;               
        void setNext(Node*);

};

#endif*/