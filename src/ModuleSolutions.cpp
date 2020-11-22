//
// Created by LaiChao on 2020/11/15.
//

#include "..//include//ModuleSolutions.h"
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <set>
#include <unordered_map>
#include <cmath>

/// ================================== GLOBAL VAR ==================================

int totalSum = -2;
TreeNode *pre;
int titleANS = 0;

///// ================================== HELP FUNC ==================================

void subsetBackTracking(vector<int> &nums, vector<vector<int>> &res, vector<int> &subseq, int startIndex) {
    res.push_back(subseq);
    for (int i = 0; i < nums.size(); i++) {
        if (i > startIndex && nums[i] == nums[i - 1]) {
            continue;
        }
        subseq.push_back(nums[i]);
        subsetBackTracking(nums, res, subseq, i + 1);
        subseq.pop_back();
    }
}

void dfs_sumRootToLeaf(TreeNode *node, int num) {
    if (node == nullptr) {
        return;
    }
    num = (num << 1) + node->val;
    if (node->left == nullptr && node->right == nullptr) {
        totalSum += num;
        return;
    }
    dfs_sumRootToLeaf(node->left, num);
    dfs_sumRootToLeaf(node->right, num);
}

int treeHeight(TreeNode *node) {
    // 求二叉树的高度的递归函数
    if (node == nullptr) {
        return 0;
    }
    return max(treeHeight(node->left), treeHeight(node->right)) + 1;
}

bool checkNumber(vector<vector<int>> &mat, int x, int y) {
    int r = mat.size(), c = mat[0].size();
    for (int i = 0; i < r; i++) {
        if (i != x && mat[i][y] == 1) {
            return false;
        }
    }
    for (int j = 0; j < c; j++) {
        if (j != y && mat[x][j] == 1) {
            return false;
        }
    }
    return true;
}

void traverseTree(TreeNode *root, int &currCount, int &maxCount, vector<int> &nums) {
    if (root == nullptr) {
        return;
    }
    traverseTree(root->left, currCount, maxCount, nums);
    if (pre == nullptr) { // 第一个节点
        currCount = 1;
    } else if (pre->val == root->val) { // 与前一个节点数值相同
        currCount++;
    } else { // 与前一个节点数值不同
        currCount = 1;
    }
    pre = root; // 更新上一个节点

    if (currCount == maxCount) { // 如果和最大值相同，放进result中
        nums.push_back(root->val);
    }

    if (currCount > maxCount) { // 如果计数大于最大值
        maxCount = currCount;
        nums.clear();     // 很关键的一步，不要忘记清空result，之前result里的元素都失效了
        nums.push_back(root->val);
    }
    traverseTree(root->right, currCount, maxCount, nums);
}

void splitStr(string &s, vector<string> &strs, char flag = ' ') {
    strs.clear();
    istringstream ss(s);
    string tmp;
    while (getline(ss, tmp, flag)) {
        strs.push_back(tmp);
    }
}

void inorderTraTree(TreeNode *&root, vector<int> &vec) {
    if (root == nullptr) {
        return;
    }
    inorderTraTree(root->left, vec);
    if (root->left == nullptr && root->right == nullptr) {
        vec.push_back(root->val);
    }
    inorderTraTree(root->right, vec);
}

void titlePossibilitiesDFS(string &str, vector<int> &visit) {
    for (int i = 0; i < str.size(); i++) {
        if ((i > 0) && (str[i] == str[i - 1]) && (visit[i - 1] == 0)) {
            continue;
        }
        if (visit[i] == 0) {
            visit[i] = 1;
            titleANS++;
            titlePossibilitiesDFS(str, visit);
            visit[i] = 0;
        }
    }
}

bool isUpChar(char c) {
    return c >= 'A' && c <= 'Z';
}

///// ================================== CLASS FUNC ==================================

int EasySolutions::cakeNumber(int n) {
    int result = 1;    /// 最后剩下的一个
    while (--n) {
        result = 3 * (result + 1) / 2;
    }
    return result;
}

long long EasySolutions::IncreasingArray(vector<int> &array) {

    return 0;
}

vector<int> EasySolutions::runningSum(vector<int> &nums) {
    if (nums.empty()) {
        return {};
    }
    vector<int> result;
    int currSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        currSum += nums[i];
        result.push_back(currSum);
    }
    return result;
}

int EasySolutions::numIdenticalPairs(vector<int> &nums) {
    if (nums.size() < 2) {
        return 0;
    }
    int result = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] == nums[j]) {
                result++;
            }
        }
    }
    return result;
}

