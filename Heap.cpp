#include "Heap.h"

Heap::Heap(){
  numItems = 1;
}

void Heap::enqueue( PrintJob* item){
    if (numItems != MAX_HEAP_SIZE){
        if( numItems == 1){
            arr[numItems] = item;
            ++numItems;
        }
        else{
            arr[numItems] = item;
            int x = numItems;
            //cout << "here" << endl;

            while ( x > 1 && arr[ (((x) /2) ) ]->getPriority() < item ->getPriority()){ //checking if parent is greater than the new item
                //cout << "here" << endl;
                arr[x] = arr[ (((x) / 2) ) ]; //changes arr to be parent
                x = (((x) / 2) ); //sets x to be where parent is 
                arr[x] = item; //set item to x
                //cout << "here" << endl;
            }
            ++numItems;
           //cout << "here" << endl;
        }
    }
   // display();
}

void Heap::dequeue ( ){
    if(isempty()){
        return;
    }
    trickleDown(0);
    //display();
}
PrintJob* Heap::highest(){
  if(isempty()){
      return nullptr;
  }
  return arr[1];
}
void Heap::print ( ){
    if(numItems == 1){
        return;
    }
    cout << "Priority: " << arr[1]->getPriority();
    cout << ", Job Number: " << arr[1]->getJobNumber();
    cout << ", Number of Pages: " << arr[1]->getPages() << endl; 
}
void Heap::trickleDown(int index){
    int i = 1;
    delete arr[i];
    arr[i] = arr[numItems-1];
    --numItems;
    while( i <= numItems ){
        //cout << "here" << endl;
    if( 2*i >= numItems){
        break;
        //cout << "here" << endl;
    }
        //cout << "here" << endl;
    else if( numItems <= 2 * i ){ //checks if left child exists
        //cout << "here" << endl;
        return;
    }
    else if (numItems <= 2 * i + 1){ //checks if right exists and if this isn't true, the left should exist
        if (arr[i] ->getPriority() < arr[2*i] ->getPriority())
        swap (arr[i], arr[2*i]);
        i = 2*i ;
        //cout << "here" << endl;
    }
    else{
        if (arr[i]->getPriority() > arr[2*i]->getPriority() && arr[i]->getPriority() > arr[2*i+1]->getPriority()){
            return;
        }
        else if (arr[i] -> getPriority() < arr[2*i] ->getPriority() && arr[2*i] ->getPriority() > arr[2*i+1] ->getPriority()){
            swap (arr[i], arr[2 * i ]);
            i = 2 * i ; //sets i to check if branch on the left does not break the max 
        }
        else if( arr[i] ->getPriority() < arr[2*i+1] -> getPriority() ){
            swap( arr[i] , arr[2 * i + 1] );
            i = 2 * i + 1; //sets i to check if the branch on the right does not break the max
            }
            /*
        else if(arr[i]->getPriority() > arr[2*i] -> getPriority() && arr[i]->getPriority() > arr[2*i+1]->getPriority()){
            return;
        }
        */
        //break;
        }

    }
}
bool Heap::isempty(){
    if(numItems == 1){
        return true;
  }
  return false;  
}
/*
void Heap::display(){
    for (int i = 1; i< numItems; i++){
        cout << arr[i]->getPriority() << " ";
    }
}
*/
// A[h] = A[2h]
// A[h] = A[2h+1]