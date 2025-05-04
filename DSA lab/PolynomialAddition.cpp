#include <iostream>
using namespace std;

struct Node {
    int coeff; // coefficient
    int pow;   // power
    Node* next;
};

// Function to create a new node
Node* createNode(int c, int p) {
    Node* temp = new Node();
    temp->coeff = c;
    temp->pow = p;
    temp->next = NULL;
    return temp;
}

// Function to insert a node at the end
void insert(Node*& head, int c, int p) {
    Node* newNode = createNode(c, p);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to add two polynomials
Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow == p2->pow) {
            insert(result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            insert(result, p1->coeff, p1->pow);
            p1 = p1->next;
        } else {
            insert(result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }

    // Add remaining terms
    while (p1 != NULL) {
        insert(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insert(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

// Function to print a polynomial
void printPolynomial(Node* head) {
    while (head != NULL) {
        cout << head->coeff << "x^" << head->pow;
        if (head->next != NULL)
            cout << " + ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // First polynomial: 3x^3 + 2x^2 + 1
    insert(poly1, 3, 3);
    insert(poly1, 2, 2);
    insert(poly1, 1, 0);

    // Second polynomial: 4x^2 + 5x + 6
    insert(poly2, 4, 2);
    insert(poly2, 5, 1);
    insert(poly2, 6, 0);

    cout << "Polynomial 1: ";
    printPolynomial(poly1);

    cout << "Polynomial 2: ";
    printPolynomial(poly2);

    Node* sum = addPolynomials(poly1, poly2);

    cout << "Sum: ";
    printPolynomial(sum);

    return 0;
}
