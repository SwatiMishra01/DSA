class Stack {
  queue < int > q;
  public:
    void Push(int x) {
      int s = q.size();
      q.push(x);
      //Use a for loop of size()-1, remove element from queue and again push back to the queue, 
      //hence the most recent element becomes the most former element and vice versa.
      for (int i = 0; i < s; i++) {
        q.push(q.front());
        q.pop();
      }
    }
  int Pop() {
    int n = q.front();
    q.pop();
    return n;
  }
  int Top() {
    return q.front();
  }
  int Size() {
    return q.size();
  }
};
