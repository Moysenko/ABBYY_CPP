import Example;

int main() {
  MyNamespace::A a;
  MyNamespace::B b;

  a.f();
  b.g();


  // без следующих двух строк все билдится и успешно отрабатывает
  f_internal();
  g_internal();
}