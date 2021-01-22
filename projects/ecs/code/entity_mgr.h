#include "entity.h"

#include <unordered_set>

namespace efiilj
{
	class entity_manager
	{
//		private:
//
//			std::unordered_set<game_entity, unsigned> _entities;
//			game_entity _next;
//
//		public:
//
//			// This entity manager is temporary and can easily be replaced in the future
//			// For a more efficient one (less hash lookups)
//
//			entity_manager()
//				: _next({0})
//			{ }
//
//			~entity_manager()
//				= default;
//
//			game_entity create()
//			{
//				++_next.id;
//				while (is_alive(_next))
//					++_next.id;
//				_entities.insert(_next);
//				return _next;
//			}
//
//			bool is_alive(game_entity e)
//			{
//				return _entities.find(e) != _entities.end();
//			}
//
//			void destroy(game_entity e)
//			{
//				_entities.erase(e);
//			}
	};
}
