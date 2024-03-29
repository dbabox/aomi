/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_EMITTER_H__
#define __PU_EMITTER_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseCameraDependency.h"
#include "ParticleUniverseCameraDependencyFactory.h"
#include "ParticleUniverseIAlias.h"
#include "ParticleUniverseParticle.h"
#include "ParticleUniverseIElement.h"
#include "ParticleUniverseDynamicAttribute.h"
#include "ParticleUniverseDynamicAttributeFactory.h"

namespace ParticleUniverse
{
	/** Abstract class defining the interface to be implemented by particle emitters.
	@remarks
		Subclasses of ParticleEmitters are responsible of spawning the particles of a particle technique.
		This class defines the interface, and provides a few implementations of some basic functions.
    */
	class _ParticleUniverseExport ParticleEmitter : public Particle, public IAlias, public IElement
	{
		public:
			// Default values
			static const bool DEFAULT_ENABLED;
			static const Ogre::Vector3 DEFAULT_POSITION;
			static const bool DEFAULT_KEEP_LOCAL;
			static const Ogre::Vector3 DEFAULT_DIRECTION;
			static const Ogre::Quaternion DEFAULT_ORIENTATION;
			static const Ogre::Quaternion DEFAULT_ORIENTATION_RANGE_START;
			static const Ogre::Quaternion DEFAULT_ORIENTATION_RANGE_END;
			static const Particle::ParticleType DEFAULT_EMITS;
			static const Ogre::uint16 DEFAULT_START_TEXTURE_COORDS;
			static const Ogre::uint16 DEFAULT_END_TEXTURE_COORDS;
			static const Ogre::uint16 DEFAULT_TEXTURE_COORDS;
			static const Ogre::ColourValue DEFAULT_START_COLOUR_RANGE;
			static const Ogre::ColourValue DEFAULT_END_COLOUR_RANGE;
			static const Ogre::ColourValue DEFAULT_COLOUR;
			static const bool DEFAULT_AUTO_DIRECTION;
			static const bool DEFAULT_FORCE_EMISSION;
			static const Ogre::Real DEFAULT_EMISSION_RATE;
			static const Ogre::Real DEFAULT_TIME_TO_LIVE;
			static const Ogre::Real DEFAULT_MASS;
			static const Ogre::Real DEFAULT_VELOCITY;
			static const Ogre::Real DEFAULT_DURATION;
			static const Ogre::Real DEFAULT_REPEAT_DELAY;
			static const Ogre::Real DEFAULT_ANGLE;
			static const Ogre::Real DEFAULT_DIMENSIONS;
			static const Ogre::Real DEFAULT_WIDTH;
			static const Ogre::Real DEFAULT_HEIGHT;
			static const Ogre::Real DEFAULT_DEPTH;

			ParticleEmitter(void);
			
			virtual ~ParticleEmitter(void);

			/** Todo
	        */
			inline ParticleTechnique* getParentTechnique(void) const {return mParentTechnique;};
			void setParentTechnique(ParticleTechnique* parentTechnique);

			/** Todo
	        */
			inline const Ogre::String& getEmitterType(void) const {return mEmitterType;};
			void setEmitterType(const Ogre::String& emitterType) {mEmitterType = emitterType;};

			/** Todo
	        */
			inline const Ogre::String& getName(void) const {return mName;};
			void setName(const Ogre::String& name) {mName = name;};

			/** Todo
	        */
			inline DynamicAttribute* getDynAngle(void) const {return mDynAngle;};
			void setDynAngle(DynamicAttribute* dynAngle);

			/** Todo
	        */
			inline DynamicAttribute* getDynEmissionRate(void) const {return mDynEmissionRate;};
			void setDynEmissionRate(DynamicAttribute* dynEmissionRate);

			/** Todo
	        */
			inline DynamicAttribute* getDynTotalTimeToLive(void) const {return mDynTotalTimeToLive;};
			void setDynTotalTimeToLive(DynamicAttribute* dynTotalTimeToLive);

			/** Todo
	        */
			inline DynamicAttribute* getDynParticleMass(void) const {return mDynParticleMass;};
			void setDynParticleMass(DynamicAttribute* dynParticleMass);

			/** Todo
	        */
			inline DynamicAttribute* getDynVelocity(void) const {return mDynVelocity;};
			void setDynVelocity(DynamicAttribute* dynVelocity);

			/** Todo
	        */
			inline DynamicAttribute* getDynDuration(void) const {return mDynDuration;};
			void setDynDuration(DynamicAttribute* dynDuration);
			void setDynDurationSet(bool durationSet);

