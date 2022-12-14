#ifndef BIGINTEGER_FOR_DATA_STRUCTURE_LIST_H
#define BIGINTEGER_FOR_DATA_STRUCTURE_LIST_H

#include<iostream>
#include<algorithm>

class List {
public:
    List();

    ~List();

    List(const List &);

    List(const std::string &str);

    const int &front();

    const int &back();

    int size() const;

    bool empty() const;

    void push_front(const int &);

    void push_back(const int &);

    void pop_front();

    void pop_back();

    void clear();

    void remove(const int &);

    List &operator=(const List &);

    void fix();

    void display();

    void displayAll();

    friend class BigInteger;

private:
    class ListNode {
    public:
        int val;
        ListNode *prev, *next;

        ListNode(const int &v) : val(v), next(nullptr), prev(nullptr) {}

        ListNode() : next(nullptr), prev(nullptr) {}
    };

    int len;
    ListNode *head;
    ListNode *tail;
};

#endif //BIGINTEGER_FOR_DATA_STRUCTURE_LIST_H