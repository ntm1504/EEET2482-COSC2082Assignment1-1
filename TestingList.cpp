//individual character for int2 list
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Node {
    //property
    private:
        int x;
        int y;
        Node* next;
        friend class int2;
    //constructor
    public:
        Node(int xValue,int yValue){
            this->x=xValue;
            this->y=yValue;
        }
    //deconstruct
        ~Node()
        {
            clog<<"deconstructing node";
            if(this->next!=NULL)
            {
            delete this-> next;
            }
        }
    //get
        int GetX()
        {
            return x;
        }
        int GetY()
        {
            return y;
        }
};
//PURPOSE
//teacher dont allow list :V we create list :V
//a list that each node contain 2 int x and y
class int2 {
protected:
    Node* head;
    Node* tail;
    int count;
public:
    int2(){
        
    }
    ~int2(){
        delete head;
    }
    //add to the nextLocation
    void Add(int first, int second);
    //get total size to convert to array later
    int Size();
    //get the node at index
    //use node.x and node.y
    Node* GetNodeAt(int index);
};
//add a new node to with x and y to the list
void int2::Add(int x, int y) {
    //increase size
    count++;
    //apply value to the next node
    Node *temp=new Node(x,y);
    temp->next=NULL;
    //if this is the first node
    if(head==NULL)
    {
        head=temp;
		tail=temp;
        return;
    }
    else//assign next and tail to the current
    {
        Node *ptr=head;
        //get next
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=temp;
        //assign tail
        tail=temp;
    }
    return;

}
//return the size of the list
int int2::Size() {
    return count;
}
//get node at index
Node* int2::GetNodeAt(int index)
{
    //fast result
    if(index==0)
    {
        return head;
    }
    else if(index==count-1)
    {
        return tail;
    } else if( index>=count)//check if index node exist
    {
        cerr<<"index are out of list length!:"<<index<<" / "<<count;
        return NULL;
    }
    else{
        //get the node at index
        Node *ptr=head;
        for(int i=0;i<index;i++)
        {
            ptr=ptr->next;
        }
        return ptr;
    }
}