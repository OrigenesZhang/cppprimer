#include <iostream>
#include <string>
#include <memory>
#include <utility>

struct connection {
  std::string ip;
  int port;

  connection(std::string ip, int port) : ip(std::move(ip)), port(port) {}
};

struct destination {
  std::string ip;
  int port;

  destination(std::string ip, int port) : ip(std::move(ip)), port(port) {}
};

connection connect(destination *dest) {
  std::shared_ptr<connection> conn_ptr(new connection(dest->ip, dest->port));
  std::cout << "Creating Connection " << conn_ptr.use_count() << std::endl;
  return *conn_ptr;
}

void disconnect(const connection& conn) {
  std::cout << "Disconnecting " << conn.ip << ":" << conn.port << std::endl;
}

void end_connection(connection *conn) {
  disconnect(*conn);
}

void f(destination &d) {
  connection c = connect(&d);
  std::shared_ptr<connection> p(&c, end_connection);
  std::cout << "Connected now: " << p.use_count() << std::endl;
}

int main() {
  destination dest("127.0.0.1", 6379);
  f(dest);
}
