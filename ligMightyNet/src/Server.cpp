#include "stdafx.h"
#include "Server.h"

#include "Tcp.h"

using namespace boost::asio::ip;

namespace Mighty
{
	namespace Net
	{
		void Server::Init(int port)
		{
			acceptor.reset(new tcp::acceptor(io_service, tcp::endpoint(tcp::v4(), port)));
		}

		void Server::Listen()
		{
			Tcp::pointer new_connection =
				Tcp::create(acceptor->get_io_service());

			acceptor->async_accept(new_connection->socket(),
				boost::bind(&Server::HandleAccept, this, new_connection,
					boost::asio::placeholders::error));
		}
	}
}