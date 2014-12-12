#include <iostream>
struct rectangle {
    int width;
    int height;
};

class CStack {
  public:
  CStack( int _bufferSize );
  ~CStack();
  void push (rectangle);
  rectangle pop();
  void grow();
  int cut(int height);
  private:
  int real_size;
  int buffer_size;
  rectangle* buffer;
};

void CStack::grow() {
  int new_buffer_size = buffer_size * 2;
  rectangle* new_buffer = new rectangle[new_buffer_size];
  for (int i = 0; i < buffer_size; i++) {
    new_buffer[i] = buffer[i];
  }
  buffer = new_buffer;
  buffer_size = new_buffer_size;

  }

  CStack::CStack (int _bufferSize) : buffer_size (_bufferSize), real_size (0)
  {
  buffer = new rectangle[buffer_size];
  }
  CStack::~CStack()
  {
  delete[] buffer;
  }

  void CStack::push (rectangle a)
  {
  if (buffer_size <= real_size) {
    grow();
  }
  buffer[real_size++] = a;
  }

  rectangle CStack::pop()
  {
  return buffer[--real_size];
  }

  int CStack::cut(int height) {
  int square, max_square = 0, width = 0, counter = real_size;
  rectangle a;
  for (int i = counter; i > 0; i--) {
    a = pop();
    if (a.height < height) {
      push(a);
      break;
    }
    width += a.width;
    square = a.height * width;
    if (square >= max_square) {
      max_square = square;
    }
  }
  a.width = width;
  a.height = height;
  push(a);
  return max_square;
  }

  int main(void) {
  int number, previous_height = 0, square, max_square = 0;
  rectangle rect;
  std::cin >> number;
  CStack stack (10);
  for (int i = 0; i < number; i++) {
    std::cin >> rect.width >> rect.height;
    
    if (rect.height >= previous_height) {
      stack.push(rect);
    }
    else {
      if (max_square <= (square = stack.cut(rect.height))) {
      max_square = square;
    }
      stack.push(rect);
    }
    previous_height = rect.height;
  }
  if (max_square <= (square = stack.cut(0))) {
      max_square = square;
  }
  std::cout << max_square;
  return 0;
}

