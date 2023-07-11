#ifndef ALGORITHMS_FUNCALGO_H
#define ALGORITHMS_FUNCALGO_H

#endif //ALGORITHMS_FUNCALGO_H

#include <cstring>

//termination condition for the recursive template below
template<typename T>
T minimum(T arg) {
    return arg;
}

//function for finding the minimum value among the arguments provided
template<typename T, typename... Args>
T minimum(T arg1, Args... args) {
    T minimum_of_rest = minimum(args...);
    return (arg1 < minimum_of_rest) ? arg1 : minimum_of_rest;
}

//the heap class
class Heap{
    public:
        int* heap;
        int size;

    Heap(int arr[], int size){
        this->heap = arr;
        this->size = size;
    };

    //util function for checking what kind of heap is being operated on; used in the inserting function
    //checks, whether a given heap is a min one
    bool is_min_heap(int i){
            if(i >= size){
                return true;
            }

            int l = 2 * i + 1; //left child index
            int r = 2 * i + 2; //right child index

            if((l <= size) && (heap[l] < heap[i])){
                return false;
            }
            if((r <= size) && (heap[r] < heap[i])){
                return false;
            }

            return is_min_heap(l) && is_min_heap(r);
    }

    //returns the parent of a node at i
    int parent(int i){
        if(i == 0){
            return 0;
        } else return (i-1)/2;
    }

    //returns the left child of a node at i
    int left(int i){
        return (2 * i) + 1;
    }

    //returns the right child of a node at i
    int right(int i){
        return (2 * i) + 2;
    }

    //heapify procedure for min heap, implemented recursively
    void heapify_min(int i, int size){
        int l = this->left(i);
        int r = this->right(i);
        int smallest_index = i;

        if(l < size && heap[l] < heap[smallest_index]){
            smallest_index = l;
        }
        if(r < size && heap[r] < heap[smallest_index]){
            smallest_index = r;
        };

        if(smallest_index != i){
            std::swap(heap[i], heap[smallest_index]);
            this->heapify_min(smallest_index, size);
        }
    }

    //build_heap for min heap
    void build_minheap(int size){
        int startIdx = (size / 2) - 1;

        for (int i = startIdx; i >= 0; i--) {
            heapify_min(i, size);
        }
    }

    //heapify for max heap, implemented recursively
    void heapify_max(int i, int size){
        int l = this->left(i);
        int r = this->right(i);
        int largest_index = i;

        if(l < size && heap[l] > heap[largest_index]){
            largest_index = l;
        }
        if(r < size && heap[r] > heap[largest_index]){
            largest_index = r;
        };

        if(largest_index != i){
            std::swap(heap[i], heap[largest_index]);
            this->heapify_max(largest_index, size);
        }
    }

    //build_heap for max heap
    void build_maxheap(int size){
        int startIdx = (size / 2) - 1;

        for (int i = startIdx; i >= 0; i--) {
            heapify_max(i, size);
        }
    }

    //inserting an item into a heap
    void insert(int el){
        bool ismin = is_min_heap(0);
        int insert_ind = 0;

        //shifting the existing elements to make space for a new one
        for (int i = size; i >= insert_ind; i--) {
            heap[i + 1] = heap[i];
        }
        heap[insert_ind] = el;
        if(ismin){
            build_minheap(size);
        }
        else{
            build_maxheap(size);
        }
    }

};

//primitive utility function for printing the heap
template <typename T>
void print_arr(T arr[], int size){
    int i=0;
    int* ptr = arr;

    while(i<size){
        if(i != size-1){
        std::cout << *(ptr+i) << ",";
        i++;}
        else {
            std::cout << *(ptr+i) << std::endl;
            break;
        }
    }

}

