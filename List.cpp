#ifndef BIGINTEGER_FOR_DATA_STRUCTURE_LIST_CPP
#define BIGINTEGER_FOR_DATA_STRUCTURE_LIST_CPP

#include "List.h"

#define MAX_LEN 200

List::List() : head(new ListNode()), tail(new ListNode()), len(0) {
    tail->prev = head;
    head->next = tail;
}

List::List(const List &rhs) {
    head = new ListNode();
    tail = new ListNode();
    tail->prev = head;
    head->next = tail;
    len = 0;
    ListNode *tmp = rhs.head->next;
    while (tmp != rhs.tail) {
        push_back(tmp->val);
        tmp = tmp->next;
    }
}

List::List(const std::string &str) {
    head = new ListNode();
    tail = new ListNode();
    tail->prev = head;
    head->next = tail;
    len = 0;
    for (int i = 0; i < std::max(MAX_LEN, (int) str.length()); i++)
        if (i >= str.length()) push_front(0);
        else push_back(int(str[i]) - 48);
}

List::~List() {
    clear();
    delete head;
    delete tail;
}

const int &List::front() {
    if (!empty())
        return head->next->val;
}

const int &List::back() {
    if (!empty())
        return tail->prev->val;
}

int List::size() const {
    return len;
}

bool List::empty() const {
    if (len == 0)
        return true;
    else
        return false;
}

void List::push_front(const int &elem) {
    auto *tmp = new ListNode(elem);
    tmp->prev = head;
    head->next->prev = tmp;
    tmp->next = head->next;
    head->next = tmp;
    len++;
}

void List::push_back(const int &elem) {
    auto *tmp = new ListNode(elem);
    tmp->next = tail;
    tail->prev->next = tmp;
    tmp->prev = tail->prev;
    tail->prev = tmp;
    len++;
}

void List::pop_front() {
    if (empty())
        return;
    ListNode *tmp = head->next;
    tmp->next->prev = head;
    head->next = tmp->next;
    delete tmp;
    len--;
}

void List::pop_back() {
    if (empty())
        return;
    ListNode *tmp = tail->prev;
    tmp->prev->next = tail;
    tail->prev = tmp->prev;
    delete tmp;
    len--;
}

void List::clear() {
    while (!empty())
        pop_back();
}

void List::remove(const int &elem) {
    if (empty())
        return;
    ListNode *tmp = head->next;
    while (tmp != tail) {
        if (tmp->val == elem) {
            ListNode *p = tmp;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            tmp = tmp->next;
            delete p;
            len--;
        } else
            tmp = tmp->next;
    }
}

List &List::operator=(const List &rhs) {
    if (this == &rhs) return *this;
    clear();
    ListNode *tmp = rhs.head->next;
    while (tmp != rhs.tail) {
        push_back(tmp->val);
        tmp = tmp->next;
    }
    return *this;
}

void List::fix() {
}

void List::display() {
    bool flag = false;
    ListNode *tmp = head->next;
    while (tmp != tail) {
        if (tmp->val > 0)
            flag = true;
        if (flag || tmp->next == tail)
            std::cout << tmp->val;
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

#endif //BIGINTEGER_FOR_DATA_STRUCTURE_LIST_CPP
