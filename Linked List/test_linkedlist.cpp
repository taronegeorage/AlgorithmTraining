#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};

class list
{
private:
    node *head, *tail;
public:
    list()
    {
    	head = NULL;
    	tail = NULL;
    } 
    void createnode(int val)
    {
    	node *temp = new node;
    	temp->data = val;
    	temp->next = NULL;
    	if(head == NULL)
    	{
    		head = temp;
    		tail = temp;
    		temp = NULL;
    	}
    	else
    	{
    		tail->next = temp;
    		tail = temp;
    	}
    }
    void display()
    {
    	node *temp = new node;
    	temp = head;
    	while(temp != NULL)
    	{
    		cout << temp->data << "\t";
    		temp = temp->next;
    	}
    }
    void insert_start(int val)
    {
    	node *temp = new node;
    	temp->data = val;
    	temp->next = head;
    	head = temp;
    }
    void insert_position(int pos, int val)
    {
    	node *temp = new node;
    	node *pre = new node;
    	node *cur = new node;
    	cur = head;

    	for(int i = 0; i < pos; i++)
    	{
    		pre = cur;
    		cur = cur->next;
    	}
    	temp->data = val;
    	pre->next = temp;
    	temp->next = cur;
    }
    void delete_first()
    {
    	node *temp = new node;
    	temp = head;
    	head = head->next;
    	delete temp;
    }
    void delete_last()
    {
    	node *cur = new node;
    	node *pre = new node;
    	cur = head;
    	while(cur->next != NULL)
    	{
    		pre = cur;
    		cur = cur->next;
    	}
    	tail = pre;
    	pre->next = NULL;
    	delete cur;
    }
    void delete_position(int pos)
    {
    	node *cur = new node;
    	node *pre = new node;
    	cur = head;	
    	for(int i = 0; i < pos; i++)
    	{
    		pre = cur;
    		cur = cur->next;
    	}
    	pre->next = cur->next;
    }
};


int main(int argc, char const *argv[])
{
	list obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.createnode(55);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_position(5,60);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_first();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Deleing At End-------------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_last();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_position(4);
	obj.display();
	cout<<"\n--------------------------------------------------\n";

	return 0;
}