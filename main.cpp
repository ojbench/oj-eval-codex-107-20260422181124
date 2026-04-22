#include <iostream>
#include <algorithm>
using namespace std;

namespace LIST {
    struct NODE {
        int val;
        NODE *next;
        NODE(int v = 0, NODE *n = nullptr) : val(v), next(n) {}
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        head = nullptr;
        len = 0;
    }

    // Move to node at index i (0 <= i < len). Assumes len > 0 and i valid.
    NODE* move(int i) {
        NODE *cur = head;
        while (i--) cur = cur->next;
        return cur;
    }

    void insert(int i, int x) {
        NODE *n = new NODE(x);
        if (len == 0) {
            // First node: points to itself
            head = n;
            n->next = n;
            len = 1;
            return;
        }
        if (i == 0) {
            // Insert before head, becomes new head
            NODE *tail = move(len - 1);
            n->next = head;
            tail->next = n;
            head = n;
            ++len;
            return;
        }
        // Insert after node i-1
        NODE *prev = move(i - 1);
        n->next = prev->next;
        prev->next = n;
        ++len;
    }

    void remove(int i) {
        if (len == 0) return; // Should not happen per problem constraints
        if (len == 1) {
            // Removing the only node
            delete head;
            head = nullptr;
            len = 0;
            return;
        }
        if (i == 0) {
            // Remove head
            NODE *tail = move(len - 1);
            NODE *old = head;
            head = head->next;
            tail->next = head;
            delete old;
            --len;
            return;
        }
        NODE *prev = move(i - 1);
        NODE *cur = prev->next;
        prev->next = cur->next;
        delete cur;
        --len;
    }

    void remove_insert(int i) {
        if (len <= 1) return; // No effect
        if (i == len - 1) return; // Moving tail to tail, no change
        // Capture tail before modifying links
        NODE *tail = move(len - 1);
        if (i == 0) {
            NODE *cur = head; // node to move
            head = head->next;      // remove head
            tail->next = head;      // close circle
            cur->next = head;       // append cur to tail
            tail->next = cur;
            return;
        }
        NODE *prev = move(i - 1);
        NODE *cur = prev->next;
        prev->next = cur->next; // unlink cur
        tail->next = cur;       // append to tail
        cur->next = head;
    }

    void get_length() {
        cout << len << '\n';
    }

    void query(int i) {
        if (i < 0 || i >= len || len == 0) {
            cout << -1 << '\n';
            return;
        }
        NODE *cur = move(i);
        cout << cur->val << '\n';
    }

    void get_max() {
        if (len == 0) {
            cout << -1 << '\n';
            return;
        }
        int mx = head->val;
        NODE *cur = head->next;
        for (int cnt = 1; cnt < len; ++cnt) {
            mx = max(mx, cur->val);
            cur = cur->next;
        }
        cout << mx << '\n';
    }

    void clear() {
        if (head == nullptr) return;
        // Break the circle and delete linearly
        NODE *tail = move(len - 1);
        tail->next = nullptr;
        NODE *cur = head;
        while (cur) {
            NODE *nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = nullptr;
        len = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_) {
        cin >> op;
        switch (op) {
            case 0:
                LIST::get_length();
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p, x);
                break;
            case 2:
                cin >> p;
                LIST::query(p);
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                break;
            case 5:
                LIST::get_max();
                break;
        }
    }
    LIST::clear();
    return 0;
}
