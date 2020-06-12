//
// Created by Oemer on 02.06.2020.
//

#ifndef NEURONET_LINKEDLIST_H
#define NEURONET_LINKEDLIST_H

class LinkedList {
protected:
    /**
     * basic LinkedList Item bilateral, with sentinel
     */

    class ListItem {
    public:
        ListItem(void *v, ListItem *n, ListItem *p) : value(v), next(n), prev(p) {}

        void *value;
        ListItem *next;
        ListItem *prev;
    };



    ListItem *head;
    ListItem *tail;
    ListItem *sentinel;
    int size;

    //Private helper methods
    /**
     *
     * @param l1
     * @param l2
     * swaps values of both ListItems
     */
    static void swap(ListItem *l1, ListItem *l2);

    /**
     *
     * @param pos
     * @return ListItem of given Position
     * @attention asserts if out of Range
     */
    ListItem *pos(int i);

    /**
     *
     * @param value
     * @param doAssert =false
     * @return ListItem with given value, if Existing otherwise sentinel of List
     * @attention Always check if return value equals sentinel
     * @attention asserts if doAssert= true && value not found
     */
    ListItem *val(void *value, bool doAssert = false);

    /**
     *  make the linked list skip this node while remaining the nodes pointers
     * @param p ListItem to unlink
     * "removes" ListItem node from LinkedList
     */
    static void unlink(ListItem *p);

//List Manipulation
public:

    class Iterator{
    private:

        ListItem *p;
        LinkedList *outa;
    public:

        bool hasNext();
        explicit Iterator(LinkedList* daddy);
        virtual void* next();
    };

     /**
     *
     * @return iterator of list
     */
    Iterator *iterator();
    /**
     * creates new Linked List
     */
    LinkedList();

    ~LinkedList();

    /**
     * adds value to the List
     * @param value
     * @return true iff value has been added
     */
    bool add(void *value);

    /**
     * adds Value to the End of the List
     * * @param value
     * @return true iff sucess
     */
    bool addLast(void *value);

    /**
     * Adds value to the Beginning of the List
     * @param value
     * @return
     */
    bool addFirst(void *value);

    /**
     * puts value on ith position, the rest will be shifted
     * @param i must be in [i,size]
     * @param value
     * @return true iff values has been added
     */
    bool addAt(int i, void *value);



    /**
     * removes Element at position i
     * @param i
     * @return true iff value has been removed
     * @attention may assert if out of Range
     */
    bool removeAt(int i);

    /**
     * removes value iff existing
     * @param value
     * @return true iff it has been removed
     */
    bool remove(void *value);

    /**
     * removes LAst element of the List
     * @return true iff success
     * @attention may assert if empty
     */
    bool removeLast();

    /**
     * removes First element of the List
     * @return true iff success
     */

    bool removeFirst();

    //bool deleteValue(void* value);

    //bool deleteAt(int i);

    /**
     * Removes last element in List
     * @return value of delted element
     * @attention may assert if List is Empty
     */
    virtual void *pop();

    /**
     * removes the ListItem with given value and returns the value of the ListItem
     * @param value
     * @return value of the ListItem or nullptr
     * @attention possible nullptr
     */


    virtual void *pop(void *value);

    /**
     * removes the ListItem of the ith position and returns its value
     * @param i
     * @return value of ith ListItem
     * @attention may assert if out of Range
     */
    virtual void *popAt(int i);

    /**
     * returns value from position i
     * @param pos
     * @return List Item of this position
     * @attention may assert if out of Range
     */
    virtual void *get(int i);

    /**
    *
    * @param value
    * @return true if Value exists in List
    */
    bool exists(void *value);

    /**
     * overrides value at position i
     * @param i
     * @param value
     * @return true if value has been set
     */
    bool set(int i, void *value);

    /**
     * replaces value with new value
     * @param value is going to be replaced, should exist in List
     * @param newValue
     * @return true, iff value has been replaced
     */
    bool replace(void *value, void *newValue);

    /**
     * removes every List Item
     */
    void clear();

    /**
     * Sorts this List with Bubblesort
     * @param comp Comparator witch returns -1 iff l <r ; 1 iff l>r , 0 iff l==r
     */
    void sort(int (*comp)(void *l, void *r));

    /**
     *
     * @return true iff List is empty
     */
    bool isEmpty() const;

    /**
     *
     * @return Count of ListItems
     */
    int getSize() const;


};

#endif //NEURONET_LINKEDLIST_H
