//
// Created by Bin Zhang on 19/6/22.
//

#include "TreeNode.h"

TreeNode::TreeNode(const TreeNode &tn) : value(tn.value), count(tn.count), left(tn.left), right(tn.right) {
  (*count)++;
}

TreeNode &TreeNode::operator=(const TreeNode &rhs) {
  ++*rhs.count;
  if (--*count == 0) {
    delete left;
    delete right;
    delete count;
  }
  value = rhs.value;
  count = rhs.count;
  left = rhs.left;
  right = rhs.right;
  return *this;
}

TreeNode::~TreeNode() {
  if (--*count == 0) {
    delete left;
    delete right;
    delete count;
  }
}

BinStrTree &BinStrTree::operator=(const BinStrTree &rhs) {
  auto new_root = new TreeNode(*rhs.root);
  delete root;
  root = new_root;
  return *this;
}
