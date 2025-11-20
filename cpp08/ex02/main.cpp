#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "=== Testing MutantStack ===" << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "MutantStack contents (using iterators):" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    // Test that MutantStack can be copied to std::stack
    std::stack<int> s(mstack);
    std::cout << "Copied to std::stack, size: " << s.size() << std::endl;
    
    std::cout << "\n=== Testing equivalent std::list ===" << std::endl;
    
    // Equivalent test with std::list
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << "Back: " << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << "Size: " << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    
    std::cout << "std::list contents (using iterators):" << std::endl;
    std::list<int>::iterator lit = mlist.begin();
    std::list<int>::iterator lite = mlist.end();
    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    
    std::cout << "\n=== Additional MutantStack Tests ===" << std::endl;
    
    // Test reverse iterators
    std::cout << "MutantStack reverse iteration:" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;
    
    // Test const iterators
    const MutantStack<int> const_mstack(mstack);
    std::cout << "Const MutantStack iteration:" << std::endl;
    for (MutantStack<int>::const_iterator cit = const_mstack.begin(); 
         cit != const_mstack.end(); ++cit)
    {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;
    
    return 0;
}