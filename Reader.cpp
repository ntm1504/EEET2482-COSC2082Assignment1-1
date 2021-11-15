#include <iostream>
#include <fstream>
#include <string>
//include class we create
#include "TestingList.cpp"
using namespace std;
//static value use in testing
//change to exact location if the name below does match
//string fileName ="data1.csv";
//read csv from given location
int2* ReadCSV(string fileLocation)
{
    const int delimiterLength=1;
    //open file
    ifstream infile(fileLocation,ios::in|ios::binary);
    //check if file open successfully
    if(!infile)
    {
        cerr<<"File failed to open!"<<endl;
        //return NULL;
    }
    cout<<"check bug";
    //Initualize List
    int2* valueList=new int2();
    //read file
    string line="";
    //int
    int x=0;
    int y=0;
    //ignore the value first line
    getline(infile,line);
    //
    while(getline(infile,line))
    {
        //split line by comma
        int cPos= line.find(",");//position of comma
        string first=line.substr(0,cPos);//first to comma
        string second=line.erase(0,cPos+delimiterLength);
        //convert to int
        x=stoi(first);
        y=stoi(second);
        valueList->Add(x,y);
    }
    //close file
    infile.close();
    return valueList;
}
//call ReadCSV with the fileName as parameter
void ReadCSV()
{

}

int main()
{
    string fileName ="data1.csv";
    return 0;
}