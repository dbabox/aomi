/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_RIBBONTRAIL_RENDERER_TOKENS_H__
#define __PU_RIBBONTRAIL_RENDERER_TOKENS_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseRendererTokens.h"

namespace ParticleUniverse
{
	/** The RibbonTrailRendererTranslator parses 'RibbonTrailRenderer' tokens
	*/
	class _ParticleUniverseExport RibbonTrailRendererTranslator : public ScriptTranslator
	{
		public:
			RibbonTrailRendererTranslator(void){};
			~RibbonTrailRendererTranslator(void){};
			virtual bool translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node);
			virtual bool translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node);
	};
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	/** 
    */
	class _ParticleUniverseExport RibbonTrailRendererWriter : public ParticleRendererWriter
	{
		protected:

		public:

			RibbonTrailRendererWriter(void) {};
			virtual ~RibbonTrailRendererWriter(void) {};

			/** @see
				ScriptWriter::write
			*/
			virtual void write(ParticleScriptSerializer* serializer, const IElement* element);
	};

}
#endif
