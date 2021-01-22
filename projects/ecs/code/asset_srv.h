#pragma once

#include "tiny_gltf.h"
#include "comp_base.h"

#include <unordered_map>
#include <filesystem>
#include <string>
#include <memory>
#include <functional>

namespace fs = std::filesystem;

namespace efiilj 
{

	struct asset_descriptor
	{
		unsigned id;
	};

	class asset_server : component_base<asset_descriptor>
	{

	public:

		asset_server();
		~asset_server();

		bool is_open(const fs::path& file);

		void load_meshes(asset_descriptor asset);
		void load_materials(asset_descriptor asset);
		bool load_model(asset_descriptor asset);
		void load_lights(asset_descriptor asset);
		void load_cameras(asset_descriptor asset);

		void load_all(asset_descriptor asset);

		asset_descriptor open(const fs::path& file);
		asset_descriptor open(const fs::path& file, bool is_binary);
		void release(const fs::path& file);

	private:

		static size_t type_component_count(const std::string& type);
		static size_t component_type_size(int type);
		static unsigned get_format(int components);
		static unsigned get_type(int bits);

		std::unordered_map<std::string, tinygltf::Model*> _models;
	};
}
