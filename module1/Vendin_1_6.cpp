#include <iostream>
using namespace std;

class BinaryTree {
  private:
  int *buffer;
  int raz;
  public:
  BinaryTree(int ra = 0 ):raz(ra) {
    buffer = new int[raz];
    for( int q = 0; q < raz; ++q){
      cin >> buffer[q];
    }
    for( int i = raz / 2 -1; i >= 0; --i ) {
      SiftDown(i);
    }
  }
  
  ~BinaryTree() { delete [] buffer; }
  void SiftDown(int);
  void SiftUp(int);
  int ExtractMax();
  void Add(int);
  void pech(){
    for(int i=0; i < raz ; i++){
      cout << buffer[i] <<" ";
    }
  }
};

void BinaryTree::SiftDown(int i) {
  for(;;) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if( left < raz && buffer[left] > buffer[i] )
      largest = left;
    if( right < raz && buffer[right] > buffer[largest] )
      largest = right;
    if(largest == i ){
      break;
  }
    std::swap(buffer[i], buffer[largest] );
    this->SiftDown(largest );
  }
}

void BinaryTree::SiftUp(int index) {
  while( index > 0 ) {
    int parent = ( index - 1 ) / 2;
    if( buffer[index] <= buffer[parent] ){
      return;
    }
    swap( buffer[index], buffer[parent] );
    index = parent;
  }
}

int BinaryTree::ExtractMax(){
  int result = buffer[0];
  raz--;
  buffer[0] = buffer[raz];
  int *buffer1 = new int [raz];
  for( int i = 0; i < raz; ++i ){
    buffer1[i]=buffer[i];
  }
  delete [] buffer;
  buffer = buffer1;
  SiftDown(0);
  return result;
}

void BinaryTree::Add( int element) {
  ++raz;
  int *buffer2 = new int [raz];
  for( int i = 0; i < (raz-1); ++i) {
    buffer2[i] = buffer[i];
  }
  buffer2[raz-1] = element;
  delete [] buffer;
  buffer = buffer2;
  SiftUp( raz - 1 );
}
  
int main(void) {
  int Ra,G,hand = 0;
  cin >> Ra;
  BinaryTree A(Ra);
  cin >> G;
  int *had = new int [Ra];
  int i=-1,w=0;
 do{
    do {
      i++;
      had[i] = A.ExtractMax();
      hand += had[i];
    } while( ((hand < G) && (i < Ra-1)));
    if( hand > G){
      A.Add(had[i]);
       i--;
    }
    hand = 0;
    while ( i >= 0 ){
      A.Add( (had[i] / 2) );
      --i;
    }
    w++;
  }while( had[i+1] != 0 );
  cout << w-1;
  delete [] had;
  return 0;
}

