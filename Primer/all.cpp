//  Created by Supertoy on 03/09/2019.
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#include <regex>
#include <new>
//#include <typeinfo>
#include <array>
#include <forward_list>
#include <memory>
//#include <cstdlib>
//#include <iterator>
//#include <random>
#include <functional>
//#include <bitset>
//#include <cstring>
//#include <cassert>
#include <fstream>
#include <sstream>

//#define NDEBUG

#include "Sales_data.h"

//#include "Sales_item.h"

using std::cin;
using std::cout; using std::endl; using std::cerr;
using std::string;
using std::vector;
using std::begin;
using std::end;
using std::runtime_error;
using std::initializer_list;

using namespace std::placeholders;

// 8.7 - 8.8
//int main (int argc, char *argv[]) {
//    cout << "Getting input from: "  << argv[1] << endl;
//    std::ifstream in(argv[1]);
//
//    cout << "Will put the output in: "  << argv[2] << endl;
//    std::ofstream out;
//    out.open(argv[2], std::ofstream::app);
//
//    Sales_data total;
//    if (read(in, total)) {
//        Sales_data trans;
//        while (read(in, trans)) {
//            if (total.isbn() == trans.isbn()) {
//                total.combine(trans);
//            }
//            else {
//                print(out, total);
//                total = trans;
//            }
//        }
//        print(out, total);
//    }
//    else
//        cerr << "No data dude!" << endl;
//    return 0;
//}

//std::istream& foo(std::istream &is) {
//    std::string contain;
//    while (is >> contain) {
//        cout << contain << endl;
//    }
//    is.clear();
//    return is;
//}


// Ex 8.9-8.10
//void lines2vec(std::ifstream &inf, vector<string> vec) {
//    string line;
//    while (getline(inf,line)) {
//        vec.push_back(line);
//    }
//}
//int main(int argc, char **argv) {
//    std::ifstream in_file(argv[1], std::ifstream::in);
//    cout << "Will get my lines from the: " << argv[1] << endl;
//
//    vector<string> lines;
//
//    for (string line; getline(in_file, line); lines.push_back(line)) {}
//
//    for (const string &i : lines) {
//        std::istringstream line(i);
//        string word;
//        while (line >> word) {
//            cout << word << endl;
//        }
//    }
//}

// Ex 8.11

//struct Person {
//    string name;
//    vector<string> phones;
//};
//
//int main() {
//    string line, word;
//    std::istringstream record;
//    vector<Person> people;
//    while (getline(cin, line)) {
//        Person info;
//        record.clear();
//        record.str(line);
//        record >> info.name;
//        while (record >> word) {
//            info.phones.push_back(word);
//        }
//        people.push_back(info);
//    }
//    cout << "Output:" << endl;
//    for (Person p : people) {
//        cout << p.name << " ";
//        for (string i : p.phones)
//            cout << i << " ";
//        cout << endl;
//    }
//}

// Ex 8.12
//struct Person {
//    string name;
//    vector<string> phones;
//};
//
//int main(int argc, char *argv[]) {
//    string line, word;
//    vector<Person> people;
//    std::ifstream in_file(argv[1]);
//
//    while (getline(in_file, line)) {
//        Person info;
//        std::istringstream record(line);
//        record >> info.name;
//        while (record >> word) {
//            info.phones.push_back(word);
//        }
//        people.push_back(info);
//    }
//
//
//
//    cout << "Output:" << endl;
//    for (Person p : people) {
//        cout << p.name << " ";
//        for (string i : p.phones)
//            cout << i << " ";
//        cout << endl;
//    }
//}

//struct Foo {
//    Foo() : Foo("BAR") {}
//    Foo(string n) : name(n) {}
//    const string get_name() {
//        return name;
//    }
//private:
//    string name;
//};

//bool isequal(const vector<int> &a, const vector<int> &b) {
//    return a == b;
//}
//bool isequal(const std::list<int> &a, const std::list<int> &b) {
//    return a == b;
//}
//bool isequal(const std::deque<int> &a, const std::deque<int> &b) {
//    return a == b;
//}
// Ex 9.15-9.16
//bool isequal(const std::list<int> &l, const std::vector<int> &v) {
//    auto lb = l.cbegin();
//    auto le = l.cend();
//    auto vb = v.cbegin();
//    auto ve = v.cend();
//    for (; (lb != le) && (vb != ve); ++vb, ++lb) {
//        cout << *vb << " " << *lb << endl;
//        if (*lb != *vb)
//            return false;
//    }
//    return true;
//}

//int main () {
//    vector<int>::const_reverse_iterator cri;
//    const vector<int> vi = {1,2,3,4,5};
//    auto i = ++vi.cbegin();
//    std::list<int> li(i, vi.cend());
//    for (auto i : li) {
//        cout << i << endl;
//    }
//    string x = "DUH";
//    std::list<Foo> lf(3, x);
//    for (auto i : lf) {
//        cout << i.get_name() << endl;
//    }
//
//    std::array<Foo, 2> ai;
//    std::array<Foo, 2> ai2 = ai;
//    cout << ai2[1].get_name() << endl;
//
//
//    Ex 9.13
//    std::list<int> li = {1,2,3,4,5,6,7};
//    std::vector<int> vi = {11,22,33,44,55,66,77};
//
//    vector<double> vd1(vi.begin(), vi.end());
//    vector<double> vd2(li.begin(), li.end());
//
//    vd1 = vd2;
//
//    vd2 = {100,200,300};
//    swap(vd1, vd2);
//    cout << vd1[1] << " " << vd1[2] << endl;
//    Ex 9.14
//    std::list<const char*> lca = {"abc", "xyz"};
//    vector<string> vs;
//    vs.assign(lca.begin(), lca.end());
//    cout << vs[1] << endl;
//    vector<int> v1 = {1,2,3,4};
//    std::list<int> l1 = {1,2,4};
//    cout << isequal(l1, v1) << endl;
//}

//  Ex 9.18-9.19
//int main() {
//    string word;
//    std::list<string> dqs;
//    while (cin >> word) {
//        dqs.push_front(word);
//    }
//    for (auto s : dqs) {
//        cout << s << " ";
//    }
//    cout << endl;
//}

// Ex 9.20
//int main() {
//    std::list<int> li = {1,2,3,4,5,6,7,8,9};
//    std::deque<int> odd;
//    std::deque<int> even;
//    for (const int &i : li) {
//        if (i % 2 == 0) {
//            even.push_back(i);
//        } else {
//            odd.push_back(i);
//        }
//    }
//    cout << "Odd: ";
//    for (auto i : odd) {
//        cout << i << " ";
//    }
//    cout << "\nEven: ";
//    for (auto i : even) {
//        cout << i << " ";
//    }
//    cout << endl;
//}

// Ex 9.22
//int main() {
//    vector<int> iv = {1,2,3,4,5,6,7};
//    const int some_val = 3;
//
//    vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;
//    while (iter != mid) {
//      if (*iter == some_val) {
//        iv.insert(iter, 2 * some_val);  // Error, we should update the iter
//        iter = iv.insert(iter, 2 * some_val);
//        ++iter;  // Increament to point to the original value
//      }
//      ++iter;  // Increment to point to the next value
//    }
//    for (int i : iv) {
//        cout << i << " ";
//    }
//    cout << endl;
//
//}

// Ex 9.26
//int main()
//{
//    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
//
//    vector<int> iv(ia, end(ia));
//    std::list<int> il(iv.begin(), iv.end());
//
//    for(std::list<int>::iterator i = il.begin(); i != il.end();) {
//        if (!(*i % 2))
//            i = il.erase(i);
//        else
//            ++i;
//    }
//
//    for(vector<int>::iterator i = iv.begin(); i != iv.end();) {
//        if (*i % 2)
//            i = iv.erase(i);
//        else
//            ++i;
//    }
//
//    for (auto i : il)
//        cout << i << " ";
//    cout << endl;
//
//    for (auto i : iv)
//        cout << i << " ";
//    cout << endl;
//}
// Ex 9.27
//int main() {
//    std::forward_list<int> fli = {1,2,3,4,5,6,7,8,9};
//    auto prev = fli.before_begin();
//    auto curr = fli.begin();
//    while (curr != fli.end()) {
//        if (*curr % 2)
//            curr = fli.erase_after(prev);
//        else {
//            ++curr;
//            ++prev;
//        }
//    }
//    for (auto i : fli)
//        cout << i << " ";
//    cout << endl;
//}

