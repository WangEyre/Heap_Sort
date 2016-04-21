//Heap sort algorithm

//maintainence in recursive procedure
void maxHeapify1(vector<int> &A, int heaplength, int i){
    int left=2*i+1;
    int right=2*i+1;
    int largest=i;
    if(left<heaplength && A[left]>A[largest])
        largest=left;
    if(right<heaplength && A[right]>A[largest])
        largest=right;
    if(i!=largest) {
        swap(A[i],A[largest]);
        maxHeapify1(A, heaplength, largest);
    }
}

//maintanence in loop procedure
void maxHeapify2(vector<int> &A, int heaplength, int i){
    while(i<heaplength){
        int left=2*i+1;
        int right=2*i+2;
        int largest=i;
        if(left<heaplength && A[left]>A[largest])
            largest=left;
        if(right<heaplength && A[right]>A[largest])
            largest=right;
        if(i!=largest) {
            swap(A[i],A[largest]);
            i=largest;
        }
    }
}

void buildHeap(vector<int> &A){
    int len=A.size();
    for(int i=len/2-1;i>=0;i--)
        maxHeapify(A,len,i);  
}

void heapSort(vector<int> &A){
    buildHeap(A);
    int len=A.size();
    for(int i=len-1;i>=1;i--){
        swap(A[0],A[i]);
        maxHeapify(A,i,0);
    }
}

//priority queue algorithm