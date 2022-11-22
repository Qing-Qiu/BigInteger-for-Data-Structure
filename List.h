#ifndef BIGINTEGER_FOR_DATA_STRUCTURE_LIST_H
#define BIGINTEGER_FOR_DATA_STRUCTURE_LIST_H

template<typename T>
class List {
public:
    List();

    ~List();

    List(const List<T> &);

    const T &front();

    const T &back();

    int size();

    bool empty();

    void push_front(const T &);

    void push_back(const T &);

    void pop_front();

    void pop_back();

    void clear();

    void remove(const T &);

    const List<T> &operator=(const List<T> &);

    T &operator[](const int);

    void display();

private:
    class ListNode {
    public:
        T val;
        ListNode *prev, next;

        ListNode(const T &v) : val(v), next(nullptr), prev(nullptr) {}

        ListNode() : next(nullptr), prev(nullptr) {}
    };

    int len;
    ListNode *head;
    ListNode *tail;
};

template<typename T>
List<T>::List() : head(new ListNode()), tail(new ListNode()), len(0) {
    tail->prev = head;
    head->next = tail;
}

template<typename T>
List<T>::~List() {
    clear();
    delete head;
    delete tail;
}

template<typename T>
const T &List<T>::front() {
    if (!empty())
        return head->next->val;
}

template<typename T>
const T &List<T>::back() {
    if (!empty())
        return tail->prev->val;
}

template<typename T>
int List<T>::size() {
    return len;
}

template<typename T>
bool List<T>::empty() {
    if (len == 0)
        return true;
    else
        return false;
}

template<typename T>
void List<T>::push_front(const T &elem) {
    ListNode *tmp = new ListNode(elem);
    tmp->prev = head;
    head->next->prev = tmp;
    tmp->next = head->next;
    head->next = tmp;
    len++;
}

template<typename T>
void List<T>::push_back(const T &elem) {
    ListNode *tmp = new ListNode(elem);
    tmp->next = tail;
    tail->prev->next = tmp;
    tmp->prev = tail->prev;
    tail->prev = tmp;
    len++;
}

template<typename T>
void List<T>::pop_front() {
    if (empty())
        return;
    ListNode *tmp = head->next;
    tmp->next->prev = head;
    head->next = tmp->next;
    delete tmp;
    len--;
}

template<typename T>
void List<T>::pop_back() {
    if (empty())
        return;
    ListNode *tmp = tail->prev;
    tmp->prev->next = tail;
    tail->prev = tmp->prev;
    delete tmp;
    len--;
}

template<typename T>
void List<T>::clear() {
    while (!empty())
        pop_back();
}

template<typename T>
void List<T>::remove(const T &elem) {
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
            p = nullptr;
            len--;
        } else
            tmp = tmp->next;
    }
}

template<typename T>
const List<T> &List<T>::operator=(const List<T> &rhs) {

}

template<typename T>
T &List<T>::operator[](const int index) {
}

template<typename T>
void List<T>::display() {
}

#endif //BIGINTEGER_FOR_DATA_STRUCTURE_LIST_H
