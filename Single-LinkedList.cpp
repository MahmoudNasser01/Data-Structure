#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
///صياغات مهمة
/*
1 - NULL --->(لا شئ) معناها اني وصلت لنهايه الليست او ممكن نقول عليها
2 - first,last--->هما متغيران من نوع نود بمعني انهم مش بس بيشاوروا لاء وكمان بياخدوا نفس القيمه بتاعه النود اللي بيشاوروا عليها
*/

class linkedList{ ///عملنا كلاس عشان يلم كل الاكواد بتاعه اللينكد لست
    struct Node{ ///عملنا ديزاين للنود اللي داخل اللينكد لست
        int data;///دي الداتا اللي هاتشيلها النود
        Node *next;///ده المؤشر اللي بيشاور علي النود اللي بعدها
    };

    Node *first;///مؤشر بيشاور علي بداية الليست (عشان يسهل عليا بعض العمليات قدام)
    Node *last;///مؤشر بيشاور علي نهاية الليست
    int len;///متغير هنحط فيه طول الليست كام
public:///دي الصيغه اللي بنحط فيها الفانكشنز  في الكلاس
    linkedList(){
        first = NULL;///مش بيشاور علي حاجه firstفي البدايه ال
        last = NULL;///برضو مش بيشاور علي حاجه lastال
        len = 0;///الطول طبعا زيرو لان الليست في بدايتها مفهاش عناصر
    }
    bool isempty(){///A function to return is the list is empty or not
    return len == 0;
    }

