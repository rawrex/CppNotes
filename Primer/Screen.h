//
//  Screens.cpp
//  C++ Primer
//
//  Created by Supertoy on 02/03/2020.
//  Copyright © 2020 Org.Name. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>

template <std::size_t w, std::size_t h> class Screen;

class Window_mgr {
    //std::vector<Screen> screens;
public:
    Window_mgr();
    //using ScreenID = std::vector<Screen>::size_type;
    //void clear(ScreenID);
    int foo = 0;
};

// Output operator for Screen<h, w> class
template <std::size_t w, std::size_t h>
std::ostream& operator<<(std::ostream& os, Screen<w, h>& s) {
	 os << s.contents; return os;
}

template <std::size_t w, std::size_t h> class Screen {
    //friend void Window_mgr::clear(ScreenID);
	friend std::ostream& operator<< <w, h>(std::ostream&, Screen&);
    // Type member
    using pos = std::size_t;

	// Data members
    pos cursor = 0;
    std::string contents;
    // Counting get() calls
    mutable size_t get_access_ctr = 0;
    // Auxilary functions
public:    
    // Constructors
    Screen (const char c = ' ') : contents(w * h, c) {}

    // Member functions
    char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	Screen& move (pos r, pos c);
	Screen& set(char);    
	Screen& set(pos, pos, char);
};

// Inlined in the class
template <std::size_t w, std::size_t h>
char Screen<w, h>::get(pos r, pos c) const {
    ++get_access_ctr;
    pos row = r * w;
    return contents[row + c];
}

// Explicitly inlined
template <std::size_t w, std::size_t h>
inline Screen<w, h>& Screen<w, h>::move(pos r, pos c) {
    pos row = w * r;
    cursor = row + c;
    return *this;
}

template <std::size_t w, std::size_t h>
inline Screen<w, h>& Screen<w, h>::set(char ch) {
    contents[cursor] = ch;
    return *this;
}

template <std::size_t w, std::size_t h>
inline Screen<w, h>& Screen<w, h>::set(pos r, pos col, char ch) {
    // Legal but redundant dereference
    this->contents[r * w + col] = ch;
    return *this;
}


//Window_mgr::Window_mgr() : screens{Screen(100,100)} {}

//void Window_mgr::clear(Window_mgr::ScreenID id) {
//    Screen &s = screens[id];
//    s.contents = std::string(s.h * s.w, ' ');
//}