// Ex 9.28
//void inflist(std::forward_list<string> &fls, const string &find_me, const string &insert_me) {
//    std::forward_list<string>::iterator curr = fls.begin();
//    std::forward_list<string>::iterator prev = fls.before_begin();
//    bool flag_not_found = true;
//    while (curr != fls.end()) {
//        if (*curr == find_me) {
//            fls.insert_after(curr, insert_me);
//            flag_not_found = false;
//        }
//        prev = curr;
//        ++curr;
//    }
//    if (flag_not_found)
//        fls.insert_after(prev, insert_me);
//}
//
//int main() {
//    const string s1 = "mama", s2 = "bar";
//    std::forward_list<string> my_list = {"abc","def","ghi","foo","jkl","nmo"};
//    inflist(my_list, s1, s2);
//    for (auto i : my_list)
//        cout << i << " ";
//    cout << endl;
//}
// Ex 9.31
//int main () {
//    std::vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
//    auto iter = vi.begin();
//    while (iter != vi.end()) {
//        if (*iter % 2) {
//            iter = vi.insert(iter, *iter); // cant *iter++ because the assignment will override the postfix inc
//            iter += 2; // list and forward_list don't have iterator arithmetic
//        } else
//            iter = vi.erase(iter);
//    }
//    for (auto i : vi)
//        cout << i << " ";
//    cout << endl;
//}
//int main () {
//    std::forward_list<int> fli = {0,1,2,3,4,5,6,7,8,9};
//    auto iter = fli.begin(),
//    prev = fli.before_begin();
//    while (iter != fli.end()) {
//        if (*iter % 2) {
//            iter = fli.insert_after(prev, *iter);
//            prev = iter;
//            ++iter; // list and forward_list don't have iterator arithmetic
//        } else {
//            iter = fli.erase_after(prev);
//            ++prev;
//        }
//    }
//    for (auto i : fli)
//        cout << i << " ";
//    cout << endl;
//}
//int main () {
//    std::vector<int> vi;
//    for (int i = 0; i != 24; ++i)
//        vi.push_back(i);
//    cout << vi.size() << endl;
//    cout << vi.capacity() << endl;
//    vi.reserve(100);
//    cout << vi.size() << endl;
//    cout << vi.capacity() << endl;
//    while (vi.size() != vi.capacity())
//        vi.push_back(0);
//    cout << vi.size() << endl;
//    cout << vi.capacity() << endl;
//    vi.push_back(1);
//    cout << vi.size() << endl;
//    cout << vi.capacity() << endl;
//    vi.shrink_to_fit();
//    cout << vi.size() << endl;
//    cout << vi.capacity() << endl;
//}

// Ex 9.41
//int main () {
//    vector<char> vecc = {'f','o','o'};
//    const char *cp = &vecc[0];
//    const string::size_type ssize = vecc.size();
//
//    string str (cp, ssize);
//
//    cout << str << endl;
//    return 0;
//}



// Ex 9.43-9.44
//void exchanger(string &s, const string &oldVal, const string &newVal) {
//    string::const_iterator iter = s.cbegin();
//    while (iter != s.cend())
//        if (*iter == oldVal[0]) {
//            string::const_iterator started_at = iter;
//            iter += 1;
//            string::const_iterator old_iter = (oldVal.cbegin() + 1);
//            while (old_iter != oldVal.cend()) {
//                if (*iter == *old_iter) {
//                    ++iter;
//                    ++old_iter;
//                    continue;
//                }
//                else {
//                    ++iter;
//                    break;
//                }
//            }
//            s.erase(started_at, iter);
//            s.insert(started_at, newVal.begin(), newVal.end());
//        }
//        else {
//            ++iter;
//        }
//}
//
//void exchanger_index(string &s, const string &oldVal, const string &newVal) {
//    string::size_type i = 0;
//    while (i != s.size()) {
//        if (s[i] == oldVal[0]) {
//            string::size_type saved_i = i, j = 1;
//            ++i;
//            while (s[i] != (oldVal.size() + saved_i)) {
//                if (s[i] == oldVal[j]) {
//                    ++j;
//                    ++i;
//                }
//                else {
//                    ++i;
//                    break;
//                }
//            }
//            s.erase(saved_i, oldVal.size());
//            s.insert(saved_i, newVal);
//        }
//        else {
//            ++i;
//        }
//    }
//}
//int main () {
//    string s1 = "Try to change my foo, dude!";
//    string foo = "my foo";
//    string bar = "BAROKKO";
//    exchanger_index(s1, foo, bar);
//    cout << s1 << endl;
//}


// Ex 9.45 - 9.46
//void addsuffix(string &name, const string &prefix, const string &suffix) {
//    const string spaced_prefix = prefix + " ",
//    spaced_suffix = " " + suffix;
//    name.append(spaced_suffix);
//    name.insert(name.cbegin(), spaced_prefix.cbegin(), spaced_prefix.cend());
//}
//
//void addsuffix_index(string &name, const string &prefix, const string &suffix) {
//    const string spaced_prefix = prefix + " ",
//    spaced_suffix = " " + suffix;
//    name.insert(0, spaced_prefix);
//    name.insert(name.size(), spaced_suffix);
//}
//
//int main() {
//    string my_name = "John";
//    string pref = "Dr.";
//    string suf = "'The Booba'";
//    addsuffix_index(my_name, pref, suf);
//    cout << my_name << endl;
//    return 0;
//}


// Ex 9.47
//vector<vector<char>> findAlphaDig(const string &str) {
//    // Should've been use regex here, but no can do for now!
//    const string digits("0123456789");
//    const string letters("abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ");
//
//    // Intermediate and final return containers
//    vector<vector<char>> ret;
//    std::vector<char> digs;
//    std::vector<char> lets;
//
//    string::size_type pos = 0;
//
//    // Searching for digits
//    // Not considering +, -, ., e, E, 0x, 0X
//    while ((pos = str.find_first_of(digits, pos)) != string::npos) {
//        digs.push_back(str[pos]);
//        ++pos;
//    }
//
//    // Reset the position
//    // Search for letters, both upper and lower case
//    pos = 0;
//    while ((pos = str.find_first_of(letters, pos)) != string::npos) {
//        lets.push_back(str[pos]);
//        ++pos;
//    }
//
//    // Prepare the return vector
//    ret.push_back(digs);
//    ret.push_back(lets);
//    return ret;
//}
//// Ex 9.48
//vector<vector<char>> findAlphaDig_notOf(const string &str) {
//    // Should've been use regex here, but no can do for now!
//    const string digits("0123456789");
//    const string letters("abcdefghijklnmopqrstuvwxyzABCDEFGHIJKLNMOPQRSTUVWXYZ");
//
//    // Intermediate and final return containers
//    vector<vector<char>> ret;
//    std::vector<char> digs;
//    std::vector<char> lets;
//
//    string::size_type pos = 0;
//
//    // Searching for digits
//    // Not considering +, -, ., e, E, 0x, 0X
//    while ((pos = str.find_first_not_of(letters, pos)) != string::npos) {
//        digs.push_back(str[pos]);
//        ++pos;
//    }
//
//    // Reset the position
//    // Search for letters, both upper and lower case
//    pos = 0;
//    while ((pos = str.find_first_not_of(digits, pos)) != string::npos) {
//        lets.push_back(str[pos]);
//        ++pos;
//    }
//
//    // Prepare the return vector
//    ret.push_back(digs);
//    ret.push_back(lets);
//    return ret;
//}
//
//int main () {
//    const string foo("ab2c3d7R4E6");
//    vector<vector<char>> bar = findAlphaDig_notOf(foo);
//    for (auto i : bar) {
//        for (auto j : i)
//            cout << j << " ";
//        cout << endl;
//    }
//}
// Ex 9.48
//int main() {
//    string numbers("0123456789"), name("r2d2");
//    // Returns string::npos
//    cout << numbers.find(name) << endl;
//}


// Ex 9.49
//bool gotForbidden(const string &s) {
//    const string forbidden("tflkbdqypgji");
//    return (s.find_first_of(forbidden) == string::npos) ? false : true;
//}
//string longestNoAscend(std::ifstream &inputFileStream) {
//    string currString;
//    string longestString;
//    string::size_type topLength = 0;
//    while (inputFileStream >> currString) {
//        if (!gotForbidden(currString)) {
//            string::size_type currLength = currString.length();
//            if (currLength > topLength) {
//                longestString = currString;
//                topLength = currLength;
//            }
//        }
//    }
//    return longestString;
//}
//int main () {
//    // Hardcoded file for agility
//    string filename("/Users/supertoy/Documents/python_play/think/words.txt");
//    std::ifstream inf(filename);
//    const string result = longestNoAscend(inf);
//    cout << "The result is: " <<  result << "\n" << std::flush;
//}

// Ex 9.50
//int sumStrInt(const vector<string> &svec);
//long double sumStrD(const vector<string> &svec);
//
//int main() {
//    const vector<string> ints = {"1","2","3"};
//    const vector<string> floats = {"1.1243","2.135153","3.141592"};
//
//    cout << "Int: " << sumStrInt(ints) << endl;
//    cout << "Floats: " << sumStrD(floats) << endl;
//}
//
//int sumStrInt(const vector<string> &svec) {
//    int i = 0, sum = 0;
//    for (const string &s : svec) {
//        i = stoi(s);
//        sum += i;
//    }
//    return sum;
//}
//
//long double sumStrD(const vector<string> &svec) {
//    double i = 0, sum = 0;
//    for (const string &s : svec) {
//        i = stold(s);
//        sum += i;
//    }
//    return sum;
//}


