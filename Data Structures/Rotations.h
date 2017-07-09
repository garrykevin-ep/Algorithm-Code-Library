// A  Node
struct Node
{
    int key, priority;
    Node *left, *right;
};
 
/* T1, T2 and T3 are subtrees of the tree rooted with y
  (on left side) or x (on right side)
                y                               x
               / \     Right Rotation          /  \
              x   T3   – – – – – – – >        T1   y
             / \       < - - - - - - -            / \
            T1  T2     Left Rotation            T2  T3 */
 
Node *rightRotate(Node *y)
{
    //move node to right
    Node *x = y->left,  *T2 = x->right;

    
    //node->left as root and new root->right as node
    x->right = y;
    //manage the right of new node when it was a subtree,stroed in T2 
    y->left = T2;
 
    return x;
}
 
Node *leftRotate(Node *x)
{
    //move node to left
    Node *y = x->right, *T2 = y->left;
 
    //node->right as root and new root->left as node
    y->left = x;
    //manage the left of new node when it was a subtree,stroed in T2
    x->right = T2;
 
    return y;
}
