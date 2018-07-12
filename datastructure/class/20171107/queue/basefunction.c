#include<stdlib.h>
#include"head.h"
Status InitQueue(LinkQueue *Q)
{
    //将Q初始化为一个空的链队列
    Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(Q->front != NULL)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
        return RIGHT;
    }else
        return WRONG;//溢出

}
Status EnterQueue(LinkQueue *Q, QueueElementType value)
{
    LinkQueueNode* newNode;
    newNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if(newNode != NULL)
    {
        newNode->data = value;
        newNode->next = NULL;
        Q->rear->next = newNode;//表尾插入节点
        Q->rear = newNode;//尾指针指向表尾
        return RIGHT;
    }else
        return WRONG;//溢出
}
Status DeleteQueue(LinkQueue *Q, QueueElementType *delete_value)
{
    if(Q->front == Q->rear) return WRONG;
    LinkQueueNode* p;
    p = Q->front->next;//p指向队列的第一个节点
    Q->front->next = p->next;//将第一个节点出队
    if(Q->rear == p) Q->rear = Q->front;//如果队列中只有一个元素，出队后脑成为空对列
    *delete_value = p->data;
    free(p);//删除节点
    return RIGHT;
}
Status IsEmpty (LinkQueue *Q)
{
    if(Q->front == Q->rear)
        return RIGHT;
    else
        return WRONG;
}
Status GetHead(LinkQueue *Q, QueueElementType *value)
{
    if(Q->front == Q->rear) return WRONG;
    *value = Q->front->next->data;
    return RIGHT;
}
Status ClearQueue(LinkQueue *Q)
{
    if(Q->front == Q->rear) return WRONG;//判断是否为空队列
    LinkQueueNode *tmp;
    //释放队列节点
    for(tmp = Q->front->next; tmp != Q->rear; Q->front->next = tmp->next, free(tmp), tmp = Q->front->next);
    Q->rear = Q->front;//尾指针指向头节点--空队列
    free(tmp);//释放尾节点
    return RIGHT;
}
