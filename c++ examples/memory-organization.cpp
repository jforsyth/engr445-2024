#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;

    /**
     * Print out elements of an array to see their address and value
     */
    int array[] = {0xa, 0xb, 0xc, 0xd};

    std::cout << "Address of array[0] " << std::hex << &array[0] << "\t Value of array[0] "<< array[0] << std::endl;
    std::cout << "Address of array[1] " << std::hex << &array[1] << "\t Value of array[1] "<< array[1] << std::endl;
    std::cout << "Address of array[2] " << std::hex << &array[2] << "\t Value of array[2] "<< array[2] << std::endl;
    std::cout << "Address of array[3] " << std::hex << &array[3] << "\t Value of array[3] "<< array[3] << std::endl;

    /**
     * Determine the standard size of objects on this architecture
     */
    std::cout << "Unsigned char is " << sizeof(unsigned char) << " bytes long" << std::endl;
    std::cout << "Unsigned int is " << sizeof(unsigned int) << " bytes long" << std::endl;
    std::cout << "Float is " << sizeof(float) << " bytes long" << std::endl;
    std::cout << "Double is " << sizeof(double) << " bytes long" << std::endl;
    std::cout << "Long long is " << sizeof(long long) << " bytes long" << std::endl;

    /**
     * See how a singular "object" is still an array of bytes
     */
    unsigned int data = 0xabcdef12;
    unsigned int* data_address = &data;
    std::cout << "The object 'data' lives at " << std::hex << data_address << " and is " << sizeof(data) << " bytes long " << std::endl;

    unsigned char* bytePtr = (unsigned char*) &data;
    std::cout << "The lowest byte of data[0] is " << std::hex << (int)bytePtr[0] << std::endl;
    std::cout << "The lowest byte of data[1] is " << std::hex << (int)bytePtr[1] << std::endl;
    std::cout << "The lowest byte of data[2] is " << std::hex << (int)bytePtr[2] << std::endl;
    std::cout << "The lowest byte of data[3] is " << std::hex << (int)bytePtr[3] << std::endl;



    return 0;
}
