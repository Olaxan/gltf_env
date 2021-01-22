#pragma once

#include "entity.h"

#include <vector>
#include <unordered_map>

namespace efiilj
{

	template <class INSTANCE>
	class component_base
	{

		private:

			unsigned _count;
			std::vector<game_entity> _owners;
			std::unordered_map<game_entity, INSTANCE, unsigned> _entities;

		public:

		component_base() 
			: _count(0) { }

		virtual ~component_base()
			= default;

		INSTANCE register_entity(game_entity e)
		{
			if (this->has_component(e))
				return this->get_component(e);

			const INSTANCE inst = { _count };

			_owners.emplace_back(e);
			append_instance();
			_entities[e] = inst;

			this->on_activate(inst);

			_count++;
			
			return inst;
		}

		void deregister_entity(game_entity e)
		{
			if (!has_component(e))
				return;

			const unsigned last = _count - 1;
			const game_entity last_e = _owners[last];
			const INSTANCE inst = get_component(e);

			on_deactivate(inst);
			remove_instance(inst);

			_owners[inst.id] = last_e;

			_entities[last_e] = inst;
			_entities.erase(e);

			_count--;
		}

		bool has_component(game_entity e) const
		{
			return _entities.find(e) != _entities.end();
		}

		INSTANCE get_component(game_entity e) const
		{
			if (has_component(e))
				return _entities[e];

			return { 0 };
		}

		game_entity get_owner(INSTANCE inst) const
		{
			return _owners[inst.id];
		}

		unsigned count() const { return _count; }

		virtual void append_instance() = 0; 
		virtual void remove_instance(INSTANCE instance) = 0;
	};
}
