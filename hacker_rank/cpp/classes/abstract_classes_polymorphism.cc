#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
  Node *next;
  Node *prev;
  int value;
  int key;
  Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val) {};
  Node(int k, int val) : prev(nullptr), next(nullptr), key(k), value(val) {};
};

class Cache {

 protected:
  map<int, Node *> mp; //map the key to the node in the linked list
  int cp;  //capacity
  Node *tail; // double linked list tail pointer
  Node *head; // double linked list head pointer
  virtual void set(int, int) = 0; //set function
  virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
 public:

  explicit LRUCache(int capacity) {
    cp = capacity;
  }

  void set(int key, int value) override {

    Node *node = get_node(key);

    if (!node) {
      set_new(key, value);
    } else {
      set_existing(node, value);
    }
  }

  int get(int key) override {
    Node *node = get_node(key);
    if (!node) {
      return -1;
    }
    return node->value;
  }

 private:

  Node *get_node(int key) {
    auto it = mp.find(key);
    if (it == mp.end()) {
      return nullptr;
    }
    return it->second;
  }

  void set_existing(Node *node, int value) {
    node->value = value;

    move_to_head(node);
  }

  void set_new(int key, int value) {
    Node *node = new Node(key, value);

    mp.emplace(key, node);

    if (mp.size() == 1) {
      head = node;
      tail = node;
    } else {
      move_to_head(node);
    }

    if (mp.size() > cp) {
      discard_tail();
    }
  }

  void move_to_head(Node *node) {
    liberate_node(node);

    if (head) {
      head->prev = node;
    }

    if (tail == node) {
      tail = node->prev;
    }

    node->prev = nullptr;
    node->next = head;
    head = node;
  }

  static void liberate_node(Node *node) {
    Node *prev = node->prev;
    Node *next = node->next;

    if (prev) {
      prev->next = next;
    }

    if (next) {
      next->prev = prev;
    }
  }

  void discard_tail() {
    mp.erase(tail->key);
    tail = tail->prev;
    tail->next = nullptr;
  }

};

int main() {
  int n, capacity, i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  for (i = 0; i < n; i++) {
    string command;
    cin >> command;
    if (command == "get") {
      int key;
      cin >> key;
      cout << l.get(key) << endl;
    } else if (command == "set") {
      int key, value;
      cin >> key >> value;
      l.set(key, value);
    }
  }
  return 0;
}
