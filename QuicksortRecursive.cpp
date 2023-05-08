#include <iostream> 
#include <chrono>  

using namespace std; 
using namespace std::chrono; 

  

// Partition function to split the array into two partitions around a pivot element 

int Partition(int arr[], int start, int end){ 

    int pivot = arr[end]; 

    int p_index = start; 

     

    // Loop through the array and swap elements if they are less than the pivot element 

    for(int i=start;i<end;i++){ 

        if (arr[i]<pivot){ 

            int temp = arr[i]; 

            arr[i]=arr[p_index]; 

            arr[p_index]=temp; 

            p_index++; 

        } 

    } 

     

    // Swap the pivot element with the partition index element 

    int temp = arr[end]; 

    arr[end]=arr[p_index]; 

    arr[p_index]=temp; 

     

    // Return the partition index 

    return p_index; 

} 

  

// Quicksort function to recursively sort the array using the Partition function 

void Quicksort(int arr[],int start,int end){ 

    if(start<end){ 

        // Find the partition index using the Partition function 

        int p = Partition(arr,start,end); 

        // Recursively sort the left partition 

        Quicksort(arr,start,(p-1)); 

        // Recursively sort the right partition 

        Quicksort(arr,(p+1),end); 

    } 

} 

  

int main() 

{    

    int sizes[] = {2000, 4000, 6000, 8000, 10000}; 

    int num_iterations = 5; 

    for (int i = 0; i < 5; i++) { 

        int size = sizes[i]; 

        int myarray[size]; 

        cout << "Sorting array of size " << size << "..." << endl; 

         

        auto total_time = microseconds(0); // Initialize a variable to hold the total time taken to sort the array 

        for (int j = 0; j < num_iterations; j++) { 

            // Generate random elements for the array 

            for(int i=0;i<size;i++){ 

                myarray[i]=rand()%10000; 

            } 

            auto start_time = high_resolution_clock::now(); // Get the start time 

            Quicksort(myarray,0,size-1); // Sort the array using Quicksort 

            auto end_time = high_resolution_clock::now(); // Get the end time 

            auto duration = duration_cast<microseconds>(end_time - start_time); // Calculate the duration 

            total_time += duration; // Add the duration to the total time 

        } 

        auto avg_time = total_time.count() / num_iterations; // Calculate the average time taken 

         

        cout << "Average execution time: " << avg_time << " microseconds" << std::endl; // Print the average time taken 

    } 

     

    return 0; 

} 
