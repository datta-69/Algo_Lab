#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int partition(int arr[], int l, int h){
    int pivot = arr[l];
    int i = l;
    int j = h;
    while(i<=j){
        while(i<=h && arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[l],arr[j]);
    return j;
}
void quickSort(int arr[],int l, int h){
    if(l<h){
        int p = partition(arr,l,h);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,h);
    }
}
void merge(int arr[], int l, int mid, int r){
int n1 = mid - l +1;
int n2 = r - mid;
int a[n1];
int b[n2];
for (int  i = 0; i < n1; i++)
{
    a[i] = arr[l+ i];
}
for (int i = 0; i < n2; i++)
{
    b[i] = arr[mid + 1 + i];
}
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
            
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }

    while (i < n1)
        {
            arr[k] = a[i];
            k++;
            i++;
        }
    while (j < n2){
            arr[k]=b[j];
            k++;
            j++;}

}
void mergeSort(int arr[],int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
void scanArray(int arr[],int count){
    for (int i = 0; i < count; i++)
    {
        cin>>arr[i];
    }
    
}
void printArray(int arr[], int count){
    for (int i = 0; i < count; i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={6,5,3,7,2,8,4,9,34,91,12};
    int n = sizeof(arr)/sizeof(arr[0]);
        int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }
    auto SQ = high_resolution_clock::now();
    quickSort(arr1,0,n-1);

    auto EQ = high_resolution_clock::now();
    duration<double> duration_Quick_Sort = EQ - SQ;

    auto SM = high_resolution_clock::now();
    mergeSort(arr2,0,n-1);

    auto EM = high_resolution_clock::now();
    duration<double> duration_Merge_Sort = EM - SM;

    cout << "After Merge Sort: ";
    printArray(arr2, n);
    cout<<endl;

    cout << "After Quick Sort: ";
    printArray(arr1, n);
    cout<<endl;
    

    cout<<fixed;
    cout.precision(10);
    cout << "Merge Sort Time: " << duration_Merge_Sort.count() << " Seconds" << endl;
    cout << "Quick Sort Time: " << duration_Quick_Sort.count() << " Seconds" << endl;


    return 0;
}