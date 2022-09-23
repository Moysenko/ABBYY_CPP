#include <iostream>

class Prism {
 public:
  Prism(double height) : height_{height} {}

  virtual double Square() const = 0;

  double Volume() const {
    return Square() * height_;
  }

 private:
  double height_;
};

class Box : public  Prism {
 public:
  Box(double height, double base)
    : Prism(height), base_{base} {}

  virtual double Square() const {
    return base_ * base_;
  }

 private:
  double base_;
};

class Cube : public Box {
 public:
  Cube(double edge_length) 
    : Box(edge_length, edge_length) {}
};


int main() {
  const Prism *p, *q, *r;
  Box a(0.5, 2), b(5, 0.2);
  Cube c(0.5);
  p = &a; q = &b; r = &c;
  std::printf("Squares: %3.3lf %3.3lf %3.3lf\n",
         p->Square(), q->Square(), r->Square());
  std::printf("Volumes: %3.3lf %3.3lf %3.3lf\n",
         p->Volume(), q->Volume(), r->Volume());
  return 0;
}