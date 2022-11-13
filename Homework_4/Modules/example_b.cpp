export module Example:B;


namespace MyNamespace {

void g_internal();

export struct B {
  void g() {
    g_internal();
  }
};

}  // namespace MyNamespace