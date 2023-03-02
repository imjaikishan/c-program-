#include <iostream>
#include <cstring>
using namespace std;

class Phone
{
	private:
		/*Member Variables*/
		int screenWidth;
		int screenHeight;
		int refreshRate;
	public:
		/*Constructors and Destructor*/
		Phone(); //default
		Phone(int var1, int var2, int var3); //param
		Phone(const Phone &ob1); //copy
		~Phone();
		
		/*Member Functions*/		
		/*Setter Methods*/
		int setHz(int varHz); 
		void setPhone(int var1, int var2, int var3);
		
		/*Getter Methods*/	
		/*DO NOT Delete/Edit the function signatures/definitions*/
		int getscreenWidth();
		int getscreenHeight();
		int getHz();
		Phone& getPhone();
		
		/*Addditional Member Methods*/
		void displayPhone();
		int aspectRatio();

		/*Operator Overloading*/
		int operator+(); //Udpate RefreshRate by 10
    	friend Phone operator>(Phone& ob1, Phone& ob2); //comaparing phone Aspect Ratio
}; 

Phone::Phone():screenWidth(2200),screenHeight(1400),refreshRate(120){}
Phone::Phone(int var1,int var2, int var3):screenWidth(var1),screenHeight(var2),refreshRate(var3){}
Phone::Phone(const Phone &ob1):screenWidth(ob1.screenWidth),screenHeight(ob1.screenHeight),refreshRate(ob1.refreshRate){}
Phone::~Phone(){}
int Phone::setHz(int varHz){
    if (varHz>=1 && varHz<241){
        refreshRate=varHz;
        return 1;
    }
    else{
        refreshRate=240;
        return 0;
    }
}
void Phone::setPhone(int var1, int var2, int var3){
    if (var1>1599 && var1<2201){
        screenWidth=var1;
    }
    if (var2>999 && var2<1401){
        screenHeight=var2;
    }
    if (var3>0 && var3<241){
        refreshRate=var3;
    }
}
int Phone::getscreenWidth(){
    return screenWidth;
}

int Phone::getscreenHeight(){
    return screenHeight;
}
int Phone::getHz(){
    return refreshRate;
}

Phone& Phone::getPhone(){
    return *this;
}

void Phone::displayPhone(){
    cout<<screenWidth<<","<<screenHeight<<","<<refreshRate<<"\n";
}
int Phone::aspectRatio(){
    int ar=screenWidth/screenHeight;
    return ar;
}
int Phone::operator+(){ 
    int res=refreshRate+10;
    if(res>0 && res<241){
        return 1;
    }
    else{
        return 0;
    }
}

Phone operator>(Phone& ob1, Phone& ob2){
    if (ob1.aspectRatio() > ob2.aspectRatio()){
        return ob1;
    }
    else if(ob1.aspectRatio() < ob2.aspectRatio()){
        return ob2;
    }
    else{
        return ob1;
    }
}

int main()
{   
    int sW, sH, rR, hZ;
    std::cin >> sW >> sH >> rR; 
    Phone object2(sW, sH, rR); 
    Phone object6(object2);
    object6.displayPhone(); 

    Phone ob1;   
    std::cin >> hZ; 
    int  a = ob1.setHz(hZ);
    ob1.displayPhone();

    Phone objectX;   
    std::cin >> sW >> sH >> rR; 
    objectX.setPhone(sW, sH, rR);
    objectX.displayPhone();

    Phone objectQ;
    std::cin >> sW >> sH >> rR; 
    objectQ.setPhone(sW, sH, rR);
    objectQ.displayPhone(); 

    Phone objectY;  
    std::cin >> sW >> sH >> rR; 
    objectY.setPhone(sW, sH, rR); 
    int i = objectY.operator+();
    std::cout << i <<"\n"; 

    Phone objectZ;   
    std::cin >> sW >> sH >> rR;  
    objectZ.setPhone(sW, sH, rR); 
    int m = objectZ.operator+();
    std::cout << m <<"\n";   

    std::cin >> sW >> sH >> rR; 
    Phone objectA(sW, sH, rR);   
    std::cin >> sW >> sH >> rR; 
    Phone objectB(sW, sH, rR);   
    Phone ob5;
    ob5 = operator>(objectA, objectB);
    ob5.displayPhone();    

    std::cin >> sW >> sH >> rR; 
    Phone objectC(sW, sH, rR);   
    std::cin >> sW >> sH >> rR; 
    Phone objectD(sW, sH, rR);    
    Phone obCD;
    obCD = operator>(objectC, objectD);
    obCD.displayPhone(); 
    
    return 0;
}