#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char c) : data(c), next(nullptr) {}
};

Node* createCircularList(const char* s) {
    if (s == nullptr || s[0] == '\0') {
        return nullptr;
    }

    Node* head = nullptr;
    Node* tail = nullptr;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        Node* newNode = new Node(s[i]);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    tail->next = head; 
    return head;
}

int getListInfo(Node* head, char* str) {
    if (head == nullptr || str == nullptr) {
        str[0] = '\0';
        return 0;
    }

    Node* p = head;
    int count = 0;

    do {
        str[count++] = p->data;
        p = p->next;
    } while (p != head);

    str[count] = '\0';
    return count;
}

bool isSubstring(const char* s, const char* t) {
    int lenS = strlen(s);
    int lenT = strlen(t);

    if (lenT == 0) return true;
    if (lenT > lenS) return false;

    for (int i = 0; i <= lenS - lenT; i++) {
        int j;
        for (j = 0; j < lenT; j++) {
            if (s[i + j] != t[j]) {
                break;
            }
        }
        if (j == lenT) {
            return true;
        }
    }
    return false;
}

void freeCircularList(Node* head) {
    if (head == nullptr) return;

    Node* p = head;
    Node* nextNode;

    do {
        nextNode = p->next;
        delete p;
        p = nextNode;
    } while (p != head);
}

int main() {
    const int MAX_LEN = 1001;
    char s1[MAX_LEN], s2[MAX_LEN];

    cin.getline(s1, MAX_LEN);
    cin.getline(s2, MAX_LEN);

    Node* list1 = createCircularList(s1);
    Node* list2 = createCircularList(s2);

    char str1[MAX_LEN], str2[MAX_LEN];
    int len1 = getListInfo(list1, str1);
    int len2 = getListInfo(list2, str2);

    freeCircularList(list1);
    freeCircularList(list2);

    int result = 0;
    if (len1 == len2) {
        char doubledStr1[2 * MAX_LEN];
        strcpy(doubledStr1, str1);
        strcat(doubledStr1, str1);
        result = isSubstring(doubledStr1, str2) ? 1 : 0;
    }

    cout << result << endl;

    return 0;
}
