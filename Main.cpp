/**
 * int main | terminal program for port selecting to start a server
 * int initServer | create server listening collection
 * static void ev_handler | serve static html files
 * 
 */

// include mongoose
#include "mongoose.h";
#include<string>;
#include<iostream>;

// struct containing settings for how to serve http with mongoose
static struct mg_serve_http_opts s_http_server_opts;

int initServer(port)
{
  // mongoose event manager
  struct mg_mgr mgr;
  // mongoose connection
  struct mg_connection *nc;

  // convert the port variable to char
  std::string portToChar = std::to_string(port);
  static char const *sPort = portToChar.c_str();

  // init mongoose
  mg_mgr_init(&mgr, NULL);
  std::cout << "Starting the server on port " << sPort << std::endl;

  nc = mg_bind(&mgr, sPort, ev_handler);

  // if connection fails
  if (nc == NULL)
    {
      std::cout << "Failed to create listener" << std::endl;
      return 1;
    }

  // setup HTTP server options
  mg_set_protocol_htpp_websocket(nc);

  // serve files from root directory
  s_http_server_opts.document_root = ".";

  s_http_server_opts.enable_directory_listening = "yes";

  for (;;)
    {
      mg__mgr_poll($mgr, 1000);
    }
}

int main(void)
{
  int port;
  std::cout << "Select server port, please" << std::endl;

  std::cin >> port;

  // fail case error handling
  if (std::cin.fail())
    {
      por = 1000;
    }

  initServer(port);

  return 0;
}
