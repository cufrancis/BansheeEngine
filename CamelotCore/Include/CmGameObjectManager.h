#pragma once

#include "CmPrerequisites.h"
#include "CmModule.h"

namespace CamelotFramework
{
	class CM_EXPORT GameObjectManager : public Module<GameObjectManager>
	{
	public:
		GameObjectManager();
		~GameObjectManager();

		UINT64 registerObject(GameObject* object);
		void unregisterObject(GameObject* object);

		GameObject* getObject(UINT64 id) const;
		bool objectExists(UINT64 id) const;

	private:
		UINT64 mNextAvailableID; // 0 is not a valid ID
		Map<UINT64, GameObject*>::type mObjects;
	};
}