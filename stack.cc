/*****************************************************************************
    File: stack.cc                                                                   
    Skeleton by: Alistair Campbell                                              
    Completed by: Eseosa Asiruwa                                                                                                                 
    Date: 2/5/16
    Assignment: Lab 3
                                                        
    Implemenation of the stack class.
                                                                             
*****************************************************************************/

#include "stack.h"

stack::stack()
{
    _init();
}

stack::~stack()
{
    _destroy(); // remove all nodes
}

stack::stack(const stack & other)
{
    _init();      // initialize.
    _copy(other); // copy other stack
}

stack & stack::operator=(const stack & rhs)
{
    if (this != &rhs) { // avoid assign to yourself
        _destroy();     // get rid of any data we already have.
        _copy(rhs);     // copy right hand side.
    }
    return *this;       // allows chained assignments
}

// Private methods
void stack::_copy(const stack & other)
{
    stack temp; // temporary storage
    // copy all data from other to temp.
    for (node *p = other._top; p != NULL; p = p->next)
        temp.push(p->data);
    // now temp is the reverse of other;
    // copy all data to this stack.
    for (node *p = temp._top; p != NULL; p = p->next)
        push(p->data);
}

void stack::_init()
{
    _size = 0;
    _top = NULL;
}

void stack::_destroy()
{
    if (_top == NULL) // nothing in the stack
        return;
    else{    
        node *p; // create a pointer to pointer to top of the stack
        p = _top;
        for (node *i = _top ->next; i!= NULL; i = i ->next){
            delete p; // loop through nodes and delete 
            p = i; // pointer points to next node
        }
    }
    _size = 0;
}

// Public methods
void stack::push(const element & item)
{
    node *box;
    box = new node; // create a new node with data from item  
    box -> data = item;
    box -> next = _top; // new node points to first node in stack
    _top = box; // top node pointer now points to new node
    _size++;
}

void stack::pop()
{
    node *p;
    p = new node;  // creates a pointer to point to first node in the stack
    p = _top;
    _top = _top -> next; // top node pointer points to the next node
    delete p;
    _size--;
}

stack::element stack::top() const
{
    return _top -> data; 
}

bool stack::empty() const
{
    return _size == 0;
}

size_t stack::size() const
{
    return _size; 
}