/*

Problem Statement:
Given the head of a sorted linked list, delete all duplicates such that each element appears only once.
Return the linked list sorted as well.

Example:
Input: head = [1,1,2]
Output: [1,2]

*/



#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* Delete_Duplicates(ListNode* head) {
        ListNode* point = head;

        while (head && head->next) {
            if (head->val == head->next->val) {
                head->next = head->next->next;
            }
            else {
                head = head->next;
            }
        }

        return point;
    }
};

ListNode* Create_List(const vector<int>& arr) {
    if (arr.empty()) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (size_t i = 1; i < arr.size(); i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

vector<int> List_To_Vector(ListNode* head) {
    vector<int> result;
    while (head != NULL) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

int main() {
    vector<int> input = { 1, 1, 2 };
    cout << "Input: head = [";
    for (size_t i = 0; i < input.size(); i++) {
        cout << input[i] << (i < input.size() - 1 ? "," : "");
    }
    cout << "]" << endl;

    ListNode* head = Create_List(input);
    Solution solution;
    head = solution.Delete_Duplicates(head);

    vector<int> output = List_To_Vector(head);
    cout << "Output: [";
    for (size_t i = 0; i < output.size(); i++) {
        cout << output[i] << (i < output.size() - 1 ? "," : "");
    }
    cout << "]" << endl;

    return 0;
}
