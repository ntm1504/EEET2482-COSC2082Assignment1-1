#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
//include class we create
#include"List.cpp"
//#include"Descriptive_Static.cpp"
using namespace std;
//static value use in testing
//change to exact location if the name below does match
//string fileName ="data1.csv";
//read csv from given location
int2 ReadCSVFile(string fileLocation)
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
    //Initualize List
    int2 valueList;
    //read file
    string line="";
    //int
    int x=0;
    int y=0;
    int count=0;
    //ignore the value first line
    getline(infile,line);
    //
    cout<<"Reading CSV FILE"<<endl;
    while(getline(infile,line))
    {
        //split line by comma
        int cPos= line.find(",");//position of comma
        string first=line.substr(0,cPos);//first to comma
        string second=line.erase(0,cPos+delimiterLength);
        //convert to int
        x=stoi(first);
        y=stoi(second);
        valueList.Add(x,y);
        //UI display
        count++;
        if(count%500==0)
        {
            cout<<"=";
        }
    }
    cout<<endl<<"Reading Complete"<<endl;
    //close file
    infile.close();
    return valueList;
}
//Common Function--------------------------------------------------------------
int2 GetATestingList()
{
    int2 valueList;
    cout<<"Value added to the list! use this to check your math:"<<"(2,3),(4,5),(9,6),(2,3),(5,1)"<<endl;
    valueList.Add(2,3);
    valueList.Add(4,5);
    valueList.Add(9,6);
    valueList.Add(2,3);
    valueList.Add(5,1);
    valueList.Add(3,5);
    valueList.Add(5,2);
    valueList.Add(6,6);
    valueList.Add(5,1);
    valueList.Add(5,6);

    return valueList;
}
//get sum of a list
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
    long sum=GetSum(valueList,usingX);
    float mean=float(sum)/float(valueList.Size());
    return mean;
}
//sort in increasing order
void SortList(int2 &valueList)
{
    //sort from the last to the first
    for(int i=valueList.Size()-1;i>=0;i--)//for each loop the largest each will be moved to the last
    {
        for(int j=0;j<=i;j++)//we will skip the sorted largest to increase performance
        {
            if(j+1<=i)//prevent error when this get out of list index
            {
                //check x
                if(valueList.GetNodeAt(j)->GetX()>valueList.GetNodeAt(j+1)->GetX())
                {
                    //need to swap
                    valueList.SwapX(j,j+1);
                }
                //check y
                if(valueList.GetNodeAt(j)->GetY()>valueList.GetNodeAt(j+1)->GetY())
                {
                    //need to swap
                    valueList.SwapY(j,j+1);
                }
            }
        }
    }
}
void Display(int2 &valueList)
{
    cout<<"value List contains X: ";
    for(int i=0;i<valueList.Size();i++)
    {
        cout<<valueList.GetNodeAt(i)->GetX()<<", ";
    }
    cout<<"value List contains Y: ";
    for(int i=0;i<valueList.Size();i++)
    {
        cout<<valueList.GetNodeAt(i)->GetY()<<", ";
    }
}
//Descriptive statistics----------------------------------------------------------
//2 Mode
int Mode(int2 &valueList,bool usingX)
{
    //sort list in any order
    SortList(valueList);//this will sort in increasing order

    //property
    if(usingX)
    {
        //top
        int maxModeValue=valueList.GetNodeAt(0)->GetX();
        int maxOccurence=0;
        //current
        int modeValueX=maxModeValue;
        int modeOccurence=0;
        //loop to check if mode Occurence 
        for(int i=0;i<valueList.Size();i++)
        {
            //check if the currentvalue is equal to value in loop
            if(modeValueX==valueList.GetNodeAt(i)->GetX()) 
            {
                //when equal increase occurence by 1
                modeOccurence++;
            }
            else if(modeValueX!=valueList.GetNodeAt(i)->GetX()){
                //when different  mode has been updated to the new 
                if(modeOccurence>maxOccurence)
                {
                    //run when there are more number of this value than the current max
                    //update new max
                    maxModeValue=modeValueX;
                    maxOccurence=modeOccurence;
                }
                //reset current mode to check for new number
                modeOccurence=1;//must be one since it count the value in loop already
                modeValueX=valueList.GetNodeAt(i)->GetX();
            }
            //update the last number value
            if(i==valueList.Size()-1)
            {
                if(modeOccurence>maxOccurence)
                {
                    //run when there are more number of this value than the current max
                    //update new max
                    maxModeValue=modeValueX;
                    maxOccurence=modeOccurence;
                }
            }
        }
        //cout<<"max occurence X is:"<<maxOccurence<<" with value of:"<<maxModeValue<<endl;
        return maxModeValue;
    }
    else{
        //top
        int maxModeValue=valueList.GetNodeAt(0)->GetY();
        int maxOccurence=0;
        //current
        int modeValueY=maxModeValue;
        int modeOccurence=0;
        //loop to check if mode Occurence 
        for(int i=0;i<valueList.Size();i++)
        {
            //check if the currentvalue is equal to value in loop
            if(modeValueY==valueList.GetNodeAt(i)->GetY()) 
            {
                //when equal increase occurence by 1
                modeOccurence++;
            }
            else if(modeValueY!=valueList.GetNodeAt(i)->GetY()){
                //cout<<"value: "<<modeValueY<<" occurence: "<<modeOccurence<<endl;
                //when different  mode has been updated to the new 
                if(modeOccurence>maxOccurence)
                {
                    //run when there are more number of this value than the current max
                    //update new max
                    maxModeValue=modeValueY;
                    maxOccurence=modeOccurence;
                }
                //reset current mode to check for new number
                modeOccurence=1;//must be one since it count the value in loop already
                modeValueY=valueList.GetNodeAt(i)->GetY();
            }
            //update the last occurence value
            if(i==valueList.Size()-1)
            {
                if(modeOccurence>maxOccurence)
                {
                    //run when there are more number of this value than the current max
                    //update new max
                    maxModeValue=modeValueY;
                    maxOccurence=modeOccurence;
                }
            }
        }
        //cout<<"max occurence Y is:"<<maxOccurence<<" with value of:"<<maxModeValue<<endl;
        return maxModeValue;
    }
}
//3 Variance
float Variance(int2 &valueList, bool usingX)
{
    //Get Means
    float mean=GetMean(valueList,usingX);
    //cout<<"Mean is:"<<mean<<endl;
    double total=0;
    //loop to get a sum of the square of difference of each number to mean
    if(usingX)
    {
        for(int i=0;i<valueList.Size();i++)
        {
            float offset=valueList.GetNodeAt(i)->GetX()-mean;//difference to mean
            float squareOffset=offset*offset;//square of the offset
            total+=squareOffset;//add to total
        }
    }
    else{
        for(int i=0;i<valueList.Size();i++)
        {
            double offset=valueList.GetNodeAt(i)->GetY()-mean;//difference to mean
            double squareOffset=offset*offset;//square of the offset
            total+=squareOffset;//add to total
        }
    }
    //divide to the variance
    float result=total/(valueList.Size()-1);
    return result*result;
}
//4 Mean Absolute Deviation(MAD)
float MeanAbsoluteDeviation(int2 &valueList,bool usingX)
{
    //get mean
    float mean=GetMean(valueList,usingX);
    float total=0;
    //get offset of each value to mean
   //loop to get a sum of the square of difference of each number to mean
    if(usingX)
    {
        for(int i=0;i<valueList.Size();i++)
        {
            float offset=valueList.GetNodeAt(i)->GetX()-mean;//difference to mean
            float absoluteOffset=abs(offset);//the absolute value
            total+=absoluteOffset;//add to total
        }
        //cout<<"Using X total is:"<<total<<endl;
    }
    else{
        for(int i=0;i<valueList.Size();i++)
        {
            double offset=valueList.GetNodeAt(i)->GetY()-mean;//difference to mean
            double absoluteOffset=abs(offset);//get the absolute value
            total+=absoluteOffset;//add to total
        }
        //cout<<"Using Y total is:"<<total<<endl;
    }
    float result=total/valueList.Size();
    return result;
}
//5
//6 Skewness
float Skewness(int2 &valueList,bool usingX,float sde)
{
     //get mean
    float mean=GetMean(valueList,usingX);
    float total=0;
    //get offset of each value to mean
   //loop 
    if(usingX)
    {
        for(int i=0;i<valueList.Size();i++)
        {
            float offset=valueList.GetNodeAt(i)->GetX()-mean;//difference to mean
            float offsetOnSde=offset/sde;//division on stardard deviation
            float cubeOffsetOnSde=offsetOnSde*offsetOnSde*offsetOnSde;//cube of offset on sde
            total+=cubeOffsetOnSde;//add to total
        }
        //cout<<"Using X total is:"<<total<<endl;
    }
    else{
        for(int i=0;i<valueList.Size();i++)
        {
            double offset=valueList.GetNodeAt(i)->GetY()-mean;//difference to mean
            double offsetOnSde=offset/sde;//division on stardard deviation
            double cubeOffsetOnSde=offsetOnSde*offsetOnSde*offsetOnSde;//cube of offset on sde
            total+=cubeOffsetOnSde;//add to total
        }
        //cout<<"Using Y total is:"<<total<<endl;
    }
    float result=total/valueList.Size();//total /n
    return result;
}
//7 Kurtosis
float Kurtosis(int2 &valueList,bool usingX, float sde)
{
    int powerLevel=4;
    //get mean
    float mean=GetMean(valueList,usingX);
    float total=0;
    //get offset of each value to mean
   //loop 
    if(usingX)
    {
        for(int i=0;i<valueList.Size();i++)
        {
            float offset=valueList.GetNodeAt(i)->GetX()-mean;//difference to mean
            float offsetOnSde=offset/sde;//division on stardard deviation
            float cubeOffsetOnSde=pow(offsetOnSde,powerLevel);//get offset on sde power of 4
            total+=cubeOffsetOnSde;//add to total
        }
        //cout<<"Using X total is:"<<total<<endl;
    }
    else{
        for(int i=0;i<valueList.Size();i++)
        {
            double offset=valueList.GetNodeAt(i)->GetY()-mean;//difference to mean
            double offsetOnSde=offset/sde;//division on stardard deviation
            double cubeOffsetOnSde=pow(offsetOnSde,powerLevel);//get offset on sde power of 4
            total+=cubeOffsetOnSde;//add to total
        }
        //cout<<"Using Y total is:"<<total<<endl;
    }
    float result=total/valueList.Size()-3;//total /n -3
    return result;
}
int main()
{
    string fileName ="data1.csv";
    //Get values from reader
    //int2 valueList=ReadCSVFile(fileName);
    //while Testing use GetATestingList to check for the result
    int2 valueList=GetATestingList();
    cout<<"--------------------------------------------"<<endl;
    cout<<"Start display the result:"<<endl;
    //2-Mode
    cout<<"2-Mode"<<endl;
    //display
    cout<<"mode_x= "<<Mode(valueList,true)<< " - "<<"mode_y= "<<Mode(valueList,false)<<endl;
    //conclusion
    cout<<"--"<<endl;
    //3-Variance-------------------------------------------
    cout<<"3-Variance and standard deviation"<<endl;
    // variable
    float varX=Variance(valueList,true);
    float varY=Variance(valueList,false);
    //standard deviation-- use below
    float sX=sqrt(varX);
    float sY=sqrt(varY);
    //display
    cout<<"var_x= "<<varX<< " - "<<"var_y= "<<varY<<endl;
    cout<<"stdev_x= "<<sX<< " - "<<"stdev_y= "<<sY<<endl;
    //conclusion
    cout<<"--"<<endl;
    //4-Mean Absolute Deviation----------------------------------
    cout<<"4-Mean Absolute Deviation"<<endl;
    //display
    cout<<"var_x= "<<MeanAbsoluteDeviation(valueList,true)<< " - "<<"var_y= "<<MeanAbsoluteDeviation(valueList,false)<<endl;
    //conclusion
    cout<<"--"<<endl;
    //5-Third quartile-------------------------------------------
    cout<<"5-Thrid Quartile"<<endl;
    //display
    //cout<<"var_x= "<<MeanAbsoluteDeviation(valueList,true)<< " - "<<"var_y= "<<MeanAbsoluteDeviation(valueList,false)<<endl;
    //conclusion
    cout<<"--"<<endl;
    //6-Skewness------------------------------------------------
    cout<<"6-Skewness"<<endl;
    //display
    cout<<"skew_x= "<<Skewness(valueList,true,sX)<< " - "<<"skew_y= "<<Skewness(valueList,false,sY)<<endl;
    //conclusion
    cout<<"--"<<endl;
    //7-Kurtosis------------------------------------------------
    cout<<"7-Kurtosis"<<endl;
    //display
    cout<<"kurt_x= "<<Kurtosis(valueList,true,sX)<< " - "<<"kurt_y= "<<Kurtosis(valueList,false,sY)<<endl;
    //conclusion
    cout<<"--"<<endl;
    return 0;
}