#include<math.h>
#include<string>
#include<iostream>
//create file
#include"CommonFunction.cpp"
#include"List.cpp"
using namespace std;
//Varianceand standard  deviation–The variance or standard  deviation  is  the most 
// common measure of the spread of a set of points and tell us how much the actual
// values differ from the mean.The formula for variance is below.
int Variance(int2 &valueList, bool usingX)
{
    //Get Means
    float mean=GetMean(valueList,true);
    cout<<"mean is: "<<mean;
    return 0;
}