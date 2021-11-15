#include<math.h>
#include<iostream>
#include"List.cpp"
using namespace std;

//return a sum of array
long GetSum(int2 &valueList,bool usingX)
{
    long sum=0;
    for(int i=0;i<valueList.Size();i++)
    {
        //cout<<"how this is run"<<inputArray[i]<<endl;
        if(usingX)
        {
            sum+=valueList.GetNodeAt(i)->GetX();
        }
        else{
            sum+=valueList.GetNodeAt(i)->GetY();
        }
    }
    return sum;
}
//return the mean of an array
float GetMean(int2 &valueList,bool usingX)
{
    int sum=GetSum(valueList,usingX);
    float mean=float(sum/valueList.Size());
    return mean;
}
// int main()
// {
//     int values[]={1,2,3,4,68,3};
//     int arrayLength=sizeof(values)/sizeof(values[0]);
//     cout<<"sum is: "<<GetSum(values,arrayLength)<<endl;
//     cout<<"mean is:"<<GetMean(values,arrayLength)<<endl;
// }