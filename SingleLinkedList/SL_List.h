#ifndef PRACT5_6_SL_LIST_H
#define PRACT5_6_SL_LIST_H


#include <ostream>
#include "SL_List_Node.h"

template <class T>
class SL_List {
    SL_List_Node<T>* head;
    SL_List_Node<T>* tail;
    unsigned int lenght;
public:
    SL_List() : lenght(0), head(), tail() {}
    SL_List(SL_List<T>&);
    explicit SL_List(T*);

    SL_List_Node<T> *getHead() const { return head; }
    SL_List_Node<T> *getTail() const { return tail; }
    void setHead(SL_List_Node<T> *head) { this->head = head; }
    void setTail(const SL_List_Node<T> *tail) { this->tail = tail; }

    unsigned int size() const { return lenght; }
    void pop(int idx=-1);
    void push_back(T);
    T* toArray();

    T& operator[](int idx);
    SL_List<T>& operator=(const SL_List& obj);

    template <class U> friend std::ostream &operator<<(std::ostream &os, const SL_List<U> &list);
};

template<class T>
SL_List<T>::SL_List(SL_List<T>& obj) : lenght(obj.lenght) {
    SL_List<T> ret;
    head = new SL_List_Node<T>;
    head->data = obj.head->data;
    SL_List_Node<T>* tmp1 = this->head;
    SL_List_Node<T>* tmp2 = obj.head;
    for(int i = 1; i < obj.lenght; i++){
        tmp1->next = new SL_List_Node<T>;
        tmp1->next->data = tmp2->next->data;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    tail = tmp1;
}

template<class T>
SL_List<T>::SL_List(T* list) : lenght(sizeof(list)) {
    head = new SL_List_Node<T>(list[0]);
    SL_List_Node<T>* tmp = head;
    for(int i = 1; i < lenght; i++){
        tmp->next = new SL_List_Node<T>(list[i]);
        tmp = tmp->next;
    }
    tail = tmp;
}

template<class T>
T* SL_List<T>::toArray() {
   T* ret = new T[lenght]();
   SL_List_Node<T>* tmp = this->head;
   for(int i = 0; i < lenght; i++){
       ret[i] = tmp->data;
       tmp = tmp->next;
   }
    return ret;
}

template<class T>
T& SL_List<T>::operator[](int idx) {
    SL_List_Node<T>* tmp = head;
    for(int i = 0; i < idx; i++){
        tmp = tmp->next;
    }
    return tmp->data;
}

template<class T>
void SL_List<T>::push_back(T data) {
    if(!head){ //list is empty
        this->head = new SL_List_Node<T>(data);
        this->head->next = nullptr;
        this->tail = this->head;
        lenght = 1;
        return;
    }
    this->tail->next = new SL_List_Node<T>(data);
    this->tail = this->tail->next;
    lenght++;
}


template<class T>
void SL_List<T>::pop(int idx) {
    if(!idx){
        SL_List_Node<T>* newhead = head->next;
        delete(this->head);
        this->head = newhead;
        lenght--;
        return;
    }
    if(idx == -1){
        SL_List_Node<T>* prev = head;
        for(int i = 0; i < lenght - 2; i++){
            prev = prev->next;
        }
        delete(tail);
        tail = prev;
        tail->next = nullptr;
        lenght--;
        return;
    }
    SL_List_Node<T>* tmp = head;
    SL_List_Node<T>* prev = head;
    for(int i = 0; i < idx; i++){
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = tmp->next;
    delete(tmp);
    lenght--;
}

template<class U>
std::ostream &operator<<(std::ostream &os, const SL_List<U> &list) {
        os << "[";
        SL_List_Node<U>* tmp = list.head;
        for(int i = 0; i < list.lenght - 1; i++){
            os << tmp->data << ", ";
            tmp = tmp->next;
        }
        os << tmp->data << "]";
        return os;
}

template<class T>
SL_List<T> &SL_List<T>::operator=(const SL_List &obj) {
    this->lenght = obj.lenght;
    head = new SL_List_Node<T>;
    head->data = obj.head->data;
    //std::cout << "DEBUG: " << head->data << std::endl;
    SL_List_Node<T>* tmp1 = this->head;
    SL_List_Node<T>* tmp2 = obj.head;
    for(int i = 1; i < obj.lenght; i++){
        tmp1->next = new SL_List_Node<T>;
        tmp1->next->data = tmp2->next->data;
        //std::cout << "DEBUG: " << tmp1->next->data << std::endl;
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    tail = tmp1;
    return *this;
}


#endif //PRACT5_6_SL_LIST_H
