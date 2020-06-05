//
// Created by Oemer on 03.06.2020.
//

#ifndef NEURONET_GENERICLIST_H
#define NEURONET_GENERICLIST_H


#include "LinkedList.h"

template<class T>
class GenericList {
    LinkedList *list;
public:
    GenericList() {
        list = new LinkedList();
    }
    ~GenericList(){

        delete list;
    }

    class Iterator {
    private:
        LinkedList::Iterator *it;
    public:
        bool hasNext() {
            return it->hasNext();
        };

        explicit Iterator(LinkedList *daddy) {
            it = daddy->iterator();
        };
        ~Iterator(){
            delete it;
        }

        T *next() {
            return (T *) it->next();
        };


    };

    /**
     * removes Item from list and then deletes the value from memory
     * @param value
     * @return true iff success
     */
    bool deleteValue(T *value) {
        T *t = pop(value);
        if (t != nullptr) {
            delete t;
        }
        return true;

    }

    /**
     * removes Item from List and deletes value from memory
     * @param i the position of the element
     * @return true iff success
     * @attention may assert--
     */

    bool deleteAt(int i) {
        T *t = popAt(i);
        delete t;
        return true;
    }


    T *pop() {
        return (T *) list->pop();
    }


    T *pop(T *value) {
        return (T *) list->pop(value);
    }


    T *popAt(int i) {
        return (T *) list->popAt(i);
    }


    T *get(int i) {
        return (T *) list->get(i);
    }


    GenericList<T>::Iterator *iterator() {
        return new Iterator(list);
    }


    bool add(T *value) {
        return list->add(value);
    }

    /**
     * adds Value to the End of the List
     * * @param value
     * @return true iff sucess
     */
    bool addLast(T *value){
        return list->addLast(value);
    }

    /**
     * Adds value to the Beginning of the List
     * @param value
     * @return
     */
    bool addFirst(T *value){
        return list->addFirst(value);
    }

    /**
     * puts value on ith position, the rest will be shifted
     * @param i must be in [i,size]
     * @param value
     * @return true iff values has been added
     */
    bool addAt(int i, T *value){
        return list->addAt(i,value);
    }

    /**
     * removes Element at position i
     * @param i
     * @return true iff value has been removed
     * @attention may assert if out of Range
     */
    bool removeAt(int i){
        return list->removeAt(i);
    }

    /**
     * removes value iff existing
     * @param value
     * @return true iff it has been removed
     */
    bool remove(T *value){
        return list->remove(value);
    }

    /**
     * removes LAst element of the List
     * @return true iff success
     * @attention may assert if empty
     */
    bool removeLast(){
        return list->removeLast();
    }

    /**
     * removes First element of the List
     * @return true iff success
     */

    bool removeFirst(){
        return  list->removeFirst();
    }


    /**
    *
    * @param value
    * @return true if Value exists in List
    */
    bool exists(T *value){
        return list->exists(value);
    }

    /**
     * overrides value at position i
     * @param i
     * @param value
     * @return true if value has been set
     */
    bool set(int i, T *value){
        return list->set(i,value);
    }

    /**
     * replaces value with new value
     * @param value is going to be replaced, should exist in List
     * @param newValue
     * @return true, iff value has been replaced
     */
    bool replace(T *value, T *newValue){
        return list->replace(value,newValue);
    }

    /**
     * removes every List Item
     */
    void clear(){
        list->clear();
    }

    /**
     * Sorts this List with Bubblesort
     * @param comp Comparator witch returns -1 iff l <r ; 1 iff l>r , 0 iff l==r
     */
    void sort(int (*comp)(T *l, T *r)){
        list->sort(comp);
    }

    /**
     *
     * @return true iff List is empty
     */
    bool isEmpty(){
        return list->isEmpty();
    }

    /**
     *
     * @return Count of ListItems
     */
    int getSize(){
        return list->getSize();
    }


};


#endif //NEURONET_GENERICLIST_H
