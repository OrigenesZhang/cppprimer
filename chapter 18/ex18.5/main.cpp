#include <iostream>
#include <stdexcept>

int main() {
  try {
    // do sth
  } catch (std::length_error &e) {
    std::cout << e.what() << std::endl;
    abort();
  } catch (std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
    abort();
  } catch (std::out_of_range &e) {
    std::cout << e.what() << std::endl;
    abort();
  } catch (std::domain_error &e) {
    std::cout << e.what() << std::endl;
    abort();
  } catch (std::range_error &e) {
    std::cout << e.what() << std::endl;
    abort();
  } catch (std::underflow_error &e) {
    std::cout << e.what() << std::endl;
    abort();
  } catch (std::overflow_error &e) {
    std::cout << e.what() << std::endl;
    abort();
  } catch (std::logic_error &e) {
    std::cout << e.what() << std::endl;
    abort();
  } catch (std::runtime_error &e) {
    std::cout << e.what() << std::endl;
    abort();
  } catch (std::bad_cast &e) {
    std::cout << e.what() << std::endl;
    abort();
  } catch  (std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
    abort();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    abort();
  }
}
