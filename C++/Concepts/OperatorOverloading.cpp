#include<iostream>
#include<string>
using namespace std;

class Box{
    private:
        int l, b, h;
    public:
        Box(): l(0), b(0), h(0){}
        Box(int a, int x, int c): l(a), b(x), h(c){}
        Box(const Box &B){
            l= B.l;
            b= B.b;
            h= B.h;
        }
        int getLength(){return l;}
        int getBreadth(){return b;}
        int getHeight(){return h;}
        long long CalculateVolume(){ return l*b*h;}
        
    friend ostream& operator << (ostream& output, const Box& bo);
    bool operator < (const Box& B){
        if(l<B.l) return true;
        else if(l== B.l && b<B.b) return true;
        else if(h<B.h && b== B.b && l == B.l) return true;
        return false;
    }
};

ostream& operator <<(ostream& output, const Box& bo){
    output<<bo.l<<" "<<bo.b<<" "<<bo.h;
    return output;
}

int main(){
	Box temp(2,4,5);
	Box b(5,6,7);
	cout<<(b<temp);
}
