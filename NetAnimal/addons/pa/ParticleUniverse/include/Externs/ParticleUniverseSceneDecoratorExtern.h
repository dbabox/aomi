/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_SCENE_DECORATOR_EXTERN_H__
#define __PU_SCENE_DECORATOR_EXTERN_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseExtern.h"

namespace ParticleUniverse
{
	/** The SceneDecoratorExtern is a test class that can be used to add additional objects to the scene. This allows quick
		prototyping, but it it not really usable in a real situation.
    */
	class _ParticleUniverseExport SceneDecoratorExtern : public Extern
	{
		public:
			SceneDecoratorExtern(void);
	        virtual ~SceneDecoratorExtern(void) {};

			/** see Extern::_prepare
			*/
			virtual void _prepare(ParticleTechnique* technique);

			/** see Extern::_unprepare
			*/
			virtual void _unprepare(ParticleTechnique* technique);

			/** see Extern::_interface
			*/
			virtual void _interface(ParticleTechnique* technique, 
				Particle* particle, 
				Ogre::Real timeElapsed);

			/** Create the desired entity
	        */
			void createEntity(void);

			/** Destroy the entity again
	        */
			void destroyEntity(void);

			/** Return the name of the mesh
	        */
			const Ogre::String& getMeshName(void) const;

			/** Set the name of the mesh
	        */
			void setMeshName(const Ogre::String& meshName);

			/** Return the name of the material used for the entity.
	        */
			const Ogre::String& getMaterialName(void) const;

			/** Set the name of the material used for the entity.
	        */
			void setMaterialName(const Ogre::String& materialName);

			/** Returns the scale value to which the node must be set.
	        */
			const Ogre::Vector3& getScale(void) const;

			/** Sets the scale value to which the node must be set.
	        */
			void setScale(Ogre::Vector3& scale);

			/** Returns the position value to which the node must be set.
	        */
			const Ogre::Vector3& getPosition(void) const;

			/** Sets the position value to which the node must be set.
	        */
			void setPosition(Ogre::Vector3& position);

			/** See Extern::_notifyStart.
			*/
			virtual void _notifyStart (void);

			/** See Extern::_notifyStop.
			*/
			virtual void _notifyStop (void);

			/** See Extern:copyAttributesTo
	        */
			virtual void copyAttributesTo (Extern* externObject);

		protected:

			bool mEntitySet;
			Ogre::Entity* mEntity;
			Ogre::String mMeshName;
			Ogre::String mEntityName;
			Ogre::String mMaterialName;
			bool mMaterialNameSet;
			Ogre::Vector3 mScale;
			Ogre::Vector3 mPosition;
			Ogre::SceneNode* mSubnode;
			unsigned int mCount;

	};

}
#endif