int EasySolutions::maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int result = 0;
    queue<TreeNode *> qNodes;
    qNodes.push(root);
    while (!qNodes.empty()) {
        int currSize = qNodes.size();
        for (int i = 0; i < currSize; i++) {
            TreeNode *tmpNode = qNodes.front();
            qNodes.pop();
            if (tmpNode->left != nullptr) {
                qNodes.push(tmpNode->left);
            }
            if (tmpNode->right != nullptr) {
                qNodes.push(tmpNode->right);
            }
        }
        result++;
    }
    return result;
}

vector<int> EasySolutions::shuffle(vector<int> &nums, int n) {
    if (nums.empty()) {
        return {};
    }
    vector<int> result;
    int prePos = 0, behPos = n;
    while (prePos < n && behPos < nums.size()) {
        result.push_back(nums[prePos]);
        result.push_back(nums[behPos]);
        prePos++, behPos++;
    }
    return result;
}

int EasySolutions::xorOperation(int n, int start) {
    vector<int> nums;
    int i = 0;
    while (i < n) {
        nums.push_back(start + 2 * i);
        i++;
    }
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
        result ^= nums[i];
    }
    return result;
}

vector<bool> EasySolutions::kidsWithCandies(vector<int> &candies, int extraCandies) {
    if (candies.size() < 2) {
        return {true};
    }
    int maxNumber = *(max_element(candies.begin(), candies.end()));
    vector<bool> result;
    for (int i = 0; i < candies.size(); i++) {
        int currNumber = candies[i];
        if (currNumber + extraCandies >= maxNumber) {
            result.push_back(true);
        } else {
            result.push_back(false);
        }
    }
    return result;
}

string EasySolutions::restoreString(string s, vector<int> &indices) {
    if (s.empty()) {
        return {};
    }
    if (indices.empty()) {
        return s;
    }
    string sResult(s.length(), 'a');
    for (int i = 0; i < s.length(); i++) {
        int index = indices[i];
        sResult[index] = s[i];
    }
    return sResult;
}

int EasySolutions::busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
    if (startTime.size() != endTime.size()) {
        return 0;
    }
    int result = 0;
    for (int i = 0; i < startTime.size(); i++) {
        if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
            result++;
        }
    }
    return result;
}

int EasySolutions::maxProduct(vector<int> &nums) {
    if (nums.size() < 2) {
        return 0;
    }
    int maxResult = -999999;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            int currResult = (nums[i] - 1) * (nums[j] - 1);
            maxResult = max(maxResult, currResult);
        }
    }
    return maxResult;
}

string EasySolutions::destCity(vector<vector<string>> &paths) {
    if (paths.empty()) {
        return {};
    }
    string result;
    vector<string> beginCity, endCity;
    for (auto city2city : paths) {
        beginCity.push_back(city2city[0]);
        endCity.push_back(city2city[1]);
    }
    /// 只有可能存在于endCity中，所以只要找到在beginCity中没有出现的城市即可
    for (int i = 0; i < endCity.size(); i++) {
        if (find(beginCity.begin(), beginCity.end(), endCity[i]) == beginCity.end()) {
            return endCity[i];
        }
    }
    return {};
}

bool EasySolutions::canMakeArithmeticProgression(vector<int> &arr) {
    if (arr.empty()) {
        return false;
    }
    sort(arr.begin(), arr.end(), [](int a, int b) { return a < b; });
    int subNumber = arr[1] - arr[0];
    for (int i = 1; i < arr.size() - 1; i++) {
        int currSubNumber = arr[i + 1] - arr[i];
        if (currSubNumber != subNumber) {
            return false;
        }
    }
    return true;
}

bool EasySolutions::canBeEqual(vector<int> &target, vector<int> &arr) {
    sort(target.begin(), target.end());
    sort(arr.begin(), arr.end());
    return target == arr;
}

vector<int> EasySolutions::finalPrices(vector<int> &prices) {
    if (prices.size() < 2) {
        return prices;
    }
    vector<int> afterDiscount;
    for (int i = 0; i < prices.size(); i++) {
        int currPrice = prices[i];
        int index = i + 1;
        while (index < prices.size()) {
            if (prices[index] <= currPrice) {
                break;
            } else {
                index++;
            }
        }
        if (index < prices.size()) {
            currPrice -= prices[index];
        }
        afterDiscount.push_back(currPrice);
    }
    return afterDiscount;
}

int EasySolutions::findMagicIndex(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == i) {
            return i;
        }
    }
    return -1;
}

int EasySolutions::numTeams(vector<int> &rating) {
    if (rating.size() < 3) {
        return 0;
    }
    int result_count = 0;
    for (int i = 0; i < rating.size(); i++) {
        int leftLess = 0, leftMore = 0, rightLess = 0, rightMore = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (rating[j] < rating[i]) {
                leftLess++;
            } else {
                leftMore++;
            }
        }
        for (int j = i + 1; j < rating.size(); j++) {
            if (rating[j] < rating[i]) {
                rightLess++;
            } else {
                rightMore++;
            }
        }
        result_count += (leftMore * rightLess);
        result_count += (leftLess * rightMore);
    }
    return result_count;
}

