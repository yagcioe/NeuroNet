//
// Created by Oemer on 03.06.2020.
//

#include "GenericList.h"

template<class T>
T GenericList<T>::Iterator::next() {
    return Iterator::next();
}
template<class T>
T *GenericList<T>::pop() {
    return LinkedList::pop();
}

template<class T>
T *GenericList<T>::pop(void *value) {
    return LinkedList::pop(value);
}

template<class T>
T *GenericList<T>::popAt(int i) {
    return LinkedList::popAt(i);
}

template<class T>
T *GenericList<T>::get(int i) {
    return LinkedList::get(i);
}

template<class T>
bool GenericList<T>::deleteAt(int i) {
    T t =popAt(i);
    delete t;
    return true;
}

template<class T>
bool GenericList<T>::deleteValue(void *value) {
    T t = pop(value);
    if(t!= nullptr){
        delete t;
    }

}