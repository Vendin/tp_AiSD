#include <stdlib.h>
#include <iostream>

class str {
  private:
  int *buffer;
  int buffersize;
  int head;
  int fins;
  public :
  str();
  ~str() {
     delete [] buffer;
  }
  void push_back(int A);
  int pop_front();
};
str::str() : buffersize(1), head(0), fins(0) {
  buffer = new int[buffersize];
}
void str::push_back(int z) {
  if (fins != 0) {
    buffer = (int *) realloc(buffer , (++buffersize) * sizeof(z));
  }
  buffer[fins] = z;
  fins += 1;
}

int str::pop_front() {
  if (head != fins) {
    int re = buffer[head];
    head = (++head);
    return re;
  } else {
    return -1;
  }
}

void viv(bool l ) {
  if (l== 0) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
}
int main() {
  int a, *op, *zn;
  bool l = 0;
  std::cin >> a;
  op = new int[a];
  zn = new int[a];
  str ob;
  for (int i = 0; i < a; i++) {
    std::cin >> op[i];
    std::cin >> zn[i];
    if (op[i] == 3) {
        ob.push_back(zn[i]);
    }
    if (op[i] == 2) {
      int u = ob.pop_front();
          if (u != zn[i] ) { l=1; }
       }
    }
  viv(l);
  delete [] op;
  delete [] zn;
return 0;
}