TreeNode *EasySolutions::getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
    if (original == nullptr) {
        return {};
    }
    if (original == target) {
        return cloned;
    }
    if (getTargetCopy(original->left, cloned->left, target)) {
        return getTargetCopy(original->left, cloned->left, target);
    } else {
        return getTargetCopy(original->right, cloned->right, target);
    }
}

ListNode *EasySolutions::removeDuplicateNodes(ListNode *head) {
    if (head == nullptr) {
        return {};
    }
    ListNode *pNode = head, *tNode = head;
    while (pNode != nullptr && pNode->next != nullptr) {
        while (tNode->next != nullptr) {
            if (pNode->val == tNode->next->val) {
                tNode->next = tNode->next->next;
            } else {
                tNode = tNode->next;     /// 未排序链表，可能后面还有重复的节点
            }
        }
        pNode = pNode->next;
        tNode = pNode;
    }
    return head;
}

int EasySolutions::numWaterBottles(int numBottles, int numExchange) {
    if (numBottles < 3) {
        return numBottles;
    }
    int drinkWater = numBottles;  /// 买入的肯定可以喝掉
    int emptyBottles = drinkWater;
    while (emptyBottles >= numExchange) {    //// 还可以换的话，就执行循环
        int exchangeCount = emptyBottles / numExchange;  /// 换的新酒个数
        drinkWater += exchangeCount;
        emptyBottles -= (exchangeCount * numExchange);
        emptyBottles += exchangeCount;
    }
    return drinkWater;
}

vector<int> EasySolutions::minSubsequence(vector<int> &nums) {
    if (nums.empty()) {
        return {};
    }
    vector<int> minSubVector;
    sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    int index = 1;
    minSubVector.push_back(nums[index - 1]);
    while (index < nums.size() + 1) {
        int leftSum = accumulate(nums.begin() + index, nums.end(), 0);  ///
        int vecNumberSum = accumulate(minSubVector.begin(), minSubVector.end(), 0);
        if (vecNumberSum > leftSum) {
            return minSubVector;
        } else {
            index++;
            minSubVector.push_back(nums[index - 1]);
        }
    }
    return {};
}

int EasySolutions::islandPerimeter(vector<vector<int>> &grid) {
    if (grid.empty()) {
        return 0;
    }
    int row = grid.size();
    int col = grid[0].size();
    int result = 0;
    vector<int> dx{0, 0, -1, 1};
    vector<int> dy{-1, 1, 0, 0};
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == 1) {
                int neighborCount = 0;
                for (int k = 0; k < 4; k++) {
                    int move_x = i + dx[k];
                    int move_y = j + dy[k];
                    if (move_x >= 0 && move_x < row && move_y >= 0 && move_y < col && grid[move_x][move_y] == 1) {
                        neighborCount++;
                    }
                }
                result += (4 - neighborCount);
            }
        }
    }
    return result;
}

int EasySolutions::repeatedNTimes(vector<int> &A) {
    if (A.size() < 2) {
        return A[0];
    }
    sort(A.begin(), A.end());
    /// 如果个数为奇数个
    if (A.size() % 2) {
        return A[A.size() / 2];
    }
        /// 如果个数为偶数个
    else {
        int left = A[A.size() / 2 - 1];
        int right = A[A.size() / 2];
        if (left == A[0]) {
            return left;
        } else {
            return right;
        }
    }
}

string EasySolutions::addStrings(string num1, string num2) {
    string str;
    int sum = 0, i = num1.size() - 1, j = num2.size() - 1;
    while (sum != 0 || i >= 0 || j >= 0) {
        if (i >= 0) {
            sum += (num1[i--] - '0');
        }
        if (j >= 0) {
            sum += (num2[j--] - '0');
        }
        str += to_string(sum % 10);
        sum /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}

vector<int> EasySolutions::numberOfLines(vector<int> &widths, string S) {
    if (widths.size() != 26 || S.empty()) {
        return {};
    }
    int lineCounts = 1;
    int leftCounts = 0;
    int currSum = 0;
    for (int i = 0; i < S.length(); i++) {
        currSum += widths[(int) (S[i] - 'a')];
        if (currSum == 100) {
            lineCounts++;
            leftCounts = currSum = 0;
        } else if (currSum > 100) {
            lineCounts++;
            leftCounts = currSum = widths[(int) (S[i] - 'a')];
        } else {
            leftCounts += widths[(int) (S[i] - 'a')];
        }
    }
    return {lineCounts, leftCounts};
}

vector<int> EasySolutions::nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.empty() || nums2.empty()) {
        return {};
    }
    vector<int> result;
    for (int i = 0; i < nums1.size(); i++) {
        int currNumberInNum1 = nums1[i];
        auto posInNum2 = find(nums2.begin(), nums2.end(), currNumberInNum1);
        if (posInNum2 == nums2.end()) {
            result.push_back(-1);
        } else {
            while (posInNum2 != nums2.end()) {
                int currNumberInNum2 = *posInNum2;
                if (currNumberInNum2 > currNumberInNum1) {
                    result.push_back(currNumberInNum2);
                    break;
                }
                posInNum2++;
            }
            if (posInNum2 == nums2.end()) {
                result.push_back(-1);
            }
        }
    }
    return result;
}

