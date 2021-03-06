//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Marko Pintera (marko.pintera@gmail.com). All rights reserved. **********************//
#pragma once

#include "BsScriptEnginePrerequisites.h"
#include "BsScriptResource.h"
#include "BsScriptObject.h"

namespace BansheeEngine
{
	/** @addtogroup ScriptInteropEngine
	 *  @{
	 */

	/**	Interop class between C++ & CLR for ManagedResource. */
	class BS_SCR_BE_EXPORT ScriptManagedResource : public ScriptObject<ScriptManagedResource, ScriptResourceBase>
	{
	public:
		SCRIPT_OBJ(ENGINE_ASSEMBLY, "BansheeEngine", "ManagedResource")

		ScriptManagedResource(MonoObject* instance, const HManagedResource& resource);

		/** @copydoc ScriptResourceBase::getGenericHandle */
		HResource getGenericHandle() const override { return mResource; }

		/** @copydoc ScriptResourceBase::setResource */
		void setResource(const HResource& resource) override;

		/**	Returns a handle to the internal wrapped resource. */
		const HManagedResource& getHandle() const { return mResource; }

		/**	Creates an empty, uninitialized managed instance of the resource interop object. */
		static MonoObject* createInstance();
	private:
		friend class ScriptResourceManager;

		/** @copydoc ScriptObjectBase::beginRefresh */
		virtual ScriptObjectBackup beginRefresh() override;

		/** @copydoc ScriptObjectBase::endRefresh */
		virtual void endRefresh(const ScriptObjectBackup& backupData) override;

		/** @copydoc ScriptObjectBase::_createManagedInstance */
		virtual MonoObject* _createManagedInstance(bool construct) override;

		/** @copydoc ScriptObjectBase::_onManagedInstanceDeleted */
		void _onManagedInstanceDeleted() override;

		HManagedResource mResource;
		String mNamespace;
		String mType;

		/************************************************************************/
		/* 								CLR HOOKS						   		*/
		/************************************************************************/
		static void internal_createInstance(MonoObject* instance);
	};

	/** @} */
}