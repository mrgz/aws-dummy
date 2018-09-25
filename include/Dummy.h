#pragma once

#include <iostream>

#include <aws/core/Aws.h>
#include <aws/core/client/ClientConfiguration.h>

namespace dummy
{
	class Dummy
	{
		private:
			Aws::SDKOptions options;
			Aws::Client::ClientConfiguration config;

		public:
			Dummy();
			~Dummy();
			void exec();
	};
}