int EasySolutions::sumRootToLeaf(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    totalSum = 0;
    dfs_sumRootToLeaf(root, 0);
    return totalSum;
}

int EasySolutions::numWays(int n, vector<vector<int>> &relation, int k) {

    return 0;
}

vector<vector<int>> EasySolutions::floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    vector<int> dx{0, 0, 1, -1};
    vector<int> dy{1, -1, 0, 0};
    int currColor = image[sr][sc];
    if (currColor == newColor) {
        return image;
    }
    int n = image.size(), m = image[0].size();
    queue<pair<int, int>> que;
    que.emplace(sr, sc);
    image[sr][sc] = newColor;
    while (!que.empty()) {
        int x = que.front().first, y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int mx = x + dx[i], my = y + dy[i];
            if (mx >= 0 && mx < n && my >= 0 && my < m && image[mx][my] == currColor) {
                que.emplace(mx, my);
                image[mx][my] = newColor;
            }
        }
    }
    return image;
}

bool EasySolutions::isBalanced(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }
    /// 这里要求左右子树的高度差不超过1，并且左右子树都是平衡树
    // return (__abs(treeHeight(root->left) - treeHeight(root->right)) < 2) && (isBalanced(root->left)) && isBalanced(root->right);
    return false;
}

vector<vector<int>> EasySolutions::subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> subseq;
    subsetBackTracking(nums, res, subseq, 0);
    return res;
}

double EasySolutions::average(vector<int> &salary) {
    double averSalary = 0;
    sort(salary.begin(), salary.end());
    int totalSalary = accumulate(salary.begin(), salary.end(), 0);
    totalSalary -= salary[0];
    totalSalary -= salary.back();
    averSalary = (double) totalSalary / (salary.size() - 2);
    return averSalary;
}

int EasySolutions::calPoints(vector<string> &ops) {
    int getScore = 0;
    stack<int> scoreRecord;
    scoreRecord.push(0);
    scoreRecord.push(0);
    for (int i = 0; i < ops.size(); i++) {
        string curr = ops[i];
        if (curr == "+") {
            if (scoreRecord.size() > 1) {
                int tmpTop = scoreRecord.top();
                scoreRecord.pop();
                int thisAdd = tmpTop + scoreRecord.top();
                scoreRecord.push(tmpTop);
                scoreRecord.push(thisAdd);
                getScore += thisAdd;
            }
        } else if (curr == "D") {
            getScore += (2 * scoreRecord.top());
            scoreRecord.push(2 * scoreRecord.top());
        } else if (curr == "C") {
            getScore -= scoreRecord.top();
            scoreRecord.pop();
        } else {    /// 数字
            int score = stoi(curr);
            scoreRecord.push(score);
            getScore += score;
        }
    }
    return getScore;
}

int EasySolutions::removePalindromeSub(string s) {
    //1、贪心算法解决回文串
    string temp = s;
    reverse(s.begin(), s.end());
    if (s.size() == 0)
        return 0;
    else if (s == temp)
        return 1;
    else
        return 2;
}

vector<string> EasySolutions::buildArray(vector<int> &target, int n) {
    vector<string> resVec;
    int pos = 1;
    for (int currNumber : target) {
        for (; pos <= n; pos++) {
            if (currNumber == pos) {
                resVec.push_back("push");
                break;
            } else {
                resVec.push_back("push");
                resVec.push_back("pop");
            }
        }
    }

    return resVec;
}

string EasySolutions::getPermutation(int n, int k) {
    string s = string("123456789").substr(0, n);
    for (int i = 0; i < k; i++) {
        next_permutation(s.begin(), s.end());
    }
    return s;
}

bool EasySolutions::threeConsecutiveOdds(vector<int> &arr) {
    if (arr.size() < 3) {
        return false;
    }
    int flag = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2) {
            flag++;
        } else {
            flag = 0;
        }
    }
    return flag > 2;
}

