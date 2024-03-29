/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#include "ParticleUniversePCH.h"

#ifndef PARTICLE_UNIVERSE_EXPORTS
#define PARTICLE_UNIVERSE_EXPORTS
#endif

#include "ParticleAffectors/ParticleUniverseBaseForceAffector.h"

namespace ParticleUniverse
{
	// Constants
	const Ogre::Vector3 BaseForceAffector::DEFAULT_FORCE_VECTOR = Ogre::Vector3::ZERO;
	const BaseForceAffector::ForceApplication BaseForceAffector::DEFAULT_FORCE_APPL = BaseForceAffector::FA_ADD;

	//-----------------------------------------------------------------------
	BaseForceAffector::BaseForceAffector(void) : 
		ParticleAffector(),
		mForceVector(DEFAULT_FORCE_VECTOR),
		mScaledVector(Ogre::Vector3::ZERO),
		mForceApplication(DEFAULT_FORCE_APPL)
	{
	}
	//-----------------------------------------------------------------------
	void BaseForceAffector::copyAttributesTo (ParticleAffector* affector)
	{
		ParticleAffector::copyAttributesTo(affector);

		BaseForceAffector* baseForceAffector = static_cast<BaseForceAffector*>(affector);
		baseForceAffector->mForceVector = mForceVector;
		baseForceAffector->mForceApplication = mForceApplication;
	}
	//-----------------------------------------------------------------------
	const Ogre::Vector3& BaseForceAffector::getForceVector(void) const
	{
		return mForceVector;
	}
	//-----------------------------------------------------------------------
	void BaseForceAffector::setForceVector(const Ogre::Vector3& forceVector)
	{
		mForceVector = forceVector;
	}
	//-----------------------------------------------------------------------
	BaseForceAffector::ForceApplication BaseForceAffector::getForceApplication(void) const
	{
		return mForceApplication;
	}
	//-----------------------------------------------------------------------
	void BaseForceAffector::setForceApplication(BaseForceAffector::ForceApplication forceApplication)
	{
		mForceApplication = forceApplication;
	}
}
