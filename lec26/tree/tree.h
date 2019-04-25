struct node 
{
    int data;
    struct node* left;
    struct node* right;
};

int countNegatives(struct node* root);
int isSameTree(struct node *root1, struct node *root2);
void mirror(struct node* root);
void padding(char ch, int n);
void printTree(struct node *root, int level);