int EasySolutions::isPrefixOfWord(string sentence, string searchWord) {
    //int count = 0;
    //vector<string>vWords;
    //string sTemp;
    //for (int i = 0; i < sentence.size(); i++) {
    //	if (sentence[i] != ' ') {
    //		sTemp += sentence[i];
    //	}
    //	else {
    //		if (sTemp != "") {
    //			vWords.push_back(sTemp);
    //			sTemp = "";
    //		}
    //	}
    //}
    //for (string str : vWords) {
    //	int indexA = 0;
    //	if (searchWord.size() > str.size()) {
    //		continue;
    //	}
    //	while (indexA < searchWord.size()) {
    //		if (searchWord[indexA] != str[indexA]) {
    //			break;
    //		}
    //		indexA++;
    //	}
    //	if (indexA == searchWord.size() - 1) {
    //		count++;
    //	}
    //}
    //return count;

    /// 简洁代码
    istringstream ss(sentence);
    string str;
    for (int i = 1; ss >> str; i++) {
        if (str.find(searchWord) == 0) {
            return i;
        }
    }
    return -1;
}

int EasySolutions::numUniqueEmails(vector<string> &emails) {
    set<string> diffEMail;
    for (int i = 0; i < emails.size(); i++) {
        string addrName, Name;
        int pAT = emails[i].find('@');
        addrName = emails[i].substr(pAT);
        int pos = 0;
        string preStr;
        while (pos < emails[i].size() && emails[i][pos] != '@') {
            if (emails[i][pos] == '.') {
                pos++;
                continue;
            } else if (emails[i][pos] == '+') {
                break;
            } else {
                preStr += emails[i][pos];
                pos++;
            }
        }
        Name = (preStr + addrName);
        diffEMail.insert(Name);
    }
    return diffEMail.size();
}

vector<string> EasySolutions::findOcurrences(string text, string first, string second) {
    vector<string> allStr;
    /// 阻断空格的方法
    istringstream words(text);
    string tmp;
    while (words >> tmp) {
        allStr.push_back(tmp);
    }

    vector<string> resVec;
    int flag = 0;
    for (int i = 0; i < allStr.size() - 2; i++) {
        if (allStr[i] == first && allStr[i + 1] == second) {
            resVec.push_back(allStr[i + 2]);
            i += 2;
        }
    }
    return resVec;
}

uint32_t EasySolutions::reverseBits(uint32_t n) {
    uint32_t res = 0, flag = 31;
    while (n != 0) {
        res += (n & 1) << flag;
        n = n >> 1;
        flag -= 1;
    }
    return res;
}

int EasySolutions::calculate(string s) {
    int x = 0, y = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            x = 2 * x + y;
        } else {
            y = 2 * y + x;
        }
    }
    return x + y;
}

TreeNode *EasySolutions::mergeTrees(TreeNode *t1, TreeNode *t2) {
    if (t1 == nullptr) {
        return t2;
    }
    if (t2 == nullptr) {
        return t1;
    }
    queue<TreeNode *> qNodes;
    qNodes.push(t1);
    qNodes.push(t2);
    TreeNode *node1, *node2;
    while (!qNodes.empty()) {
        node1 = qNodes.front();
        qNodes.pop();
        node2 = qNodes.front();
        qNodes.pop();
        node1->val += node2->val;   /// 合并节点
        /// 判断左子树
        if (node1->left || node2->left) {
            if (node1->left == nullptr) {
                node1->left = new TreeNode(0);
            }
            if (node2->left == nullptr) {
                node2->left = new TreeNode(0);
            }
            qNodes.push(node1->left);
            qNodes.push(node2->left);
        }
        /// 判断右子树
        if (node1->right || node2->right) {
            if (node1->right == nullptr) {
                node1->right = new TreeNode(0);
            }
            if (node2->right == nullptr) {
                node2->right = new TreeNode(0);
            }
            qNodes.push(node1->right);
            qNodes.push(node2->right);
        }
    }
    return t1;
}

vector<int> EasySolutions::findMode(TreeNode *root) {
    if (root == nullptr) {
        return {};
    }
    vector<int> res;
    int currCounts = 1;
    int maxCounts = 1;
    traverseTree(root, currCounts, maxCounts, res);
    return res;
}

int EasySolutions::numSpecial(vector<vector<int>> &mat) {
    int res = 0;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            if (mat[i][j] == 1 && checkNumber(mat, i, j)) {
                res++;
            }
        }
    }
    return res;
}

