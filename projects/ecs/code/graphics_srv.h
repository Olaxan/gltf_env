#pragma once

#include <vector>

namespace efiilj
{


	class graphics_server
	{
		graphics_server();

		~graphics_server()
			= default;

		
		private:

		struct 
		{
			std::vector<unsigned> vao;

		} _data;
	};
}
