#ifndef PRACT5_6_SL_LIST_H
#define PRACT5_6_SL_LIST_H


#include <ostream>
#include "SL_List_Node.h"

template <class T>
class SL_List {
    SL_List_Node<T>* head;
    SL_List_Node<T>* tail;
protected:
    size_t length;
public:
    SL_List() : length(0), head(), tail() {}
    SL_List(SL_List<T>&);
    explicit SL_List(T*);

    SL_List_Node<T> *getHead() const { return head; }
    SL_List_Node<T> *getTail() const { return tail; }
    void setHead(SL_List_Node<T> *head) { this->head = head; }
    void setTail(const SL_List_Node<T> *tail) { this->tail = tail; }

    size_t size() const { return length; }
    void pop(int idx=-1);
    void push_back(T);
    void insert(int, T);
    void swap(int, int);
    void clear();
    void bubble_sort();
    SL_List_Node<T>* getNode(int);
    T* toArray();

    T& operator[](int idx);
    SL_List<T>& operator=(const SL_List& obj);

    template <class U> friend std::ostream &operator<<(std::ostream &os, const SL_List<U> &list);
};

template<class T>
SL_List<T>::SL_List(SL_List<T>& obj) : length(obj.length) {
    if(obj.length != 0){
        SL_List<T> ret;
        head = new SL_List_Node<T>;
        head->data = obj.head->data;
        SL_List_Node<T>* tmp1 = this->head;
        SL_List_Node<T>* tmp2 = obj.head;
        for(int i = 1; i < obj.length; i++){
            tmp1->next = new SL_List_Node<T>;
            tmp1->next->data = tmp2->next->data;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        tail = tmp1;
    } else {
        this->head = nullptr;
        this->tail = nullptr;
    }
}

template<class T>
SL_List<T>::SL_List(T* list) : length(sizeof(list)) {
    head = new SL_List_Node<T>(list[0]);
    SL_List_Node<T>* tmp = head;
    for(int i = 1; i < length; i++){
        tmp->next = new SL_List_Node<T>(list[i]);
        tmp = tmp->next;
    }
    tail = tmp;
}

template<class T>
T* SL_List<T>::toArray() {
   T* ret = new T[length]();
   SL_List_Node<T>* tmp = this->head;
   for(int i = 0; i < length; i++){
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
        length = 1;
        return;
    }
    this->tail->next = new SL_List_Node<T>(data);
    this->tail = this->tail->next;
    length++;
}
template<class T>
void SL_List<T>::pop(int idx) {
    if(!idx){
        SL_List_Node<T>* newhead = head->next;
        delete(this->head);
        this->head = newhead;
        length--;
        return;
    }
    if(idx == -1){
        SL_List_Node<T>* prev = head;
        for(int i = 0; i < length - 2; i++){
            prev = prev->next;
        }
        delete(tail);
        tail = prev;
        tail->next = nullptr;
        length--;
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
    length--;
}

template<class U>
std::ostream &operator<<(std::ostream &os, const SL_List<U> &list) {
        os << "[";
        if(list.length > 0) {
            SL_List_Node<U>* tmp = list.head;
            for (int i = 0; i < list.length - 1; i++) {
                os << tmp->data << ", ";
                tmp = tmp->next;
            }
            os << tmp->data ;
        }
        return os << "]";
}

template<class T>
SL_List<T> &SL_List<T>::operator=(const SL_List &obj) {
    this->length = obj.length;
    head = new SL_List_Node<T>;
    if(obj.head) {
        head->data = obj.head->data;
        SL_List_Node<T> *tmp1 = this->head;
        SL_List_Node<T> *tmp2 = obj.head;
        for (int i = 1; i < obj.length; i++) {
            tmp1->next = new SL_List_Node<T>;
            tmp1->next->data = tmp2->next->data;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        tail = tmp1;
    } else
        head = tail = nullptr;
    return *this;
}

template<class T>
void SL_List<T>::insert(int index, T data) {
    SL_List_Node<T>* iter = head;
    for(; index > 0; index--) iter = iter->next;
    SL_List_Node<T>* newnode = new SL_List_Node<T>(data);
    newnode->next = iter->next;
    iter->next = newnode;
    length++;
}

template<class T>
void SL_List<T>::swap(int i, int j) {
    T tmp = this->getNode(i)->data;
    this->getNode(i)->data = this->getNode(j)->data;
    this->getNode(j)->data = tmp;
}

template<class T>
SL_List_Node<T> *SL_List<T>::getNode(int index) {
    SL_List_Node<T>* iter = head;
    for(; index > 0; index--) iter = iter->next;
    return iter;
}

template<class T>
void SL_List<T>::bubble_sort() {
    bool swapped;
    for(int i = 0; i < length - 1; i++){
        swapped = false;
        for(int j = 0; j < length - i - 1; j++){
            if(getNode(j)->data > getNode(j+1)->data) {
                swap(j, j + 1);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

#endif //PRACT5_6_SL_LIST_H