vector<int> EasySolutions::fraction(vector<int> &cont) {
    int hight, low;
    hight = cont[cont.size() - 1];
    low = 1;
    for (int i = cont.size() - 2; i >= 0; i--) {
        swap(hight, low);
        int temp = cont[i] * low;
        hight = temp + hight;
    }
    vector<int> ans(2);
    ans[0] = hight;
    ans[1] = low;
    return ans;
}

Node *EasySolutions::connect(Node *root) {
    if (root == nullptr) {
        return root;
    }
    queue<Node *> qNodes;
    qNodes.push(root);
    while (!qNodes.empty()) {
        int currSize = qNodes.size();
        for (int i = 0; i < currSize; i++) {
            Node *curr = qNodes.front();
            qNodes.pop();
            if (i == currSize - 1) {
                curr->next = nullptr;
            } else {
                curr->next = qNodes.front();
            }
            if (curr->left != nullptr) {
                qNodes.push(curr->left);
            }
            if (curr->right != nullptr) {
                qNodes.push(curr->right);
            }
        }
    }
    return root;
}

vector<vector<int>> EasySolutions::allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<int> dx{-1, 0, 0, 1, -1, -1, 1, 1};
    vector<int> dy{0, -1, 1, 0, -1, 1, -1, 1};
    vector<vector<int>> res;
    queue<pair<int, int>> qCoords;
    qCoords.push(make_pair(r0, c0));
    vector<vector<bool>> flags(R, vector<bool>(C, false));
    while (!qCoords.empty()) {
        int currSize = qCoords.size();
        for (int i = 0; i < currSize; i++) {
            auto curr = qCoords.front();
            qCoords.pop();
            if (!flags[curr.first][curr.second]) {
                res.push_back({curr.first, curr.second});
            }
            flags[curr.first][curr.second] = true;
            for (int j = 0; j < 8; j++) {
                int move_x = curr.first + dx[j];
                int move_y = curr.second + dy[j];
                if (move_x >= 0 && move_x < R && move_y >= 0 && move_y < C && !flags[move_x][move_y]) {
                    qCoords.push(make_pair(move_x, move_y));
                }
            }
        }
    }
    return res;
}

TreeNode *EasySolutions::insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    TreeNode *pos = root;
    while (pos != nullptr) {
        if (pos->val > val) {
            if (pos->left == nullptr) {
                pos->left = new TreeNode(val);
                break;
            } else {
                pos = pos->left;
            }
        } else {
            if (pos->right == nullptr) {
                pos->right = new TreeNode(val);
                break;
            } else {
                pos = pos->right;
            }
        }
    }
    return root;
}

vector<string> EasySolutions::fizzBuzz(int n) {
    vector<string> res;
    for (int i = 1; i <= n; i++) {
        string currStr;
        if (i % 3 == 0 && i % 5 == 0) {
            currStr = "FizzBuzz";
        } else if (i % 3 == 0) {
            currStr == "Fizz";
        } else if (i % 5 == 0) {
            currStr = "Buzz";
        } else {
            currStr = to_string(i);
        }
        res.push_back(currStr);
    }
    return res;
}

int EasySolutions::maxNumberOfBalloons(string text) {
    if (text.size() < 7) {
        return 0;
    }
    string check = "balloon";
    int res = 0;
    unordered_map<char, int> hashMap;
    for (int i = 0; i < text.length(); i++) {
        hashMap[text[i]]++;
    }
    int b = hashMap['b'];
    int a = hashMap['a'];
    int l = hashMap['l'] / 2;
    int o = hashMap['o'] / 2;
    int n = hashMap['n'];
    vector<int> all;
    all.push_back(b);
    all.push_back(a);
    all.push_back(l);
    all.push_back(o);
    all.push_back(n);

    return *min_element(all.begin(), all.end());
}

vector<string> EasySolutions::uncommonFromSentences(string A, string B) {
    vector<string> strA, strB;
    splitStr(A, strA);
    splitStr(B, strA);
    vector<string> res;
    for (int i = 0; i < strA.size(); i++) {
        string curr = strA[i];
        if (find(strB.begin(), strB.end(), curr) == strB.end()) {
            res.push_back(curr);
        }
    }
    for (int i = 0; i < strB.size(); i++) {
        string curr = strB[i];
        if (find(strA.begin(), strA.end(), curr) == strA.end()) {
            res.push_back(curr);
        }
    }
    return res;
}

bool EasySolutions::leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> tree01, tree02;
    inorderTraTree(root1, tree01);
    inorderTraTree(root2, tree02);
    return tree01 == tree02;
}

int EasySolutions::countBinarySubstrings(string s) {
    vector<int> counts;
    int ptr = 0, n = s.size();
    while (ptr < n) {
        char c = s[ptr];
        int count = 0;
        while (ptr < n && s[ptr] == c) {
            ++ptr;
            ++count;
        }
        counts.push_back(count);
    }
    int ans = 0;
    for (int i = 1; i < counts.size(); ++i) {
        ans += min(counts[i], counts[i - 1]);
    }
    return ans;
}

