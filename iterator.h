#ifndef _ITERATOR_H_
#define _ITERATOR_H_
#include "Node.h"
#include "linkedList.h"
using namespace std;
template <class T>
class Iterator1{
    private:
        
        Node<T> * actual;
         
    public:
        Node<T>* getActual();
        Iterator1(Node<T> * C);
        Iterator1<T>& operator+=(const T valor){
            
            this->actual->value += valor;
            return *this;
        }
        Iterator1<T>& operator++() {
            actual = actual->next;
            return *this;
        }
        bool operator!=(const Iterator1<T>& i) const {
            return this->actual != i.actual;

        }
        friend std::ostream& operator <<(std::ostream &salida1,const Iterator1& it){
            cout<<it.actual->getValue();
            return salida1;
        }
};
template <class T>
Iterator1<T>::Iterator1(Node<T> * C){
    actual = C;
}
template <class T>
Node<T>* Iterator1<T>::getActual(){
    return actual;
}
#endif
