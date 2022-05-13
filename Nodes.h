#pragma once

#include <iostream>
#include "pch.h"

struct LinkNode
{
    int _data;
    LinkNode* _next;
    LinkNode(const int& data)
        :_data(data)
        , _next(NULL)
    {}
};

class Link
{
public:
    Link()
        :pHead(new LinkNode(0))
    {}
    void PushBack(const int& data)
    {
        if (pHead == NULL)
            return;
        LinkNode* newNode = new LinkNode(data);
        if (pHead->_next == NULL) {  // Первый узел вставлен
            pHead->_next = newNode;
        }
        else {  // найти последний узел и вставить его напрямую
            LinkNode* cur = pHead->_next;
            while (cur->_next) {
                cur = cur->_next;
            }
            cur->_next = newNode;
        }
    }

    void PopBack()
    {
        if (pHead == NULL)
            return;
        LinkNode* cur = pHead;
        LinkNode* prev = NULL;
        while (cur->_next)
        {
            prev = cur;
            cur = cur->_next;
        }
        prev->_next = NULL;
        delete cur;
    }

    LinkNode* FindNode(const int& data)
    {
        if (pHead == NULL)
            return NULL;
        LinkNode* cur = pHead->_next;
        while (cur)
        {
            if (cur->_data == data)
                return cur;
            cur = cur->_next;
        }
        return NULL;
    }

    bool Delete(int data)
    {
        LinkNode* pos = FindNode(data);
        if (pos == NULL)
            return false;
        LinkNode* cur = pHead->_next;
        while (cur->_next != pos)
        {
            cur = cur->_next;
        }
        cur->_next = pos->_next;
        delete pos;
        return true;
    }

    void Destroy()
    {
        if (pHead == NULL)
            return;
        LinkNode* cur = pHead->_next;
        while (cur)
        {
            LinkNode* del = cur;
            cur = cur->_next;
            delete del;
            del = NULL;
        }
        delete pHead;  // Удалить головной узел
    }
    LinkNode* pHead;
};

class TestLink :public testing::Test
{
public:
    virtual void SetUp()
    {
        std::cout << "SetUp" << std::endl;
        for (int i = 1; i <= 5; i++) {
            link.PushBack(i);
        }
    }
    virtual void TearDown()
    {
        std::cout << "TearDown" << std::endl;
        link.Destroy();
    }

    Link link;
};


TEST_F(TestLink, PushBack) {

    ASSERT_FALSE(link.pHead == NULL);
    link.PushBack(9);

    LinkNode* res = link.FindNode(9);
    ASSERT_FALSE(res == NULL);

}

TEST_F(TestLink, FindNode) {

    ASSERT_TRUE(link.FindNode(3));

}

TEST_F(TestLink, Delete) {

    ASSERT_FALSE(link.pHead == NULL);
    ASSERT_TRUE(link.Delete(3) == true);
    ASSERT_TRUE(link.Delete(9) == false);

}