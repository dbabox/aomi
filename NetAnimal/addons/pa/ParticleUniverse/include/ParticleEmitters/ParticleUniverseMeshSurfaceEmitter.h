/*
-----------------------------------------------------------------------------------------------
This source file is part of the Particle Universe product.

Copyright (c) 2010 Henry van Merode

Usage of this program is licensed under the terms of the Particle Universe Commercial License.
You can find a copy of the Commercial License in the Particle Universe package.
-----------------------------------------------------------------------------------------------
*/

#ifndef __PU_MESH_SURFACE_EMITTER_H__
#define __PU_MESH_SURFACE_EMITTER_H__

#include "ParticleUniversePrerequisites.h"
#include "ParticleUniverseSystem.h"
#include "ParticleUniverseEmitter.h"

namespace ParticleUniverse
{
	/** Definition of a Triangle
    */
	class Triangle
	{
		public:
			/** The struct is used to return both the position and the normal
		    */
			struct PositionAndNormal
			{
				Ogre::Vector3 position;
				Ogre::Vector3 normal;
			};

			/** Public attributes **/
			Ogre::Real squareSurface;
			Ogre::Vector3 surfaceNormal;	// Normal of triangle v1-v2-v3
			Ogre::Vector3 v1;				// Vertex v1
			Ogre::Vector3 v2;				// Vertex v2
			Ogre::Vector3 v3;				// Vertex v3
			Ogre::Vector3 vn1;			// Normal of vertex v1
			Ogre::Vector3 vn2;			// Normal of vertex v2
			Ogre::Vector3 vn3;			// Normal of vertex v3
			Ogre::Vector3 en1;			// Normal of edge v1-v2
			Ogre::Vector3 en2;			// Normal of edge v2-v3
			Ogre::Vector3 en3;			// Normal of edge v3-v1

			/** Constructor **/
			Triangle(void){};

			/** Calculate the (square) surface of the triangle **/
			void calculateSquareSurface (void);

			/** Calculate the surface normal of the triangle **/
			void calculateSurfaceNormal (void);

			/** Calculate the edge normals of the 3 edges  **/
			void calculateEdgeNormals (void);

			/** Determine a random position on this triangle **/
			const Ogre::Vector3 getRandomTrianglePosition (void);

			/** Determine a random position including its normal on a one of the edges **/
			const PositionAndNormal getRandomEdgePositionAndNormal (void);

			/** Determine a random vertex including its normal of this triangle **/
			const PositionAndNormal getRandomVertexAndNormal (void);
	};

	/** Comparer used for sorting vector in ascending order
    */
	struct SortAscending
	{
		bool operator() (const Triangle& a, const Triangle& b)
		{
			return a.squareSurface < b.squareSurface;
		}
	};

	/** Comparer used for sorting vector in descending order
    */
	struct SortDescending
	{
		bool operator() (const Triangle& a, const Triangle& b)
		{
			return a.squareSurface > b.squareSurface;
		}
	};

	/** Define a template class for a vector of triangles.
    */
	typedef Ogre::vector<Triangle>::type Triangles;

	/** Class that constructs mesh information of a given mesh name
    @remarks
    */
	class MeshInfo
	{
		public:
			/** Defining several methods to emit particles on the mesh surface
			@remarks
				Sometimes the difference is not always visible, for example if the mesh contains triangles with more or
				less the same size. Only in case a mesh contains both small and large triangles the difference between
				the various distribution methods is more obvious.
			*/
			enum MeshSurfaceDistribution
			{ 
				MSD_HOMOGENEOUS,		// Distribute particles homogeneous (random) on the mesh surface
				MSD_HETEROGENEOUS_1,	// Distribute more particles on the smaller faces
				MSD_HETEROGENEOUS_2,	// Same as above, but now more particles are emitting from the larger faces
				MSD_VERTEX,				// Particles only emit from the vertices
				MSD_EDGE				// Particles emit random on the edges
			};

			/** Constructor **/
			MeshInfo (const Ogre::String& meshName, 
				const MeshSurfaceDistribution distribution = MSD_HOMOGENEOUS,
				const Ogre::Quaternion& orientation = Ogre::Quaternion::IDENTITY,
				const Ogre::Vector3& scale = Ogre::Vector3::ZERO);