// Ex 9.51
//struct Date {
//    Date (unsigned d, unsigned m, unsigned y) : day(d), month(m), year(y) {
//        cout << "Used three arguments constructor" << endl;
//    }
//    Date (string stringDate) : day(fromString(stringDate)[0]), month(fromString(stringDate)[1]), year(fromString(stringDate)[2]) {}
//    // Default constructor
//    Date () : Date(01, 01, 1970) {}
//    unsigned day, month, year;
//private:
//    // Auxilary function for numeric string constructor
//    vector<unsigned> fromString(const string &str) {
//        char delimiters[] = {'.', '/', '-', '\0'};
//        std::vector<unsigned> ret;
//
//        // Init i with the first valid numeric date value
//        string::size_type i = str.find_first_not_of(delimiters);
//
//        // Start iterating over the string
//        while ((i = str.find_first_not_of(delimiters, i)) != string::npos) {
//            auto j = std::stoi(str.substr(i));
//            ret.push_back(j);
//            i = str.find_first_of(delimiters, i);
//        }
//        return ret;
//    }
//};
//
//int main() {
//    string s("11/22/1990");
//    Date date1(s);
//    Date date2;
//    cout << date1.year << endl;
//    cout << date2.year << endl;
//}

//int main () {
////    string s("foobar");
////    if (s.begin() != s.end())
////        *s.begin() = toupper(*s.begin());
////    cout << s << endl;
////
////    ptrdiff_t pd;
////    string::size_type sst;
////    vector<int>::size_type vecist;
////    vector<int>::difference_type vecidt;
////    vector<int>::const_iterator vecCiter;
//    int arr[] = {1,2,3,4,5};
//    for (int *i = arr; i != &arr[sizeof(arr) / sizeof(int)] && !(*i == 4 || *i == 3); ++i)
//        cout << *i << " ";
//    cout << endl;
//}
//
//struct Foo {
//    Foo () : Foo(33) {}
//    Foo (int b) : bar(b) {}
//    int get_bar() {
//        return bar;
//    }
//private:
//    int bar;
//};
//
//int main () {
//    std::forward_list<Foo> fl;
//    fl.resize(1);
//    cout << fl.front().get_bar() << endl;
//}

//int main () {
////    vector<int> vi(10,0);
////    int i = 0;
////    fill(vi.begin(), vi.end(), i++);
////    for (int i : vi)
////        cout << i << " ";
////    cout << endl;
////    std::list<string> ls = {"foo", "bar"};
////    cout << accumulate(ls.cbegin(), ls.cend(), string("")) << endl;
//    vector<int> vi = {1,8,5,1,3,4,5,191,1,4,4,12,2,1,15,23,3,52,3,58};
//    sort(vi.begin(), vi.end());
////    auto ret = unique(vi.begin(), vi.end());
//    vi.erase(unique(vi.begin(), vi.end()), vi.end());
//    for (auto i : vi)
//        cout << i << " ";
//    cout << endl;
//}

//// Ex 10.1 - 10.2
//int main () {
//    vector<int> vi = {1,2,3,4,5,76,7,7,4,3,2,5,6,3,212,6,6,2,3,6,4756,2};
//    std::list<int> li(vi.cbegin(), vi.cend());
//    cout << count(vi.cbegin(), vi.cend(), 4756) << endl;
//    cout << count(li.cbegin(), li.cend(), 5) << endl;
//}


//void printVec(const std::vector<int> &vi) {
//    for (auto i : vi)
//        cout << i << " ";
//    cout << endl;
//}
//
//void rewriteVec(std::vector<int> &vi, const int val) {
//    fill_n(vi.begin(), vi.size(), val);
//}
//
//void zeroVec(std::vector<int> &vi) {
//    rewriteVec(vi, 0);
//}
// Ex 10.3
//int main () {
//    vector<int> vi = {1,2,3,4,5,76,7,7,4,3,2,5,6,3,212,6,6,2,3,6,4756,2};
////    cout << accumulate(vi.cbegin(), vi.cend(), 0) << endl;
//
//    vector<double> vd = {1.214, 0.412356, 0.1235235, 0.5112};
//    // Losing precision due to conversion to int
//    //cout << accumulate(vd.cbegin(), vd.cend(), 0) << endl;
//
//    printVec(vi);
//    zeroVec(vi);
//    printVec(vi);
//
//}
// Ex 10.9, 10.11
//
//void elimDupls(std::vector<string> &vs) {
//    std::sort(vs.begin(), vs.end());
//    vs.erase(std::unique(vs.begin(), vs.end()), vs.end());
//}
//
//inline bool isShorter(const string &s1, const string &s2) {
//    return s1.size() < s2.size();
//}
//
inline void printVecStr(const vector<string> &vs) {
    for (const string &s : vs)
        cout << s << " ";
    cout << endl;
}
//
//int main() {
//    std::vector<string> vs;
//    string s;
//    cout << "Enter some strings: " << endl;
//    while (std::cin >> s) {
//        vs.push_back(s);
//    }
//
//    cout << "So far we got: " << endl;
//    printVec(vs);
//
//    cout << "Eliminating duplicates..." << endl;
//    elimDupls(vs);
//
//    cout << "Now we got: " << endl;
//    printVecStr(vs);
//
//    cout << "Calling stable_sort with isShorter..." << endl;
//    stable_sort(vs.begin(), vs.end(), isShorter);
//
//    cout << "Now we got: " << endl;
//    printVecStr(vs);
//}

// Ex 10.12

//inline bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {
//    return sd1.isbn() < sd2.isbn();
//}
//inline void printSDvec(const vector<Sales_data> &sdv) {
//    for (Sales_data sd : sdv) {
//        print(cout, sd);
//        cout << endl;
//    }
//}
//
//int main() {
//    vector<Sales_data> sdv {Sales_data("1234"), Sales_data("1235"), Sales_data("1233"), Sales_data("1235"), Sales_data("1235")};
//    Sales_data sd;
//
//    cout << endl;
//
//    cout << "So far we got" << endl;
//    printSDvec(sdv);
//
//    cout << endl;
//
//    cout << "Sorting the vec..." << endl;
//    sort(sdv.begin(), sdv.end(), compareIsbn);
//    cout << endl;
//
//    cout << "Now we got" << endl;
//    cout << "In the first one: " << endl;
//    printSDvec(sdv);
//
//    return 0;
//}

// Ex 10.13
//
//inline bool strMoreFive(const string &s) {
//    return s.size() >= 5;
//}
//
//int main() {
//    std::vector<string> vs;
//    string s;
//
//    cout << "Enter some strings: " << endl;
//    while (std::cin >> s) {
//        vs.push_back(s);
//    }
//
//    cout << "So far we got:" << endl;
//    printVecStr(vs);
//    cout << endl;
//
//    cout << "Partitioning..." << endl;
//    cout << endl;
//
//    auto part_ret = partition(vs.begin(), vs.end(), strMoreFive);
//    vs.erase(part_ret, vs.end());
//
//    cout << "Now we got:" << endl;
//    printVecStr(vs);
//
//    return 0;
//}

//auto foo() {
//    string s = "bar";
//    auto f = [&] {return s;};
//    return f;
//}
//
//int main () {
//    auto skip = foo();
//    cout << foo()() << endl;
//}

//int sumtwo(const int &i, const int &j) {
//    return i + j;
//}
//
//int main () {
//    auto addten = std::bind(sumtwo, _2, 10);
//    int res = addten(1,3);
//    cout << res << endl;
//}


// Ex 10.14 - 10.16
void elimDupls(std::vector<string> &vs) {
    std::sort(vs.begin(), vs.end());
    vs.erase(std::unique(vs.begin(), vs.end()), vs.end());
}

//inline bool isShorter(const string &s1, const string &s2) {
//    return s1.size() < s2.size();
//}
//
//void biggies(vector<string> &words, const string::size_type &sz) {
//    elimDupls(words);
//    stable_sort(words.begin(), words.end(), [] (const string &s1, const string &s2){return s1.size() < s2.size();});
//    auto wc = find_if(words.begin(), words.end(), [sz] (const string &s) { return s.size() >= sz; });
//    auto count = words.end() - wc;
//    cout << "Found" << count << "words" << endl;
//    for_each(wc, words.end(), [] (const string &s) { cout << s << " "; });
//}
//
//int main() {
//    auto foo = [] (const int &a, const int &b) { return a + b; };
//    int i=12, j=13;
//    cout << foo(i,j) << endl;
//    int x = 33;
//    auto bar = [x] (const int &i) { return x + i; };
//    cout << bar(22) << endl;
//    return 0;
//}

// Ex 10.17
//inline bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2) {
//    return sd1.isbn() < sd2.isbn();
//}
//inline void printSDvec(const vector<Sales_data> &sdv) {
//    for (Sales_data sd : sdv) {
//        print(cout, sd);
//        cout << endl;
//    }
//}
//
//int main() {
//    vector<Sales_data> sdv {Sales_data("1234"), Sales_data("1235"), Sales_data("1233"), Sales_data("1235"), Sales_data("1235")};
//    Sales_data sd;
//
//    cout << endl;
//
//    cout << "So far we got" << endl;
//    printSDvec(sdv);
//
//    cout << endl;
//
//    cout << "Sorting the vec..." << endl;
//    sort(sdv.begin(), sdv.end(),
//         [] (const Sales_data &sd1, const Sales_data &sd2)
//         { int i = stoi(sd1.isbn()); cout << i << " "; return stoi(sd1.isbn()) < stoi(sd1.isbn()); });
//    cout << endl;
//
//    cout << "Now we got" << endl;
//    printSDvec(sdv);
//
//    return 0;
//}