double EasySolutions::largestTriangleArea(vector<vector<int>> &points) {
    double mmax = 0;
    vector<double> res;
    for (int i = 0; i < points.size(); i++)
        for (int j = i + 1; j < points.size(); j++)
            for (int k = j + 1; k < points.size(); k++)
                //mmax = max(mmax, 0.5 * abs(points[i][0] * points[j][1] + points[i][1] * points[k][0] + points[j][0] * points[k][1] - points[i][0] * points[k][1] - points[i][1] * points[j][0] - points[j][1] * points[k][0]));
                return mmax;
    return mmax;
}

int EasySolutions::lengthOfLastWord(string s) {
    if (s.empty()) {
        return 0;
    }
    int pos = s.length() - 1;
    while (s[pos] == ' ' && pos >= 0) {
        pos--;
    }
    if (pos == -1) {
        return 0;
    }
    string res;
    while (s[pos] != ' ' && pos >= 0) {
        res += s[pos];
        pos--;
    }
    return res.length();
}

bool EasySolutions::isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
        return true;
    } else if (p == nullptr || q == nullptr) {
        return false;
    } else if (p->val != q->val) {
        return false;
    } else {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}

bool EasySolutions::isSameTree2(TreeNode *p, TreeNode *q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    if (p == nullptr || q == nullptr) {
        return false;
    }
    queue<TreeNode *> qNodeS1, qNodeS2;
    qNodeS1.push(p), qNodeS2.push(q);
    while (!qNodeS1.empty() && !qNodeS2.empty()) {
        if (qNodeS1.front()->val != qNodeS2.front()->val) {
            return false;
        }
        if (qNodeS1.front()->left != nullptr && qNodeS2.front() != nullptr) {
            qNodeS1.push(qNodeS1.front()->left);
            qNodeS2.push(qNodeS2.front()->left);
        } else if (qNodeS1.front()->left != nullptr || qNodeS2.front()->left != nullptr) {
            return false;
        }
        if (qNodeS1.front()->right != nullptr && qNodeS2.front()->right != nullptr) {
            qNodeS1.push(qNodeS1.front()->right);
            qNodeS2.push(qNodeS2.front()->right);
        } else if (qNodeS1.front()->right != nullptr || qNodeS2.front()->right != nullptr) {
            return false;
        }
        qNodeS1.pop(), qNodeS2.pop();
    }
    if (!qNodeS1.empty() || !qNodeS2.empty()) {
        return false;
    }
    return true;
}

bool EasySolutions::detectCapitalUse(string word) {
    int upCounts = 0;
    for (char c:word) {
        if (isUpChar(c)) {
            upCounts++;
        }
    }
    return upCounts == word.size() || !upCounts || (upCounts == 1 && isUpChar(word[0]));
}

int EasySolutions::minOperations(vector<string> &logs) {
    if (logs.empty()) {
        return 0;
    }
    int flag = 0;
    for (string ss:logs) {
        if (ss.size() > 1) {
            string moveStr = ss.substr(0, ss.size() - 1);
            if (moveStr == "..") {
                if (flag != 0) {
                    flag--;
                }
            } else if (moveStr == ".") {
                continue;
            } else {
                flag++;
            }
        }
    }
    return flag;
}

int MeduimSolutions::minOperations(int n) {
    vector<int> allNumber(n, 0);
    for (int i = 0; i < allNumber.size(); i++) {
        allNumber[i] = (2 * i) + 1;
    }
    int res = 0;
    long sum = accumulate(allNumber.begin(), allNumber.end(), 0);
    int aver = sum / n;
    for (int i = 0; i < allNumber.size() && allNumber[i] < aver; i++) {
        res += (aver - allNumber[i]);
    }
    return res;
}

int MeduimSolutions::maxCoins(vector<int> &piles) {
    sort(piles.begin(), piles.end(), [](int a, int b) { return a > b; });    // 按大到小排序
    int res = 0;
    int n = piles.size() / 3;
    int pos = 1;
    while (n) {
        res += piles[pos];
        pos += 2;
        n--;
    }
    return res;
}

vector<int> MeduimSolutions::processQueries(vector<int> &queries, int m) {
    /// vector 前插操作：vec.insert(vec.begin(), num);
    vector<int> resVec;
    deque<int> dQuery;
    for (int i = 0; i < m; i++) {
        dQuery.push_back(i + 1);
    }
    for (int i = 0; i < queries.size(); i++) {
        int findNumber = queries[i];
        deque<int>::iterator pDeque = dQuery.begin();
        int pos = 0;
        while (pDeque != dQuery.end()) {
            if (*pDeque == findNumber) {
                resVec.push_back(pos);
                dQuery.push_front(findNumber);
                dQuery.erase(pDeque);
                break;
            } else {
                pDeque++;
                pos++;
            }
        }
    }
    return resVec;
}

