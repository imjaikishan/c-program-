#include<iostream>
typedef enum { 
   red,
   green,
   blue
};
class Color {
    int m_r; 
    int m_g;
    int m_b;   
public:
    void init(int red,int green,int blue)
    {
        m_r=red;
        m_g=green;
        m_b=blue;
    }   
    // Invert the color by subtracting each value from 255
    void invert() {
        m_r = 255 - m_r;
        m_g = 255 - m_g;
        m_b = 255 - m_b;
    }    
    // Display the color values
    void display() const {
        std::cout << "Color (R,G,B) = (" << m_r << "," << m_g << "," << m_b << ")" << std::endl;
    }
};
int main()
{
    Color cl;
    cl.init(25,23,67);
    cl.display();
    cl.invert();
    std::cout << "After invert function called:\n";
    cl.display();
    return 0;
}