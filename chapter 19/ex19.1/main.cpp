#include <cstdlib>
#include <stdexcept>

void *operator new(size_t size) {
  if (void *mem = malloc(size))
    return mem;
  else
    throw std::bad_alloc();
}

void operator delete (void *mem) noexcept {
  free(mem);
}

int main() {}
