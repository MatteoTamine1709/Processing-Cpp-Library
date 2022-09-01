#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <memory>

template <typename T>
struct node {
  T value;
  std::shared_ptr<node> next;
};

template<typename T>
class LinkedList {

  std::shared_ptr<node<T>> head;

public:
  LinkedList() {}
  ~LinkedList() {}

  void add(T value) {
    std::shared_ptr<node<T>> newNode = std::make_shared<node<T>>();
    newNode->value = value;
    newNode->next = head;
    head = newNode;
  }

  void remove(T value) {
    std::shared_ptr<node<T>> current = head;
    std::shared_ptr<node<T>> previous = nullptr;
    while (current != nullptr) {
      if (current->value == value) {
        if (previous == nullptr) {
          head = current->next;
        } else {
          previous->next = current->next;
        }
        break;
      }
      previous = current;
      current = current->next;
    }
  }

  void remove(int index) {
    std::shared_ptr<node<T>> current = head;
    std::shared_ptr<node<T>> previous = nullptr;
    int i = 0;
    while (current != nullptr) {
      if (i == index) {
        if (previous == nullptr) {
          head = current->next;
        } else {
          previous->next = current->next;
        }
        break;
      }
      previous = current;
      current = current->next;
      i++;
    }
  }

  void clear() {
    head = nullptr;
  }

  int size() {
    int size = 0;
    std::shared_ptr<node<T>> current = head;
    while (current != nullptr) {
      size++;
      current = current->next;
    }
    return size;
  }

  T get(int index) {
    std::shared_ptr<node<T>> current = head;
    int i = 0;
    while (current != nullptr) {
      if (i == index) {
        return current->value;
      }
      current = current->next;
      i++;
    }
    return T();
  }

  T getFirst() {
    return head->value;
  }

  T getLast() {
    std::shared_ptr<node<T>> current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    return current->value;
  }

  bool contains(T value) {
    std::shared_ptr<node<T>> current = head;
    while (current != nullptr) {
      if (current->value == value) {
        return true;
      }
      current = current->next;
    }
    return false;
  }

  int indexOf(T value) {
    std::shared_ptr<node<T>> current = head;
    int i = 0;
    while (current != nullptr) {
      if (current->value == value) {
        return i;
      }
      current = current->next;
      i++;
    }
    return -1;
  }

  int lastIndexOf(T value) {
    std::shared_ptr<node<T>> current = head;
    int i = 0;
    int lastIndex = -1;
    while (current != nullptr) {
      if (current->value == value) {
        lastIndex = i;
      }
      current = current->next;
      i++;
    }
    return lastIndex;
  }

  void print() {
    std::shared_ptr<node<T>> current = head;
    while (current != nullptr) {
      std::cout << current->value << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }

  void insert(int index, T value) {
    std::shared_ptr<node<T>> newNode = std::make_shared<node<T>>();
    newNode->value = value;
    std::shared_ptr<node<T>> current = head;
    std::shared_ptr<node<T>> previous = nullptr;
    int i = 0;
    while (current != nullptr) {
      if (i == index) {
        newNode->next = current;
        if (previous == nullptr) {
          head = newNode;
        } else {
          previous->next = newNode;
        }
        break;
      }
      previous = current;
      current = current->next;
      i++;
    }
  }

  void insert(T value, std::function<bool(T, T)> comp) {
    std::shared_ptr<node<T>> newNode = std::make_shared<node<T>>();
    newNode->value = value;
    std::shared_ptr<node<T>> current = head;
    std::shared_ptr<node<T>> previous = nullptr;
    while (current != nullptr) {
      if (comp(value, current->value)) {
        newNode->next = current;
        if (previous == nullptr) {
          head = newNode;
        } else {
          previous->next = newNode;
        }
        break;
      }
      previous = current;
      current = current->next;
    }
  }

  void reverse() {
    std::shared_ptr<node<T>> current = head;
    std::shared_ptr<node<T>> previous = nullptr;
    std::shared_ptr<node<T>> next = nullptr;
    while (current != nullptr) {
      next = current->next;
      current->next = previous;
      previous = current;
      current = next;
    }
    head = previous;
  }

  void sort() {
    std::shared_ptr<node<T>> current = head;
    std::shared_ptr<node<T>> previous = nullptr;
    std::shared_ptr<node<T>> next = nullptr;
    while (current != nullptr) {
      next = current->next;
      while (previous != nullptr && previous->value > current->value) {
        previous->next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        next = current->next;
      }
      previous = current;
      current = next;
    }
    head = previous;
  }

  void sort(bool (*comp)(const T &, const T &)) {
    std::shared_ptr<node<T>> current = head;
    std::shared_ptr<node<T>> previous = nullptr;
    std::shared_ptr<node<T>> next = nullptr;
    while (current != nullptr) {
      next = current->next;
      while (previous != nullptr && comp(previous->value, current->value)) {
        previous->next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        next = current->next;
      }
      previous = current;
      current = next;
    }
    head = previous;
  }

  // For each
  template <typename F>
  void forEach(F f) {
    std::shared_ptr<node<T>> current = head;
    while (current != nullptr) {
      f(current->value);
      current = current->next;
    }
  }

};

#endif