#ifndef H_CLIENT_MCG
#define H_CLIENT_MCG

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <deque>
#include <boost/array.hpp>
#include <vector>
#include <string>

#include "message_observer.h"

#define BUFFER_MAX_SIZE 10000

class client
{
private:

  std::vector<message_observer*> msg_listeners;

  boost::asio::ip::tcp::socket sock_;
  boost::asio::io_service & io_service_;
  std::deque<std::string> message_queue;
  boost::asio::streambuf response_;

  void do_write(std::string msg);
  void handle_write(const boost::system::error_code& error);
  void do_close();

  void handle_connect(const boost::system::error_code& error);
  void handle_read(const boost::system::error_code& error);

public:

  client(boost::asio::io_service& io_service, boost::asio::ip::tcp::resolver::iterator endpoint_iterator);
  void send(std::string && message);
  void close();
  void add_observer(message_observer* observer);
  void remove_observer(message_observer* observer);
  void notify_all(std::string message);
  virtual ~client();
};


#endif