			/** Todo
	        */
			inline DynamicAttribute* getDynRepeatDelay(void) const {return mDynRepeatDelay;};
			void setDynRepeatDelay(DynamicAttribute* dynRepeatDelay);
			void setDynRepeatDelaySet(bool repeatDelaySet);

			/** Todo
	        */
			inline DynamicAttribute* getDynParticleAllDimensions(void) const {return mDynParticleAllDimensions;};
			void setDynParticleAllDimensions(DynamicAttribute* dynParticleAllDimensions);
			void setDynParticleAllDimensionsSet(bool particleAllDimensionsSet);

			/** Todo
	        */
			inline DynamicAttribute* getDynParticleWidth(void) const {return mDynParticleWidth;};
			void setDynParticleWidth(DynamicAttribute* dynParticleWidth);
			void setDynParticleWidthSet(bool particleWidthSet);

			/** Todo
	        */
			inline DynamicAttribute* getDynParticleHeight(void) const {return mDynParticleHeight;};
			void setDynParticleHeight(DynamicAttribute* dynParticleHeight);
			void setDynParticleHeightSet(bool particleHeightSet);

			/** Todo
	        */
			inline DynamicAttribute* getDynParticleDepth(void) const {return mDynParticleDepth;};
			void setDynParticleDepth(DynamicAttribute* dynParticleDepth);
			void setDynParticleDepthSet(bool particleDepthSet);

			/** Todo
	        */
			inline ParticleType getEmitsType(void) const {return mEmitsType;};
			void setEmitsType(ParticleType emitsType) {mEmitsType = emitsType;};

			/** Todo
	        */
			inline const Ogre::String& getEmitsName(void) const {return mEmitsName;};
			void setEmitsName(const Ogre::String& emitsName);

			/** Set the distance-value and inc. indication to recalculate the emission rate.
	        */
			void setEmissionRateCameraDependency(CameraDependency* cameraDependency);
			void setEmissionRateCameraDependency(Ogre::Real squareDistance, bool inc = false);

			/** Todo
	        */
			CameraDependency* getEmissionRateCameraDependency(void) const;

			/** Returns the base direction of the particle that is going to be emitted.
			*/
			inline virtual const Ogre::Vector3& getParticleDirection(void) const;

			/** Returns the originally set particle direction. This value is not affected by affectors, angle, etc.
			*/
			const Ogre::Vector3& getOriginalParticleDirection(void) const;

			/** Returns the base orientation of the particle that is going to be emitted.
			*/
			inline const Ogre::Quaternion& getParticleOrientation(void) const;

			/** Set the orientation of the particle.
			*/
			inline void setParticleOrientation(const Ogre::Quaternion& orientation);

			/** Returns the start orientation of the particle that is going to be emitted.
			@remarks
				The orientation is generated random between mParticleOrientationRangeStart and mParticleOrientationRangeEnd.
			*/
			inline const Ogre::Quaternion& getParticleOrientationRangeStart(void) const;

			/** Set start orientation of the particle that is going to be emitted.
			@remarks
				The orientation is generated random between mParticleOrientationRangeStart and mParticleOrientationRangeEnd.
			*/
			inline void setParticleOrientationRangeStart(const Ogre::Quaternion& orientationRangeStart);

			/** Returns the end orientation of the particle that is going to be emitted.
			@remarks
				The orientation is generated random between mParticleOrientationRangeStart and mParticleOrientationRangeEnd.
			*/
			inline const Ogre::Quaternion& getParticleOrientationRangeEnd(void) const;

			/** Set end orientation of the particle that is going to be emitted.
			@remarks
				The orientation is generated random between mParticleOrientationRangeStart and mParticleOrientationRangeEnd.
			*/
			inline void setParticleOrientationRangeEnd(const Ogre::Quaternion& orientationRangeEnd);

			/** Enables or disables the emitter.
	        */
			virtual void setEnabled (bool enabled);
			
			/** Sets the direction of the particle that the emitter is emitting.
			@remarks
				Don't confuse this with the emitters own direction.
			@param dir The base direction of emitted particles.
			*/
			inline virtual void setParticleDirection(const Ogre::Vector3& direction);

			/** Todo
	        */
			inline bool isAutoDirection(void) const;

			/** Todo
	        */
			void setAutoDirection(bool autoDirection);

			/** Todo
	        */
			inline bool isForceEmission(void) const;

			/** Todo
	        */
			void setForceEmission(bool forceEmission);

			/** Perform initialisation actions.
	        */
			inline virtual void _prepare(ParticleTechnique* particleTechnique){/* Do nothing */};

