#include "MutantStack.hpp"

int main()
{
    {
        std::cout << "-----------------test1----------------\n";
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
    
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);
    }
    {
        std::cout << "\n------------------------test2-------------------------\n";
        std::cout << "list\n";
        std::list<int> mlist;
        mlist.push_back(5);
        mlist.push_back(17);
        std::cout << mlist.back() << std::endl;
        mlist.pop_back();
        std::cout << mlist.size() << std::endl;
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
    
        mlist.push_back(0);
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::list<int> s(mlist);

    }
     {
        std::cout << "\n------------------------test3-------------------------\n";
        std::cout << "deque\n";
        std::deque<int> mdeque;
        mdeque.push_back(5);
        mdeque.push_back(17);
        std::cout << mdeque.back() << std::endl;
        mdeque.pop_back();
        std::cout << mdeque.size() << std::endl;
        mdeque.push_back(3);
        mdeque.push_back(5);
        mdeque.push_back(737);
    
        mdeque.push_back(0);
        std::deque<int>::iterator it = mdeque.begin();
        std::deque<int>::iterator ite = mdeque.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::deque<int> s(mdeque);
    }
    {
        std::cout << "\n------------------------test4-------------------------\n";
        std::cout << "vector\n";
        std::vector<int> mvector;
        mvector.push_back(5);
        mvector.push_back(17);
        std::cout << mvector.back() << std::endl;
        mvector.pop_back();
        std::cout << mvector.size() << std::endl;
        mvector.push_back(3);
        mvector.push_back(5);
        mvector.push_back(737);
    
        mvector.push_back(0);
        std::vector<int>::iterator it = mvector.begin();
        std::vector<int>::iterator ite = mvector.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::vector<int> s(mvector);
    }
    {
        std::cout << "\n------------------------test5-------------------------\n";
        MutantStack<long long> mstack;
        srand(time(NULL));
        for(int i = 0; i < 10; i++){
            mstack.push(i);
        }
        MutantStack<long long>::iterator it = mstack.begin();
        MutantStack<long long>::iterator ite = mstack.end();
        while(it != ite){
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
        std::cout << mstack.empty() << std::endl;
        std::cout << mstack.size() << std::endl;
        std::cout << *(mstack.begin()) << std::endl;

        MutantStack<long long>copy;
        copy = mstack;
        std::cout << copy.empty() << std::endl;
        std::cout << copy.size() << std::endl;
        std::cout << *(copy.begin()) << std::endl;

        std::cout << "copy test\n";
        *(mstack.begin()) = 100;
        std::cout << "mstack begin : " << *mstack.begin() << std::endl;
        std::cout << "copy begin: " <<*copy.begin() << std::endl;


    }
    {
        std::cout << "\n------------------------test6-------------------------\n";
        MutantStack<long long, std::vector<long long> > mstack;
        srand(time(NULL));
        srand(time(NULL));
        for(int i = 0; i < 10; i++){
            mstack.push(rand() % 100);
        }
        MutantStack<long long , std::vector<long long> >::reverse_iterator it = mstack.rbegin();
        MutantStack<long long, std::vector<long long> >::reverse_iterator ite = mstack.rend();
        while(it != ite){
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
        mstack.pop();
        mstack.pop();
        it = mstack.rbegin();
        ite = mstack.rend();
        while(it != ite){
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;

        
    }
    return 0;
}