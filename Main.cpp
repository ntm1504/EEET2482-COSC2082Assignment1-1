#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
//include class we create
#include "List.cpp"
//#include"Descriptive_Static.cpp"
using namespace std;
//static value use in testing
//change to exact location if the name below does match
//string fileName ="data1.csv";
//read csv from given location
int2 ReadCSVFile(string fileLocation)
{
    const int delimiterLength = 1;
    //open file
    ifstream infile(fileLocation, ios::in | ios::binary);
    //check if file open successfully
    if (!infile)
    {
        cerr << "File failed to open!" << endl;
        //return NULL;
    }
    //Initualize List
    int2 valueList;
    //read file
    string line = "";
    //int
    int x = 0;
    int y = 0;
    int count = 0;
    //ignore the value first line
    getline(infile, line);
    //
    cout << "Reading CSV FILE" << endl;
    while (getline(infile, line))
    {
        //split line by comma
        int cPos = line.find(",");           //position of comma
        string first = line.substr(0, cPos); //first to comma
        string second = line.erase(0, cPos + delimiterLength);
        //convert to int
        x = stoi(first);
        y = stoi(second);
        valueList.Add(x, y);
        //UI display
        count++;
        if (count % 500 == 0)
        {
            cout << "=";
        }
    }
    cout << endl
         << "Reading Complete" << endl;
    //close file
    infile.close();
    return valueList;
}
//Common Function--------------------------------------------------------------
int2 GetATestingList()
{
    int2 valueList;
    valueList.Add(1, 2);
    valueList.Add(3, 4);
    valueList.Add(8, 6);
    valueList.Add(4, 8);
    valueList.Add(2, 10);
    valueList.Add(9, 12);
    valueList.Add(3, 10);
    valueList.Add(1, 8);
    valueList.Add(2, 6);
    return valueList;
}
//display
void Display(double *arr, int size)
{
    cout << "array contains: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}
//get sum of a list
double GetSum(double *arr, int size)
{
    long sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
//return the mean of an array
double GetMean(double *arr, int size)
{
    double sum = GetSum(arr, size);
    double mean = sum / float(size);
    return mean;
}
// A utility function to swap two elements
void swap(double *a, double *b)
{
    if(a==b)
    {
        //no swapping when value is similar
        return;
    }
    double t = *a;
    *a = *b;
    *b = t;
}
/* This function takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right
 * of pivot */
int partition(double *array, int low, int high,int size)
{
    int i = (low - 1);
    //cout<<"high is "<<high<<endl;
    int pivot = array[high];
    //cout<<"pivot is:"<<pivot<<endl;
    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if(i!=j)//avoid swap similar index value
            {
                //cout<<"swap happen between:"<<i<<"- "<<array[i]<<" and "<<j<<"- "<<array[j]<<endl;
                swap(&array[i], &array[j]);
                //cout<<"swap complete:"<<array[i]<<" and "<<array[j]<<endl;
            }
            //cout<<"swap successfully"<<endl;
            //swap(&arr[i], &arr[j]);
        }
    }
    //cout<<"final i is:"<<i+1;
    //cout<<"swap happen between:"<<array[i+1]<<" and "<<high<<endl;
    swap(&array[i + 1], &array[high]);
    //cout<<"swap complete:"<<array[i+1]<<" and "<<high<<endl;
    //cout<<"swap successfully"<<endl;
    //cout<<"done"<<endl;
    //cout<<"Partion complete and new array is:"<<endl;
    //Display(array,size);
    return (i + 1);
}
/* The main function that implements QuickSort
 * arr[] --> Array to be sorted,
 * low --> Starting index,
 * high --> Ending index
 */
