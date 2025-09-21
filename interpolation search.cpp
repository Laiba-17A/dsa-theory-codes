#include<iostream>
using namespace std;

void interpolationSearch(int arr[], int n, int key)
{
    int Low = 0, High = n-1;
    bool flag = true;
    //Checking the corner cases
    while(Low <= High && key >= arr[Low] && key <= arr[High])
    {
        int q = (key - arr[Low])/(arr[High] - arr[Low]);
        int pos = Low + (High - Low) * q;
        cout<<"Low value is "<<Low<<" High value is "<<High<<" position calculated is "<<pos<<endl;
        if(arr[pos] == key)
        {
            cout<<"Element found at position "<<pos<<endl;
            flag = false;
        }
        //If the element is greater than the value at that position
        if(arr[pos] < key)
        {
            Low = pos + 1;
        }
        //If the element is lesser than the value at that position
        else
        {
            High = pos - 1;
        }
    }
    //If the element is not found after traversing the whole array
    if(flag == true)
    {
     cout<<"Element not found"<<endl;
    }
}

//Main function to take in the inputs from the user
int main()
{
	int n=20,i,x;
	int arr[n]={0,5,10,15,20,25,31,35,40,45,50,55,60,65,70,75,80,85,90,95};;
    cout<<"Enter the element to be searched\n";
    cin>>x;
    interpolationSearch(arr, n, x);
    return 0;
}