			/** Reverse initialisation actions.
	        */
			inline virtual void _unprepare(ParticleTechnique* particleTechnique){/* Do nothing */};

			/** Perform activities before the individual particles are processed.
	        */
			inline virtual void _preProcessParticles(ParticleTechnique* technique, Ogre::Real timeElapsed);

			/** Perform activities after the individual particles are processed.
	        */
			inline virtual void _postProcessParticles(ParticleTechnique* technique, Ogre::Real timeElapsed){/* Do nothing */};

			/** Perform initialising activities as soon as the emitter is emitted.
	        */
			inline virtual void _initForEmission(void);

			/** Initialise the ParticleEmitter before it is expired itself.
	        */
			inline virtual void _initForExpiration(ParticleTechnique* technique, Ogre::Real timeElapsed);

			/** Todo
	        */
			inline virtual void _initParticlePosition(Particle* particle);

			/** Todo
	        */
			inline virtual void _initParticleForEmission(Particle* particle);

			/**  Internal method for generating the particle direction.
			*/
			inline virtual void _initParticleDirection(Particle* particle);

			/**  Internal method for generating the particle orientation.
			*/
			inline virtual void _initParticleOrientation(Particle* particle);

			/**  Internal method for generating the angle.
			*/
			inline void _generateAngle(Ogre::Radian& angle);

			/**  Internal method for generating the particle velocity.
			@param dVector Reference to vector direction * velocity
			*/
			inline virtual void _initParticleVelocity(Particle* particle);

			/**  Internal method for generating the mass of a particle.
			*/
			inline virtual void _initParticleMass(Particle* particle);

			/**  Internal method for generating the colour of a particle.
			*/
			inline virtual void _initParticleColour(Particle* particle);

			/**  Internal method for setting the texture coords of a particle.
			*/
			inline virtual void _initParticleTextureCoords(Particle* particle);

			/**  Internal method for generating the time to live of a particle.
			*/
			inline Ogre::Real _initParticleTimeToLive(void);

			/** Calculate the number of particles that the emitter wants to emit.
			*/
			virtual unsigned short _calculateRequestedParticles(Ogre::Real timeElapsed);

			/**  Internal method for generating particles' own dimensions.
			@remarks
				Particles' own dimensions will only be set if the mDynParticleAllDimensions or the mDynParticleWidth, 
				mDynParticleHeight and/or mDynParticleDepth have been defined in the emitter.
			@param particle Pointer to a particle
			 */
			inline void _initParticleDimensions(Particle* particle);

			/** Initialise some attributes that are time-based.
	        */
			inline void _initTimeBased(void);

			/** Calculate the derived position of the emitter.
			@remarks
				Note, that in script, the position is set into localspace, while if the emitter is
				emitted, its position is automatically transformed . This function always returns the 
				transformed (derived) position.
	        */
			inline const Ogre::Vector3& getDerivedPosition(void);

			/** Perform activities when a ParticleEmitter is started.
			*/
			virtual void _notifyStart (void);

			/** Perform activities when a ParticleEmitter is stopped.
			*/
			virtual void _notifyStop (void);

			/** Perform activities when a ParticleEmitter is paused.
			*/
			virtual void _notifyPause (void){/* Do nothing */};

			/** Perform activities when a ParticleEmitter is resumed.
			*/
			virtual void _notifyResume (void){/* Do nothing */};

			/** Notify that the Particle System is rescaled.
	        */
			inline virtual void _notifyRescaled(const Ogre::Vector3& scale);

			/** Copy attributes to another emitter.
	        */
			virtual void copyAttributesTo (ParticleEmitter* emitter);

			/** Copy parent attributes to another emitter.
	        */
			virtual void copyParentAttributesTo (ParticleEmitter* emitter);

			/** Get the colour of a particle that will be emitted.
	        */
			inline const Ogre::ColourValue& getParticleColour(void) const;

			/** Set the colour of an emitted particle.
	        */
			inline void setParticleColour(const Ogre::ColourValue& particleColour);

			/** Get the colour range start of an emitted particle.
	        */
			inline const Ogre::ColourValue& getParticleColourRangeStart(void) const;

			/** Set the colour range start of an emitted particle. This is the lower value used to generate a random colour.
	        */
			inline void setParticleColourRangeStart(const Ogre::ColourValue& particleColourRangeStart);

			/** Get the colour range end of an emitted particle.
	        */
			inline const Ogre::ColourValue& getParticleColourRangeEnd(void) const;

