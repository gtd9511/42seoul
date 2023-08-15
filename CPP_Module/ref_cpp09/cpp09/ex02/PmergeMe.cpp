#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): hasDuplicate(false), isLeft(false){
    std::cout << "PmergeMe created.\n";
}

PmergeMe::PmergeMe(const PmergeMe &copy) : hasDuplicate(false), nums(copy.nums), duplicateCheck(copy.duplicateCheck), vmainChain(copy.vmainChain), vpendingElements(copy.vpendingElements), dmainChain(copy.dmainChain), dpendingElements(copy.dpendingElements) , leftBehind(copy.leftBehind), isLeft(false){
}


PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
    if(this != &copy){
        hasDuplicate = copy.hasDuplicate;

        std::copy(copy.nums.begin(), copy.nums.end(), this->nums.begin());
        for(std::set<long long>::iterator it = copy.duplicateCheck.begin(); it != copy.duplicateCheck.end(); it++){
            this->duplicateCheck.insert(*it);
        }
        std::copy(copy.vmainChain.begin(), copy.vmainChain.end(), this->vmainChain.begin());
        std::copy(copy.vpendingElements.begin(), copy.vpendingElements.end(), this->vpendingElements.begin());
        std::copy(copy.dmainChain.begin(), copy.dmainChain.end(), this->dmainChain.begin());
        std::copy(copy.dpendingElements.begin(), copy.dpendingElements.end(), this->dpendingElements.begin());
        leftBehind = copy.leftBehind;

    }
    return *this;
}

PmergeMe::~PmergeMe(){

}


// ----- key member functions ----
void PmergeMe::sortCompare(char **str){
    //parse 후에 before print 한다.
    try{
        parse(str);
        printBefore();
        mergeInsertSortUsingVector();
        mergeInsertSortUsingDeque();
    }
    catch (std::exception &e){
        std::cout << e.what();
    }
}

void PmergeMe::parse(char **str){

    validCheckAndSaveARgs(str);
    makeAnswer();

}

void PmergeMe::validCheckAndSaveARgs(char **str){
    //parse 함수에서 호출, duplicateCheck set 이용해서 중복확인, 범위 확인
        //parse 함수에서 호출, duplicateCheck set 이용해서 중복확인, 범위 확인
    long long num = 0;
    int i = 1;
    while(str[i] != NULL){

    std::string expr = str[i];
    unsigned long j = 0;
    while(expr[j] != '\0'){
        num = 0;
        while(expr[j] != '\0' && isdigit(expr[j]))
            num = num * 10 + expr[j++] - '0';
        if(expr[j] != ' ' && j != expr.length())
            throw WrongExpression();
        if(num < 0)
            throw NotPositiveFailure();
        if(duplicateCheck.find(num) != duplicateCheck.end())
            hasDuplicate = true;

        nums.push_back(num);
        duplicateCheck.insert(num);
        if (expr[j] == '\0')
            break;
            j++;
        }
        i++;
    }
}

void PmergeMe::makeAnswer(){
    std::vector<long long> tmp(nums);
    answer = tmp;
    sort(answer.begin(), answer.end());
}

void PmergeMe::printBefore(){

    std::cout << "Before: ";
    for(unsigned long i = 0; i < nums.size(); i++)
        std::cout << nums[i] << " ";

    std::cout << "\n";
    std::cout << "After: ";
    for(unsigned long i = 0; i < answer.size(); i++)
        std::cout << answer[i] << " ";
    std::cout << "\n";

}


int PmergeMe::jacob(int n){
	if(n == 0 || n ==1)
		return n;
	return jacob(n-1) + 2 * jacob(n-2);
}


void PmergeMe::mergeInsertSortUsingVector(){

    clock_t begin = clock();


    pairSort(vmainChain, vpendingElements);
    std::vector<int> insertIndexes = jacobsthalNumbers(vpendingElements.size());
    mergeUsingInsertUsingVector(insertIndexes);


    clock_t end = clock();
    checkCorrectSort(vmainChain);

    double duration = static_cast<double>(end) - static_cast<double>(begin);
    std::setprecision(10);
    std::cout << "Time to process a range of " << nums.size() << " elments with std::vector : " << duration << "\n";

}

void PmergeMe::mergeInsertSortUsingDeque(){

    clock_t begin = clock();


    pairSort(dmainChain, dpendingElements);
    std::vector<int> insertIndexes = jacobsthalNumbers(vpendingElements.size());
    mergeUsingInsertUsingDeque(insertIndexes);

    clock_t end = clock();

    checkCorrectSort(dmainChain);

    double duration = static_cast<double>(end) - static_cast<double>(begin);
    std::setprecision(10);
    std::cout << "Time to process a range of " << nums.size() << " elments with std::deque: " << duration << "\n";
}

void PmergeMe::mergeUsingInsertUsingVector(std::vector<int>indexes){

    std::cout << "index size: " << indexes.size() << "\n";
    for(unsigned long i = 0; i < indexes.size(); i++){
        int cur = indexes[i] - 1;
	    std::vector<long long >::iterator pos = std::upper_bound(vmainChain.begin(), vmainChain.end(), vpendingElements[cur]);
        if (pos == vmainChain.end())
			vmainChain.push_back(vpendingElements[cur]);
		else
			vmainChain.insert(pos, vpendingElements[cur]);
    }
}

void PmergeMe::mergeUsingInsertUsingDeque(std::vector<int>indexes){
    for(unsigned long i = 0; i < indexes.size(); i++){

        int cur = indexes[i] -1;
	    std::deque<long long>::iterator pos = std::upper_bound(dmainChain.begin(), dmainChain.end(), dpendingElements[cur]);
        if (pos == dmainChain.end())
			dmainChain.push_back(dpendingElements[cur]);
		else
			dmainChain.insert(pos, dpendingElements[cur]);
    }
}


// -- jacobsthal numbers---
int PmergeMe::jacobsthal(int n){
	if(n == 0 || n == 1){
        return n;
    }
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<int> PmergeMe::jacobsthalNumbers(int len){

    if (len <= 1){
        std::vector<int> tmp;
        return tmp;
    }

    std::queue<int> jacobN;
    bool endFlag = false;
    int i = 2;
    while(!endFlag) {
        int idx = jacob(++i);
        if(idx > len)
            endFlag = true;
        jacobN.push(idx);

    }
    //after getting jacobsthal number, should make the indexes in a row:
    std::vector<int> indexes;
    std::set<int> usedIndexes;
    indexes.push_back(1);
    usedIndexes.insert(1);
    int idx = 1;
    while(true)
    {
        if (usedIndexes.find(idx) == usedIndexes.end())//did not find in usedIndex
        {
            indexes.push_back(idx);
            usedIndexes.insert(idx);
            idx--;
        }
        else
        {
            if(jacobN.empty())
                break;
            idx = jacobN.front();
            if(idx > len)
                idx = len;
            jacobN.pop();
        }
    }
    return indexes;
}

//---error handling---
const char *PmergeMe::NotPositiveFailure::what() const throw ()
{
    return "there is a non-positive number.\n";
}

const char *PmergeMe::WrongSortFailure::what() const throw ()
{
    return "wrong sort\n";
}

const char *PmergeMe::WrongExpression::what() const throw ()
{
    return "wrong expression\n";
}










