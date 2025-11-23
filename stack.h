#ifndef stack_h
#define stack_h
#include "node.h"

class Stack {
    NodePtr top;
    int size;
public:
    void push(int);
    int pop();
    bool isEmpty();
    Stack();
    ~Stack();
};

bool Stack::isEmpty() {
    return top == NULL;
}

void Stack::push(int x) {
    NodePtr new_node = new NODE(x);

    if (!new_node) return; 

    new_node->set_next(top);   
    top = new_node;            
    size++;
}

int Stack::pop() {
    if (isEmpty()) {
        cout << "Stack empty!" << endl;
        return -1;
    }

    NodePtr t = top;
    int value = t->get_value();

    top = t->get_next();       

    cout << value << endl;     

    delete t;
    size--;

    return value;
}

Stack::Stack() {
    top = NULL;
    size = 0;
}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();  
    }
}

#endif