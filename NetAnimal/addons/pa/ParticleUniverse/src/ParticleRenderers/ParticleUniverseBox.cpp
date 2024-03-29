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

#include "ParticleRenderers/ParticleUniverseBox.h"
#include "ParticleRenderers/ParticleUniverseBoxSet.h"

namespace ParticleUniverse
{
	//-----------------------------------------------------------------------
	Box::Box(void):
        mOwnDimensions(false),
		mPosition(Ogre::Vector3::ZERO),
		mColour(Ogre::ColourValue::White),
        mParentSet(0),
		mWidth(10.0f),
		mHeight(10.0f),
		mDepth(10.0f),
		mHalfWidth(5.0f),
		mHalfHeight(5.0f),
		mHalfDepth(5.0f),
		mDimensionsChanged(false),
		mTempCorner(Ogre::Vector3::ZERO)
	{
		mOrientation = Ogre::Quaternion::IDENTITY;
		_calculateCorners();
	}
    //-----------------------------------------------------------------------
    Box::Box(const Ogre::Vector3& position, BoxSet* owner) :
        mOwnDimensions(false),
		mPosition(Ogre::Vector3::ZERO),
		mColour(Ogre::ColourValue::White),
        mParentSet(0),
		mWidth(10.0f),
		mHeight(10.0f),
		mDepth(10.0f),
		mHalfWidth(5.0f),
		mHalfHeight(5.0f),
		mHalfDepth(5.0f),
		mDimensionsChanged(false),
		mTempCorner(Ogre::Vector3::ZERO)
	{
		mOrientation = Ogre::Quaternion::IDENTITY;
		_calculateCorners();
	}
	//-----------------------------------------------------------------------
	Box::~Box(void)
	{
	}
	//-----------------------------------------------------------------------
	void Box::_calculateCorners(void)
	{
		if (mDimensionsChanged)
		{
			mHalfWidth = 0.5f * mWidth;
			mHalfHeight = 0.5f * mHeight;
			mHalfDepth = 0.5f * mDepth;
			mDimensionsChanged = false;
		}

		mCorners[0].x = -mHalfWidth;
		mCorners[0].y = -mHalfHeight;
		mCorners[0].z = -mHalfDepth;

		mCorners[1].x = mHalfWidth;
		mCorners[1].y = -mHalfHeight;
		mCorners[1].z = -mHalfDepth;

		mCorners[2].x = -mHalfWidth;
		mCorners[2].y = mHalfHeight;
		mCorners[2].z = -mHalfDepth;

		mCorners[3].x = mHalfWidth;
		mCorners[3].y = mHalfHeight;
		mCorners[3].z = -mHalfDepth;

		mCorners[4].x = -mHalfWidth;
		mCorners[4].y = -mHalfHeight;
		mCorners[4].z = mHalfDepth;

		mCorners[5].x = mHalfWidth;
		mCorners[5].y = -mHalfHeight;
		mCorners[5].z = mHalfDepth;

		mCorners[6].x = -mHalfWidth;
		mCorners[6].y = mHalfHeight;
		mCorners[6].z = mHalfDepth;

		mCorners[7].x = mHalfWidth;
		mCorners[7].y = mHalfHeight;
		mCorners[7].z = mHalfDepth;
	}
	//-----------------------------------------------------------------------
	const Ogre::Vector3& Box::getCorner(size_t index)
	{
		assert(index < 8 && "Corner index out of bounds." );
		if (mOrientation == Ogre::Quaternion::IDENTITY)
		{
			return mCorners[index];
		}
		else
		{
			mTempCorner = mOrientation * mCorners[index];
			return mTempCorner;
		}
	}
	//-----------------------------------------------------------------------
	const Ogre::Vector3& Box::getWorldspaceCorner(size_t index)
	{
		assert(index < 8 && "Corner index out of bounds." );
		if (mOrientation == Ogre::Quaternion::IDENTITY)
		{
			mTempCorner = mPosition + mCorners[index];
		}
		else
		{
			mTempCorner = mPosition + mOrientation * mCorners[index];
		}

		return mTempCorner;
	}
	//-----------------------------------------------------------------------
	void Box::setPosition(const Ogre::Vector3& position)
	{
		mPosition = position;
		_calculateCorners();
	}
	//-----------------------------------------------------------------------
	void Box::setPosition(Ogre::Real x, Ogre::Real y, Ogre::Real z)
	{
		mPosition.x = x;
		mPosition.y = y;
		mPosition.z = z;
		_calculateCorners();
	}
	//-----------------------------------------------------------------------
	const Ogre::Vector3& Box::getPosition(void) const
	{
		return mPosition;
	}
	//-----------------------------------------------------------------------
	void Box::setDimensions(Ogre::Real width, Ogre::Real height, Ogre::Real depth)
	{
		mOwnDimensions = true;
		mWidth = width;
		mHeight = height;
		mDepth = depth;
		if (mParentSet)
			mParentSet->_notifyResized();
		mDimensionsChanged = true;
		_calculateCorners();
    }
	//-----------------------------------------------------------------------
	bool Box::hasOwnDimensions(void) const
	{
		return mOwnDimensions;
	}
	//-----------------------------------------------------------------------
	void Box::_notifyOwner(BoxSet* owner)
	{
		mParentSet = owner;
	}
	//-----------------------------------------------------------------------
	void Box::setColour(const Ogre::ColourValue& colour)
	{
		mColour = colour;
	}
	//-----------------------------------------------------------------------
	const Ogre::ColourValue& Box::getColour(void) const
	{
		return mColour;
	}
	//-----------------------------------------------------------------------
	Ogre::Real Box::getOwnWidth(void) const
	{
		return mWidth;
	}
	//-----------------------------------------------------------------------
	Ogre::Real Box::getOwnHeight(void) const
	{
		return mHeight;
	}
	//-----------------------------------------------------------------------
	Ogre::Real Box::getOwnDepth(void) const
	{
		return mDepth;
	}

}