//// Ex 10.18 - 10.19
//void biggies(vector<string> &words, const string::size_type &sz) {
//    elimDupls(words);
//    stable_sort(words.begin(), words.end(), [] (const string &s1, const string &s2){return s1.size() < s2.size();});
//    cout << "So far we have" << endl;
//    printVecStr(words);
//    auto pastlast = stable_partition(words.begin(), words.end(), [sz] (const string &s) { return s.size() >= sz; });
//    cout << "Now we have" << endl;
//    printVecStr(words);
////    auto wc = find_if(words.begin(), words.end(), [sz] (const string &s) { return s.size() >= sz; });
////    auto count = words.end() - wc;
//    auto count = pastlast - words.begin();
//    cout << "Found " << count << " words" << endl;
//    for_each(words.begin(), pastlast, [] (const string &s) { cout << s << " "; });
//    cout << endl;
//}
//
//int main () {
//    vector<string> vs = {"foobar", "lalaland", "balalikes", "bar", "dude", "abc", "karmical"};
//    biggies(vs, 4);
//}


// Ex 10.20
//void biggies(vector<string> &words, const string::size_type &sz) {
//    elimDupls(words);
//    stable_sort(words.begin(), words.end(), [] (const string &s1, const string &s2) { return s1.size() < s2.size(); });
////    printVecStr(words);
//    auto pastlast = stable_partition(words.begin(), words.end(), [sz] (const string &s) { return s.size() >= sz; });
////    printVecStr(words);
////    auto wc = find_if(words.begin(), words.end(), [sz] (const string &s) { return s.size() >= sz; });
////    auto count = words.end() - wc;
//
////    auto count = pastlast - words.begin();
//    auto count = count_if(words.cbegin(), words.cend(), [sz] (const string &s) { return s.size() >= sz; });
//    cout << "Found " << count << " words" << endl;
//    for_each(words.begin(), pastlast, [] (const string &s) { cout << s << " "; });
//    cout << endl;
//}
//
//int main () {
//    vector<string> vs = {"foobar", "lalaland", "balalikes", "bar", "dude", "abc", "karmical"};
//    biggies(vs, 4);
//}

// Ex 10.21
//int main() {
//    int i = 3;
//    auto f = [&i] () -> bool { return i > 0 ? !--i: !i; };
//    while (i > 0) {
//        f();
//        cout << i << endl;
//    }
//}

// Ex 10.22
//
//inline bool isShorter(const string &s1, const string &s2) {
//    return s1.size() < s2.size();
//}
//
//bool longerEqThan(const string &s, const unsigned &i) {
//    return s.size() >= i;
//}
//
//void printS(const string &s, std::ostream &os) {
//    os << s << endl;
//}
//
//void biggies(vector<string> &words, const string::size_type &sz) {
//    elimDupls(words);
//    stable_sort(words.begin(), words.end(), isShorter);
//    auto pastlast = stable_partition(words.begin(), words.end(), std::bind(longerEqThan, _1, sz));
////    auto wc = find_if(words.begin(), words.end(), [sz] (const string &s) { return s.size() >= sz; });
//
//    auto count = count_if(words.cbegin(), words.cend(), std::bind(longerEqThan, _1, sz));
//    cout << "Found " << count << " words" << endl;
//    for_each(words.begin(), pastlast, std::bind(printS, _1, ref(cout)));
//    cout << endl;
//}

// Ex 10.24

//
//inline bool check_size(const string &str, const unsigned &sz) {
//    return str.size() >= sz;
//}
//
//int main () {
//    vector<int> vs = {2,5,3,1,6,7,10,4,6};
//    const string s = "foobar";
//    auto ret = find_if_not(vs.cbegin(), vs.cend(), std::bind(check_size, s, _1));
//    cout << *ret << endl;
//}

//int main () {
//    std::ostream_iterator<int> out_iter(cout, " ");
//    vector<int> vi = {1,2,3,4,5};
//    for (auto e : vi)
//        out_iter = e;
//    cout << endl;
//}


// Ex 10.27
//int main() {
//    vector<int> vi = {1,2,3,4,4,4,4,4,5,5,5,5,6,7,8};
//    std::list<int> li;
//    auto back_ins_list = std::back_inserter(li);
//    std::unique_copy(vi.cbegin(), vi.cend(), back_ins_list);
//    for (auto i : li)
//        cout << i << " ";
//    cout << endl;
//}

// Ex 10.28
//
//void insCopy(const vector<int> &vi, std::deque<int> &dq, const char &flag = 0);
//void insCopy(const vector<int> &vi, std::list<int> &lt);
//void printMe(const std::deque<int> &dq);
//void printMe(const std::list<int> &lt);
//
//int main() {
//    vector<int> vi = {1,2,3,4,5,6,7,8,9};
//
//    std::deque<int> dq_front;
//    std::deque<int> dq_back;
//    std::list<int> lt_ins;
//
//    insCopy(vi, dq_front);
//    insCopy(vi, dq_back, 1);
//    insCopy(vi, lt_ins);
//
//    printMe(dq_front);
//    printMe(dq_back);
//    printMe(lt_ins);
//}
//
//void insCopy(const vector<int> &vi, std::deque<int> &dq, const char &flag) {
//    if (flag == 0)
//        copy(vi.cbegin(), vi.cend(), std::front_inserter(dq));
//    else
//        copy(vi.cbegin(), vi.cend(), std::back_inserter(dq));
//}
//
//void insCopy(const vector<int> &vi, std::list<int> &lt) {
//    copy(vi.cbegin(), vi.cend(), std::inserter(lt, lt.begin()));
//}
//
//void printMe(const std::deque<int> &dq) {
//    for (auto i : dq)
//        cout << i << " ";
//    cout << endl;
//}
//
//void printMe(const std::list<int> &lt) {
//    for (auto i : lt)
//        cout << i << " ";
//    cout << endl;
//}


// Ex 10.29
//
//void readFileVecStr(std::vector<string> &vs, const string &filename);
//vector<string> makeVecStr(const string &filename);
//
//int main() {
//    vector<string> vs;
//    cout << "Start read from file" << endl;
//    readFileVecStr(vs, "/Users/supertoy/Documents/foo.txt");
//    cout << "Done" << endl;
//    cout << "Printing" << endl;
//    printVecStr(vs);
//}
//
//void readFileVecStr(std::vector<string> &vs, const string &filename) {
//    std::ifstream ifs(filename);
//    std::istream_iterator<string> ifs_iter(ifs), eof;
//    while (ifs_iter != eof)
//        vs.push_back(*ifs_iter++);
//}
//
//vector<string> makeVecStr(const string &filename) {
//    std::ifstream ifs(filename);
//    std::istream_iterator<string> ifs_iter(ifs), eof;
//    vector<string> vec(ifs_iter, eof);
//    return vec;
//}

// Ex 10.30-10.31
//
//void readSortPrint(const string &filename);
//
//int main () {
//    readSortPrint("/Users/supertoy/Documents/foo.txt");
//}
//
//void readSortPrint(const string &filename) {
//    // Create an ifstream from the filename
//    std::ifstream ifs(filename);
//
//    // Create istream_iterators and ostream_iterator to get and print items
//    std::istream_iterator<int> in_iter_int(ifs), eof;
//    std::ostream_iterator<int> out_iter(cout, "\n");
//
//    // Get the items from the stream to a holder and sort them in there
//    vector<int> holder(in_iter_int, eof);
//    sort(holder.begin(), holder.end());
//
//    // Print the holder contents
//    copy(holder.begin(), holder.end(), out_iter);
//
////    // Print unique the holder contents
////    unique_copy(holder.begin(), holder.end(), out_iter);
//}

// Ex 10.32
//// Take ISBN, quantity and price integers
//// Accumulate a vector of Sales_data in random order
//vector<Sales_data> readSalesData(std::istream &is);
//
//// Take a vector of Sales_data, sort it and accumulate total quantity and money
//// Return vector of Sales_data totals accumulated based on the ISBN
//vector<Sales_data> total(vector<Sales_data> &vsi);
//
//// Declaration of predicate
//inline bool compareIsbnData(const Sales_data &sd1, const Sales_data &sd2);
//
//
//int main() {
////    cout << "Enter the input: " << endl;
////    vector<Sales_data> vec_SI = readSalesData();
////    cout << "Computing the total" << endl;
////    vector<Sales_data> totals = total(vec_SI);
////    for (auto i : totals)
////        print(std::cout, i);
////    cout << endl;
//}
//
////vector<Sales_data> readSalesData(std::istream &is) {
////    std::istream_iterator<Sales_data> istr_iter(is), eof;
////    vector<Sales_data> vsi(istr_iter, eof);
////    return vsi;
////}
//
//vector<Sales_data> total(vector<Sales_data> &vsi) {
//    vector<Sales_data> total;
//    sort(vsi.begin(), vsi.end(), compareIsbnData);
//    auto curr = vsi.begin();
//    while (curr != vsi.end()) {
//        auto tail = find_if(curr, vsi.end(), [curr] (const Sales_data &sd) {return curr->isbn() != sd.isbn(); } );
//        auto item = accumulate(curr, tail, Sales_data("",0,0));
//        total.push_back(item);
//        curr = tail;
//    }
//    return total;
//}
//
//inline bool compareIsbnData(const Sales_data &sd1, const Sales_data &sd2) {
//    return sd1.isbn() < sd2.isbn();
//}


