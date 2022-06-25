//
// Created by Bin Zhang on 26/6/22.
//

#ifndef EX13_49_MESSAGE_H
#define EX13_49_MESSAGE_H


#include <string>
#include <utility>
#include <set>

class Folder;

class Message {
  friend class Folder;
  friend void swap(Message&, Message&);
public:
  explicit Message(std::string str = "") : contents(std::move(str)) {}
  Message(const Message&);
  Message &operator=(const Message&);
  Message(Message&&);
  Message &operator=(Message&&);
  ~Message();
  void save(Folder&);
  void remove(Folder&);
private:
  std::string contents;
  std::set<Folder*> folders;
  void add_to_Folders(const Message&);
  void remove_from_Folders();
  void move_Folders(Message*);
  void addFldr(Folder *f) { folders.insert(f); }
  void remFldr(Folder *f) { folders.erase(f); }
};

void swap(Message &, Message &);

class Folder {
  friend class Message;
  friend void swap(Folder&, Folder&);
public:
  Folder() = default;
  Folder(const Folder&);
  Folder &operator=(const Folder&);
  ~Folder();
private:
  std::set<Message*> msgs;
  void add_to_Message(const Folder&);
  void remove_from_Message();
  void addMsg(Message *m) { msgs.insert(m); }
  void remMsg(Message *m) { msgs.erase(m); }
};

void swap(Folder &, Folder &);


#endif //EX13_49_MESSAGE_H
