//
// Created by Bin Zhang on 19/6/22.
//

#ifndef EX13_28_TREENODE_H
#define EX13_28_TREENODE_H

#include <string>

class TreeNode {
public:
  TreeNode() : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}
  TreeNode(const TreeNode&);
  TreeNode& operator=(const TreeNode&);
  ~TreeNode();
private:
  std::string value;
  int *count;
  TreeNode *left;
  TreeNode *right;
};

class BinStrTree {
  BinStrTree() : root(new TreeNode()) {}
  BinStrTree(const BinStrTree& bst) : root(new TreeNode(*bst.root)) {}
  BinStrTree& operator=(const BinStrTree&);
  ~BinStrTree() { delete root; }
private:
  TreeNode *root;
};


#endif //EX13_28_TREENODE_H