// Ex 10.33
//
//void foo(const string &ifname,  const string &odd, const string &even);
//
//int main () {
//    const string out_odd = "/Users/supertoy/Documents/out_odd.txt", out_even = "/Users/supertoy/Documents/out_even.txt",
//    in_file = "/Users/supertoy/Documents/foo.txt";
//    foo(in_file, out_odd, out_even);
//}
//
//void foo(const string &ifname, const string &odd, const string &even) {
//    std::ifstream ifs(ifname);
//    std::ofstream odd_str(odd), even_str(even);
//
//    std::istream_iterator<int> is_iter(ifs), eof;
//    std::ostream_iterator<int> odd_iter(odd_str, " "), even_iter(even_str, "\n");
//
//    while (is_iter != eof)
//        (*is_iter % 2) ? (odd_iter = *is_iter++) : (even_iter = *is_iter++);
//}


// Ex 10.34
//void printRev(const vector<int> &v) {
//    std::ostream_iterator<int> os(std::cout, "\n");
//    copy(v.crbegin(), v.crend(), os);
//}
//
//// Ex 10.35
//void printNornRev(const vector<int> &v) {
//    vector<int>::const_iterator i = v.cend()-1;
//    for (/* */; i != v.cbegin(); --i)
//        cout << *i << endl;
//    cout << *i << endl;
//}
//
//// Ex 10.36
//auto findLastZero(const std::list<int> &lt) {
//    return find(lt.crbegin(), lt.crend(), 0);
//}
//
//int main() {
//    std::list<int> li = {1,2,3,4,5,10,0,23};
//    std::ostream_iterator<int> os(std::cout, "\n");
//    auto ret = findLastZero(li);
//    copy(ret.base(), li.cend(), os);
//}

// Ex 10.37
//
//void foo(const vector<int> &v, std::list<int> &lt);
//
//int main() {
//    vector<int> vs = {1,2,3,4,5,6,7,8,9,10};
//    std::list<int> lt;
//    foo(vs, lt);
//    for (auto i : lt)
//        cout << i << " ";
//    cout << endl;
//}
//
//void foo(const vector<int> &v, std::list<int> &lt) {
//    copy(v.crbegin()+3, v.crend()-2, inserter(lt, lt.begin()));
//}

// Ex 10.42
//
//void elimDupls(std::list<string> &lt_str) {
//    lt_str.sort();
//    lt_str.erase(std::unique(lt_str.begin(), lt_str.end()), lt_str.end());
//}
//
//inline bool isShorter(const string &s1, const string &s2) {
//    return s1.size() < s2.size();
//}
//
//// Vector
//void biggies(vector<string> &words, const string::size_type &sz) {
//    elimDupls(words);
//    stable_sort(words.begin(), words.end(), [] (const string &s1, const string &s2){return s1.size() < s2.size();});
//    auto wc = find_if(words.begin(), words.end(), [sz] (const string &s) { return s.size() >= sz; });
//    auto count = words.end() - wc;
//    cout << "Found" << count << "words" << endl;
//    for_each(wc, words.end(), [] (const string &s) { cout << s << " "; });
//}
//
//// List
//void biggies(std::list<string> &words, const string::size_type &sz) {
//    elimDupls(words);   // Overloaded funciton call resolves to the list version
////    stable_sort(words.begin(), words.end(), isShorter);
//    words.sort(isShorter);
//    auto found = find_if(words.begin(), words.end(), [sz] (const string &s) { return s.size() >= sz; });
//    unsigned counter = 0;
//    for (auto i = found; i != words.cend(); ++i) {
//        cout << *i << " ";
//        ++counter;
//    }
//    cout << endl;
//    cout << "Found " << counter << " words" << endl;
//    for_each(found, words.end(), [] (const string &s) { cout << s << " "; });
//}
//
//int main() {
//    std::list<string> lt_str = {"foo", "bar", "abcde", "bazooka", "bazon",  "abcde", "bazooker", "troll", "ringless", "abcde"};
//    biggies(lt_str, 4);
//    cout << endl;
//}


// Ex 11.3-11.4
//
//std::map<const string, unsigned> make_word_count(vector<string> &v);
//string format(string &s, std::set<const char> exclude = {'.',',','!','?','"'});
//
//int main () {
//    vector<string> vcs = {"foo","bar","Foo","foo","Bar","doo","DOO","bar!","foo?!!"};
//    std::map<const string, unsigned> my_dict = make_word_count(vcs);
//    for (std::pair<const string, unsigned> i : my_dict)
//        cout << i.first << " " << i.second << endl;
//}
//
//std::map<const string, unsigned> make_word_count(vector<string> &v) {
//    std::map<const string, unsigned> dict;
//    for (string &word : v) {
//        word = format(word);
//        ++dict[word];
//    }
//    return dict;
//}
//string format(string &s, std::set<const char> exclude) {
//    string formated;
//    for (char ch : s) {
//        if (exclude.find(ch) == exclude.end())
//            formated.push_back(tolower(ch));
//    }
//    return formated;
//}


// Ex 11.7 A
//
//struct Family {
//    Family(const string &l_name, vector<string> names = {}) : last_name(l_name), kids(names) {}
//    Family() : Family("") {}
//
//    vector<string> get_kids_names() {
//        return kids;
//    }
//    string get_last_name() {
//        return last_name;
//    }
//    std::pair<const string, vector<string>> get_whole() {
//        return {last_name, kids};
//    }
//
//    void add_kid(const string &name) {
//        kids.push_back(name);
//    }
//private:
//    const string last_name;
//    vector<string> kids;
//};
//
//
//struct Families {
//
//private:
//    std::map<string, vector<Family>> x;
//};

// Ex 11.7 B
// TO DO: function to create non-empty mapping from the start

//std::map<string, vector<string>> make_empty_family_map();
//void add_fams(std::map<string, vector<string>> &families, std::istream &is = std::cin);
//void print_fams(std::map<string, vector<string>> &fams);
//
//int main () {
//    std::map<string, vector<string>> fams = make_empty_family_map();
//    add_fams(fams);
//    print_fams(fams);
//
//}
//
//std::map<string, vector<string>> make_empty_family_map() {
//    return std::map<string, vector<string>>();
//}
//
//void add_fams(std::map<string, vector<string>> &families, std::istream &is) {
//    string current_input;
//    vector<string> current_kids;
//    string last_name;
//
//    cout << "Enter the family's last name:" << endl;
//    if (is >> current_input) {
//        last_name = current_input;
//        families[current_input] = vector<string>();
//    }
//
//    cout << "Enter names:" << endl;
//    while (is >> current_input)
//        families[last_name].push_back(current_input);
//
//    cout << "Done" << endl;
//}
//
//void print_fams(std::map<string, vector<string>> &fams) {
//    for (const auto &i : fams) {
//        cout << "Last name: " << i.first << endl;
//        cout << "Kids:";
//        for (const string &s : i.second)
//            cout << s << " ";
//        cout << endl;
//    }
//}
// Ex 11.8
//
//std::map<const string, unsigned> make_word_count(vector<string> &v);
//
//// Working on:
//string format(string &s, vector<char> exclude = {'.',',','!','?','"'});
//
//int main () {
//    vector<string> vcs = {"foo","bar","Foo","foo","Bar","doo","DOO","bar!","foo?!!"};
//    std::map<const string, unsigned> my_dict = make_word_count(vcs);
//    for (std::pair<const string, unsigned> i : my_dict)
//        cout << i.first << " " << i.second << endl;
//}
//
//std::map<const string, unsigned> make_word_count(vector<string> &v) {
//    std::map<const string, unsigned> dict;
//    for (string &word : v) {
//        word = format(word);
//        ++dict[word];
//    }
//    return dict;
//}
//
//// Working on:
//string format(string &s, vector<char> exclude) {
//    string formated;
//    for (char ch : s) {
//        if (find(exclude.cbegin(), exclude.cend(), ch) == exclude.cend())
//            formated.push_back(tolower(ch));
//    }
//    return formated;
//}

//int main () {
//    std::pair<unsigned, unsigned> p1 = {2, 3}, p2 = {2, 4};
//    cout << (p1 < p2) << endl;
//}

// Ex 11.12
//
//vector<std::pair<string, int>> make_vec_pairs(std::istream &is = std::cin);
//void print_vec_pair(const vector<std::pair<string, int>> &vec);
//
//int main () {
//    vector<std::pair<string, int> > my_vec = make_vec_pairs();
//    cout << "Made one vector" << endl;
//    print_vec_pair(my_vec);
//}
//
//vector<std::pair<string, int>> make_vec_pairs(std::istream &is) {
//    vector<std::pair<string, int>> vec;
//    string s;
//    int i;
//    while (is >> s)
//        if (is >> i) {
//            std::pair<string, int> p(s, i);
//            vec.push_back(p);
//        }
//    return vec;
//}
//
//void print_vec_pair(const vector<std::pair<string, int>> &vec) {
//    for (const std::pair<string, int> &p : vec)
//        cout << p.first << " " << p.second << endl;
//}

// Ex 11.13
//vector<std::pair<string, int>> make_vec_pairs(std::istream &is);
//
//int main () {}
//
//vector<std::pair<string, int>> make_vec_pairs(std::istream &is) {
//    vector<std::pair<string, int>> vec;
//    string s;
//    int i;
//    while (is >> s)
//        if (is >> i) {
////            vec.push_back({s, i});
////            vec.push_back(make_pair(s, i));
//            vec.push_back(std::pair<string, int> (s, i));
//        }
//    return vec;
//}

