#include "cyclic_rc/shared_ptr.h"

#include <map>
#include <iostream>

using namespace cyclic_rc;

class PyObject;
using PyObjectPtr = shared_ptr<PyObject, false>;

class PyObject : public cyclic_rc_base<false> {
 public:
  virtual ~PyObject() { std::cout << "obj destroyed" << std::endl; }

  void visit_children(int t) override {}
};

class PySet: public PyObject {
 public:
  void add(PyObjectPtr &obj) { data_ = obj; }

  void visit_children(int t) override {
    data_.visit_children(t);
  }

 private:
  PyObjectPtr data_;
};

void run() {
  PyObject *obj = new PyObject();
  PyObjectPtr ptr_0(obj);

  PySet *set_1 = new PySet();
  set_1->add(ptr_0);
  PyObjectPtr ptr_1(set_1);

  PySet *set_2 = new PySet();
  set_2->add(ptr_1);
  PyObjectPtr ptr_2(set_2);

  PySet *set_3 = new PySet();
  set_3->add(ptr_1);
  PyObjectPtr ptr_3(set_3);

  ptr_1 = PyObjectPtr();
}

void run2() {
  PySet *obj_1 = new PySet();
  PyObjectPtr ptr_1(obj_1);

  PySet *obj_2 = new PySet();
  PyObjectPtr ptr_2(obj_2);

  obj_1->add(ptr_2);
  obj_2->add(ptr_1);
}

void make_map(std::map<int, PyObjectPtr> &m) {
  m.emplace(1, PyObjectPtr(new PyObject()));
  m.emplace(2, PyObjectPtr(new PyObject()));
}

void run3() {
  std::map<int, PyObjectPtr> m1;
  make_map(m1);

  std::map<int, PyObjectPtr> m2;
  for (auto &e: m1) {
    m2.insert(e);
  }

  std::map<int, PyObjectPtr> m3;
  for (auto &e: m1) {
    m3.insert(e);
  }
}


int main() {
  run();
  // run2();
  // run3();
  return 0;
};
