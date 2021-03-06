#include <stdio.h>
#include <stdlib.h>
typedef int TElemType;
#define MAXSIZE 6
typedef struct  BiTNode
{
    char data;
    struct BiTree *lchild,*rchild;
}BiTNode,*BiTree;
TElemType m,n;
//创建二叉树
 BiTree createBiTree(BiTree T){
    char ch;
    ch=getchar();
    if (ch=='#')
    {
        T=NULL;
    }else{
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=ch;
        T->lchild=createBiTree(T->lchild);
        T->rchild=createBiTree(T->rchild);
    }   
    return T; 
}
//遍历二叉树前序
void frontOrder(BiTree T){
    if (T)
    {   
        printf("%c",T->data);
        frontOrder(T->lchild);
        frontOrder(T->rchild);
    }
}
//中序遍历
void InOrderTransverse(BiTree  T){
    if(T==NULL){
        return;
    }
        InOrderTransverse(T->lchild);
        printf("%c",T->data);
        InOrderTransverse(T->rchild);
}
 
 
//后序遍历
void PostOrderTransverse(BiTree T){
         PostOrderTransverse(T->lchild);
        PostOrderTransverse(T->rchild);   
         printf("%c",T->data);
}
//复制二叉树
BiTree copyBiTree(BiTree T){
    BiTree A=NULL;
    if (T==NULL)
    {
         A=NULL;
         return A;
    }
    
    if (T)
    {
        A=(BiTree)malloc(sizeof(BiTNode));
        A->data=T->data;
        A->lchild=copyBiTree(T->lchild);
        A->rchild=copyBiTree(T->rchild);
        return A;
    }
}
//计算深度
int depBiTree(BiTree T){
    int i,j;
    if (T==NULL)
    {
        return 0;
    }else{
        i=depBiTree(T->lchild);
        j=depBiTree(T->rchild);
        return (i>j?(i+1):(j+1));
    }
    
}
//计算节点数
int NodeCount(BiTree T){
    if (T==NULL)
    {
        return 0;
    }else{
        return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
    }
    
}
int main(){
    BiTree T,A=NULL;
    T=createBiTree(T);
    printf("创建二叉树成功\n");
    frontOrder(T);
    A=copyBiTree(T);
    printf("\n");
    printf("复制二叉树成功\n");
    frontOrder(A);
    //I=深度 j=结点数
    int i,j;
    i=depBiTree(T);
    printf("该树的深度为%d\n",i);
    j=NodeCount(T);
    printf("该树有%d个结点\n",j);
    return 0;
}