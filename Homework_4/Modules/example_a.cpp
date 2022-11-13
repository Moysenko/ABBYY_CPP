export module Example:A;


namespace MyNamespace {

void f_internal();

export struct A {
  void f() {
    f_internal();
  }
};

}  // namespace MyNamespace