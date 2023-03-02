#include <iostream>
#include <cstdint>
#include <cstdbool>
enum IPClass {
    A,
    B,
    C,
    D
};

class IPAddress {
    uint32_t ipval;
    
public:

    void init(uint32_t ipvalue)
    {
        ipval=ipvalue;
    }
    // Check if the IP address is loopback (127.0.0.1)
    bool isLoopBack() const {
        return (ipval & 0xFF000000) == 0x7F000000;
    }
    
    // Determine the IP class based on the first octet
    IPClass getIPClass() const {
        uint8_t octet1 = (ipval & 0xFF000000) >> 24;
        if (octet1 < 128) {
            return A;
        } else if (octet1 < 192) {
            return B;
        } else if (octet1 < 224) {
            return C;
        } else {
            return D;
        }
    }
    
    // Display the IP address in dot-decimal notation
    void display() const {
        std::cout << ((ipval >> 24) & 0xFF) << "."
                  << ((ipval >> 16) & 0xFF) << "."
                  << ((ipval >> 8) & 0xFF) << "."
                  << (ipval & 0xFF) << std::endl;
    }
};

int main() {
    // Create an IP address object with initial value
    IPAddress myIP;  // 192.168.1.1
    myIP.init(0xC0A80101);
    // Display the IP address in dot-decimal notation
    std::cout << "IP address: ";
    myIP.display();
    
    // Check if the IP address is loopback
    if (myIP.isLoopBack()) {
        std::cout << "This is a loopback address." << std::endl;
    } else {
        std::cout << "This is not a loopback address." << std::endl;
    }
    
    // Determine the IP class and display it
    IPClass ipClass = myIP.getIPClass();
    std::cout << "IP class: ";
    switch (ipClass) {
        case A:
            std::cout << "Class A" << std::endl;
            break;
        case B:
            std::cout << "Class B" << std::endl;
            break;
        case C:
            std::cout << "Class C" << std::endl;
            break;
        case D:
            std::cout << "Class D" << std::endl;
            break;
    }
    
    return 0;
}
