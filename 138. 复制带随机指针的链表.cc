/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        //处理random指针
        unordered_map<int, Node*> srcIdMap; //$id->Node 当前的node id映射到random指针上
        unordered_map<Node*, int> srcNodeMap; //Node->$id 当前的node*映射到node id上

        unordered_map<int, Node*> dstIdMap;

        Node *header = nullptr;
        if(head == nullptr) return header;

        int id = 1;
        header = new Node(head->val);
        Node *n = header;
        srcIdMap[id] = head->random;
        srcNodeMap[head] = id;
        dstIdMap[id] = n;
        ++id;

        /* 遍历原链表 */
        Node *p = head->next;
        while(p)
        {
            Node *t = new Node(p->val);
            n->next = t;
            n = n->next;

            srcIdMap[id] = p->random;
            srcNodeMap[p] = id;
            dstIdMap[id] = t;
            ++id;
            p = p->next;
        }

        //处理random指针
        p = header;
        int i = 1;
        while(p)
        {
            int obj = srcNodeMap[srcIdMap[i]];
            p->random = dstIdMap[obj];

            ++i;
            p = p->next;
        }

        assert(i == id);
        return header;
    }
};