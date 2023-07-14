#include <iostream>

// 基礎類別
class Shape {
public:
  void setWidth(int w) {
    width = w;
  }
  
  void setHeight(int h) {
    height = h;
  }
  
protected:
  int width;
  int height;
};

// 繼承自 Shape 的子類別
class Rectangle : public Shape {
public:
  int getArea() {
    return width * height;
  }
};

int main() {
  Rectangle rect;
  
  rect.setWidth(5);
  rect.setHeight(3);
  
  int area = rect.getArea();
  
  std::cout << "矩形的面積為：" << area << std::endl;
  
  return 0;
}
