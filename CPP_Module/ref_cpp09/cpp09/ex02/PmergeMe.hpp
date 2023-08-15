#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <sstream>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>


class PmergeMe {
private:
        bool hasDuplicate;
        std::vector<long long> nums; //args 저장
        std::vector<long long> answer; //정렬한 정답
        std::set<long long> duplicateCheck; //중복 확인(에러핸들링은 따로 안함)
        std::vector<long long> vmainChain;//vector용
        std::vector<long long> vpendingElements;
        std::deque<long long> dmainChain;//deque 용
        std::deque<long long> dpendingElements;
        long long leftBehind;
        bool isLeft;


        class NotPositiveFailure: public std::exception{
                virtual const char *what(void) const throw();
        };
        class WrongSortFailure: public std::exception{
                virtual const char *what(void) const throw();
        };
        class WrongExpression: public std::exception{
                virtual const char *what(void) const throw();
        };



        int jacobsthal(int n);
        std::vector<int> jacobsthalNumbers(int len);
        int jacob(int n);
        void printBefore();
        void makeAnswer();
        void parse(char ** str); //int main에서 받아와서 파싱
        void validCheckAndSaveARgs(char **str);//parse 함수에서 호출, duplicateCheck set 이용해서 중복확인, 범위 확인

        void mergeInsertSortUsingVector();//vector 를 이용한.
        void mergeInsertSortUsingDeque();//deque 를 이용한 정렬.

        void mergeUsingInsertUsingVector(std::vector<int>indexes); //merge : vector 버전
        void mergeUsingInsertUsingDeque(std::vector<int>indexes);//merge: deque 버전

        template<typename T> void pairSort(T &mainChain, T& pendingElements); //처음 mainChain, pendingElements 로 나눔
        template<typename T>void checkCorrectSort(T& arr);//sort 되었는지 answer와 비교
       

public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();
        void sortCompare(char **str);

};

template<typename T> 
void swap(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
}

template<typename T> 
void PmergeMe::pairSort(T &mainChain, T& pendingElements){
        //nums를 쌍 별로 우선 큰 원소가 왼쪽으로 오게 정렬
        if(nums.size() % 2 == 1){
                isLeft = true;
                leftBehind = nums.back();
        }

        for(unsigned long i = 0; i < nums.size() - 1; i+=2){
                mainChain.push_back(nums[i]);
                pendingElements.push_back(nums[i+1]);
        }
        
        for(unsigned long i = 0; i < mainChain.size(); i++){
                for(unsigned int j = 0; j < mainChain.size() - 1 - i; j++){
                        if(mainChain[j] > mainChain[j+1]){
                                swap(mainChain[j], mainChain[j+1]);
                                swap(pendingElements[j], pendingElements[j+1]);
                        }
                }
        }
        // std::cout << "mainchain\n";
        // for(unsigned long i = 0; i < mainChain.size(); i++){
        //         std::cout << mainChain[i] << " ";
        // }
        // std::cout << "\n";

        // std::cout << "pending elements\n";
        // for(unsigned long i = 0; i < pendingElements.size(); i++){
        //         std::cout << pendingElements[i] << " ";
        // }
        // std::cout << "\n";
        if(isLeft)
                pendingElements.push_back(leftBehind);

}

template<typename T> 
void PmergeMe::checkCorrectSort(T &arr){
        for(unsigned long i = 0; i < answer.size(); i++){
                if (arr[i] != answer[i])
                        throw WrongSortFailure();
        }
        std::cout << "sort Success!!\n";
}
#endif