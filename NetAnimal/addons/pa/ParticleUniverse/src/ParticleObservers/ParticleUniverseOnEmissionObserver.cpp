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

#include "ParticleObservers/ParticleUniverseOnEmissionObserver.h"

namespace ParticleUniverse
{
	//-----------------------------------------------------------------------
	bool OnEmissionObserver::_observe (ParticleTechnique* particleTechnique, Particle* particle, Ogre::Real timeElapsed)
	{
		if (!particle)
			return false;

		return particle->hasEventFlags(Particle::PEF_EMITTED);
	}
}