			/** Set the colour range end of an emitted particle. This is the upper value used to generate a random colour.
	        */
			inline void setParticleColourRangeEnd(const Ogre::ColourValue& particleColourRangeEnd);

			/** Get the texture coords of an emitted particle.
	        */
			const Ogre::uint16& getParticleTextureCoords(void) const;

			/** Set the texture coords of an emitted particle.
	        */
			void setParticleTextureCoords(const Ogre::uint16& particleTextureCoords);

			/** Get the texture coords range start  of an emitted particle.
	        */
			const Ogre::uint16& getParticleTextureCoordsRangeStart(void) const;

			/** Set the texture coords range start of an emitted particle. This is the lower value used to set a random texture coords.
	        */
			void setParticleTextureCoordsRangeStart(const Ogre::uint16& particleTextureCoordsRangeStart);
			
			/** Get the texture coords range end of an emitted particle.
	        */
			const Ogre::uint16& getParticleTextureCoordsRangeEnd(void) const;

			/** Set the texture coords range end of an emitted particle. This is the upper value used to set a random texture coords.
	        */
			void setParticleTextureCoordsRangeEnd(const Ogre::uint16& particleTextureCoordsRangeEnd);

			/** Todo
			*/
			inline bool isKeepLocal(void) const;

			/** If this attribute is set to 'true', the particles are emitted relative to the emitter
			*/
			void setKeepLocal(bool keepLocal);

			/** Transforms the particle position in a local position relative to the emitter
			*/
			inline bool makeParticleLocal(Particle* particle);

			/** Forwards an event to the parent technique.
	        */
			void pushEvent(ParticleUniverseEvent& particleUniverseEvent);

		protected:

			/** Convenient function to generate events.
			*/
			void _pushEmitterEvent(EventType eventType);

			/** Technique to which this emitter belongs.
			*/
			ParticleTechnique* mParentTechnique;

			/** Although the scale is on a Particle System level, the emitter can also be scaled.
			*/
			Ogre::Vector3 _mEmitterScale;

			// Type of the emitter
			Ogre::String mEmitterType;

			// Name of the emitter (optional)
			Ogre::String mName;

			/** Direction (and speed) of the emitted particle
			@remarks
				Don't confuse the particle direction with the direction of the emitter itself. 
				The particleDirection is the direction of an emitted particle.
			*/
			Ogre::Vector3 mParticleDirection;
			
			/** The original direction of the emitted particle
			@remarks
				Don't confuse this with the particles' originalDirection.
			*/
			Ogre::Vector3 mOriginalParticleDirection;

			/** Orientation of the particle as soon as it is emitted.
			@remarks
				This is only visible if a renderer is used that renders 3D particles.
			*/
			Ogre::Quaternion mParticleOrientation;

			/** If set, the range generates a random orientation between start and end.
			*/
			Ogre::Quaternion mParticleOrientationRangeStart;
			Ogre::Quaternion mParticleOrientationRangeEnd;
			bool mParticleOrientationRangeSet;

			// Angle around direction which particles may be emitted
			DynamicAttribute* mDynAngle;

			// Rate of particle emission.
			DynamicAttribute* mDynEmissionRate;

			// Identifies the type of particle this emitter emits (default is visual particle).
			ParticleType mEmitsType;

			// Identifies the name of particle this emitter emits (default is visual particle, so there is no name)
			Ogre::String mEmitsName;

			/** Dynamic attribute used to generate the total time to live.
			*/
			DynamicAttribute* mDynTotalTimeToLive;

			/** Dynamic attribute used to generate the mass of a particle.
			*/
			DynamicAttribute* mDynParticleMass;

			/** Dynamic attribute used to generate the velocity of a particle.
			*/
			DynamicAttribute* mDynVelocity;

			/** Dynamic attribute used to define the duration of the emitter.
			*/
			DynamicAttribute* mDynDuration;

			/** Dynamic attribute used to define the repeat/delay of the emitter.
			*/
			DynamicAttribute* mDynRepeatDelay;

			/** Dynamic attribute used to define the (own) dimensions of a particle.
			@remarks
				In the Particle Technique it is possible to set the default dimensions for all particles, but it
				is also possible to set the dimensions per particle. Note, that this only applies to visual particles,
				of course. This attribute is used to x, y and z dimensions with the value.
			*/
			DynamicAttribute* mDynParticleAllDimensions;
			bool mDynParticleAllDimensionsSet;

			/** Dynamic attribute used to define the (own) width of a particle.
			@remarks
				In the Particle Technique it is possible to set the default width for all particles, but it
				is also possible to set the width per particle. Note, that this only applies to visual particles,
				of course.
			*/
			DynamicAttribute* mDynParticleWidth;
			bool mDynParticleWidthSet;

