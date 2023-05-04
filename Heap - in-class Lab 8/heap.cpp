#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int left = 2 * root + 1; // left child of the current root
   int right = 2* root + 2;  // right child of the current root
   int largest;

   // if the left child is larger than root
   if (left < n && arr[left]>arr[root] )
      largest = left;
   else
      largest = root;
  
   // if the right child is larger than current largest
   if (right<n && arr[right] > arr[largest])
      largest = right;
  
   // if the largest is not root
   if (largest != root)
   {
      int temp = arr[root];
      swap(arr[root], arr[largest]);// swap the root with the largest child
      heapify(arr,n-largest-1,largest);// recursively heapify the affected sub-tree
   }
} 

  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   int heapsize = n;
   // call heapify on each node to build a max heap
   for (int i = heapsize/2 ; i>=0; i--)
   {
      heapify(arr,heapsize,i);
   }
   
   // extracting elements from heap one by one
   for (int i = n-1; i>=1;i--)
   {
      swap(arr[i],arr[0]); // swap the root with the last element
      heapsize--;
      heapify(arr,heapsize,0); // heapify the root
   }
} 

  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
