#ifndef _MCG_MESSAGE_OBSERVER
#define _MCG_MESSAGE_OBSERVER

#include <string>

class message_observer {
public:
   virtual void onMessageReceived(std::string message) = 0;
};


#endif
