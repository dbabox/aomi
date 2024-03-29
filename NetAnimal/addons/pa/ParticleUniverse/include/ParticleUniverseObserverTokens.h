/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_OBSERVER_TOKENS_H__
#define __PU_OBSERVER_TOKENS_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseObserver.h"
#include "ParticleUniverseScriptDeserializer.h"

namespace ParticleUniverse
{
	/** The ObserverTranslator parses 'Observer' tokens
	*/
	class _ParticleUniverseExport ObserverTranslator : public ScriptTranslator
	{
		protected:
			ParticleObserver* mObserver;

		public:
			ObserverTranslator(void);
			virtual ~ObserverTranslator(void){};
			virtual void translate(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node);
	};
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	/** 
    */
	class _ParticleUniverseExport ParticleObserverWriter : public ScriptWriter
	{
		public:

			ParticleObserverWriter(void) {};
			virtual ~ParticleObserverWriter(void) {};

			/** @see
				ScriptWriter::write
			*/
			virtual void write(ParticleScriptSerializer* serializer, const IElement* element);
	};

}
#endif