			/** Destructor **/
			~MeshInfo (void);

			/** Generate a random number. The �high� argument determines that numbers are 
				returned between [0..high] **/
			Ogre::Real getGaussianRandom (Ogre::Real high, Ogre::Real cutoff = 4);

		    /** Retrieve vertex info **/
			void getMeshInformation(Ogre::MeshPtr mesh,
									const Ogre::Vector3& position = Ogre::Vector3::ZERO,
									const Ogre::Quaternion& orient = Ogre::Quaternion::IDENTITY,
									const Ogre::Vector3& scale = Ogre::Vector3::UNIT_SCALE);

			/** Get a triangle based on the index. */
			const Triangle& getTriangle (size_t triangleIndex);

				/** Get a random triangle (index) from the mesh. */
			const size_t getRandomTriangleIndex (void);

			/** Returns both a random point on a given triangle and its normal vector.
				How the random point and the normal are determined depends on the distribution type.
			**/
			const Triangle::PositionAndNormal getRandomPositionAndNormal (const size_t triangleIndex);

		protected:
			Triangles _triangles;
			MeshSurfaceDistribution mDistribution;
	};

	/** The MeshSurfaceEmitter is a ParticleEmitter that emits particles on the surface of a mesh.
	@remarks
		There are several ways of emitting it on the surface, from the vertices, edges and faces of a mesh.
		It is also possible to define whether more particles emit on larger faces.
    */
	class _ParticleUniverseExport MeshSurfaceEmitter : public ParticleEmitter
	{
		public:
			// Constants
			static const Ogre::Vector3 DEFAULT_SCALE;
			static const MeshInfo::MeshSurfaceDistribution DEFAULT_DISTRIBUTION;

			MeshSurfaceEmitter(void);
	        virtual ~MeshSurfaceEmitter(void);

			/** Returns the mesh name.
	        */
			const Ogre::String& getMeshName(void) const;

			/** Sets the mesh name.
	        */
			void setMeshName(const Ogre::String& meshName, bool doBuild = true);

			/** Returns true if normals are used for the particle direction.
	        */
			bool useNormals (void) const;

			/** Set indication whether normals are used for the particle direction.
	        */
			void setUseNormals (bool useNormals);

			/** Returns the type op distribution.
			@remarks
				There are several ways to emit particles on the surface of a mesh. This attribute indicates
				the type of distrubution on the surface.
	        */
			const MeshInfo::MeshSurfaceDistribution getDistribution (void) const;

			/** Set the type of particle distribution on the surface of a mesh.
	        */
			void setDistribution(MeshInfo::MeshSurfaceDistribution distribution);

			/** Returns the scale of the mesh.
	        */
			const Ogre::Vector3& getScale (void) const;

			/** Set the scale of the mesh.
			@remarks
				This options makes it possible to scale the mesh independently from the particle system scale as a whole.
	        */
			void setScale (const Ogre::Vector3& scale);

			/** Build all the data needed to generate the particles.
	        */
			void build(void);

			/** Build the data if the mesh name has been set.
	        */
			virtual void _prepare(ParticleTechnique* particleTechnique);

			/** Reverse it.
	        */
			virtual void _unprepare(ParticleTechnique* particleTechnique);

			/** Determine a particle position on the mesh surface.
	        */
			virtual void _initParticlePosition(Particle* particle);

			/** See ParticleEmitter.
			*/
			virtual unsigned short _calculateRequestedParticles(Ogre::Real timeElapsed);

			/** Determine the particle direction.
	        */
			virtual void _initParticleDirection(Particle* particle);

			/** 
	        */
			virtual void copyAttributesTo (ParticleEmitter* emitter);

		protected:
			Ogre::String mMeshName;
			Ogre::Quaternion mOrientation;
			Ogre::Vector3 mScale;
			MeshInfo::MeshSurfaceDistribution mDistribution;
			MeshInfo* mMeshInfo;
			size_t mTriangleIndex;
			bool mDirectionSet;
	};

}
#endif
