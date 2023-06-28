# C++ Standard Template Library (STL) Container Types
This project involves implementing various container types of the C++ Standard Template Library (STL). Each container is implemented in its own class file and is tested using ft::<container>. The project is coded in C++98, and all features, including deprecated ones, are expected to be implemented.

## Implementation Details
Two binaries are produced for testing: one with the implemented containers and one with STL containers.<br>
Outputs and timing of the two binaries are compared. The implemented containers can be up to 20 times slower.<br>
Member functions, non-member functions, and overloads have been implemented.<br>
Naming conventions and details have been respected.<br>
std::allocator has been used.<br>
Inner data structure for each container has been justified.<br>
If the container has an iterator system, it has been implemented.<br>
iterators_traits, reverse_iterator, enable_if, is_integral, equal/lexicographical compare, std::pair, std::make_pair, have been reimplemented.<br>
https://www.cplusplus.com/ and https://cppreference.com/ have been used as references.<br>
No more public functions than the ones offered in the standard containers have been implemented. Everything else is private or protected. Each public function/variable has been justified.<br>
For non-member overloads, the keyword friend has been used. Each use of friend has been justified and will be checked during evaluation.<br>

## Useful resources <br>

### Understanding iterators:

This link has a good graphic representation of begin, end, rbegin, rend: <br>
https://stackoverflow.com/questions/34830192/what-doesone-past-the-last-element-mean-in-vectors<br>
<br>
Const overloading:<br>
https://leimao.github.io/blog/CPP-Const-Overloading/<br>
<br>
Script for time:<br>
https://unix.stackexchange.com/questions/52313/how-to-get-execution-time-of-a-script-effectively<br>
