#include <iostream>
#include <stdlib.h>
using namespace std;
class Stack_Osi{
private:
 int *heig,*widt,buffersize,head,fins;
public:
  Stack_Osi();
  ~Stack_Osi(){
    delete [] heig;
    delete [] widt;
    };
    void add();
    int pop_w(int);
    int pop_h(int);
};
  Stack_Osi::Stack_Osi():buffersize(1),head(0),fins(0){
    heig = new int[buffersize];
    widt = new int[buffersize];
    }
  
void Stack_Osi::add(){
    int w,h;
    cin>>w>>h;
    if(fins!=0){
      widt = (int *)realloc(widt,(++buffersize)*sizeof(int));
      heig = (int *)realloc(heig,(++buffersize)*sizeof(int));
      }
      widt[fins]=w;
      heig[fins]=h;
      fins++;
 }
 int Stack_Osi::pop_w(int i){
    if( i < buffersize ){
    return (widt[i]);
    }
    exit(1);
 }
  int Stack_Osi::pop_h(int i){
    if( i < buffersize ){
    return (heig[i]);
    }
    exit(1);
 }
int main(){
  int ra;
  cin>>ra;
  Stack_Osi H;
  for(int i=0;i<ra;i++){
    H.add();
  }
  if(ra>1){
  int *S,ww,hh,q=0;
  S=new int[1500];
    for(int u=1;u<ra;u++){
      ww=H.pop_w(u-1);
      hh=H.pop_h(u-1);
      for(int i=u;i<ra;i++){
        if(hh<H.pop_h(i)){
          if(i!=ra-1){
          ww+=H.pop_w(i);
          }
          else{
           ww+=H.pop_w(i);
           S[q]=hh*ww;
           q++;
           }
          }
        else{
          if(i!=ra-1){
           S[q]=ww*hh;
           ww+=H.pop_w(i);
           hh=H.pop_h(i);
           q++;}
          else{
          S[q]=hh*ww;
          q++;
           hh=H.pop_h(i);
           ww+=H.pop_w(i);
           S[q]=hh*ww;
           q++;
           }
          }
        }
        }
        int A=S[0];
         for(int i=0;i<=q;i++){
              if(A<S[i]){
                A=S[i];
                }
                }
              cout<<A;
               delete [] S;}
              else{
                cout<<H.pop_w(0)*H.pop_h(0);
                }
  return 0;
}
      