void quickSort(double *array, int low, int high,int size)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(array, low, high,size);
        // Separately sort elements before
        // partition and after partition
        quickSort(array, low, pi - 1,size);
        quickSort(array, pi + 1, high,size);
    }
}
//Descriptive statistics----------------------------------------------------------
//1 Median
double Median(double *array, int size)
{
    int n; //median
    if (size % 2 == 1)
    {                       //odd size
        n = (size + 1) / 2; //1.2.3,4,5,6,7n=3
        //return x or y
        return array[n - 1];
    }
    else
    {
        n = (size + 1) / 2;
        double centerValue = (array[n] + array[n - 1]) / 2;
        return centerValue;
    }
}
//2 Mode
int Mode(double *arr, int size)
{
    //top
    int maxModeValue = arr[0];
    int maxOccurence = 0;
    //current
    int modeValueX = maxModeValue;
    int modeOccurence = 0;
    //loop to check if mode Occurence
    for (int i = 0; i < size; i++)
    {
        //check if the currentvalue is equal to value in loop
        if (modeValueX == arr[i])
        {
            //when equal increase occurence by 1
            modeOccurence++;
        }
        else if (modeValueX != arr[i])
        {
            //when different  mode has been updated to the new
            if (modeOccurence > maxOccurence)
            {
                //run when there are more number of this value than the current max
                //update new max
                maxModeValue = modeValueX;
                maxOccurence = modeOccurence;
            }
            //reset current mode to check for new number
            modeOccurence = 1; //must be one since it count the value in loop already
            modeValueX = arr[i];
        }
        //update the last number value
        if (i == size - 1)
        {
            if (modeOccurence > maxOccurence)
            {
                //run when there are more number of this value than the current max
                //update new max
                maxModeValue = modeValueX;
                maxOccurence = modeOccurence;
            }
        }
    }
    //cout<<"max occurence X is:"<<maxOccurence<<" with value of:"<<maxModeValue<<endl;
    return maxModeValue;
}
//3 Variance
double Variance(double *arr, int size)
{
    //Get Means
    double mean = GetMean(arr, size);
    //cout<<"Mean is:"<<mean<<endl;
    double total = 0;
    //loop to get a sum of the square of difference of each number to mean

    for (int i = 0; i < size; i++)
    {
        double offset = arr[i] - mean;         //difference to mean
        double squareOffset = offset * offset; //square of the offset
        total += squareOffset;                 //add to total
    }

    //divide to the variance
    double result = total / (size - 1);
    return result * result;
}
//4 Mean Absolute Deviation(MAD)
double MeanAbsoluteDeviation(double *arr, int size)
{
    //get mean
    double mean = GetMean(arr, size);
    double total = 0;
    //get offset of each value to mean
    //loop to get a sum of the square of difference of each number to mean

    for (int i = 0; i < size; i++)
    {
        double offset = arr[i] - mean;       //difference to mean
        double absoluteOffset = abs(offset); //the absolute value
        total += absoluteOffset;             //add to total
    }
    //cout<<"Using X total is:"<<total<<endl;

    double result = total / size;
    return result;
}
//5 Quartile3
//6 Skewness
double Skewness(double *arr, int size, double sde)
{
    //get mean
    double mean = GetMean(arr, size);
    double total = 0;
    //get offset of each value to mean
    //loop

    for (int i = 0; i < size; i++)
    {
        double offset = arr[i] - mean;                                    //difference to mean
        double offsetOnSde = offset / sde;                                //division on stardard deviation
        double cubeOffsetOnSde = offsetOnSde * offsetOnSde * offsetOnSde; //cube of offset on sde
        total += cubeOffsetOnSde;                                         //add to total
    }
    //cout<<"Using X total is:"<<total<<endl;
    double result = total / size; //total /n
    return result;
}
//7 Kurtosis
double Kurtosis(double *arr, int size, double sde)
{
    int powerLevel = 4;
    //get mean
    double mean = GetMean(arr, size);
    double total = 0;
    //get offset of each value to mean
    //loop
    for (int i = 0; i < size; i++)
    {
        double offset = arr[i] - mean;                         //difference to mean
        double offsetOnSde = offset / sde;                     //division on stardard deviation
        double cubeOffsetOnSde = pow(offsetOnSde, powerLevel); //get offset on sde power of 4
        total += cubeOffsetOnSde;                              //add to total
    }
    //cout<<"Using X total is:"<<total<<endl;
    double result = (total / size) - 3; //total /n -3
    return result;
}
//Inferential Statistics
//Covariance
double Covariance(double *xArray, double *yArray, int size)
{
    double sum = 0;
    //get means
    double meanX = GetMean(xArray, size);
    double meanY = GetMean(yArray, size);
    //commpute sum
    for (int i = 0; i < size; i++)
        sum = sum + (xArray[i] - meanX) *
                        (yArray[i] - meanY);
    return sum / (size - 1);
}
//Pearson Correlation Coefficient
float CorrelationCoefficient(double *xArray, double *yArray, int size)
{
    //initualize
    double sum_X = GetSum(xArray, size);
    double sum_Y = GetSum(yArray, size);
    double sum_XY = 0;
    double squareSum_X = 0, squareSum_Y = 0;

    for (int i = 0; i < size; i++)
    {
        // sum of X[i] * Y[i].
        sum_XY += +xArray[i] * yArray[i];

        // sum of square of array elements.
        squareSum_X += xArray[i] * xArray[i];
        squareSum_Y += yArray[i] * yArray[i];
    }

    // Calculate correlation coefficient
    double corr = (double)(size * sum_XY - sum_X * sum_Y) / sqrt((size * squareSum_X - sum_X * sum_X) * (size * squareSum_Y - sum_Y * sum_Y));

    return corr;
}
int main()
{
    string fileName = "data1.csv";
    //Get values from reader
    //int2 valueList = ReadCSVFile(fileName);
    //while Testing use GetATestingList to check for the result
    int2 valueList=GetATestingList();
    //convert list to 2 array
    double *xArray = new double[valueList.Size()];
    double *yArray = new double[valueList.Size()];
    //initing
    cout<<"Initualize dynamic array"<<endl;
    for (int i = 0; i < valueList.Size(); i++)
    {
        xArray[i] = valueList.GetNodeAt(i)->GetX();
        yArray[i] = valueList.GetNodeAt(i)->GetY();
    }
    int arraySize = valueList.Size();
    Display(xArray,arraySize);
    Display(yArray,arraySize);
    //sorting
    cout << "Sorting Start! Please Wait" << endl;
    quickSort(xArray, 0, arraySize - 1,arraySize);
    quickSort(yArray, 0, arraySize - 1,arraySize);
    cout << "Sorting Completed successfully" << endl;
    Display(xArray,arraySize);
    Display(yArray,arraySize);
    //Display(valueList);
    cout << "--------------------------------------------" << endl;
    cout << "Start display the result:" << endl;
    cout << "Descriptive Statics" << endl;
    //1-Median
    cout << "1-Median" << endl;
    //display
    cout << "median_x= " << Median(xArray, arraySize) << " - "
         << "median_y= " << Median(yArray, arraySize) << endl;
    //conclusion
    cout << "--" << endl;
    //2-Mode
    cout << "2-Mode" << endl;
    //display
    cout << "mode_x= " << Mode(xArray, arraySize) << " - "
         << "mode_y= " << Mode(yArray, arraySize) << endl;
    //conclusion
    cout << "--" << endl;
    //3-Variance-------------------------------------------
    cout << "3-Variance and standard deviation" << endl;
    // variable
    double varX = Variance(xArray, arraySize);
    double varY = Variance(yArray, arraySize);
    //standard deviation-- use below
    double sX = sqrt(varX);
    double sY = sqrt(varY);
    //display
    cout << "var_x= " << varX << " - "
         << "var_y= " << varY << endl;
    cout << "stdev_x= " << sX << " - "
         << "stdev_y= " << sY << endl;
    //conclusion
    cout << "--" << endl;
    //4-Mean Absolute Deviation----------------------------------
    cout << "4-Mean Absolute Deviation" << endl;
    //display
    cout << "var_x= " << MeanAbsoluteDeviation(xArray, arraySize) << " - "
         << "var_y= " << MeanAbsoluteDeviation(yArray, arraySize) << endl;
    //conclusion
    cout << "--" << endl;
    //5-Third quartile-------------------------------------------
    cout << "5-Thrid Quartile" << endl;
    //display
    //cout<<"var_x= "<<MeanAbsoluteDeviation(valueList,true)<< " - "<<"var_y= "<<MeanAbsoluteDeviation(valueList,false)<<endl;
    //conclusion
    cout << "--" << endl;
    //6-Skewness------------------------------------------------
    cout << "6-Skewness" << endl;
    //display
    cout << "skew_x= " << Skewness(xArray, arraySize, sX) << " - "
         << "skew_y= " << Skewness(yArray, arraySize, sY) << endl;
    //conclusion
    cout << "--" << endl;
    //7-Kurtosis------------------------------------------------
    cout << "7-Kurtosis" << endl;
    //display
    cout << "kurt_x= " << Kurtosis(xArray, arraySize, sX) << " - "
         << "kurt_y= " << Kurtosis(yArray, arraySize, sY) << endl;
    //conclusion
    cout << "--" << endl;
    cout << "Inferential Statics" << endl;
    //1-Covariance------------------------------------------------
    cout << "1-Covariance" << endl;
    //display
    cout << "cov(x_y)= " << Covariance(xArray, yArray, arraySize) << endl;
    //conclusion
    cout << "--" << endl;
    //2-Pearson correlation coefficient------------------------------------------------
    cout << "2-Pearson correlation coefficient" << endl;
    //display
    cout << "r(x_y)= " << CorrelationCoefficient(xArray, yArray, arraySize) << endl;
    //conclusion
    cout << "--" << endl;
    //delete array
    delete[] xArray;
    delete[] yArray;
    return 0;
}
