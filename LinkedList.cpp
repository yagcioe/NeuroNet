//
// Created by Oemer on 02.06.2020.
//

#include <c++/4.8.3/cassert>
#include <zconf.h>
#include "LinkedList.h"

//private Utility functions
void LinkedList::swap(LinkedList::ListItem *l1, LinkedList::ListItem *l2) {
    void *temp = l1->value;
    l1->value = l2->value;
    l2->value = temp;
}

LinkedList::ListItem *LinkedList::pos(int i) {
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
    ListItem *l = head;
    for (int i = 0; i < size; ++i) {
        if (l->value == value) { return l; }
        l = l->next;
    }
    assert(doAssert && "Value not Found!");
    return sentinel;
}


void LinkedList::unlink(LinkedList::ListItem *p) {
    p->next->prev = p->prev;
    p->prev->next = p->next;


}

//Main Methods
bool LinkedList::add(void *value) {
    ListItem l(value, sentinel, tail);
    l.prev->next = &l;
    l.next->prev = &l;
    if (isEmpty()) {
        head = &l;
    }
    tail = &l;
    size++;
    return true;
}

bool LinkedList::addAt(int i, void *value) {
    size++;
    ListItem *p = LinkedList::pos(i);

    ListItem l(value, p->prev, p);
    if (size == 1) {
        head = &l;
    }
    if (i == size - 1) {
        tail = &l;
    }
    p->next->prev = &l;
    p->next = &l;
    return true;
}

bool LinkedList::remove(void *value) {
    ListItem *p = val(value);
    if (p != sentinel) {
        if (head==p){
            head= p->next;
        }
        if(tail==p){
            tail=p->prev;
        }
        unlink(p);
        size--;
        p->~ListItem();
        return true;
    }
    return false;
}

bool LinkedList::removeAt(int i) {
    ListItem *p = LinkedList::pos(i);
    if (head==p){
        head= p->next;
    }
    if(tail==p){
        tail=p->prev;
    }
    unlink(p);
    size--;
    p->~ListItem();
    return true;
}

void *LinkedList::pop(void *value) {
    ListItem *p = val(value);
    if (p != sentinel) {
        void *temp = p->value;
        unlink(p);
        size--;
        p->~ListItem();
        return temp;
    }

    return nullptr;
}


void *LinkedList::popAt(int i) {
    ListItem *p = pos(i);
    void *temp = p->value;
    unlink(p);
    size--;
    p->~ListItem();
    return temp;

}

void *LinkedList::get(int i) {
    return LinkedList::pos(i)->value;
}

bool LinkedList::set(int i, void *value) {
    LinkedList::pos(i)->value = value;
    return true;
}

bool LinkedList::replace(void *value, void *newValue) {
    ListItem *p = val(value);
    if (p == sentinel) {
        return false;
    }
    p->value = newValue;
    return true;
}

bool LinkedList::exists(void *value) {
    ListItem *p = val(value);
    return p != sentinel;
}

//TODO better performance
void LinkedList::clear() {
    while (size > 0) {
        removeAt(0);
    }
}

void LinkedList::sort(int (*comp)(void *, void *)) {
    ListItem *p=head;
    for (int i = 0; i <size-1 ; ++i) {
        p=head;
        for (int j = 0; j <size-i-1 ; ++j) {
            if(comp(p,p->next)>0){swap(p,p->next);}
            p=p->next;
        }
    }
}

bool LinkedList::isEmpty() {
    return size==0;
}

int LinkedList::getSize() {
    return size;
}
//TODO
void *LinkedList::pop() {
    assert(isEmpty());

}











