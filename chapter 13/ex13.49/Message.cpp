//
// Created by Bin Zhang on 26/6/22.
//

#include "Message.h"

Message::Message(const Message &m) : contents(m.contents), folders(m.folders) {
  add_to_Folders(m);
}

Message &Message::operator=(const Message &rhs) {
  remove_from_Folders();
  contents = rhs.contents;
  folders = rhs.folders;
  add_to_Folders(rhs);
  return *this;
}

Message::~Message() {
  remove_from_Folders();
}

void Message::save(Folder &f) {
  folders.insert(&f);
  f.addMsg(this);
}

void Message::remove(Folder &f) {
  folders.erase(&f);
  f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
  for (auto f : m.folders)
    f->addMsg(this);
}

void Message::remove_from_Folders() {
  for (auto f : folders)
    f->remMsg(this);
}

void swap(Message &lhs, Message &rhs) {
  using std::swap;
  lhs.remove_from_Folders();
  rhs.remove_from_Folders();
  swap(lhs.contents, rhs.contents);
  swap(lhs.folders, rhs.folders);
  lhs.add_to_Folders(lhs);
  rhs.add_to_Folders(rhs);
}

Message::Message(Message &&m) : contents(std::move(m.contents)) {
  move_Folders(&m);
}

Message &Message::operator=(Message &&rhs) {
  if (this != &rhs) {
    remove_from_Folders();
    contents = std::move(rhs.contents);
    move_Folders(&rhs);
  }
  return *this;
}

void Message::move_Folders(Message *m) {
  folders = std::move(m->folders);
  for (auto f : folders) {
    f->remMsg(m);
    f->addMsg(this);
  }
  m->folders.clear();
}

Folder::Folder(const Folder &f) : msgs(f.msgs) {
  add_to_Message(f);
}

Folder &Folder::operator=(const Folder &rhs) {
  remove_from_Message();
  msgs = rhs.msgs;
  add_to_Message(rhs);
  return *this;
}

Folder::~Folder() {
  remove_from_Message();
}

void Folder::add_to_Message(const Folder &f) {
  for (auto m : f.msgs)
    m->addFldr(this);
}

void Folder::remove_from_Message() {
  for (auto m : msgs)
    m->remFldr(this);
}

void swap(Folder &lhs, Folder &rhs) {
  using std::swap;
  lhs.remove_from_Message();
  rhs.remove_from_Message();
  swap(lhs.msgs, rhs.msgs);
  lhs.add_to_Message(lhs);
  rhs.add_to_Message(rhs);
}