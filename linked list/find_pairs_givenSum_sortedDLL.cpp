#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
// brute force approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// approach: nested loops
// 1. Initialize an empty list to store the pairs.
// 2. Use a nested loop to iterate through each possible pair of nodes in the DLL.
// 3. For each pair, check if the sum of their values equals the target sum
// 4. If a pair is found, store it in the list.
// 5. Return the list of pairs found.
vector<pair<int,int>> findPairsWithGivenSumBruteForce(Node* head, int target) {
    vector<pair<int,int>> result;
    // for (Node* first = head; first != NULL; first = first->next) {
    //     for (Node* second = first->next; second != NULL; second = second->next) {
    //         if (first->data + second->data == target) {
    //             result.push_back({first->data, second->data});
    //         }
    //     }
    // }
    Node* temp1=head;
    while(temp1!=NULL){
        Node* temp2=temp1->next;
        while(temp2!=NULL && temp1->data+temp2->data<=target){
            if(temp1->data+temp2->data==target){
                result.push_back({temp1->data,temp2->data});
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return result;
}
// optimal approach
// Time Complexity: O(2n)
// Space Complexity: O(1)
// approach: two pointer approach
// 1. Initialize two pointers, left at the head and right at the tail of the DLL.
// 2. While left is less than right, calculate the sum of the values at the left and right pointers.
// 3. If the sum equals the target, store the pair and move both pointers inward
// 4. If the sum is less than the target, move the left pointer to the right to increase the sum.
// 5. If the sum is greater than the target, move the right pointer to the left to decrease the sum.
// 6. Repeat until the pointers meet.
// 7. Return the list of pairs found.
vector<pair<int,int>> findPairsWithGivenSum(Node* head, int target) {
    vector<pair<int,int>> result;
    if (!head) return result;

    Node* left = head;
    Node* right = head;

    // Move right to the end of the DLL
    while (right->next) {
        right = right->next;
    }

    while (left != right && right->next != left) {
        int currentSum = left->data + right->data;
        if (currentSum == target) {
            result.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if (currentSum < target) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }

    return result;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(5);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    int target = 7;
    vector<pair<int,int>> pairs = findPairsWithGivenSum(head, target);

    cout << "Pairs with sum " << target << " are:\n";
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}