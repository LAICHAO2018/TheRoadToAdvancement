//
// Created by LaiChao on 2020/11/15.
//

#ifndef THEROADTOADVANCEMENT_MODULESOLUTIONS_H
#define THEROADTOADVANCEMENT_MODULESOLUTIONS_H

#include "./__OSJudge.h"
#include ".//DataStructure//Tree.h"
#include ".//DataStructure//List.h"
#include ".//LeetCodeDefinition.h"
#include <vector>
#include <string>

using namespace std;

class EasySolutions {
public:
    static int cakeNumber(int n);                                       // NC-12
    static long long IncreasingArray(vector<int> &array);               // NC-31
    static vector<int> runningSum(vector<int> &nums);                   // Leetcode-easy 1480
    static int numIdenticalPairs(vector<int> &nums);                    // Leetcode-easy 1512
    static int maxDepth(TreeNode *root);                                // Leetcode-easy 104
    static vector<int> shuffle(vector<int> &nums, int n);               // Leetcode-easy 1470
    static int xorOperation(int n, int start);                          // Leetcode-easy 1486
    static vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies);    // Leetcode-easy 1431
    static string restoreString(string s, vector<int> &indices);        // Leetcode-easy 1528
    static int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime);    // Leetcode-easy 1450
    static int maxProduct(vector<int> &nums);                           // Leetcode-easy 1464
    static string destCity(vector<vector<string>> &paths);              // Leetcode-easy 1436
    static bool canMakeArithmeticProgression(vector<int> &arr);         // Leetcode-easy 1502
    static bool canBeEqual(vector<int> &target, vector<int> &arr);      // Leetcode-easy 1460
    static vector<int> finalPrices(vector<int> &prices);                // Leetcode-easy 1475
    static string generateTheString(int n);                             // Leetcode-easy 1374
    static int findMagicIndex(vector<int> &nums);

    static int numTeams(vector<int> &rating);

    static TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target);

    static ListNode *removeDuplicateNodes(ListNode *head);

    static int numWaterBottles(int numBottles, int numExchange);

    static vector<int> minSubsequence(vector<int> &nums);

    static int islandPerimeter(vector<vector<int>> &grid);

    static int repeatedNTimes(vector<int> &A);

    static vector<string> letterCasePermutation(string S);

    static string addStrings(string num1, string num2);                    //415. 字符串相加
    static int countGoodTriplets(vector<int> &arr, int a, int b, int c);   //1534. 统计好三元组
    static vector<int> numberOfLines(vector<int> &widths, string S);       //806. 写字符串需要的行数
    static vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2);        //496. 下一个更大元素 I
    static int sumRootToLeaf(TreeNode *root);                              //1022. 从根到叶的二进制数之和
    static vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor);    //733. 图像渲染
    static bool isBalanced(TreeNode *root);                                // 110. 平衡二叉树
    static vector<vector<int>> subsetsWithDup(vector<int> &nums);         // 90. 子集 II
    static double average(vector<int> &salary);                            // 1491. 去掉最低工资和最高工资后的工资平均值
    static int calPoints(vector<string> &ops);                            // 682. 棒球比赛
    static int removePalindromeSub(string s);                              // 1332. 删除回文子序列
    static vector<string> buildArray(vector<int> &target, int n);         // 1441. 用栈操作构建数组
    static string getPermutation(int n, int k);                            // 60. 第k个排列
    static bool threeConsecutiveOdds(vector<int> &arr);        // 1550. 存在连续三个奇数的数组
    static int isPrefixOfWord(string sentence, string searchWord);        // 1455. 检查单词是否为句中其他单词的前缀
    static int numUniqueEmails(vector<string> &emails);       // 929. 独特的电子邮件地址
    static vector<string> findOcurrences(string text, string first, string second);    // 1078. Bigram 分词
    static uint32_t reverseBits(uint32_t n);           // 190. 颠倒二进制位
    static int calculate(string s);                    // LCP 17. 速算机器人
    static TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2);        // 617. 合并二叉树
    static vector<int> findMode(TreeNode *root);                    // 501. 二叉搜索树中的众数
    static int numSpecial(vector<vector<int>> &mat);                // 1582. 二进制矩阵中的特殊位置
    static vector<int> fraction(vector<int> &cont);                 // LCP 02. 分式化简
    static Node *connect(Node *root);                  // 117. 填充每个节点的下一个右侧节点指针 II
    static vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0);    // 1030. 距离顺序排列矩阵单元格
    static TreeNode *insertIntoBST(TreeNode *root, int val);        // 701. 二叉搜索树中的插入操作
    static vector<string> fizzBuzz(int n);              // 412. Fizz Buzz
    static int maxNumberOfBalloons(string text);        // 1189. “气球” 的最大数量
    static vector<string> uncommonFromSentences(string A, string B);    // 884. 两句话中的不常见单词
    static bool leafSimilar(TreeNode *root1, TreeNode *root2);          // 872. 叶子相似的树
    static int countBinarySubstrings(string s);         // 696. 计数二进制子串
    static double largestTriangleArea(vector<vector<int>> &points);     // 812. 最大三角形面积
    static int lengthOfLastWord(string s);              // 58. 最后一个单词的长度
    static bool isSameTree(TreeNode *p, TreeNode *q);   // 100. 相同的树
    static bool isSameTree2(TreeNode *p, TreeNode *q);  // 100. 相同的树(非递归方法)
    static bool detectCapitalUse(string word);          // 520. 检测大写字母520. 检测大写字母
    static int minOperations(vector<string> &logs);     // 1598. 文件夹操作日志搜集器
    static string reformatDate(string date);            // 1507. 转变日期格式
    static int maxLengthBetweenEqualCharacters(string s);           // 1624. 两个相同字符之间的最长子字符串
    static int lastStoneWeight(vector<int> &stones);    // 1046. 最后一块石头的重量
    static int binaryGap(int n);                        // 868. 二进制间距
    static int numWays(int n, vector<vector<int>> &relation, int k);    // LCP 07. 传递信息
    static bool hasAlternatingBits(int n);              // 693. 交替位二进制数
    static string dayOfTheWeek(int day, int month, int year);           // 1185. 一周中的第几天
    static vector<string> stringMatching(vector<string> &words);        // 1408. 数组中的字符串匹配
    static int rotatedDigits(int N);                    // 788. 旋转数字
    static string toGoatLatin(string S);                // 824. 山羊拉丁文
    static string thousandSeparator(int n);             // 1556. 千位分隔数
    static vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries);       // 985. 查询后的偶数和
    static bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2);             // 1662. 检查两个字符串数组是否相等
    static int specialArray(vector<int> &nums);         // 1608. 特殊数组的特征值
    static char firstUniqChar(string s);                // 剑指 Offer 50. 第一个只出现一次的字符
    static int maxSubArray(vector<int> &nums);          // 剑指 Offer 42. 连续子数组的最大和
    static string shortestCompletingWord(string licensePlate, vector<string> &words);           // 748. 最短补全词
    static bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces);                    // 1640. 能否连接形成数组
    static double trimMean(vector<int> &arr);           // 1619. 删除某些元素后的数组均值
    static vector<int> decrypt(vector<int> &code, int k);               // 1652. 拆炸弹
    static int bitwiseComplement(int N);                // 1009. 十进制整数的反码
    static int getImportance(vector<Employee *> employees, int id);     // 690. 员工的重要性
    static vector<string> reorderLogFiles(vector<string> &logs);        // 937. 重新排列日志文件
    static string replaceSpaces(string S, int length);  // 面试题 01.03. URL化
    static int add(int a, int b);                       // 面试题 17.01. 不用加号的加法
    static bool isSymmetric(TreeNode *root);            // 剑指 Offer 28. 对称的二叉树
    static int distanceBetweenBusStops(vector<int> &distance, int start, int destination);      // 1184. 公交站间的距离
    static int maxPower(string s);                      // 1446. 连续字符
    static int maxDepth(string s);                      // 1614. 括号的最大嵌套深度
    static int sumOddLengthSubarrays(vector<int> &arr);                 // 1588. 所有奇数长度子数组的和
    static int numberOfMatches(int n);                  // 1688. 比赛中的配对次数
    static string reformatNumber(string number);        // 1694. 重新格式化电话号码
    static bool halvesAreAlike(string s);               // 5637. 判断字符串的两半是否相似
    static bool kLengthApart(vector<int> &nums, int k);                 // 1437. 是否所有 1 都至少相隔 k 个元素
    static bool findTarget(TreeNode *root, int k);      // 653. 两数之和 IV - 输入 BST
    static string mergeAlternately(string word1, string word2);         // 1768. 交替合并字符串
    static vector<int> intersection(vector<int> &nums1, vector<int> &nums2);                    // 349. 两个数组的交集
    static bool isHappy(int n);                         // 202. 快乐数
    static vector<int> twoSum(vector<int> &nums, int target);           // 1. 两数之和
    static bool isIsomorphic(string s, string t);       // 205. 同构字符串
    static vector<string> findRestaurant(vector<string> &list1, vector<string> &list2);         // 599. 两个列表的最小索引总和
    static int firstUniqChar01(string s);               // 387. 字符串中的第一个唯一字符
    static int nearestValidPoint(int x, int y, vector<vector<int>> &points);    // 1779. 找到最近的有相同 X 或 Y 坐标的点
    static bool canConstruct(string ransomNote, string magazine);       // 383. 赎金信
    static int sumBase(int n, int k);                   // 1837. K 进制表示下的各位数字总和
    static string reverseStr(string s, int k);          // 541. 反转字符串 II
    static vector<int> mostVisited(int n, vector<int> &rounds);         // 1560. 圆形赛道上经过次数最多的扇区
    static string reverseOnlyLetters(string s);         // 917. 仅仅反转字母
    static int search(vector<int> &nums, int target);   // 704. 二分查找(模板)
    static string tree2str(TreeNode *root);             // 606. 根据二叉树创建字符串
    static vector<string> findRelativeRanks(vector<int> &score);        // 506. 相对名次
    static int dayOfYear(string date);                  // 1154. 一年中的第几天
    static bool isAlienSorted(vector<string> &words, string order);     // 953. 验证外星语词典
    static bool isFlipedString(string s1, string s2);   // 面试题 01.09. 字符串轮转
    static bool canPermutePalindrome(string s);         // 面试题 01.04. 回文排列
    static int minMoves(vector<int> &nums);             // 453. 最小操作次数使数组元素相等
    static int findString(vector<string> &words, string s);             // 面试题 10.05. 稀疏数组搜索
    static vector<int> constructRectangle(int area);    // 492. 构造矩形
    static int maxScore(string s);          // 1422. 分割字符串的最大得分
    static bool isPathCrossing(string path);            // 1496. 判断路径是否相交
    static int largestSumAfterKNegations(vector<int> &nums, int k);     // 1005. K 次取反后最大化的数组和
};

