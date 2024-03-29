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

#include "ParticleUniverseDynamicAttributeFactory.h"
#include "ParticleUniverseDynamicAttributeTokens.h"

namespace ParticleUniverse
{
	/**************************************************************************
	 * DynamicAttributeTranslator
	 *************************************************************************/
	DynamicAttributeTranslator::DynamicAttributeTranslator()
		:mDynamicAttribute(0)
	{
	}
	//-------------------------------------------------------------------------
	void DynamicAttributeTranslator::translate(Ogre::ScriptCompiler* compiler, const Ogre::AbstractNodePtr &node)
	{
		Ogre::ObjectAbstractNode* obj = reinterpret_cast<Ogre::ObjectAbstractNode*>(node.get());

		// The first value is the type
		Ogre::String type = obj->name;

		if (type == token[TOKEN_DYN_RANDOM])
		{
			mDynamicAttribute = OGRE_NEW_T(DynamicAttributeRandom, Ogre::MEMCATEGORY_SCENE_OBJECTS)();
		}
		else if (type == token[TOKEN_DYN_CURVED_LINEAR])
		{
			mDynamicAttribute = OGRE_NEW_T(DynamicAttributeCurved, Ogre::MEMCATEGORY_SCENE_OBJECTS)(IT_LINEAR);
		}
		else if (type == token[TOKEN_DYN_CURVED_SPLINE])
		{
			mDynamicAttribute = OGRE_NEW_T(DynamicAttributeCurved, Ogre::MEMCATEGORY_SCENE_OBJECTS)(IT_SPLINE);
		}
		else if (type == token[TOKEN_DYN_OSCILLATE])
		{
			mDynamicAttribute = OGRE_NEW_T(DynamicAttributeOscillate, Ogre::MEMCATEGORY_SCENE_OBJECTS)();
		}
		else
		{
			// Create a fixed one.
			mDynamicAttribute = OGRE_NEW_T(DynamicAttributeFixed, Ogre::MEMCATEGORY_SCENE_OBJECTS)();
		}

		// Run through properties
		for(Ogre::AbstractNodeList::iterator i = obj->children.begin(); i != obj->children.end(); ++i)
		{
			if((*i)->type == Ogre::ANT_PROPERTY)
			{
				Ogre::PropertyAbstractNode* prop = reinterpret_cast<Ogre::PropertyAbstractNode*>((*i).get());
				if (prop->name == token[TOKEN_DYN_MIN])
				{
					// Property: min
					if (mDynamicAttribute->getType() == DynamicAttribute::DAT_RANDOM)
					{
						if (passValidateProperty(compiler, prop, token[TOKEN_DYN_MIN], VAL_REAL))
						{
							Ogre::Real val = 0.0f;
							if(getReal(prop->values.front(), &val))
							{
								(static_cast<DynamicAttributeRandom*>(mDynamicAttribute))->setMin(val);
							}
						}
					}
				}
				else if (prop->name == token[TOKEN_DYN_MAX])
				{
					// Property: max
					if (mDynamicAttribute->getType() == DynamicAttribute::DAT_RANDOM)
					{
						if (passValidateProperty(compiler, prop, token[TOKEN_DYN_MAX], VAL_REAL))
						{
							Ogre::Real val = 0.0f;
							if(getReal(prop->values.front(), &val))
							{
								(static_cast<DynamicAttributeRandom*>(mDynamicAttribute))->setMax(val);
							}
						}
					}
				}
				else if (prop->name == token[TOKEN_DYN_CONTROL_POINT])
				{
					// Property: control_point
					if (mDynamicAttribute->getType() == DynamicAttribute::DAT_CURVED)
					{
						if (passValidateProperty(compiler, prop, token[TOKEN_DYN_CONTROL_POINT], VAL_VECTOR2))
						{
							Ogre::Vector2 val;
							if(getVector2(prop->values.begin(), prop->values.end(), &val))
							{
								(static_cast<DynamicAttributeCurved*>(mDynamicAttribute))->addControlPoint(val.x, val.y);
							}
						}
					}
				}
				else if (prop->name == token[TOKEN_DYN_OSCILLATE_FREQUENCY])
				{
					// Property: oscillate_frequency
					if (mDynamicAttribute->getType() == DynamicAttribute::DAT_OSCILLATE)
					{
						if (passValidateProperty(compiler, prop, token[TOKEN_DYN_OSCILLATE_FREQUENCY], VAL_REAL))
						{
							Ogre::Real val = 0.0f;
							if(getReal(prop->values.front(), &val))
							{
								(static_cast<DynamicAttributeOscillate*>(mDynamicAttribute))->setFrequency(val);
							}
						}
					}
				}
				else if (prop->name == token[TOKEN_DYN_OSCILLATE_PHASE])
				{
					// Property: oscillate_phase
					if (mDynamicAttribute->getType() == DynamicAttribute::DAT_OSCILLATE)
					{
						if (passValidateProperty(compiler, prop, token[TOKEN_DYN_OSCILLATE_PHASE], VAL_REAL))
						{
							Ogre::Real val = 0.0f;
							if(getReal(prop->values.front(), &val))
							{
								(static_cast<DynamicAttributeOscillate*>(mDynamicAttribute))->setPhase(val);
							}
						}
					}
				}
				else if (prop->name == token[TOKEN_DYN_OSCILLATE_BASE])
				{
					// Property: oscillate_base
					if (mDynamicAttribute->getType() == DynamicAttribute::DAT_OSCILLATE)
					{
						if (passValidateProperty(compiler, prop, token[TOKEN_DYN_OSCILLATE_BASE], VAL_REAL))
						{
							Ogre::Real val = 0.0f;
							if(getReal(prop->values.front(), &val))
							{
								(static_cast<DynamicAttributeOscillate*>(mDynamicAttribute))->setBase(val);
							}
						}
					}
				}
				else if (prop->name == token[TOKEN_DYN_OSCILLATE_AMPLITUDE])
				{
					// Property: oscillate_amplitude
					if (mDynamicAttribute->getType() == DynamicAttribute::DAT_OSCILLATE)
					{
						if (passValidateProperty(compiler, prop, token[TOKEN_DYN_OSCILLATE_AMPLITUDE], VAL_REAL))
						{
							Ogre::Real val = 0.0f;
							if(getReal(prop->values.front(), &val))
							{
								(static_cast<DynamicAttributeOscillate*>(mDynamicAttribute))->setAmplitude(val);
							}
						}
					}
				}
				else if (prop->name == token[TOKEN_DYN_OSCILLATE_TYPE])
				{
					// Property: oscillate_type
					if (mDynamicAttribute->getType() == DynamicAttribute::DAT_OSCILLATE)
					{
						if (passValidateProperty(compiler, prop, token[TOKEN_DYN_OSCILLATE_TYPE], VAL_STRING))
						{
							Ogre::String val;
							if(getString(prop->values.front(), &val))
							{
								if (val == token[TOKEN_DYN_SINE])
								{
									(static_cast<DynamicAttributeOscillate*>(mDynamicAttribute))->setOscillationType(
										DynamicAttributeOscillate::OSCT_SINE);
								}
								else if (val == token[TOKEN_DYN_SQUARE])
								{
									(static_cast<DynamicAttributeOscillate*>(mDynamicAttribute))->setOscillationType(
										DynamicAttributeOscillate::OSCT_SQUARE);
								}
							}
						}
					}
				}
				else
				{
					errorUnexpectedProperty(compiler, prop);
				}

			}
			else if((*i)->type == Ogre::ANT_OBJECT)
			{
				processNode(compiler, *i);
			}
            else
			{
				errorUnexpectedToken(compiler, *i);
			}
		}

		// Set it in the context
		obj->context = Ogre::Any(mDynamicAttribute);
	}
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	//-----------------------------------------------------------------------
	void DynamicAttributeWriter::write(ParticleScriptSerializer* serializer, const IElement* element)
	{
		// The DynamicAttribute doesn't know its context (which property), so that information is passed from another level.
		const DynamicAttribute* dynAttribute = static_cast<const DynamicAttribute*>(element);
		switch(dynAttribute->getType())
		{
			case DynamicAttribute::DAT_FIXED:
				{
					const DynamicAttributeFixed* dynFixed = static_cast<const DynamicAttributeFixed*>(element);
					DynamicAttributeFixed df(*dynFixed); // Needed to get rid of the const, because the getValue function is not a const!
					serializer->writeLine(
						serializer->getKeyword(), 
						Ogre::StringConverter::toString(df.getValue()),
						serializer->getIndentation());
				}
				break;

			case DynamicAttribute::DAT_RANDOM:
				{
					serializer->writeLine(serializer->getKeyword(), token[TOKEN_DYN_RANDOM], serializer->getIndentation());
					serializer->writeLine("{", serializer->getIndentation());
					const DynamicAttributeRandom* dynRandom = static_cast<const DynamicAttributeRandom*>(element);
					serializer->writeLine(token[TOKEN_DYN_MIN], Ogre::StringConverter::toString(dynRandom->getMin()), serializer->getIndentation() + 4);
					serializer->writeLine(token[TOKEN_DYN_MAX], Ogre::StringConverter::toString(dynRandom->getMax()), serializer->getIndentation() + 4);
					serializer->writeLine("}", serializer->getIndentation());
				}
				break;

			case DynamicAttribute::DAT_CURVED:
				{
					const DynamicAttributeCurved* dynCurved = static_cast<const DynamicAttributeCurved*>(element);
					Ogre::String type = token[TOKEN_DYN_CURVED_LINEAR];
					if (dynCurved->getInterpolationType() == IT_SPLINE)
					{
						type = token[TOKEN_DYN_CURVED_SPLINE];
					}
					serializer->writeLine(serializer->getKeyword(), type, serializer->getIndentation());
					serializer->writeLine("{", serializer->getIndentation());

					// Write controlpoints
					const DynamicAttributeCurved::ControlPointList controlPoints = dynCurved->getControlPoints();
					if (!controlPoints.empty())
					{
						DynamicAttributeCurved::ControlPointList::const_iterator it;
						DynamicAttributeCurved::ControlPointList::const_iterator itEnd = controlPoints.end();
						for(it = controlPoints.begin(); it != itEnd; ++it)
						{
							serializer->writeLine(token[TOKEN_DYN_CONTROL_POINT], Ogre::StringConverter::toString(*it), serializer->getIndentation() + 4);
						}
					}

					serializer->writeLine("}", serializer->getIndentation());
				}
				break;

			case DynamicAttribute::DAT_OSCILLATE:
				{
					serializer->writeLine(serializer->getKeyword(), token[TOKEN_DYN_OSCILLATE], serializer->getIndentation());
					serializer->writeLine("{", serializer->getIndentation());
					const DynamicAttributeOscillate* dynOscillate = static_cast<const DynamicAttributeOscillate*>(element);
					serializer->writeLine(token[TOKEN_DYN_OSCILLATE_FREQUENCY], Ogre::StringConverter::toString(dynOscillate->getFrequency()), serializer->getIndentation() + 4);
					serializer->writeLine(token[TOKEN_DYN_OSCILLATE_PHASE], Ogre::StringConverter::toString(dynOscillate->getPhase()), serializer->getIndentation() + 4);
					serializer->writeLine(token[TOKEN_DYN_OSCILLATE_BASE], Ogre::StringConverter::toString(dynOscillate->getBase()), serializer->getIndentation() + 4);
					serializer->writeLine(token[TOKEN_DYN_OSCILLATE_AMPLITUDE], Ogre::StringConverter::toString(dynOscillate->getAmplitude()), serializer->getIndentation() + 4);
					Ogre::String type = token[TOKEN_DYN_SINE];
					if (dynOscillate->getOscillationType() == DynamicAttributeOscillate::OSCT_SQUARE)
					{
						type = token[TOKEN_DYN_SQUARE];
					}
					serializer->writeLine(token[TOKEN_DYN_OSCILLATE_TYPE], type, serializer->getIndentation() + 4);
					serializer->writeLine("}", serializer->getIndentation());
				}
				break;
		}
	}

}
