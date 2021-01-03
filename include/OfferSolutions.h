//
// Created by LaiChao on 2020/11/5.
//

#ifndef THEROADTOADVANCEMENT_OFFERSOLUTIONS_H
#define THEROADTOADVANCEMENT_OFFERSOLUTIONS_H
/// ============== 剑指Offer题目 ==============

#include "./__OSJudge.h"
#include "./DataStructure/Tree.h"
#include "./DataStructure/List.h"
#include <vector>
#include <string>

using namespace std;


class OfferSolutions {
public:
    static int findRepeatNumber(vector<int> &nums);         // 剑指 Offer 03. 数组中重复的数字
    static bool findNumberIn2DArray(vector<vector<int>> &matrix, int target);       // 剑指 Offer 04. 二维数组中的查找
    static string replaceSpace(string s);           // 剑指 Offer 05. 替换空格
    static vector<int> reversePrint(ListNode *head);        // 剑指 Offer 06. 从尾到头打印链表
    static TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder);        // *** 剑指 Offer 07. 重建二叉树 ***
    static int fib(int n);          // 剑指 Offer 10- I. 斐波那契数列
    static int numWays(int n);      // 剑指 Offer 10- II. 青蛙跳台阶问题
    static int minArray(vector<int> &numbers);      // 剑指 Offer 11. 旋转数组的最小数字
    static bool exist(vector<vector<char>> &board, string word);        // *** 剑指 Offer 12. 矩阵中的路径 ***
    static int movingCount(int m, int n, int k);        // *** 剑指 Offer 13. 机器人的运动范围 ***
    static int movingCount_bfs(int m, int n, int k);    // *** 剑指 Offer 13. 机器人的运动范围(广度优先方法) ***
    static int cuttingRope(int n);      // *** 剑指 Offer 14- I. 剪绳子 ***
    static int cuttingRope02(int n);    // 剑指 Offer 14- II. 剪绳子 II
    static int hammingWeight(uint32_t n);       // 剑指 Offer 15. 二进制中1的个数
    static double myPow(double x, int n);       // 剑指 Offer 16. 数值的整数次方
    static vector<int> printNumbers(int n);     // 剑指 Offer 17. 打印从1到最大的n位数
    static ListNode *deleteNode(ListNode *head, int val);       // 剑指 Offer 18. 删除链表的节点
    static bool isMatch(string s, string p);    // *** 剑指 Offer 19. 正则表达式匹配 ***
    static bool isNumber(string s);     // 剑指 Offer 20. 表示数值的字符串
    static vector<int> exchange(vector<int> &nums);     // 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
    static ListNode *getKthFromEnd(ListNode *head, int k);      // 剑指 Offer 22. 链表中倒数第k个节点
    static ListNode *reverseList(ListNode *head);       // *** 剑指 Offer 24. 反转链表 ***
    static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2); // 剑指 Offer 25. 合并两个排序的链表
    static bool isSubStructure(TreeNode *A, TreeNode *B);       // 剑指 Offer 26. 树的子结构
    static TreeNode *mirrorTree(TreeNode *root);        // *** 剑指 Offer 27. 二叉树的镜像 ***
    static TreeNode *mirrorTree02(TreeNode *root);      // *** 剑指 Offer 27. 二叉树的镜像(非递归) ***
    static bool isSymmetric(TreeNode *root);            // *** 剑指 Offer 28. 对称的二叉树 ***
    static vector<int> spiralOrder(vector<vector<int>> &matrix);    // 剑指 Offer 29. 顺时针打印矩阵
};

#endif //THEROADTOADVANCEMENT_OFFERSOLUTIONS_H
