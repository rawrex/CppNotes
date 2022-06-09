#ifndef FOLDER_H
#define FOLDER_H
#include "Message.h"

struct Folder {
	void remMessage(Message*);
	void addMessage(Message*);
private:
	std::set<Message*> messages;
};
#endif