//// Ex 11.14
//typedef std::array<unsigned, 3> birthday;
//typedef std::pair<string, birthday> kid;
//typedef vector<kid> kids;
//typedef std::map<string, kids> families_map;
//typedef families_map::value_type family;
//
//void add_kid(families_map &fam_map, const string &last_name, kid k);
//void add_family(families_map &fam_map, const string &last_name, kids fams_kids = {});
//families_map make_fam_map();
//void print_fam_map(const families_map &fm);
//
//int main() {
//    families_map fam_map_1 = make_fam_map();
//    const string last_name_1 = "Foofam";
//    const string last_name_2 = "Barfam";
//    add_family(fam_map_1, last_name_1);
//    add_family(fam_map_1, last_name_2);
//    kid kid_1 = {"Folkid_1", birthday{11,01,2003}};
//    kid kid_2 = {"Fookid_2", birthday{11,01,2003}};
//
//    kid kid_3 = {"Barkid_1", birthday{13,12,2000}};
//    kid kid_4 = {"Barkid_2", birthday{13,12,2000}};
//    kid kid_5 = {"Barkid_3", birthday{13,12,2000}};
//
//    add_kid(fam_map_1, last_name_1, kid_1);
//    add_kid(fam_map_1, last_name_1, kid_2);
//
//    add_kid(fam_map_1, last_name_2, kid_3);
//    add_kid(fam_map_1, last_name_2, kid_4);
//    add_kid(fam_map_1, last_name_2, kid_5);
//
//    print_fam_map(fam_map_1);
//}
//
//void add_kid(families_map &fam_map, const string &last_name, kid k) {
//    fam_map[last_name].push_back(k);
//}
//
//void add_family(families_map &fam_map, const string &fam_last_name, kids k) {
//    fam_map[fam_last_name] = k;
//}
//
//void print_fam_map(const families_map &fm) {
//    for (family f : fm) {
//        cout << "Last name:" << f.first << endl;
//        for (kid k : f.second)
//            cout << "Kid: " <<  k.first << " born " << k.second[0] << "-" << k.second[1] << "-" << k.second[2] << endl;
//        cout << endl;
//    }
//}
//
//families_map make_fam_map() {
//    families_map fam_map = {};
//    return fam_map;
//}

// Ex 11.16
//
//int main () {
//    std::map<string, unsigned> dict = {{"foo", 1}, {"bar", 2}};
//    std::map<string, unsigned>::iterator diter = dict.begin();
//    while (diter != dict.end()) {
//        diter->second = 21;
//        ++diter;
//    }
//    for (auto i : dict)
//        cout << i.first << " " << i.second << endl;
//}

// Ex 11.17

//int main() {
//    std::multiset<string> c = {"foo","bar","tar"};
//    vector<string> v = {"foo","bar","tar"};
////    copy(v.begin(), v.end(), inserter(c, c.end()));
////    for (auto i : c)
////        cout << i << " ";
////    cout << endl;
//
//    copy(c.begin(), c.end(), back_inserter(v));
//    for (auto &i : v)
//        i = "xxx";
//    cout << endl;
//
//    for (auto i : v)
//        cout << i << " ";
//    cout << endl;
//}

// Ex 11.18
//int main() {
//    std::map<string, unsigned> dict;
//    std::map<string, unsigned>::const_iterator dciter = dict.cbegin();
//}

// Ex 11.19
//
//bool fooCompareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
//    return lhs.isbn() < rhs.isbn();
//}
//
//int main() {
//    std::multiset<Sales_data, decltype(fooCompareIsbn)*> bookstore(fooCompareIsbn);
//    std::multiset<Sales_data, decltype(fooCompareIsbn)*>::const_iterator iter = bookstore.begin();
//}

void print_word_count(const std::map<string, unsigned> &dict);

//int main() {
//    std::map<string, unsigned> dict = {{"foo",1}, {"bar",2}, {"tar",3}};
//    std::map<string, unsigned>::iterator diter = dict.begin();
//    ++diter;
//    ++diter;
//    dict.insert(diter, std::make_pair("foo", 333));
//
//    print_word_count(dict);
//}

void print_word_count(const std::map<string, unsigned> &dict) {
    for (const std::map<string, unsigned>::value_type &i : dict)
        cout << i.first << " " << i.second << endl;
}

//
//// Ex 11.33
//std::map<string, string> makeMap(std::ifstream &map_file);
//void word_transform(std::ifstream &map_file, std::ifstream &input);
//const string & transform(const string &word, const std::map<string, string> &word_map);
//
//void word_transform(std::ifstream &map_file, std::ifstream &input) {
//    auto trans_map = makeMap(map_file);
//    string text;
//    while (getline(input, text)) {
//        std::istringstream stream(text);
//        string word;
//        bool firstword = true;
//        while (stream >> word) {
//            if (firstword)
//                firstword = false;
//            else
//                cout << " ";
//            cout << transform(word, trans_map);
//        }
//        cout << endl;
//    }
//}
//
//std::map<string, string> makeMap(std::ifstream &map_file) {
//    std::map<string, string> trans_map;
//    string key, value;
//    while (map_file >> key && getline(map_file, value))
//        if (value.size() > 1)
//            trans_map[key] = value.substr(1);
//        else
//            throw runtime_error("No rule for the " + key);
//    return trans_map;
//}
//
//const string & transform(const string &word, const std::map<string, string> &word_map) {
//    auto map_it = word_map.find(word);
//    if (map_it != word_map.cend())
//        return map_it->second;
//    else return word;
//}

//int main () {
////    std::unordered_map<string, string> umap {{"a", "foo"}, {"b", "bar"}};
////    cout << umap.max_bucket_count() << endl;
////    std::unordered_multiset<Sales_data> s;
////    string s1 = "foo";
////    string s2 = "bar";
////    string s3 = "foo";
////    auto h1 = std::hash<string> () (s1);
////    auto h2 = std::hash<string> () (s2);
////    auto h3 = std::hash<string> () (s3);
////    cout << h1 << endl;
////    cout << h2 << endl;
////    cout << h3 << endl;
//    auto a = std::make_shared<int> (22);
//    auto b = std::make_shared<int> (33);
//    auto foo = a.get();
//    a = b;
//    for (int i = 0; i != 1000; ++i)
//        cout << *foo << endl;
//
//}
////
////size_t hasher(const Sales_data & sd) {
////    return std::hash<string> () (sd.isbn());
////}


// Ex 12.2
//
//struct StrBlob {
//    typedef std::vector<std::string>::size_type size_type;
//    // constructors
//    StrBlob();
//    StrBlob(std::initializer_list<std::string> il);
//    // auxilary
//    size_type size() const { return data->size(); }
//    bool empty() const { return data->empty(); }
//    // add and remove
//    void push_back();
//    void pop_back();
//    // access
//    std::string& front();
//    std::string& back();
//    std::string& front() const;
//    std::string& back() const;
//private:
//    std::shared_ptr<vector<std::string>> data;
//    void check(size_type i, const std::string &msg) const; // throw msg is data[i] isn't valid
//};
//
//// Constructors definitions
//StrBlob::StrBlob() : data(std::make_shared<vector<string>> ()) {}
//StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<vector<string>> (il)) {}
//
//// Member funcitons definitions
//void StrBlob::check(size_type i, const std::string &msg) const {
//    if (i >= data->size())
//        throw std::out_of_range(msg);
//}
//
//std::string& StrBlob::front() {
//    check(0, "front() on empty StrBlob");
//    return data->front();
//}
//std::string& StrBlob::back() {
//    check(0, "front() on empty StrBlob");
//    return data->back();
//}
//
//std::string& StrBlob::front() const {
//    check(0, "front() on empty StrBlob");
//    return data->front();
//}
//std::string& StrBlob::back() const {
//    check(0, "front() on empty StrBlob");
//    return data->back();
//}
//
//int main () {
//    vector<string*> vps;
//    while (true) {
//        string *p = new string("foo");
//        vps.push_back(p);
//    }
//}
//


//  Ex 12.6
//vector<int>* make_vec();
//void read_in(vector<int> *vec, std::istream &is = std::cin);
//void print(vector<int> *vec, std::ostream &os = std::cout);
//void read_print(std::istream &is = std::cin, std::ostream &os = std::cout);
//
//int main() {
//    read_print();
//}
//
//vector<int>* make_vec() {
//    return new vector<int>;
//}
//void read_in(vector<int> *vec, std::istream &is) {
//    int i;
//    while (is >> i)
//        vec->push_back(i);
//}
//void print(vector<int> *vec, std::ostream &os) {
//    for (const int &i : *vec)
//        os << i << ' ';
//    os << endl;
//}
//void read_print(std::istream &is, std::ostream &os) {
//    vector<int> *vec = make_vec();
//    read_in(vec, is);
//    print(vec, os);
//    delete vec;
//}