			/** Dynamic attribute used to define the (own) height of a particle.
			@remarks
				In the Particle Technique it is possible to set the default height for all particles, but it
				is also possible to set the height per particle. Note, that this only applies to visual particles,
				of course.
			*/
			DynamicAttribute* mDynParticleHeight;
			bool mDynParticleHeightSet;

			/** Dynamic attribute used to define the (own) depth of a particle.
			@remarks
				In the Particle Technique it is possible to set the default depth for all particles, but it
				is also possible to set the depth per particle. Note, that this only applies to visual particles,
				of course.
			*/
			DynamicAttribute* mDynParticleDepth;
			bool mDynParticleDepthSet;

			/** Notional up vector, just used to speed up generation of variant directions.
			*/
			Ogre::Vector3 mUpVector;

			/** Particles that are left to be emitted from the previous time.
			*/
			Ogre::Real mRemainder;

			/** Helper factory
			*/
			DynamicAttributeFactory mDynamicAttributeFactory;

			/** Helper class
			*/
			DynamicAttributeHelper mDynamicAttributeHelper;

			/** Duration remainder.
	        */
			Ogre::Real mDurationRemain;

			/** Indication to determine whether duration is set.
	        */
			bool mDynDurationSet;

			/** Repeat/delay remainder.
	        */
			Ogre::Real mRepeatDelayRemain;

			/** Indication to determine whether repeat/delay is set.
	        */
			bool mDynRepeatDelaySet;

			/** Distance value that causes a decrease (or increase if needed) of the particle emission rate.
			@remarks
				This is used to decrease the emission rate if the camera is further away.
			@par
				Note, that the distance concerns the squared distance between the camera and the ParticleTechnique
				and NOT between the camera and the ParticleEmitter position. This means that it will not be accurate
				if the emitter is emitted itself. The reason is to reduce the number of calculations.
			@par
				This should be typically used for a 1 camera setup, since using 2 camera�s would result in wrong 
				calculations (mixed values).
			*/
			CameraDependency* mEmissionRateCameraDependency;

			/** Factory to create a CameraDependency.
			*/
			CameraDependencyFactory mCameraDependencyFactory;

			/** Auto direction means that the direction of a particle is not determined by the 
				direction vector that has been set, but the direction vector is generated based on
				the shape of the emitter. In most cases this means that the particle direction is
				perpendicular on the shape of the emitter.
			@remarks
				This attribute has only a meaning for certain emitters.
			*/
			bool mAutoDirection;

			/** In normal cases, emission is regulated by time. This prevents that too much particles are
				emitted at once, which causes a drop in the framerate. In some cases you just want to emit
				all particles immediately without any delay. Setting the 'mForceEmission' to true enables this.
				In that case, the emission rate defines the number of particles that are emitted immediately.
				If the emission rate is 100, the emitter emits 100 particles at once and then disables.
			*/
			bool mForceEmission;

			/** Original value, used to set it back.
			*/
			bool mOriginalForceEmission;

			/** If mForceEmission has been set to true and if all particles are emitted, the mForceEmissionExecuted
				is also set to true, preventing any further 'forced emission'.
			*/
			bool mForceEmissionExecuted;

			/** Original value, used to set it back.
			*/
			bool mOriginalForceEmissionExecuted;

			/** Colour that is assigned to an emitted particle.
			*/
			Ogre::ColourValue mParticleColour;

			/** Used to randomize the colour of an emitted particle.
			*/
			Ogre::ColourValue mParticleColourRangeStart;

			/** Used to randomize the colour of an emitted particle.
			*/
			Ogre::ColourValue mParticleColourRangeEnd;

			/** Used to determine whether the colour range has been set.
			*/
			bool mParticleColourRangeSet;

			/** Determines whether particle positions should be kept local in relation to the emitter.
	        */
			bool mKeepLocal;

			/** Texture coords that is assigned to an emitted particle (only works if the renderer uses it)
			*/
			Ogre::uint16 mParticleTextureCoords;

			/** Used to randomize the texture coords of an emitted particle.
			*/
			Ogre::uint16 mParticleTextureCoordsRangeStart;
				
			/** Used to randomize the texture coords of an emitted particle.
			*/
			Ogre::uint16 mParticleTextureCoordsRangeEnd;

			/** Used to determine whether the texture coords range has been set.
	        */
			bool mParticleTextureCoordsRangeSet;
	};

}
#endif
