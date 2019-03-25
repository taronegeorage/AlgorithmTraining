#include <iostream>
#include "stack.hpp"

using namespace std;

template <class T> stack<T>::stack()
{
    this -> count = 10;
    this->array = new T[this->count];
    this->flag = 0;
    if(! this->array)
        cout << "array malloc memory failure" << endl;
}

template <class T> stack<T>::stack(int count)
{
    this -> count = count;
    this->array = new T[this->count];
    this->flag = 0;
    if(! this->array)
        cout << "array malloc memory failure" << endl;
}

template <class T> stack<T>::~stack()
{
    this->count = 0;
    this->flag = 0;
    if(this->array){
        delete [] this->array;
        this->array = NULL;
    }
}

template<class T> void stack<T>::push(T data){
    if(this->flag == this->count){
        cout << "The stack is full, expand to 1.5 times larger. " << endl;
        this->count = int(1.5*this->count);
        T *temp = new T[this->count];
        for(int i = 0; i < this->flag; i++){
            temp[i] = this->array[i];
        }
        delete [] this->array;
        temp[this->flag] = data;
        this->flag++;
        this->array = temp;
    }
    else{
        this->array[this->flag] = data;
        this->flag++;
    }
}

template<class T> T stack<T>::pop(){
    this->flag--;
    return this->array[this->flag];
}

template<class T> T stack<T>::peak(){
    return this->array[this->flag-1];
}

template<class T> int stack<T>::stackSize(){
    return this->flag;
}

template<class T> int stack<T>::stackMaxsize(){
    return this->count;
}

int main(int argc, char** argv){
    stack<int> s(5);
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);

    cout << "peak () " << s.peak() << endl;
    cout << "pop ()" << s.pop() <<endl;
    s.push(14);
    s.push(15);
    s.push(16);
    return 0;
}