vector<int> MeduimSolutions::deckRevealedIncreasing(vector<int> &deck) {
    sort(deck.begin(), deck.end());
    vector<int> resVec(deck.size());
    vector<bool> isOK(deck.size(), true);
    int pos = 0;
    bool isJump = true;
    for (int i = 0; i < deck.size(); i++) {
        while (1) {
            if (pos >= deck.size()) {
                pos = 0;
            } else {
                if (isOK[pos]) {
                    if (isJump) {
                        isJump = false;
                        resVec[pos] = deck[pos];
                        break;
                    } else {
                        pos++;
                        isJump = true;
                    }
                } else {
                    pos++;
                }
            }
        }
    }
    return resVec;
}

int MeduimSolutions::matrixScore(vector<vector<int>> &A) {
    if (A.empty()) {
        return 0;
    }
    vector<bool> reRow(A.size(), false);
    for (int i = 0; i < A.size(); i++) {
        if (A[i][0] == 0) {
            reRow[i] = true;
        }
    }
    for (int i = 0; i < reRow.size(); i++) {
        if (reRow[i]) {
            for (int j = 0; j < A[i].size(); j++) {
                A[i][j] == 0 ? 1 : 0;
            }
        }
    }
    vector<bool> reCol(A[0].size(), false);
    for (int j = 0; j < A[0].size(); j++) {
        int oneCounts = 0, zeroCounts = 0;
        for (int i = 0; i < A.size(); i++) {
            A[i][j] == 0 ? (zeroCounts++) : (oneCounts++);
        }
        reCol[j] = (zeroCounts > oneCounts);
    }

    for (int j = 0; j < reCol.size(); j++) {
        if (reCol[j]) {
            for (int i = 0; i < A.size(); i++) {
                A[i][j] == 0 ? 1 : 0;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < A.size(); i++) {
        int curr = 0;
        for (int j = A[i].size() - 1; j >= 0; j--) {
            int tmp = A[i][j] * pow(2, j);
            curr += tmp;
        }
        res += curr;
    }
    return res;
}

int MeduimSolutions::countBattleships(vector<vector<char>> &board) {
    /// 因为给的都是有效的案例，所以只要统计左上角的数就可以了
    if (board.empty()) {
        return 0;
    }
    int res = 0;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            char curr = board[i][j];
            if (curr == 'X') {
                if (i == 0 || board[i - 1][j] == '.') {
                    if (j == 0 || board[i][j - 1] == '.') {
                        res++;
                    }
                }
            }
        }
    }
    return res;
}

int MeduimSolutions::numTilePossibilities(string tiles) {
    vector<int> visit = vector<int>(tiles.size(), 0);
    sort(tiles.begin(), tiles.end());
    titlePossibilitiesDFS(tiles, visit);

    return 0;
}

vector<int> MeduimSolutions::lexicalOrder(int n) {
    vector<string> allStr;
    for (int i = 1; i < n + 1; i++) {
        string tmp = to_string(i);
        allStr.push_back(tmp);
    }
    sort(allStr.begin(), allStr.end());
    vector<int> resVec;
    for (int i = 0; i < allStr.size(); i++) {
        int curr = stoi(allStr[i]);
        resVec.push_back(curr);
    }
    return resVec;
}

bool MeduimSolutions::exist(vector<vector<char>> &board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board, word, 0, i, j) {
                return true;
            }
        }
    }
    return false;
}

string MeduimSolutions::longestPalindrome(string s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--, r++;
        }
        if (res.size() < r - l - 1) {
            res = s.substr(l + 1, r - l - 1);
        }

        l = i, r = i + 1;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--, r++;
        }
        if (res.size() < r - l - 1) {
            res = s.substr(l + 1, r - l - 1);
        }
    }
    return res;
}

string MeduimSolutions::convert(string s, int numRows) {
    if (numRows == 1) {
        return s;
    }
    string res;
    for (int i = 0; i < numRows; i++) {
        if (i == 0 || i == numRows - 1) {
            for (int j = i; j < s.size(); j += 2 * numRows - 2) {
                res += s[j];
            }
        } else {
            for (int j = i, k = 2 * numRows - 2 - i;
                 j < s.size() || k < s.size(); j += 2 * numRows - 2, k += 2 * numRows - 2) {
                if (j < s.size()) {
                    res += s[j];
                }
                if (k < s.size()) {
                    res += s[k];
                }
            }
        }
    }
    return res;



