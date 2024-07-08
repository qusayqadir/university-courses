#include "objPosDLinkedList.h"
#include <iostream>
using namespace std;

// Develop the objPos Doubly Linked List here.  
// Use the Test cases Test.cpp to complete the Test-Driven Development

objPosDLinkedList::objPosDLinkedList()
{
    listSize = 0; 
    listHead = new DNode(); 
    listTail = new DNode(); 

    listHead->next = listTail;
    listTail->prev = listHead; 

    persistHead = nullptr;
}

objPosDLinkedList::~objPosDLinkedList()
{
    DNode* persistHead = listHead->next; 
    while(persistHead != listTail)
    {
        DNode* temp = persistHead->next; 
        delete persistHead; 
        persistHead = temp; 
    }
    delete listHead; 
    delete listTail; 

}

int objPosDLinkedList::getSize()
{
    return listSize; 
}

bool objPosDLinkedList::isEmpty()
{
    return listSize == 0; 
}

void objPosDLinkedList::insertHead(const objPos &thisPos)
{
    DNode* new_element = new DNode();

    new_element->data = thisPos; //giving the node thispos data

    new_element->next = listHead->next; //essentially connecting newnode to node that was previously at beginning
    new_element->prev = listHead;

    listHead->next->prev = new_element;
    listHead->next = new_element; 

    listSize++;
}


void objPosDLinkedList::insertTail(const objPos &thisPos)
{
    DNode* new_element = new DNode();
    new_element->data = thisPos;
    new_element->next = listTail;
    new_element->prev = listTail->prev;
    
    
    listTail->prev->next =  new_element;
    listTail->prev = new_element;
    

    listSize++;

}

void objPosDLinkedList::insert(const objPos &thisPos, int index)
{

    if(index <= 0)
    {
        insertHead(thisPos); 
    }
    else if (index >= listSize - 1)
    {
        insertTail(thisPos); 
    }
    else{
        DNode* new_element = new DNode(); 
        new_element->data = thisPos; 
        DNode* temp = listHead->next;

        for(int i=0; i<index; i++){
            temp = temp->next;
        }
        new_element->next = temp; 
        new_element->prev = temp->prev;

        temp->prev->next = new_element; 
        temp->prev = new_element;  
        listSize++; 
    }

}

objPos objPosDLinkedList::getHead() const
{
    return listHead->next->data; 
}

objPos objPosDLinkedList::getTail() const
{
    return listTail->prev->data; 
}

objPos objPosDLinkedList::get(int index) const
{
    if(index <= 0)
    {
        return getHead();
    }
    else if(index >= listSize-1)
    {
        return getTail();
    }
    else{
        DNode* temp = listHead->next; 
        for(int i =0; i < index && temp!=listTail; i++)
        {
            temp = temp->next;
        }
        return temp->data; 
    }

}

objPos objPosDLinkedList::getNext()
{
    if(persistHead->next == listTail)
    {
        return objPos(-99,0,0,0,0);
        resetReadPos(); 
    }
    persistHead = persistHead->next; 
    return persistHead->data; 
}

void objPosDLinkedList::resetReadPos()
{
    persistHead = listHead; 
}

void objPosDLinkedList::set(const objPos &thisPos, int index)
{
    if(index < 0){
        index = 0; 
    }
    else if ( index > listSize - 1){
        index = listSize - 1 ; 
    } 
    DNode* temp = listHead->next; 
    for(int k=0; k < index; ++k)
    {
        temp = temp->next;
    }
    temp->data = thisPos; 

}

objPos objPosDLinkedList::removeHead()
{

    if(isEmpty() == true){
        return objPos(-99,0,0,0,0); 
    } 
    DNode* node_remove = listHead->next; 
    objPos remove_data = node_remove->data; 
    listHead->next = node_remove->next; 

    if(node_remove->next != nullptr){
        node_remove->next->prev = listHead;
    }
    
    listSize --; 
    delete node_remove; 
    return remove_data; 
    
}

objPos objPosDLinkedList::removeTail()
{
    if(isEmpty() == true) {  
        return objPos(-99,0,0,0,0); 
    }
    DNode* remove_element = listTail->prev; 
    objPos remove_data = remove_element->data; 
    listTail->prev = remove_element->prev; 
    remove_element->prev->next = listTail; 
    
    listSize--; 
    delete remove_element;
    return remove_data;  
}

objPos objPosDLinkedList::remove(int index)
{
    if(index <= 0)
    {
        return removeHead();
    }
    else if(index >= listSize - 1)
    {
        return removeTail();
    }

    DNode* temp = listHead->next;
    for(int i =0; i<index && temp !=listTail; i++)
    {
        temp = temp->next;
    }
    listSize--;

    return temp->data;
}


void objPosDLinkedList::printList() const
{   /*
    if(listHead->next != listTail){
        int pos = 0; 
        DNode* temp = listHead->next; 
        while(pos < listSize)
        {
            cout << temp->data << endl; 
            temp = temp->next; 
            pos++; 
        }
    } 
    */
}
