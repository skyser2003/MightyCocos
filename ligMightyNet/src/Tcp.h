#pragma once

namespace Mighty
{
	namespace Net
	{
		class Tcp
		{
		private:
			Tcp(boost::asio::io_service& io_service)
				: socket_(io_service)
			{
			}

		public:
			using tcp = boost::asio::ip::tcp;

			typedef boost::shared_ptr<Tcp> pointer;

			static pointer create(boost::asio::io_service& io_service)
			{
				return pointer(new Tcp(io_service));
			}

			tcp::socket& socket()
			{
				return socket_;
			}

		private:
			tcp::socket socket_;
			std::string message_;
		};
	}
}
