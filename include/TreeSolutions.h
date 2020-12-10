//
// Created by LaiChao on 2020/11/5.
//

#ifndef THEROADTOADVANCEMENT_TREESOLUTIONS_H
#define THEROADTOADVANCEMENT_TREESOLUTIONS_H

#include "./__OSJudge.h"
#include "./DataStructure/Tree.h"
#include <vector>

using namespace std;

class TreeSolution {
public:
    static TreeNode *newNode(int data);                         // 二叉搜索树创建结点
    static TreeNode *insertNode(TreeNode *root, int data);      // 二叉搜索树插入结点
    static TreeNode *insertNode2(TreeNode *root, int data);     // 二叉搜索树插入节点(非递归)
    static int sizeTreeNode(TreeNode *root);                    // 二叉树结点数目（不需要是二叉搜索树）
    static int maxDepth(TreeNode *root);                        // 二叉树深度（根结点到最远叶结点距离，空树深度为0）
    static int minValue(TreeNode *root);                        // 二叉搜索树最小值（最大值类似，查询右子树即可）
    static bool findData(TreeNode *root, int target);           // 查找二叉搜索树中是否存在某个值
    static bool isBSTree(TreeNode *root);                       // 判定一棵二叉树是否是二叉搜索树
    static bool hasPathSum(TreeNode *root, int sum);            // 判定二叉树是否存在和为给定值的路径
    static void mirrorTree(TreeNode *root);                     // 二叉树镜像
    static bool sameTree(TreeNode *a, TreeNode *b);             // 判定两棵二叉树结构是否相同
    static int countBSTree(int numKeys);                        // 二叉搜索树的数目

    static int deepestLeavesSum(TreeNode *root);                // 1302. 层数最深叶子节点的和
    static int sumEvenGrandparent(TreeNode *root);              // 1315. 祖父节点值为偶数的节点和

    ////// 二叉树的非递归遍历
    static vector<int> preorderTraversal(TreeNode *root);       // 前序遍历（非递归）
    static vector<int> inorderTraversal(TreeNode *root);        // 中序遍历（非递归）
    static vector<int> postorderTraversal(TreeNode *root);      // 后序遍历（非递归）
    static vector<int> levelTraversal(TreeNode *root);          // 层次遍历（非递归）
};


#endif //THEROADTOADVANCEMENT_TREESOLUTIONS_H
