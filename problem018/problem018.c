/*
 * Project Euler: Problem 14
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node *left;
	struct node *right;
};
typedef struct node item;

item* root;
int d1[]  = {75};
int d2[]  = {95, 64};
int d3[]  = {17, 47, 82};
int d4[]  = {18, 35, 87, 10};
int d5[]  = {20, 4, 82, 47, 65};
int d6[]  = {19, 1, 23, 75, 3, 34};
int d7[]  = {88, 2, 77, 73, 7, 63, 67};
int d8[]  = {99, 65, 4, 28, 6, 16, 70, 92};
int d9[]  = {41, 41, 26, 56, 83, 40, 80, 70, 33};
int d10[] = {41, 48, 72, 33, 47, 32, 37, 16, 94, 29};
int d11[] = {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14};
int d12[] = {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57};
int d13[] = {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48};
int d14[] = {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31};
int d15[] = {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23};

void buildTree()
{
	int i;
	item* n2[2];
	item* n3[3];
	item* n4[4];
	item* n5[5];
	item* n6[6];
	item* n7[7];
	item* n8[8];
	item* n9[9];
	item* n10[10];
	item* n11[11];
	item* n12[12];
	item* n13[13];
	item* n14[14];
	item* n15[15];
	for (i = 0; i < 15; ++i) {
		n15[i] = (item*)malloc(sizeof(item));
		n15[i]->val = d15[i];
	}
	for (i = 0; i < 14; ++i) {
		n14[i] = (item*)malloc(sizeof(item));
		n14[i]->val = d14[i];
		n14[i]->left = n15[i];
		n14[i]->right = n15[i+1];
	}
	for (i = 0; i < 13; ++i) {
		n13[i] = (item*)malloc(sizeof(item));
		n13[i]->val = d13[i];
		n13[i]->left = n14[i];
		n13[i]->right = n14[i+1];
	}
	for (i = 0; i < 12; ++i) {
		n12[i] = (item*)malloc(sizeof(item));
		n12[i]->val = d12[i];
		n12[i]->left = n13[i];
		n12[i]->right = n13[i+1];
	}
	for (i = 0; i < 11; ++i) {
		n11[i] = (item*)malloc(sizeof(item));
		n11[i]->val = d11[i];
		n11[i]->left = n12[i];
		n11[i]->right = n12[i+1];
	}
	for (i = 0; i < 10; ++i) {
		n10[i] = (item*)malloc(sizeof(item));
		n10[i]->val = d10[i];
		n10[i]->left = n11[i];
		n10[i]->right = n11[i+1];
	}
	for (i = 0; i < 9; ++i) {
		n9[i] = (item*)malloc(sizeof(item));
		n9[i]->val = d9[i];
		n9[i]->left = n10[i];
		n9[i]->right = n10[i+1];
	}
	for (i = 0; i < 8; ++i) {
		n8[i] = (item*)malloc(sizeof(item));
		n8[i]->val = d8[i];
		n8[i]->left = n9[i];
		n8[i]->right = n9[i+1];
	}
	for (i = 0; i < 7; ++i) {
		n7[i] = (item*)malloc(sizeof(item));
		n7[i]->val = d7[i];
		n7[i]->left = n8[i];
		n7[i]->right = n8[i+1];
	}
	for (i = 0; i < 6; ++i) {
		n6[i] = (item*)malloc(sizeof(item));
		n6[i]->val = d6[i];
		n6[i]->left = n7[i];
		n6[i]->right = n7[i+1];
	}
	for (i = 0; i < 5; ++i) {
		n5[i] = (item*)malloc(sizeof(item));
		n5[i]->val = d5[i];
		n5[i]->left = n6[i];
		n5[i]->right = n6[i+1];
	}
	for (i = 0; i < 4; ++i) {
		n4[i] = (item*)malloc(sizeof(item));
		n4[i]->val = d4[i];
		n4[i]->left = n5[i];
		n4[i]->right = n5[i+1];
	}
	for (i = 0; i < 3; ++i) {
		n3[i] = (item*)malloc(sizeof(item));
		n3[i]->val = d3[i];
		n3[i]->left = n4[i];
		n3[i]->right = n4[i+1];
	}
	for (i = 0; i < 2; ++i) {
		n2[i] = (item*)malloc(sizeof(item));
		n2[i]->val = d2[i];
		n2[i]->left = n3[i];
		n2[i]->right = n3[i+1];
	}
	root = (item*)malloc(sizeof(item));
	root->val = d1[0];
	root->left = n2[0];
	root->right = n2[1];

}

int biggestSum(item* node)
{
	int l, r;
	int s = node->val;
	if (node->left != NULL) {
		l = biggestSum(node->left);
		r = biggestSum(node->right);
		if (l > r)
			return l + s;
		else
			return r + s;
	}
	return s;
}

int main(void)
{
	int sum;
	buildTree();
	sum = biggestSum(root);
	printf("Result: %d\n", sum);
	return 0;
}


//curr = (item*)malloc(sizeof(item));