// Ex 12.7
//
//std::shared_ptr<vector<int>> shared_make_vec();
//void shared_read(std::shared_ptr<vector<int>>, std::istream& = std::cin);
//void shared_print(std::shared_ptr<vector<int>>, std::ostream& = std::cout);
//void shared_read_print(std::istream& = std::cin, std::ostream& = std::cout);
//
//int main() {
//    shared_read_print();
//}
//
//std::shared_ptr<vector<int>> shared_make_vec() {
//    return std::make_shared<vector<int>>();
//}
//void shared_read(std::shared_ptr<vector<int>> vi, std::istream &is) {
//    for (int i; is >> i; vi->push_back(i));
//}
//void shared_print(std::shared_ptr<vector<int>> vi, std::ostream &os) {
//    for (const int &i : *vi)
//        os << i << ' ';
//    os << endl;
//}
//void shared_read_print(std::istream &is, std::ostream &os) {
//    std::shared_ptr<vector<int>> vi(shared_make_vec());
//    shared_read(vi);
//    shared_print(vi);
//}
//

// Ex 12.14-12.15
//struct Destination;
//struct Connection {
//    Connection();
//
//private:
//    string data = "";
//};
//
//Connection connect(Destination&) {
//    return Connection();
//}
//void disconnect(Connection);
//void end_connection(Connection *c) {
//    disconnect(*c);
//}
//void foo(Destination &d) {
//    Connection con = connect(d);
//    //std::shared_ptr<Connection> pcon(&con, &end_connection);
//    std::shared_ptr<Connection> pcon(&con, [] (Connection *c) { disconnect(*c); });
//}
// 
// struct StrBlob {
//     friend class StrBlobPtr;
//     friend class ConstStrBlobPtr;
//     typedef std::vector<std::string>::size_type size_type;
//     // constructors
//     StrBlob();
//     StrBlob(std::initializer_list<std::string> il);
//     // auxilary
//     size_type size() const { return data->size(); }
//     bool empty() const { return data->empty(); }
//     // add and remove
//     void push_back(string s); // should it be a reference or const?
//     void pop_back();
//     // access
//     std::string& front();
//     std::string& back();
//     std::string& front() const;
//     std::string& back() const;
// private:
//     std::shared_ptr<vector<std::string>> data;
//     void check(size_type i, const std::string &msg) const; // throw msg is data[i] isn't valid
// };
// 
// // Constructors definitions
// StrBlob::StrBlob() : data(std::make_shared<vector<string>> ()) {}
// StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<vector<string>> (il)) {}
// 
// // Member funcitons definitions
// void StrBlob::check(size_type i, const std::string &msg) const {
//     if (i >= data->size())
//         throw std::out_of_range(msg);
// }
// 
// std::string& StrBlob::front() {
//     check(0, "front() on empty StrBlob");
//     return data->front();
// }
// std::string& StrBlob::back() {
//     check(0, "front() on empty StrBlob");
//     return data->back();
// }
// 
// std::string& StrBlob::front() const {
//     check(0, "front() on empty StrBlob");
//     return data->front();
// }
// std::string& StrBlob::back() const {
//     check(0, "front() on empty StrBlob");
//     return data->back();
// }
// 
// void StrBlob::push_back(string s) {
//     data->push_back(s);
// }
// void StrBlob::pop_back() {
//     check(0, "Pop back on empty StrBlob");
//     data->pop_back();
// }
// 
// 
// struct StrBlobPtr {
//     // copying from the StrBlob. Is it even ok to copy?
//     typedef std::vector<std::string>::size_type size_type;
//     
//     // Constructors
//     StrBlobPtr() : curr(0) {}
//     StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz)  {}
//     // Auxilary
//     std::string& deref() const;
//     StrBlobPtr& incr();
//     size_type size() const {  auto p = wptr.lock(); return p->size(); }
// private:
//     std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
//     std::weak_ptr<std::vector<std::string>> wptr;
//     std::size_t curr;
// };
// 
// std::shared_ptr<std::vector<std::string>>
//     StrBlobPtr::check(std::size_t i, const std::string& msg) const {
//     auto ret = wptr.lock();
//     if (!ret) // is the object does not exist
//         throw std::runtime_error("Unbound StrBlobPtr");
//     if (i >= ret->size()) // is index illegal
//         throw std::out_of_range(msg);
//     return ret;
// }
// 
// std::string& StrBlobPtr::deref() const {
//     auto p = check(curr, "Dereference past the end");
//     return (*p)[curr];
// }
// 
// StrBlobPtr& StrBlobPtr::incr() {
//     check(curr, "inrement past the end");
//     ++curr;
//     return *this;
// }
// 
// 
// // Ex 12.20
// 
// int main() {
//     std::ifstream ifs;
//     ifs.open("/home/raw/Documents/foo.bar");
//     string s;
//     StrBlob sb;
//     
//     // Populate the StrBlob
//     while (getline(ifs, s))
//         sb.push_back(s);
//     
//     // Create a pinter class
//     StrBlobPtr sbp(sb);
//     
//     // Print out the contents via the pointer
//     for (int i = 0; i != sbp.size(); ++i) {
//         cout << sbp.deref() << endl;
// //         sbp.incr();
//     }
// }
// 
// // Ex 12.22
// struct ConstStrBlobPtr {
//     ConstStrBlobPtr() : curr(0) {}
//     ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz)  {}
//     const std::string& deref() const;
//     StrBlobPtr& incr();
// private:
//     std::shared_ptr<const std::vector<std::string>> check(std::size_t, const std::string&) const;
//     std::weak_ptr<const std::vector<std::string>> wptr;
//     std::size_t curr;
// };
// 

// Ex 12.23
// char* heap_chars(const std::string s1 = "Foo", const std::string s2 = "Bar");
// 
// int main () {
// 	const char *cp1 = "cFoo", *cp2 = "cBar";
// 	char *cp3 = new char[std::strlen(cp1) + std::strlen(cp2)];
// 	std::strcpy(cp3, cp1);
// 	std::strcat(cp3, cp2);
// 	std::cout << cp3 << std::endl;
// 	delete [] cp3;
// 
// 	char* p = heap_chars();
// 	std::cout << p << std::endl;
// 	delete [] p;
// }
// 
// char* heap_chars(const std::string s1, const std::string s2) {
// 		const std::string tmp = s1 + s2;
// 		const size_t arr_size = tmp.size();
// 		char *pc = new char[arr_size];
// 		for (std::string::size_type i = 0; i != arr_size; ++i)
// 				pc[i] = tmp[i];
// 		return pc;
// }

// Ex 12.24
// 
// char* heap_chars_limited(const size_t &sz, std::istream &is = std::cin);
// char* heap_chars(std::istream &is = std::cin);
// 
// int main () {
// 	//size_t sz;
// 	//cout << "Enter the size of the input string: ";
// 	//cin >> sz;
// 	//const char *arr = heap_chars_limited_2(sz);
// 	cout << "Enter a string" << endl;
// 	char *arr = heap_chars();
// 	std::cout << arr << std::endl;
// 	delete [] arr;
// }
// 
// char* heap_chars_limited(const size_t &sz, std::istream &is) {
// 	char *ret = new char[sz+1];
// 	string s;
// 	size_t curr_size = s.size();
// 	while (curr_size <= sz && is >> s) {
// 			if (s.size() + curr_size > sz)
// 					break;
// 			std::strcat(ret, s.c_str());
// 			curr_size += s.size();
// 	}
// 	ret[curr_size] = '\0';
// 	return ret;
// }
// 
// 
// char* heap_chars(std::istream &is) {
// 	string s;
// 	size_t sz = 0;
// 	if (is >> s)
// 		sz = s.size();
// 	char *ret = new char[sz + 1];
// 	std::strcat(ret, s.c_str());
// 	ret[sz] = '\0';
// 	return ret;
// }
// 
// 
// Ex 12.26
// string* heap_memo_str(const unsigned &n) {
// 		std::allocator<string> a;
// 		auto ret = a.allocate(n);
// 		return ret;
// }
// 
// 
// int main () {
// 		const size_t n = 30;
// 		std::allocator<string> alloc;
// 		auto *sp = alloc.allocate(n);
// 		string *sq = sp;
// 		string s;
// 		if (std::cin >>	s)
// 				alloc.construct(sq++, s);
// 		std::cout << *sp << std::endl;
// 		while (sq != sp)
// 				alloc.destroy(--sq);
// 		alloc.deallocate(sp, n);
// }
// 

