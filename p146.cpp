struct Node
{
    Node()
    {
        next = nullptr;
        prev = nullptr;
    }
    Node(int v)
    {
        val = v;
        next = nullptr;
        prev = nullptr;
    }
    int val;
    Node* next;
    Node* prev; //dude i hate this
};

class LRUCache {
public:
    LRUCache(int capacity)
        :cap(capacity), count(0)
    {
        head = nullptr;
        tail = nullptr;
    }
    
    ~LRUCache()
    {
        while(head!=nullptr)
        {
            tail = head->next;
            delete head;
            head = tail;
        }
    }
    int get(int key) {
        if (my_map.count(key) && my_map[key].first != -1)
        {
            Node* temp = my_map[key].second;
            if(temp == tail)
                return my_map[key].first;
            //found
            if (temp != head)
                temp->prev->next = temp->next;
            else
                head = head->next;
            temp->next->prev = temp->prev;
            tail->next = temp;
            temp->next = nullptr;
            temp->prev = tail;
            tail = temp;
            return my_map[key].first;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(count == 0)
        {
            head = new Node(key);
            tail = head;
            count++;
            Node* bob = head;
            my_map[key] = make_pair(value, bob);//does bob survive?
            return;
        }
        if(get(key) == -1)
        {
            Node* temp = new Node(key);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            
            if (count < cap)
                count ++;
            else
            {
                Node* Omae_Wa_Mou_Shindeiru = head;
                my_map[Omae_Wa_Mou_Shindeiru->val].first = -1;
                head = head->next;
                head->prev = nullptr;
                delete Omae_Wa_Mou_Shindeiru;
            }
            my_map[key] = make_pair(value, temp);
        }
        else 
        {
            Node* temp = my_map[key].second;
            my_map[key] = make_pair(value, temp);
            if (temp == tail)//covers count = 1 case
            {
                return;
            }
            if (temp != head)
                temp->prev->next = temp->next;
            else
                head = head->next;
            temp->next->prev = temp->prev;
            tail->next = temp;
            temp->next = nullptr;
            temp->prev = tail;
            tail = temp;
        }
    }
private:
    unordered_map<int, pair<int, Node*>> my_map;
    int cap;
    int count;
    Node* head;
    Node* tail;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */