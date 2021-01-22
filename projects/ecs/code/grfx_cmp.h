#pragma once

#include "entity.h"
#include "comp_base.h"

#include <vector>
#include <utility>
#include <memory>
#include <string>

namespace efiilj
{
	struct graphics_instance
	{
		unsigned id;
	};

	struct primitive
	{
		unsigned material;
		unsigned offset;
	};

	struct model
	{
		std::vector<primitive> prims;
	};

	class graphics_component_manager 
		: component_base<graphics_instance>
	{
		public:

		graphics_component_manager();

		~graphics_component_manager()
			= default;

		void append_instance() override;
		void remove_instance(graphics_instance inst) override;

		void set_uri(graphics_instance inst, std::string path);
		std::string get_uri(graphics_instance inst);

		void load(graphics_instance inst);
		void bind(graphics_instance inst);

		private:

		struct
		{
			std::vector<std::string> paths;
			std::vector<unsigned> vao;
			std::vector<primitive> prims;
			std::vector<bool> loaded;
		} _data;

		//std::shared_ptr<asset_server> _assets;
	};
}
