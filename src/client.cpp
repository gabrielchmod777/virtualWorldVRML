#include "client.h"
#include <string>
#include <iostream>
#include <algorithm>
#include "message_observer.h"


#define BUFFER_MAX_SIZE 4096

std::string keep = "";

client::client(boost::asio::io_service& io_service, boost::asio::ip::tcp::resolver::iterator endpoint_iterator) : sock_(io_service), io_service_(io_service)
{
  boost::asio::async_connect(
    sock_,
    endpoint_iterator,
    boost::bind( &client::handle_connect,
		 this,
		 boost::asio::placeholders::error)
  );
}

void client::send(std::string && message)
{
  io_service_.post(boost::bind(&client::do_write, this, message));
}

void client::do_write(std::string msg)
{

  bool sending_data = !message_queue.empty();
  message_queue.push_back(msg);
  if(!sending_data)
    {
      boost::asio::async_write(sock_,
          boost::asio::buffer(message_queue.front().data(),
                              message_queue.front().length()),
          boost::bind(&client::handle_write, this,
                      boost::asio::placeholders::error)
	  );
    }
}

void client::handle_write(const boost::system::error_code& error)
{

  if (!error)
    {
      message_queue.pop_front();
      if (!message_queue.empty())
	{
	  boost::asio::async_write(
	    sock_,
	    boost::asio::buffer(message_queue.front().data(),
	 	                message_queue.front().length()),
	    boost::bind(&client::handle_write, this,
		       boost::asio::placeholders::error)
	    );
	}
    }
  else
    {
      do_close();
    }
}

void client::do_close()
{
  //sock_.close();
}

void client::close()
{

}

void client::handle_connect(const boost::system::error_code& error)
{

  if(!error)
    {

      boost::asio::async_read(
	sock_, response_,
        boost::asio::transfer_at_least(1),
	boost::bind( &client::handle_read, 
                     this,
                     boost::asio::placeholders::error)
	  ); 
    }
}


  void client::handle_read(const boost::system::error_code& error)
  {
    if (!error)
      {

	//std::cout<<&response_;
	std::string targetstring;
	std::istream is(&response_);
	is >> targetstring;
	notify_all(targetstring);

        boost::asio::async_read(
				sock_, response_,
				boost::asio::transfer_at_least(1),
				boost::bind( &client::handle_read,this,
					     boost::asio::placeholders::error)
	  );	
       }
     else
       {
         do_close();
       }
}

void client::add_observer(message_observer* observer)
{
  msg_listeners.push_back(observer);
}


void client::remove_observer(message_observer* observer)
{
  msg_listeners.erase(std::remove(msg_listeners.begin(), msg_listeners.end(), observer), msg_listeners.end()); 
}

void client::notify_all(std::string message){
  for_each(msg_listeners.begin(), msg_listeners.end(), 

	   [message](message_observer * observer)
	   {
	     observer->onMessageReceived(message);
	   }
	   ); 
    
}

client::~client()
{
}
