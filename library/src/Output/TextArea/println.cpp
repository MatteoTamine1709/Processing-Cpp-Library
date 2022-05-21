#include "Engine.hpp"

void Engine::_println() {
  std::cout << std::endl;
}

template<typename T>
void Engine::_println(T value) {
  std::cout << value << std::endl;
}

template<typename T, typename... Args>
void Engine::_println(T value, Args... args) {
  std::cout << value;
  _println(args...);
}