#include "grfx_cmp.h"

#include <GL/glew.h>

namespace efiilj
{
	graphics_component_manager::graphics_component_manager()
	{}

	void graphics_component_manager::append_instance() 
	{
		_data.paths.emplace_back("");
		_data.vao.emplace_back(0);
		_data.loaded.emplace_back(false);
	}

	void graphics_component_manager::remove_instance(graphics_instance inst) 
	{

	}

	void graphics_component_manager::set_uri(
			graphics_instance inst, std::string path)
	{
		_data.paths[inst.id] = path;
	}

	std::string graphics_component_manager::get_uri(
			graphics_instance inst)
	{
		return _data.paths[inst.id];
	}

	void graphics_component_manager::load(graphics_instance inst)
	{
	}

	void graphics_component_manager::bind(graphics_instance inst)
	{
		if (_data.loaded[inst.id])
			glBindVertexArray(_data.vao[inst.id]);
	}
}
