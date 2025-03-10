//the following code contain the solution of leetcode problemhttps://leetcode.com/problems/design-circular-queue/
class MyCircularQueue {
  public:
      int f;
      int b;
      vector<int> arr;
      int c;
      int s;
      MyCircularQueue(int k) {
          f = 0;
          b = 0;
          vector<int> v(k);
          arr = v;
          c = k;
          s = 0;//current size   
      }
      
      bool enQueue(int value) {//to push a value in queue;
      if(s >= c) return false;
      arr[b] = value;
      b++;
      if(b == c) b = 0;
      s++;
      return true;  
      };
      
      bool deQueue() {//to pop a value following the fifo principle applied in a queue
          if(s == 0) return false;
          else if(f == c-1) f = 0;
          else f++;
          s--;
          return true;
      }
      
      int Front() {
          if(s == 0) return -1;
          else return arr[f];
      }
      
      int Rear() {
          if(s == 0) return -1;
          else if(b==0) return arr[c-1];
          else return arr[b-1];
      }
      
      bool isEmpty() {
          if(s == 0) return true;
          else return false;
      }
      
      bool isFull() {
          if(s == c) return true;
          else return false;
      }
  };
  
  /**
   * Your MyCircularQueue object will be instantiated and called as such:
   * MyCircularQueue* obj = new MyCircularQueue(k);
   * bool param_1 = obj->enQueue(value);
   * bool param_2 = obj->deQueue();
   * int param_3 = obj->Front();
   * int param_4 = obj->Rear();
   * bool param_5 = obj->isEmpty();
   * bool param_6 = obj->isFull();
   */