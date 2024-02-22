/**
 * #include adds the <iostream> library so information can be read to/from the terminal
 */

#include <iostream>

/**
 * Main() is where all programs begin. There can only be one main() in any c++ project.
 * If you attempt to have multiple "programs" in the project the compiler will not understand
 *
 * Main() is the entirety of the program. Once it ends (return 0) the program ends
 */
int main()
{
    std::cout << "Hello, World!" << std::endl;

    /**
     * Final call from the program before ending. The return value is typically used as an "error code"
     * A return of 0 may be indicate normal/typical whereas other numbers (especially -1) indicate an error
     */

    return 0;
}
