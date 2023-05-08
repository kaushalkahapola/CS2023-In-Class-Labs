#include <iostream> 

#include <chrono> 

#include <queue> 

  

using namespace std; 

using namespace std::chrono; 

  

int Partition(int arr[], int start, int end){ 

    int pivot = arr[end]; 

    int p_index = start; 

     

    for(int i=start;i<end;i++){ 

        if (arr[i]<pivot){ 

            int temp = arr[i]; 

            arr[i]=arr[p_index]; 

            arr[p_index]=temp; 

            p_index++; 

        } 

    } 

     

    int temp = arr[end]; 

    arr[end]=arr[p_index]; 

    arr[p_index]=temp; 

     

    return p_index; 

} 

  

void Quicksort(int arr[], int start, int end){ 

    queue<int> queue; 

    queue.push(start); 

    queue.push(end); 

  

    while (!queue.empty()) { 

        int left = queue.front(); 

        queue.pop(); 

        int right = queue.front(); 

        queue.pop(); 

  

        if (left < right) { 

            int p = Partition(arr, left, right); 

  

            // Enqueue the left sub-array 

            queue.push(left); 

            queue.push(p - 1); 

  

            // Enqueue the right sub-array 

            queue.push(p + 1); 

            queue.push(right); 

        } 

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

         

        // generate random elements for the array 

        for(int i=0;i<size;i++){ 

            myarray[i]=rand()%10000; 

        } 

         

        auto total_time = microseconds(0); 

        for (int j = 0; j < num_iterations; j++) { 

            auto start_time = high_resolution_clock::now(); 

            Quicksort(myarray,0,size-1); 

            auto end_time = high_resolution_clock::now(); 

            auto duration = duration_cast<microseconds>(end_time - start_time); 

            total_time += duration; 

        } 

        auto avg_time = total_time.count() / num_iterations; 

         

        cout << "Average execution time: " << avg_time << " microseconds" << std::endl; 

    } 

     

    return 0; 

} 
