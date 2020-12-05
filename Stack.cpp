#include <iostream>
using namespace std;
const int MAX = 100;//عمل الحد الاقصي لدي الستاك

class Stack{//بداية الستاك
    int top;
    int arr[MAX];
public:
    Stack(){
        top = -1;//تفعيل التوب ب -1
    }
    void push(int item){
        top++;//تذويد التوب 
        arr[top] = item;//اضافه القيمة داخل التوب 
    }
    void pop(){
        top--;
    }
    void print(){
        for(int i = 0;i<=top;i++){
            cout<<arr[top]<<" ";
        }
    }

};
int main(int argc, char** argv) {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.print();



    return 0;
}
