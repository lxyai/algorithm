#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

class TreeNode
{
  public:
    int value;
    int x;
    int y;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val, int dx, int dy, TreeNode *init_left, TreeNode *init_right)
    {
        value = val;
        x = dx;
        y = dy;
        left = init_left;
        right = init_right;
    }
};

int calulator_y(int m)
{
    double tmp = log10(m+1) / log10(2);
    return floor(tmp);
}

int calulator_x(int m)
{
    int y = calulator_y(m);
    return m - pow(2, y) + 1;
}

TreeNode *MakeTree(int *arr, int count)
{
    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    TreeNode *root = NULL;
    for (int i=0; i<count; i++){
        cout<<"45 :"<<calulator_y(i)<<" "<<calulator_x(i)<<endl;
        TreeNode *temp = new TreeNode(arr[i], calulator_x(i), calulator_y(i), NULL, NULL);
        q1.push(temp);
    }
    while(q1.size() != 0){
        if (q2.size() == 0){
            root = q1.front();
            q1.pop();
            q2.push(root);
        }
        else
        {
            int q2_size = q2.size();
            for (int i=0; i<q2_size; i++){
                TreeNode* main_node =q2.front();
                q2.pop();
                TreeNode* left_node = NULL;
                TreeNode* right_node = NULL;
                if (q1.size() != 0){
                    left_node = q1.front();
                    q1.pop();
                }
                if (q1.size() != 0){
                    right_node = q1.front();
                    q1.pop();
                }
                main_node->left = left_node;
                main_node->right = right_node;
                q2.push(left_node);
                q2.push(right_node);
            }
        }
    }
    return root;
}

void Print_Tree(TreeNode* root){
    if (root->left == NULL && root->right == NULL){
        //cout<<"99 :exit in:"<<root->y<<","<<root->x<<endl;
        cout<<root->y<<","<<root->x<<":"<<root->value<<endl;
        return ;
    }
    cout<<root->y<<","<<root->x<<":"<<root->value<<endl;
    if (root->left != NULL){
        Print_Tree(root->left);
    }
    if (root->right != NULL){
        Print_Tree(root->right);
    }
}

int main(int argc, char const *argv[])
{
    int src[] = {0,1,2,3,4,5,6,7,8,9};
    TreeNode* firstNode = MakeTree(src, 10);
    if (firstNode != NULL){
        Print_Tree(firstNode);
    }
    else{
        cout<<"firstNode is NULL"<<endl;
    }
    return 0;
}
