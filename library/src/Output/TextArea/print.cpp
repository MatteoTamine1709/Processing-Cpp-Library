#include "Engine.hpp"

void Engine::_print() {}

template<typename T>
void Engine::_print(T value) {
  std::cout << value;
}

template<typename T, typename... Args>
void Engine::_print(T value, Args... args) {
  std::cout << value;
  _print(args...);
}