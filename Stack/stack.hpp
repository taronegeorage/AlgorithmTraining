
template <class T> 
class stack
{
private:
    /* data */
    int flag;  //point to head
    int count; //size
    T *array;

public:
    stack(/* args */);
    stack(int count);
    ~stack();
    void push(T data); 
    T pop();
    T peak(); //get the head value
    int stackSize();
    int stackMaxsize();
};
