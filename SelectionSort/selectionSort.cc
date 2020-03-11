#include <iostream>
using namespace std;

int main(){
    int size, i, j, temp, num, x, count=0;
    cout<<"Enter Array Size : ";
    cin>>size;
    int arr[size];
    cout<<"Enter Array Elements : ";

    for(i=0; i<size; i++)
        cin>>arr[i];
   
    for(i=0; i<(size-1); i++)
    {
        x = arr[i];
        for(j=(i+1); j<size; j++)
        {
            if(x>arr[j])
            {
                x = arr[j];
                count++;
                num = j;
            }
        }
        if(count!=0)
        {
            temp = arr[i];
            arr[i] = x;
            arr[num] = temp;
        }
        count=0;
    }
    cout<<"The array has been sorted\n";
    for(i=0; i<size; i++)
        cout<<arr[i]<<" ";

    cout << "\n";
}
