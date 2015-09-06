#pragma once

#include "Tcp.h"

namespace Mighty
{
	namespace Net
	{
		class Server
		{
		public:
			void Init(int port);
			void Listen();

		private:
			void HandleAccept(Tcp::pointer new_connection,
				const boost::system::error_code& error);

			std::unique_ptr<boost::asio::ip::tcp::acceptor> acceptor;
			boost::asio::io_service io_service;
		};
	}
}