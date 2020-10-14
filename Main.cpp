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

int main(void)
{
	int port;
	std::cout << "Select server port, please" << std::endl;

	std::cin >> port;
}