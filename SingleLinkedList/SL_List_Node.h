#ifndef PRACT5_6_SL_LIST_NODE_H
#define PRACT5_6_SL_LIST_NODE_H


template <class T>
class SL_List_Node {
public:
    SL_List_Node *next;
    T data;

    explicit SL_List_Node(T data) : data(data), next(nullptr) {}
    SL_List_Node() : data(), next(nullptr) {}
    virtual ~SL_List_Node() = default;
};


#endif //PRACT5_6_SL_LIST_NODE_H
