#ifndef MESSAGE_H
#define MESSAGE_H
#include <set>
#include <string>
#include <iostream>

class Message;

struct Folder {
	// Constructors
	Folder() = default;
	
	// Copy-control
	~Folder();
	Folder(const Folder&);
	Folder& operator=(const Folder &rhs);

	// Member functinos
	void remMessage(Message*);
	void addMessage(Message*);
private:
	// Data members
	std::set<Message*> messages;
	
	// Utility functions
	void remove_from_messages();
	void add_to_messages(const Folder &);
};

void Folder::addMessage(Message *m) { messages.insert(m); }
void Folder::remMessage(Message *m) { messages.erase(m); }

struct Message {
friend class Folder;
friend void swap(Message &, Message &);

	// Default constructor
	explicit Message(const std::string &s = std::string()) : contents(s) {}

	// Copy-control
	Message(const Message&);
	Message& operator=(const Message&);
	Message& operator=(Message&&);
	~Message();
	Message(Message &&);

	// Member functions
	void save(Folder&);
	void remove(Folder&);
	std::string getContents() { return contents; }

private:
	std::set<Folder*> folders;
	std::string contents;
	void add_to_folders(const Message&);
	void remove_from_folders();
	void addFolder(Folder *f) { folders.insert(f); }
	void removeFolder(Folder *f) { folders.erase(f); }
	
	void move_Folders(Message *m) {
		folders = std::move(m->folders);
		for (auto f : folders) {
			f->remMessage(m);
			f->addMessage(this);
		}
		m->folders.clear();
	}
};

// Member functions
void Message::save(Folder &f) {
	addFolder(&f);
	f.addMessage(this);
}
void Message::remove(Folder &f) {
	removeFolder(&f);
	f.remMessage(this);
}

// Utility functions
void Message::add_to_folders(const Message &m) {
	for (auto f : m.folders)
		f->addMessage(this);	
}
void Message::remove_from_folders() {
	for (auto f : folders)
		f->remMessage(this);
}

// Copy-control definitions

Message::Message(const Message &m) :
	contents(m.contents), folders(m.folders) { add_to_folders(m); }

Message::Message(Message &&m) : contents(std::move(m.contents)) { 
	move_Folders(&m); 
}

Message::~Message() { 
	remove_from_folders();
}
Message& Message::operator=(const Message &rhs) {
	remove_from_folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_folders(rhs);
	return *this;
}
Message& Message::operator=(Message &&rhs) {
	if (this != &rhs) {
		remove_from_folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}

void swap(Message &lhs, Message &rhs) {
	using std::swap;
	lhs.remove_from_folders();
	rhs.remove_from_folders();
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	lhs.add_to_folders(lhs);
	rhs.add_to_folders(rhs);
}


// Folder utility function to delete pointer to the Folder
void Folder::remove_from_messages() {
	// Can't call m->remove(*this) since using range for
	// the remove() will alter the contents of the messages container
	// while we iterating over it with the range for
	for (auto m : messages) m->removeFolder(this);
}
void Folder::add_to_messages(const Folder &f) {
	for (auto m : f.messages)
		m->addFolder(this);
}

// Folder copy-control

Folder::Folder(const Folder &f) : messages(f.messages) {
	add_to_messages(f);	
}	
Folder::~Folder() { 
	remove_from_messages();
}
Folder& Folder::operator=(const Folder &rhs) {
	remove_from_messages();
	messages = rhs.messages;
	add_to_messages(rhs);
	return *this;
}

#endif
