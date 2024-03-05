#include <iostream>
#include <queue>

using namespace std;

namespace BinaryTree
{
    template <class T>
    struct Node
    {
        T data;
        Node *left;
        Node *right;

        Node(T data)
        {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    template <class T>
    class CBinaryTree
    {

    public:
        Node<T> *root;

        CBinaryTree()
        {
            root = nullptr;
        }
        ~CBinaryTree()
        {
            // TODO cleanup
        }

        void Inorder(Node<T> *_root)
        {
            if (_root == nullptr)
            {
                return;
            }

            Inorder(_root->left);
            cout << _root->data << " ";
            Inorder(_root->right);
        }
        void Preorder(Node<T> *_root)
        {
            if (_root == nullptr)
            {
                return;
            }

            cout << _root->data << " ";

            Preorder(_root->left);
            Preorder(_root->right);
        }

        void Postorder(Node<T> *_root)
        {
            if (_root == nullptr)
            {
                return;
            }

            Postorder(_root->left);
            Postorder(_root->right);
            cout << _root->data << " ";
        }

        void Levelorder(Node<T> *_root)
        {
            if (_root == nullptr)
            {
                return;
            }

            queue<Node<T> *> Q;

            Q.push(_root);

            while (!Q.empty())
            {
                auto temp = Q.front();
                Q.pop();
                if (temp != nullptr)
                {

                    cout << temp->data << " ";
                    Q.push(temp->left);
                    Q.push(temp->right);
                }
            }
        }
    };
}

using namespace BinaryTree;

void main()
{

    CBinaryTree<int> tree;

    tree.root = new Node<int>(10);

    tree.root->left = new Node<int>(5);
    tree.root->right = new Node<int>(20);

    tree.root->left->left = new Node<int>(3);
    tree.root->left->right = new Node<int>(6);

    /*tree
               (10)
                /\
               /  \
             (5)  (20)
             /\
            /  \
           (3) (6)

   */

    cout << "Inorder" << endl;
    tree.Inorder(tree.root);
    cout << endl
         << "Preorder" << endl;
    tree.Preorder(tree.root);
    cout << endl
         << "Postorder" << endl;
    tree.Postorder(tree.root);
    cout << endl
         << "Levelorder" << endl;
    tree.Levelorder(tree.root);
}