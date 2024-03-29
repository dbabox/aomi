/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_DO_ENABLE_COMPONENT_EVENT_HANDLER_TOKENS_H__
#define __PU_DO_ENABLE_COMPONENT_EVENT_HANDLER_TOKENS_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseEventHandlerTokens.h"

namespace ParticleUniverse
{
	/** The DoEnableComponentEventHandlerTranslator parses 'DoEnableComponentEventHandler' tokens
	*/
	class _ParticleUniverseExport DoEnableComponentEventHandlerTranslator : public ScriptTranslator
	{
		public:
			DoEnableComponentEventHandlerTranslator(void){};
			~DoEnableComponentEventHandlerTranslator(void){};
			virtual bool translateChildProperty(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node);
			virtual bool translateChildObject(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node);
	};
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	/** 
    */
	class _ParticleUniverseExport DoEnableComponentEventHandlerWriter : public ParticleEventHandlerWriter
	{
		public:

			DoEnableComponentEventHandlerWriter(void) {};
			virtual ~DoEnableComponentEventHandlerWriter(void) {};

			/** @see
				ScriptWriter::write
			*/
			virtual void write(ParticleScriptSerializer* serializer, const IElement* element);
	};

}
#endif
