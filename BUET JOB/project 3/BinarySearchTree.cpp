#include<stdio.h>
#include<stdlib.h>

#define FALSE_VALUE 0
#define TRUE_VALUE 1

struct treeNode
{
    int item;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};

struct treeNode * root;


void initializeTree()
{
    root = 0;
}


struct treeNode * searchItem(struct treeNode * node, int item)
{
    if(node==0) return 0;
    if(node->item==item) return node; //found, return node
    struct treeNode * t = 0;
    if(item < node->item)
        t = searchItem(node->left, item); //search in the left sub-tree
    else
        t = searchItem(node->right, item); //search in the right sub-tree
    return t;
};


struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

struct treeNode * insertItem(struct treeNode * node, int item)
{
    if(node==0) //insert as the root as the tree is empty
    {
        struct treeNode * newNode = makeTreeNode(item);
        root = newNode;
        return newNode;
    }

    if(node->item==item) return 0; //already an item exists, so return NULL

    if(item<node->item && node->left==0) //insert as the left child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->left = newNode;
        return newNode;
    }

    if(item>node->item && node->right==0) //insert as the right child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->right = newNode;
        return newNode;
    }

    if(item<node->item)
        return insertItem(node->left, item); //insert at left sub-tree
    else
        return insertItem(node->right, item); //insert at right sub-tree
}



int calcNodeHeight(struct treeNode * node) //return height of a node
{
    if(node==0) return -1;
    int l, r;
    l = calcNodeHeight(node->left);
    r = calcNodeHeight(node->right);
    if(l>r) return l+1;
    else return r+1;
}


int calcHeight(int item) //return height of an item in the tree
{
    struct treeNode * node = 0;
    node = searchItem(root, item);
    if(node==0) return -1; //not found
    else return calcNodeHeight(node);
}

int getSize(struct treeNode * node)
{
    if(node==NULL)
        return 0;
    return 1 + getSize(node->left) + getSize(node->right);
}

int calcNodeDepth(struct treeNode * node) //return depth of a node
{
    //write your codes here

    if(root==0)
        return -1;

    int t = node->item;

    treeNode* temp=root;

    int k=0;

    while(temp->item!=t)
    {
        if(t > temp->item)
            temp=temp->right;
        else
            temp=temp->left;
        k++;
    }

    return k;

}


int calcDepth(int item)//return depth of an item in the tree
{
    //write your codes here
    if(root==NULL)
        return -1;

    if(searchItem(root, item)==NULL)
        return -2;

    treeNode* temp = root;
    int k=0;

    while(temp->item!=item)
    {
        if(item > temp->item)
            temp=temp->right;
        else
            temp=temp->left;
        k++;
    }

    return k;
}

treeNode* findMin(treeNode* node)
{
	while(node->left != NULL) node = node->left;
	return node;
}

treeNode* deleteItem(struct treeNode * node, int item)
{
    //write your code here, return TRUE, FALSE
    if(node==NULL)
        return node;
    else if(item < node->item)  node->left = deleteItem(node->left, item);
    else if(item > node->item)  node->right = deleteItem(node->right, item);
    else
    {
        if(node->left==NULL && node->right==NULL)
        {
            free(node);
            node=NULL;
        }
        else if(node->left==NULL)
        {
            treeNode* temp=node;
            node = node->right;
            free(temp);
        }
        else if(node->right==NULL)
        {
            treeNode* temp=node;
            node = node->left;
            free(temp);
        }
        else
        {
            treeNode* temp = findMin(node->right);
            node->item=temp->item;
            node->right = deleteItem(node->right, temp->item);
        }
    }

    return node;

}


int getMinItem() //returns the minimum item in the tree
{
    //write your codes here
    treeNode* temp=root;
    treeNode* temp2=NULL;
    while(temp!=NULL)
    {
        temp2=temp;
        temp=temp->left;
    }

    return temp2->item;
}

int getMaxItem() //returns the maximum item in the tree
{
    //write your codes here
    treeNode* temp=root;
    treeNode* temp2=NULL;
    while(temp!=NULL)
    {
        temp2=temp;
        temp=temp->right;
    }

    return temp2->item;
}

int rangeSearch(struct treeNode * node, int leftBound, int rightBound) //returns number of items in the
{
    //write your codes here
    if(node==NULL)
        return -1;

    int k;

    k=0;

    if((node->item >= leftBound)&&(node->item <= rightBound))
        k=1;
    if(node->left!=NULL)
        k+=rangeSearch(node->left,leftBound,rightBound);
    if(node->right!=NULL)
        k+=rangeSearch(node->right,leftBound,rightBound);

    return k;
}


void printInOrder(struct treeNode * node, int height)
{
    if(node==0) return ;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);

    //print right sub-tree
    printInOrder(node->right, height-1);
}



int main(void)
{
    initializeTree();
    while(1)
    {
        printf("1. Insert item. 2. Delete item. 3. Search item. \n");
        printf("4. Print height of tree. 5. Print height of an item. \n");
        printf("6. PrintInOrder. 7. Print Size of tree. 8. Print the minimum item. \n");
        printf("9. Print the maximum item. 10. Search in Range. \n");
        printf("11. Print Depth of tree. 12. Print Depth of an Item. 13. Exit. \n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item,h;
            scanf("%d", &item);
            insertItem(root, item);

            h=calcNodeHeight(root);

            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==2)
        {
            int item,h;
            scanf("%d", &item);
            root = deleteItem(root, item);

            h=calcNodeHeight(root);

            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");

        }
        else if(ch==3)
        {
            int item,h;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");

            h=calcNodeHeight(root);

            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==4)
        {
            int height = calcNodeHeight(root);
            printf("Height of tree = %d\n", height);
        }
        else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            int height = calcHeight(item);
            printf("Height of %d = %d\n", item, height);
        }
        else if(ch==6)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==7)
        {
            int h = getSize(root);
            printf("Size of tree = %d\n", h);
        }
        else if(ch==8)
        {
            if(root==NULL)
                printf("Empty tree.\n\n");
            else
            {
                int h=getMinItem();
                printf("Minimum = %d\n\n", h);
            }
        }
        else if(ch==9)
        {
            if(root==NULL)
                printf("\nThe tree is empty.\n\n");
            else
            {
                int h=getMaxItem();
                printf("Maximum = %d\n\n", h);
            }
        }
        else if(ch==10)
        {
            int l,r;
            scanf("%d %d", &l, &r);
            int h=rangeSearch(root,l,r);
            if(h==-1)
                printf("Number of items in the range [ %d , %d ] is : 0\n\n", l,r);
            else
                printf("Number of items in the range [ %d , %d ] is : %d\n\n", l,r,h);
        }
        else if(ch==11)
        {
            int h = calcNodeDepth(root);

            if(h==-1)
                printf("Empty tree\n\n");
            else
                printf("Depth of the root node is %d\n\n", h);
        }
        else if(ch==12)
        {
            int k,d;
            scanf("%d", &k);
            d=calcDepth(k);
            if(d==-1)
                printf("Empty tree\n");
            else if(d==-2)
                printf("Item not Found.\n");
            else
                printf("Depth of item %d : %d\n", k, d);
        }
        else if(ch==13)
        {
            break;
        }
    }

}