class MeduimSolutions {
public:
    static int minOperations(int n);                    // 1551. 使数组中所有元素相等的最小操作数
    static int maxCoins(vector<int> &piles);            // 1561. 你可以获得的最大硬币数目 *****
    static vector<int> processQueries(vector<int> &queries, int m);         // 1409. 查询带键的排列
    static vector<int> deckRevealedIncreasing(vector<int> &deck);           // 950. 按递增顺序显示卡牌
    static int matrixScore(vector<vector<int>> &A);     // 861. 翻转矩阵后的得分 *****
    static int countBattleships(vector<vector<char>> &board);               // 419. 甲板上的战舰
    static int numTilePossibilities(string tiles);      // 1079. 活字印刷  *****  全排序（穷举）(=== 78. 子集 ===)
    static vector<int> lexicalOrder(int n);             // 386. 字典序排数
    static vector<vector<int>> combinationSum3(int k, int n);               // 216. 组合总和 III
    static bool exist(vector<vector<char>> &board, string word);            // 79. 单词搜索
    static vector<vector<int>> combinationSum(vector<int> &candidates, int target);         // 39. 组合总和
    static vector<vector<int>> combinationSum2(vector<int> &candidates, int target);        // 40. 组合总和 II
    static int maximalSquare(vector<vector<char>> &matrix);         // 221. 最大正方形
    static string longestPalindrome(string s);          // 5. 最长回文子串
    static string convert(string s, int numRows);       // 6. Z 字形变换
    static bool isValidSudoku(vector<vector<char>> &board);         // 36. 有效的数独
    static bool isValidBST(TreeNode *root);             // 98. 验证二叉搜索
    static int maximumUniqueSubarray(vector<int> &nums);            // 1695. 删除子数组的最大得分
    static double myPow(double x, int n);               // 50. Pow(x, n) ****
    static int findKthLargest(vector<int> &nums, int k);            // 215. 数组中的第K个最大元素
//    static vector<int> topKFrequent(vector<int> &nums, int k);      // 347. 前 K 个高频元素
};

#endif //THEROADTOADVANCEMENT_MODULESOLUTIONS_H