// 
// struct StrBlob {
//     friend class StrBlobPtr;
//     friend class ConstStrBlobPtr;
//     typedef std::vector<std::string>::size_type size_type;
//     // constructors
//     StrBlob();
//     StrBlob(std::initializer_list<std::string> il);
//     // auxilary
//     size_type size() const { return data->size(); }
//     bool empty() const { return data->empty(); }
//     // add and remove
//     void push_back(string s); // should it be a reference or const?
//     void pop_back();
//     // access
//     std::string& front();
//     std::string& back();
//     std::string& front() const;
//     std::string& back() const;
// private:
//     std::shared_ptr<vector<std::string>> data;
//     void check(size_type i, const std::string &msg) const; // throw msg is data[i] isn't valid
// };
// 
// // Constructors definitions
// StrBlob::StrBlob() : data(std::make_shared<vector<string>> ()) {}
// StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<vector<string>> (il)) {}
// 
// // Member funcitons definitions
// void StrBlob::check(size_type i, const std::string &msg) const {
//     if (i >= data->size())
//         throw std::out_of_range(msg);
// }
// 
// std::string& StrBlob::front() {
//     check(0, "front() on empty StrBlob");
//     return data->front();
// }
// std::string& StrBlob::back() {
//     check(0, "front() on empty StrBlob");
//     return data->back();
// }
// 
// std::string& StrBlob::front() const {
//     check(0, "front() on empty StrBlob");
//     return data->front();
// }
// std::string& StrBlob::back() const {
//     check(0, "front() on empty StrBlob");
//     return data->back();
// }
// 
// void StrBlob::push_back(string s) {
//     data->push_back(s);
// }
// void StrBlob::pop_back() {
//     check(0, "Pop back on empty StrBlob");
//     data->pop_back();
// }
// 
// struct QueryResult;
// struct TextQuery {
// friend QueryResult;
// 		using line_n = std::vector<std::string>::size_type;
// 		TextQuery(std::ifstream&);
// 		QueryResult query(const std::string&) const;
// private:
// 		std::map<std::string, std::shared_ptr<std::set<line_n>>> wm;
// 		std::shared_ptr<std::vector<std::string>> file;
// };
// TextQuery::TextQuery(std::ifstream &ifs) : file(new vector<std::string>) {
// 		std::string line;
// 		while (getline(ifs, line)) {
// 				file->push_back(line);
// 				line_n n = file->size() - 1;
// 				std::string word;
// 				std::istringstream iss_line(line);
// 				while (iss_line >> word) {
// 						auto &lines = wm[word];
// 						if (!lines)
// 								lines.reset(new std::set<line_n>);
// 						lines->insert(n);
// 				}
// 		}
// }
// 
// struct QueryResult {
// friend std::ostream& print(std::ostream&, const QueryResult&);
// 	QueryResult(const std::string &w, std::shared_ptr<vector<std::string>> f, std::shared_ptr<std::set<TextQuery::line_n>> n) :
// 	word(w), lines(n), file(f) {}
// private:
// 	const std::string word;
// 	std::shared_ptr<std::set<TextQuery::line_n>> lines;
// 	std::shared_ptr<std::vector<std::string>> file;
// };
// 
// QueryResult TextQuery::query(const std::string &word) const {
// 		static std::shared_ptr<std::set<line_n>> nodata(new std::set<line_n>); // Not found any
// 		auto loc = wm.find(word);
// 		if (loc == wm.end())
// 			return QueryResult(word, file, nodata);
// 		return QueryResult(word, file, loc->second);
// }
// 
// std::ostream& print(std::ostream &os, const QueryResult &qr) {
// 		for (auto num : *qr.lines)
// 				os << num + 1 << "\t" << *(qr.file->begin() + num) << endl;
// 
// 		os << qr.word << " occurs on " << qr.lines->size() << " line(s)" << endl;
// 		return os; 
// }
// 
// void word_lookup(const std::string &filename, const std::string &word) {
// 		std::ifstream ifs(filename);
// 		TextQuery tq(ifs);
// 		print(std::cout, tq.query(word)) << std::endl;
// }
// 
// int main(int argc, char *argv[]) {
// // 		if (argc == 3) {
// // 				const string &filename = argv[1], &word = argv[2];
// // 				word_lookup(filename, word);
// // 				return 0;
// // 		} else return -1;
// 		
// 		std::ifstream ifs(filename);
// 		StrBlob sb();
// }

// Ex 13.5
// struct HasPtr {
// 	HasPtr(const std::string &s = std::string()): ps(new std::string(s)), i(0) { }
// 	HasPtr(const HasPtr&);
// 	HasPtr& operator=(const HasPtr&);
// 	~HasPtr() { delete ps; }
// private:
// 	std::string *ps;
// 	int i;
// };
// 
// HasPtr::HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
// HasPtr& HasPtr::operator=(const HasPtr &rhs) {
// 	delete ps;
// 	ps = new std::string(*rhs.ps);
// 	i = rhs.i;
// 	return *this;
// }
// //HasPtr::~HosPtr() {
// //	delete ps;
// //}
// 
// int main () {
// 
// }
// 
// struct X {
// 	X() {std::cout << "X()" << std::endl;}
// 	X(const X&) {std::cout << "X(const X&)" << std::endl;}
// 	X& operator=(const X&) { std::cout << "operator=(const X&)" << std::endl; return *this; }
// 	~X() { std::cout << "~X()" << std::endl; }
// };
// 
// void foo(const X) {
// }
// int main () {
// 		X x;
// 		foo(x);
// }

// Ex 13.18

// struct Employee {
// 	Employee() : Employee(string()) {};
// 	Employee(const std::string &n) : name(n), id(id_seed++) {}
// 	string get_name() {
// 		return name;
// 	}
// 	const unsigned get_id() {
// 		return id;
// 	}
// 	Employee& operator=(const Employee &rhs) {
// 			name = rhs.name;
// 			id = Employee::id_seed++;
// 			return *this;
// 	}
// 	Employee(const Employee &rhs) : name(rhs.name), id(id_seed++) {}
// private:
// 	unsigned id;
// 	std::string name;
// 	static unsigned id_seed;
// };
// 
// unsigned Employee::id_seed=0;
// 
// int main () {
// 	Employee e1("Beth");
// 	Employee e2 = e1;
// 	Employee e3;
// 	e3 = e1;
// 	std::cout << "e1: " << e1.get_name() << " " << e1.get_id() << std::endl;		
// 	std::cout << "e2: " << e2.get_name() << " " << e2.get_id() << std::endl;	
// 	std::cout << "e3: " << e3.get_name() << " " << e3.get_id() << std::endl;
// }

 //Ex 13.22
 //valuelike	
 struct HasPtr {
	friend void swap(HasPtr&, HasPtr&);
 	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
 	HasPtr(const HasPtr &rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) {}
 	HasPtr& operator=(const HasPtr &rhs) {
 		std::string *tmp = new std::string(*rhs.ps);
 		delete ps;
 		ps = tmp;
 		i = rhs.i;
 		return *this;
 	}
	// Ex 13.30
	bool operator<(const HasPtr &rhs) { return *ps < *rhs.ps; }
 	~HasPtr() { delete ps; }
	// aux to Ex 13.30
	const string val() { return *ps; }
 private:
 	std::string *ps;
 	int i;
 };

// Ex 13.27
// pointerlike
//
//struct HasPtr {
//	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
//	HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
//	HasPtr& operator=(const HasPtr &rhs);
//private:
//	std::string *ps;
//	int i;
//	std::size_t *use;
//};
//
//HasPtr& HasPtr::operator=(const HasPtr &rhs) {
//	return 
//}
//int main () {
//	HasPtr valp1("Foo");
//	HasPtr valp2 = valp2;
// 	HasPtr valp3;
// 	valp3 = valp1;
//}
//
// Ex 13.28
// a) pointerlike
struct TreeNode {
	TreeNode(const std::string &s = std::string(), TreeNode *l = nullptr, TreeNode *r = nullptr)
		: value(s), count(new std::size_t(1)), left(l), right(r) {}
	TreeNode(const TreeNode &tn)
		: value(tn.value), count(tn.count), left(tn.left), right(tn.right) { ++*count; }
	TreeNode& operator=(const TreeNode &rhs);
	~TreeNode() { if (--*count == 0) {  delete count; }}

	void print() {
		std::cout << value << std::endl;
		if (left)
			left->print();
		if (right)
			right->print();
	}
private:
	std::string value;
	std::size_t *count;
	TreeNode *left;
	TreeNode *right;
};

TreeNode& TreeNode::operator=(const TreeNode &rhs) {
	++*rhs.count;
	if (--*count == 0) { delete count; delete left; delete right; }
	value = rhs.value;
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;
	return *this;
}

// b) pointerlike, too

struct BinStrTree {
	BinStrTree(const TreeNode &tn = TreeNode()) : root(new TreeNode(tn)), use(new std::size_t(1)) {}
	BinStrTree(const BinStrTree &rhs) : root(rhs.root), use(rhs.use) { ++*use; }
	BinStrTree& operator=(const BinStrTree &rhs) {
		++*rhs.use;
		if (--*use == 0) { delete use; delete root; }
		root = rhs.root;
		use = rhs.use;
		return *this;
	}
	~BinStrTree() { if (--*use == 0) { delete root; delete use; }}	
	void print() {
		root->print();
	}
private:
	TreeNode *root;
	std::size_t *use;
};



// Ex 13.30
void swap(HasPtr &a, HasPtr &b) {
		using std::swap;
		std::cout << "START" << std::endl;
		std::cout << "swap("<< *a.ps << ", " << *b.ps << ")" << std::endl;
		swap(a.ps, b.ps);
		swap(a.i, b.i);
		std::cout << "swap("<< *a.ps << ", " << *b.ps << ")" << std::endl;
		std::cout << "END" << std::endl;
}

int main() {
	HasPtr a("a"), b("b"), c("c"), x("x");
	std::vector<HasPtr> hpvec = {
			c, b, x, a, c, b, x, a, c, b, x, a, c, 
			b, x, a, c, b, x, a, c, b, x, a, c, b, 
			x, a, c, b, x, a, c, b, x, a, c, b, x, 
			a, c, b, x, a, c, b, x, a, c, b, x, a
	};
	std::sort(hpvec.begin(), hpvec.end());
	for (auto i : hpvec)
			std::cout << i.val() << std::endl;
}
