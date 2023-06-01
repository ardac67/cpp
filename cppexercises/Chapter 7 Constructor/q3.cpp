#include <iostream> 

using namespace std;
/*sikko bir soru anlamadım tekrar bakarım*/
class Counter{
    public:
        Counter(int maxNum):counter(maxNum){}
        void Reset(){counter=0;};
        void incr1(){
            counter++;
        }
        void incr10(){
            counter+=10;
        }
        void incr100(){
            counter+=100;
        }
        void incr1000(){
            counter+=1000;
        }
        
    private:
        int counter;
        int overFlow;
};