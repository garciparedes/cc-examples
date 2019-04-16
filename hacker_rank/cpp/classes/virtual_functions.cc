#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
 public:
  string name;
  int age;
  int cur_id;

  explicit Person(int cur_id)
      : name(""),
        age(0),
        cur_id(cur_id) {}

  virtual void getdata() {
    cin >> name >> age;
  }

  virtual void putdata() {
    cout << name << ' ' << age << ' ';
  }
};

class Professor : public Person {
 private:
  typedef Person person;

 public:
  int publications;

  static int cur_id_gen;

  Professor()
      : Person(cur_id_gen++),
        publications(0) {}

  void getdata() override {
    person::getdata();
    cin >> publications;
  }

  void putdata() override {
    person::putdata();
    cout << publications << ' ' << cur_id << '\n';
  }
};
int Professor::cur_id_gen = 1;

class Student : public Person {
 private:
  typedef Person person;

 public:
  vector<int> marks;

  static int cur_id_gen;

  Student()
      : Person(cur_id_gen++) {}

  void getdata() override {
    person::getdata();

    int temp;
    for (int i = 0; i < 6; i++) {
      cin >> temp;
      marks.push_back(temp);
    }
  }

  void putdata() override {
    person::putdata();

    cout << sum_marks() << ' ' << cur_id << '\n';
  }

  int sum_marks() {
    int s = 0;
    for (auto &v: marks) {
      s += v;
    }
    return s;
  }
};
int Student::cur_id_gen = 1;

int main() {

  int n, val;
  cin >> n;
  Person *per[n];

  for (int i = 0; i < n; i++) {

    cin >> val;
    if (val == 1) {

      per[i] = new Professor;

    } else per[i] = new Student;

    per[i]->getdata();

  }

  for (int i = 0; i < n; i++)
    per[i]->putdata();

  return 0;

}
