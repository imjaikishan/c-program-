#include<iostream>

class Image {
int m_x;
int m_y;
int m_width;
int m_height;

public:
// Default constructor
Image();

// Parameterized constructor
Image(int x, int y, int width, int height);

// Copy constructor
Image(const Image& ref);

// Destructor
~Image();

void move(int x, int y);

void scale(int factor);

void resize(int width, int height);

void display() const;
};
Image::Image() : m_x(12), m_y(34), m_width(23), m_height(89) {}
Image::Image(int x, int y, int width, int height) : m_x(x), m_y(y), m_width(width), m_height(height) {}
Image::Image(const Image& ref): m_x(ref.m_x), m_y(ref.m_y), m_width(ref.m_width), m_height(ref.m_height) {}
Image::~Image(){}

void Image::move(int x,int y)
{
    m_x += x;
    m_y += y;
}
void Image::scale(int factor)
{
    m_width *= factor;
    m_height *= factor;
}

void Image::resize(int width,int height)
{
    m_width = width;
    m_height = height;
}

void Image::display() const{
    std::cout << "Image(x=" << m_x << ", y=" << m_y << ", width=" << m_width << ", height=" << m_height << ")" << std::endl;
}

int main() {
// Default constructor
Image img1;
std::cout << "Initial state:" << std::endl;
img1.display();

// Parameterized constructor
Image img2(10, 20, 100, 200);

std::cout << "Image created using parameterized constructor:" << std::endl;
img2.display();

// Copy constructor
Image img3(img2);

std::cout << "Image created using copy constructor:" << std::endl;
img3.display();

std::cout << "Moving image by (15, 40):" << std::endl;
img1.move(15, 40);
img1.display();

std::cout << "Scaling image by factor of 3:" << std::endl;
img1.scale(3);
img1.display();

std::cout << "Resizing image to (800, 600):" << std::endl;
img1.resize(800, 600);
img1.display();

return 0;
}