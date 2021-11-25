#include <iostream>
using namespace std;
// Find median
int MedianIndex(double* a, int low, int size)
{
    int excludeAmount=1;
    int n = size - low-excludeAmount;//amount of numbers exclude the low
    if(low==0)
    {
        excludeAmount=0;
        n=size;//no exclude when low is 0
    }
	if(n%2==1)//odd amount
    {
        return n/2+low+excludeAmount;//add back offset
    }
    else{   //even amount
        //return the lower index of the 2 median
        return (n/2-1)+low+excludeAmount;//add back offset
    }
}

// Function to calculate Q3
double quartile3(double* arr, int size)
{
	// Median of total data
	int med = MedianIndex(arr, 0, size);
    cout<<"midIndex: "<<med<<endl;
	double Q3;
	// Median of second half
    //check if the exclusive ammount of number is odd or even
	if ((size - med-1) % 2 == 1) {//odd amount
	    Q3 = arr[MedianIndex(arr, med,size)];
	}
	else {//even amount
        int q3Index=MedianIndex(arr, med, size);//location of the lower mmedian of the two mmedian;
	    Q3 = (arr[q3Index] + arr[q3Index + 1]) / 2;//since MedianIndex return the lower index of the two median must add 1 to compute the average
	}
	return Q3;
}

//Sorting array
void sortarray(double* arr, int r)
{
	int i, j, temp;
	for (i = 0; i < r; i++)
	{
		for (j = i + 1; j < r; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return;
}
// Driver Code
int main()
{
	int i, j, temp;
	double arr[] = { 1,2,3,4,5,6,7,8 };
	int m = sizeof(arr) / sizeof(arr[0]);
	sortarray(arr, m);

	cout << "Third Quartile = " << quartile3(arr, m) << endl;
	return 0;
}