//
// Created by Oemer on 02.06.2020.
//

#include <c++/4.8.3/cassert>
#include <zconf.h>
#include <c++/4.8.3/iostream>
#include "LinkedList.h"

//private Utility functions
void LinkedList::swap(LinkedList::ListItem *l1, LinkedList::ListItem *l2) {
    std::cout<<"swap Values in List"<<std::endl;
    void *temp = l1->value;
    l1->value = l2->value;
    l2->value = temp;
}

LinkedList::ListItem *LinkedList::pos(int i) {
    std::cout<<"iterate by index in List "<<std::endl;
    assert(i < size && "Index out of Range");
    ListItem *p = head;
    if (i < 0) {
        for (int k = i; k != 0; k++) {
            p = p->prev;
        }
    } else {
        for (int k = i; k != 0; k--) {
            p = p->next;
        }
    }
    return p;
}

LinkedList::ListItem *LinkedList::val(void *value, bool doAssert) {
    std::cout<<"iterate by value in List"<<std::endl;
    ListItem *l = head;
    for (int i = 0; i < size; ++i) {
        if (l->value == value) { return l; }
        l = l->next;
    }
    assert(doAssert && "Value not Found!");
    return sentinel;
}


void LinkedList::unlink(LinkedList::ListItem *p) {
    std::cout<<"unlink in List"<<std::endl;
    p->next->prev = p->prev;
    p->prev->next = p->next;


}

//Main Methods
bool LinkedList::add(void *value) {
    std::cout<<"add to List"<<std::endl;
    addLast(value);
}

bool LinkedList::addAt(int i, void *value) {
    std::cout<<"add to List"<<std::endl;
    size++;
    ListItem *p = LinkedList::pos(i);

    auto *l = new ListItem(value, p->prev, p);
    if (size == 1) {
        head = l;
    }
    if (i == size - 1) {
        tail = l;
    }
    p->next->prev = l;
    p->next = l;
    return true;
}

bool LinkedList::remove(void *value) {
    std::cout<<"rm from List"<<std::endl;
    ListItem *p = val(value);
    if (p != sentinel) {
        if (head == p) {
            head = p->next;
        }
        if (tail == p) {
            tail = p->prev;
        }
        unlink(p);
        delete p;
        size--;

        return true;
    }
    return false;
}

bool LinkedList::removeAt(int i) {
    std::cout<<"rm from List"<<std::endl;
    ListItem *p = LinkedList::pos(i);
    if (head == p) {
        head = p->next;
    }
    if (tail == p) {
        tail = p->prev;
    }
    unlink(p);
    delete p;
    size--;
    return true;
}

void *LinkedList::pop(void *value) {
    std::cout<<"pop from List"<<std::endl;
    ListItem *p = val(value);
    if (p != sentinel) {
        void *temp = p->value;
        unlink(p);
        delete p;
        size--;
        return temp;
    }

    return nullptr;
}


void *LinkedList::popAt(int i) {
    std::cout<<"pop from List"<<std::endl;
    ListItem *p = pos(i);
    void *temp = p->value;
    unlink(p);
    delete p;
    size--;
    return temp;

}

void *LinkedList::get(int i) {
    std::cout<<"get from List"<<std::endl;
    return LinkedList::pos(i)->value;
}

bool LinkedList::set(int i, void *value) {
    std::cout<<"set in List"<<std::endl;
    LinkedList::pos(i)->value = value;
    return true;
}

bool LinkedList::replace(void *value, void *newValue) {
    std::cout<<"preplace in List"<<std::endl;
    ListItem *p = val(value);
    if (p == sentinel) {
        return false;
    }
    p->value = newValue;
    return true;
}

bool LinkedList::exists(void *value) {
    std::cout<<"check in List"<<std::endl;
    ListItem *p = val(value);
    return p != sentinel;
}

//TODO better performance
void LinkedList::clear() {
    while (size > 0) {
        removeFirst();
    }
}

void LinkedList::sort(int (*comp)(void *, void *)) {
    ListItem *p = head;
    for (int i = 0; i < size - 1; ++i) {
        p = head;
        for (int j = 0; j < size - i - 1; ++j) {
            if (comp(p, p->next) > 0) { swap(p, p->next); }
            p = p->next;
        }
    }
}

bool LinkedList::isEmpty() {
    return size == 0;
}

int LinkedList::getSize() {
    return size;
}

void *LinkedList::pop() {
    std::cout<<"pop from List"<<std::endl;
    assert(isEmpty());
    void *value = tail->value;
    removeLast();
    return value;

}

LinkedList::Iterator *LinkedList::iterator() {
    std::cout<<"Iterator from"<<std::endl;
    return new Iterator(this);
}

bool LinkedList::removeLast() {
    std::cout<<"rm from List"<<std::endl;
    if (isEmpty()) {
        return false;
    } else {
        ListItem *last = tail;
        unlink(last);
        tail = last->prev;
        if(size==1){
            head=tail;
        }
        delete last;
        return true;
    }
}

bool LinkedList::addLast(void *value) {
    std::cout<<"add to List"<<std::endl;
    auto *l = new ListItem(value, sentinel, tail);
    l->prev->next = l;
    l->next->prev = l;
    if (isEmpty()) {
        head = l;
    }
    tail = l;
    size++;
    return true;
}

bool LinkedList::addFirst(void *value) {
    std::cout<<"add to List"<<std::endl;
    auto *l = new ListItem(value, head, sentinel);
    l->prev->next = l;
    l->next->prev = l;
    if (isEmpty()) {
        tail = l;
    }
    head = l;
    size++;
    return true;
}

bool LinkedList::removeFirst() {
    std::cout<<"rm from List"<<std::endl;
    if(isEmpty()) {return false;}
    else{
        ListItem *first = head;
        unlink(first);
        head=first->next;
        if(size==1){
            tail=head;
        }
        delete first;
        size--;
        return true;
    }

}

LinkedList::LinkedList() {
    std::cout<<"create list"<<std::endl;
    sentinel = new ListItem(nullptr, nullptr, nullptr);
    sentinel->next=sentinel;
    sentinel->prev=sentinel;
    head=sentinel;
    tail=sentinel;
    size=0;
}

LinkedList::~LinkedList() {
    clear();
    delete sentinel;
}

/*bool LinkedList::deleteValue(void *value) {
    void* v=pop(value);
    if(v== nullptr) return false;


}
*/

bool LinkedList::Iterator::hasNext() {
    return outa->sentinel != p->next;
}

void *LinkedList::Iterator::next() {
    assert(hasNext());
    return (p = p->next);
}

LinkedList::Iterator::Iterator(LinkedList *daddy) {
    outa = daddy;
    p = daddy->head;
}