    void insertFirst(int element){ ///فانكشن عشان احط عناصر من بدايه الليست
            Node *newNode = new Node;///عملنا نود جديدة
            if(len == 0){ ///بنشوف هل الليست فيها عناصر قبل كده ولا لاء
                newNode->data = element;///اللي جوا النود dataبنحط القيمه اللي جايه من الفانكشن وبنساويها بال
                first = newNode;///يشاور علي النود الجديده لانها اصلا هي النود الوحيدة اللي عندي firstبنخلي ال
                last = newNode;///يشاور علي النود الاخيرة لانها ذي ماقلنا انها النود الوحيدة lastبرضو بنخلي ال
                newNode->next = NULL;///هنخلي النود دي تشاور علي النهايه
            }
            else{///الشرط هيتحقق لو الليست كان فيها عناصر قبل كده

                newNode->next = first;///هنخلي الليست اللي انا عاوز احطها تشاور علي البداية
                first = newNode;///هخلي البداية بقاا تشاور علي العنصر الجديد اللي انا ضفته

            }
            len++;///بعد الاضافه طبعا لازم نزود طول الليست
    }

void insertLast(int element){///فانكشن بتضيف عناصر من نهاية الليست
            Node *newNode = new Node;///هنعمل نود جديدة
            newNode->data = element;///هنحط القيمة اللي داخا النود وهنساويها بالقيمة الجايه من الفانكشن
            if(len == 0){///شرط عشان نشوف هل الليست فيها نود قبل كده ولا لاء
                first = newNode;
                last = newNode;
                newNode->next = NULL;
            }
            else{
                newNode->next = NULL;///لانها بتتحط من الاخر وبكده هتكون اخر نود عندي NULLهنخلي النود الجديدة هيا اللي تشاور علي
                last->next = newNode;///تشاور علي النود الجديدة بتعتي lastهنخلي النود اللي كان بيشاور عليها ال
                last = newNode;///نفسه هوا اللي بيشاور علي النود الجديدة بتعتي lastهنا هنخلي ال

            }
            len++;///طبعا هنزود النود بتعتنا
    }
void insertAt(int pos  , int element){///فانكشن بتحط قيمه في مكان معين
    Node *newNode = new Node;///عملنا نود جديدة
    newNode->data = element;
    if(pos == 0){
        insertFirst(element);
    }
    else if(pos == len){
        insertLast(element);
    }
    else{
        Node* cur = first;
        for(int i = 1;i<pos ;i++){
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}
void popFirst(){///فانكشن بتشيل عنصر من بداية الليست
    if(len == 0)return; ///لو الليست مفهاش عناصر منعملش حاجه
    else if(len == 1){ ///ده لو الليست فيها عنصر واحد
        delete first;/// firstبنمسح القيمة اللي بيشاور عليها ال
        last = NULL;///بنرجع الفرست و الاست لقيمتهم الافتراضية
        first = NULL;
        len--;///بنقص الطول بتاع الليست
    }
    else{///ده لو الليست فيها اكثر من نود
        Node* cur = first;///
        first = first->next;///يشاور علي تاني عنصر وبكده العنصر الاولاني هيتشال من الليست firstبكل بساطة بنخلي ال
        delete cur;
    /*
    :ملحوظه مهمه
    firstعشان يشاور علي نفس القيمه اللي بيشاور عليها ال cur احنا عملنا متغير اسمو
    هتشيل فعلا العنصر من الليست بس مش من الميموري عشان كده المتغير ده بيتعمل عشان نشيل القيمه من المموري c++عشان نمسحها لان ال
    (تقدر متعملهاش عادي خالص بس عشان يكون كودك صح ميه ف الميه)
    */
    }
}
void popBack(){///اذاله العنصر الاخير
    if(len == 0 )return;///مش هنعمل حاجه لو الليست مفهاش عناصر
    else if(len == 1){///لو الليست فيها عنصر واحد
        delete first;///NULLمن الميموري  وهنحطه ب firstهنمسح ال
        last = NULL;
        first = NULL;
        len--;///هنشيا من طول الليست
    }
    else{///طب لو الليست فيها اكتر من عنصر
        Node* pt1 = first;///firstهنعمل متغير هيساوي ال
        Node*pt2 = first->next;///first هنعمل متغير تاني هيشاور علي القيمه اللي بعد ال
        while(pt2 != last){///lastلو القيمه الاولانيه بتساوي ال
            pt1 = pt2;
            pt2 = pt2->next; ///pt2 و pt1 لل update هنا هنعمل
        }
        delete pt2;///من الميموري pt2 هنمسح ال
        pt1->next = NULL;
        last = pt1;
    }

}
void remove(int element){
if(first->data == element){
        Node* cur = first;
        first = first->next;
        delete cur;
        len--;
    }

    else{
    Node* i = first;
    Node* j = first->next ;
        while(j != NULL){
            if(j->data == element)break;
            i = j;
            j = j->next;

        }
        if(j == NULL)cout<<"The ELment is No Found";
        else{
            i->next = j->next;
            if(last == j)last = i;
            delete j;
            len--;
        }
    }
}

bool ishere(int element){///فانكشن عشان تشوف هل العنصر موجود في الليست ولا لاء
    Node *i = first; ///first هي بوينتر من نوع نود وقيمته الابتدائية i
    while(i != NULL){///الي النهاية  iلوب تستمر حتي تصل ال
        if(i->data == element){///بتساوي القيمه اللي بدور عليها ولا لاء i بنشوف لو القيمه اللي في ال

            return true;///trueلو الشرط اتحقق هنرجع
        }
        i = i->next;///للقيمه اللي بعدها iهنا بنغير قيمه ال
    }
    return false;///دي هيا اللي هتشتغل معني كده اني مشيت علي الليست كلها وملقتش العنصر returnال....return true لو اللوب اللي فوق خلصت منغير ماتعمل
}

void sort(){///فانكشن بترتب الليست
    Node *i , *j;
    for(i = first; i != NULL;i=i->next){
        for(j = first;j!= NULL;j=j->next){
            if(j->next!=NULL && j->data > j->next->data){
                swap(j->next->data , j->data);
            }
        }
    }

}

void sort_rev(){
    Node *i , *j;
    for(i = first; i != NULL;i=i->next){
        for(j = first;j!= NULL;j=j->next){
            if(j->next!=NULL && j->data < j->next->data){
                swap(j->next->data , j->data);
            }
        }
    }
}

    void print(){///فانكشن لطباعة العناصر الموجودة داخل الليست
        Node *i = first;///firstهنعمل متغير نوعه نود بيبتدي من ال
        while(i != NULL){///NULL مش بتساوي  iاللوب دي هتشتغل طالما ال
            cout<<i->data<<" ";/// i هنطبع الداتا اللي موجودة داخل ال
            i  = i->next;///تتحرك علي النود اللي بعدها iهنخلي ال
        }

    }

};


int main(){
linkedList li;
li.insertLast(12);
li.insertLast(109);
li.insertLast(1);
li.insertLast(4);
li.insertLast(1);
li.insertLast(6);
li.ishere(6);
li.sort();
li.print();

return 0;
}

///لينك لمسائل
///https://leetcode.com/problemset/all/?difficulty=Easy&topicSlugs=linked-list




