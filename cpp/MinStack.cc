class MinStack {
private:
    stack<int> S;
    stack<int> MIN_S;
public:
    void push(int x) {
        S.push(x);
        if (MIN_S.empty() || x <= MIN_S.top()) { // NOTE: the "=" here is very important to keep sync between S and MIN_S
            MIN_S.push(x);
        }
    }

    void pop() {
        if (S.empty()) return;
        int element = S.top();
        S.pop();
        if (element == MIN_S.top()) MIN_S.pop();
    }

    int top() {
        if (S.empty()) {
            return -1;
        }
        return S.top();
    }

    int getMin() {
        if (MIN_S.empty()) {
            return -1;
        }
        return MIN_S.top();
    }
};
