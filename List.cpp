//individual character for int2 list
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Node {
    //property
    private:
        int x;
        long y;
        friend class int2;
    public:
        Node* next;
            //constructor
        Node(int xValue,long yValue){
            this->x=xValue;
            this->y=yValue;
        }
    //deconstruct
        ~Node()
        {
            //clog<<"deconstructing node";
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
    //set
        void SetX(int x)
        {
            this->x=x;
        }
        void SetY(long y)
        {
            this->y=y;
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
    void Add(int first, long second);
    //swap method
    void SwapX(int fIndex,int sIndex);
    void SwapY(int fIndex,int sIndex);
    //get total size to convert to array later
    int Size();
    //get the node at index
    //use node.x and node.y
    Node* GetNodeAt(int index);
};
//add a new node to with x and y to the list
void int2::Add(int x, long y) {
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
//swap method
//swap X
void int2::SwapX(int fIndex,int sIndex)
{
    int fValue=GetNodeAt(fIndex)->GetX();
    int sValue=GetNodeAt(sIndex)->GetX();
    GetNodeAt(fIndex)->SetX(sValue);
    GetNodeAt(sIndex)->SetX(fValue);
}
//swap Y
void int2::SwapY(int fIndex,int sIndex)
{
    int fValue=GetNodeAt(fIndex)->GetY();
    int sValue=GetNodeAt(sIndex)->GetY();
    GetNodeAt(fIndex)->SetY(sValue);
    GetNodeAt(sIndex)->SetY(fValue);
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