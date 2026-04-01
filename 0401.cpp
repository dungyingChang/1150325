#include <iostream>
using namespace std;

// 節點 Node
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Linked List 類別
class LinkedList {
private:
    Node* head;

public:
    // 建構子
    LinkedList() {
        head = NULL;
    }

    // 解構子：釋放記憶體
    ~LinkedList() {
        clear();
    }

    // 1. 判斷是否為空
    bool isEmpty() {
        return head == NULL;
        // Time Complexity: O(1)
    }

    // 2. 在前面插入節點
    void insertFront(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Insert " << value << " at front. Time Complexity: O(1)" << endl;
    }

    // 3. 在後面插入節點
    void insertBack(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Insert " << value << " at back. Time Complexity: O(n)" << endl;
    }

    // 4. 刪除第一個指定值
    void deleteValue(int value) {
        if (head == NULL) {
            cout << "List is empty, cannot delete. Time Complexity: O(1)" << endl;
            return;
        }

        // 如果頭節點就是要刪除的值
        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Delete " << value << ". Time Complexity: O(1) ~ O(n)" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Value " << value << " not found. Time Complexity: O(n)" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        cout << "Delete " << value << ". Time Complexity: O(n)" << endl;
    }

    // 5. 搜尋資料
    bool search(int value) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == value) {
                cout << "Value " << value << " found. Time Complexity: O(n)" << endl;
                return true;
            }
            temp = temp->next;
        }

        cout << "Value " << value << " not found. Time Complexity: O(n)" << endl;
        return false;
    }

    // 6. 顯示 Linked List
    void display() {
        if (head == NULL) {
            cout << "Linked List is empty. Time Complexity: O(1)" << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
        cout << "Display Time Complexity: O(n)" << endl;
    }

    // 7. 計算長度
    int length() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "Length calculation Time Complexity: O(n)" << endl;
        return count;
    }

    // 8. 清空 Linked List
    void clear() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
        // Time Complexity: O(n)
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n===== Linked List Menu =====" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Back" << endl;
        cout << "3. Delete Value" << endl;
        cout << "4. Search Value" << endl;
        cout << "5. Display List" << endl;
        cout << "6. Get Length" << endl;
        cout << "7. Check Empty" << endl;
        cout << "8. Clear List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at front: ";
            cin >> value;
            list.insertFront(value);
            break;

        case 2:
            cout << "Enter value to insert at back: ";
            cin >> value;
            list.insertBack(value);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteValue(value);
            break;

        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;

        case 5:
            list.display();
            break;

        case 6:
            cout << "Length of list: " << list.length() << endl;
            break;

        case 7:
            if (list.isEmpty()) {
                cout << "List is empty. Time Complexity: O(1)" << endl;
            } else {
                cout << "List is not empty. Time Complexity: O(1)" << endl;
            }
            break;

        case 8:
            list.clear();
            cout << "List cleared. Time Complexity: O(n)" << endl;
            break;

        case 0:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice, please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
