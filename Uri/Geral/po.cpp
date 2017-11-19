#include <bits/stdc++.h>

typedef unsigned long long uint64;

using namespace std;

 struct TREAP{
        struct Node{
               int fix, size;
               int val;
               Node *ch[2];
        }mem
, *root;
        struct mem_poor{//内存池 
               queue<Node>Q;
               void push(Node *t){//消除指针t所占用的地址 
                    Q.push((*t)); 
               }
               Node* get(){
                    Node* t = &Q.front();
                    Q.pop();
                    return t;
               }
        }poor;
        int tot, size;
        //大随机
        void init(){
            // for (int i = 0; i <= 200000 + 5; i++)
             //poor.Q.push(mem[i]);
             size = 0;
             tot = 0;
        } 
        int BIG_RAND(){return rand();}
        Node *NEW(){
             Node *p = new Node;
             p->fix = rand();//BIG_RAND();
             p->size = 1;
             p->ch[0] = p->ch[1] = NULL;
             return p;
        }
        //将t的d节点换到t 
        void rotate(Node *&t, int d){
             Node *p = t->ch[d];
             t->ch[d] = p->ch[d ^ 1];
             p->ch[d ^ 1] = t;
             t->size = 1;
             if (t->ch[0] != NULL) t->size += t->ch[0]->size;
             if (t->ch[1] != NULL) t->size += t->ch[1]->size; 
             p->size = 1;
             if (p->ch[0] != NULL) p->size += p->ch[0]->size;
             if (p->ch[1] != NULL) p->size += p->ch[1]->size; 
             t = p;
             return; 
        }
        void insert(Node *&t, int val){
             //插入 
             if (t == NULL){
                t = NEW();
                t->val = val;
                //size++;
                return; 
             }
             //大的在右边,小的在左边 
             int dir = (val >= t->val);
             insert(t->ch[dir], val);
             //维护最大堆的性质 
             if (t->ch[dir]->fix > t->fix) rotate(t, dir);
             t->size = 1;
             if (t->ch[0] != NULL) t->size += t->ch[0]->size;
             if (t->ch[1] != NULL) t->size += t->ch[1]->size; 
        }
        //在t的子树中找到第k小的值 
        int kth(Node *t, int k){
            if (t == NULL ||  k<=0 || k > t -> size) return 1;
            if (t->size == 1 ) return t->val;
            int l = 0;//t的左子树中有多少值 
            if (t->ch[0] != NULL) l += t->ch[0]->size;
            if (k == (l + 1)) return t->val;
            if (k <= l) return kth(t->ch[0], k);
            else return kth(t->ch[1], k - (l + 1));
        }
        int qcount( Node* t, int val ){
            if( !t ) return 0;
            if( t->val == val ){
                int a = 0, b= 0;
                if(t->ch[1] && t->ch[1]->val == val) a =  qcount(t->ch[1], val);
                else if( t->ch[1] && t->ch[1]->ch[0] ) a += ((t->ch[1]->ch[0])?(t->ch[1]->ch[0]->size):(0));
               
                if(t->ch[0] && t->ch[0]->val == val ) b = qcount(t->ch[0], val);
                else if( t->ch[0] && t->ch[0]->ch[0] ) b +=  ((t->ch[0]->ch[0])?(t->ch[0]->ch[0]->size):(0));
                
                return  a + b + 1;
            }
            
            int a = 0, b = 0;
            if( t->ch[0] && t->ch[0]->val < val ){
                a = ((t->ch[0])?(t->ch[0]->size):(0));
            }
            else if( t->ch[0] && t->ch[0]->val == val ){
                a = qcount(t->ch[0], val)+1;
            }
            else if( t->ch[0] && t->ch[0]->val > val ){
                
            }
            
            if( t->ch[1] && t->ch[1]->val == val ){
                b = qcount(t->ch[1], val)+1;
            }    
            return a+b;
        }
        /*int find(Node *t, int val){
            if (t == NULL) return 0;
            int l = 0;//累加值
            if (t->ch[0] != NULL) l += t->ch[0]->size;
            if (val == t->val) return l + 1;
            else if (val < t->val) return find(t->ch[0], val);
            else return l + 1 + find(t->ch[1], val);
        }*/ 
        //找到值为val的节点 
        /*Node *&get(Node *&t, int val){
            //if (t == NULL) return NULL;
            if (val == t->val) return t;//根结点是，没办法 
            
            if (t->ch[0] != NULL && t->ch[0]->val == val) return t;
            if (t->ch[1] != NULL && t->ch[1]->val == val) return t;
            
            if (val < t->val) return get(t->ch[0], val);
            else return get(t->ch[1], val);
        }*/
        /*void update(Node *&t){
             if (t == NULL) return;
             update(t->ch[0]);
             update(t->ch[1]);
             t->size = 1;
             if (t->ch[0] != NULL) t->size += t->ch[0]->size;
             if (t->ch[1] != NULL) t->size += t->ch[1]->size; 
        }*/
        void Delete(Node* &t,int x){
             int d;
             if (x == t->val) d = -1;
             else d = (x > t->val);
             if (d == -1){
                Node *tmp = t;
                if(t->ch[0] == NULL){
                   t = t->ch[1];
                   //poor.push(tmp);
                   delete tmp;
                   tmp = NULL;
                }else if(t->ch[1] == NULL){
                   t = t->ch[0];
                   //poor.push(tmp);
                   delete tmp;
                   tmp = NULL;
                }else{
                   int k = t->ch[0]->fix > t->ch[1]->fix ? 0 : 1;
                   //int  k = 1; 
                   rotate(t,k);
                   Delete(t->ch[k ^ 1],x);
                }
             }else Delete(t->ch[d],x);
             if (t!=NULL){
                 t->size = 1;
                 if (t->ch[0] != NULL) t->size += t->ch[0]->size;
                 if (t->ch[1] != NULL) t->size += t->ch[1]->size; 
             }
        }
        void print(Node *t){
             if (t == NULL) return;
             printf("[%d] -> ", t->val);
             if( t->ch[0] ) printf("%d", t->ch[0]->val);
             else printf("-1");
             if( t->ch[1] ) printf(" , %d\n", t->ch[1]->val);
             else printf("-1\n");
             print(t->ch[0]);
             
             print(t->ch[1]);
        }
 }treap; 

int main(int argc, char* argv[]) {
    srand(time(NULL));
    //ios::sync_with_stdio(false);
    vector < int > vet;
    treap.init();
    treap.root = NULL;
    for(int i = 0; i < 30; i++){
        vet.push_back(rand() % 5);
        treap.insert(treap.root, vet.back());
    }

    random_shuffle(vet.begin(), vet.end());
    treap.print(treap.root);

    for(int i = 0; i < 30; i++){
    //    cout << vet[i] << " " << treap.qcount(treap.root, vet[i]) << endl;
        //treap.Delete(treap.root, vet[i]);
        //treap.print(treap.root);
    }
    
    //cout << treap.root->size << endl;
    return 0;
}