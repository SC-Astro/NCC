#include "stdio.h"
#include "math.h"

int minimum(int first, int second){
    if(second>first)
      return first;
    
      else
      return second;
}


int JumpSearch(int arr[], int wanna_search, int jumpsize){
    //Finding jump size
    int step = sqrt(jumpsize);
  
    //Finding the number
    //If it is present
    int previous = 0;
    while (arr[minimum(step, jumpsize)-1] < wanna_search){
        previous = step;
        step += sqrt(jumpsize);
        if (previous >= jumpsize){
            return -1;
        }
            
    }
  
    
    //Doing a linear search for the number that we want to search
    while (arr[previous] < wanna_search){
        previous++;
  
        //After we have searched the whole array, if we don't find it, then that number is not present in this array
        if (previous == minimum(step, jumpsize))
            return -1;
    }
    
    //If the number is found
    if (arr[previous] == wanna_search){
        return previous;
    }
  
    return -1;
}

int main(){
    int arr[] = { 0, 1, 2, 3, 5, 8, 13, 21, 23, 26};
    int wanna_search = 5;
    int jumpsize = sizeof(arr)/sizeof(arr[0]);
    int index = JumpSearch(arr, wanna_search, jumpsize);
    
    if(index >= 0){
        printf("Searching number -> %d\n", wanna_search);
        printf("Numer is found:)\n");
        printf("It is at %d index", index);
    }
    else{
        printf("Number is not exist in the array");
    }
    
    return 0;
}